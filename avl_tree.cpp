#include<iostream>
#define SPACE 10

using namespace std;

class TreeNode {
	public:
		int value;
		TreeNode* left;
		TreeNode* right;
		
		TreeNode(){
			value = 0;
			left = right = NULL;
		}
		
		TreeNode(int v){
			value = v;
			left = right = NULL;
		}
};

class AVLTree {
	public:
		TreeNode* root;
		
		AVLTree(){
			root = NULL;
		}
		
		bool isEmpty();
		TreeNode* insertNode(TreeNode* r, TreeNode* new_node);
		void print2D(TreeNode* n, int space);
		void printPreorder(TreeNode* n);
		void printInorder(TreeNode* n);
		void printPostorder(TreeNode* n);
		void printLevelOrderBFS(TreeNode* n);
		void printGivenLevel(TreeNode* n, int level);
		TreeNode* iterativeSearch(int val);
		int height(TreeNode* n);
		TreeNode* rightRotate(TreeNode* y);
		TreeNode* leftRotate(TreeNode* x);
		TreeNode* deleteNode(TreeNode* n, int v);
		TreeNode* minValueNode(TreeNode* n);
		TreeNode* maxValueNode(TreeNode* n);
		int getBalanceFactor(TreeNode* n);
};

bool AVLTree::isEmpty(){
	if(root == NULL)
		return true;
	else
		return false;
}

void AVLTree::print2D(TreeNode* n, int space){
	if(n==NULL){
		return;
	} else {
		space +=SPACE;
		print2D(n->right, space);//process the right child
		cout<<endl;
		
		for(int i=SPACE; i<space; i++){//print current node after counting space
			cout<<" ";
		}
		cout<<n->value<<endl;
		print2D(n->left, space);//process the left child
	}
}

void AVLTree::printPreorder(TreeNode* n){
	if(n==NULL)
		return;
	cout<<n->value<<" ";
	printPreorder(n->left);
	printPreorder(n->right);
}

void AVLTree::printInorder(TreeNode* n){
	if(n==NULL)
		return;
	printInorder(n->left);
	cout<<n->value<<" ";
	printInorder(n->right);
}

void AVLTree::printPostorder(TreeNode* n){
	if(n==NULL)
		return;
	printPostorder(n->left);
	printPostorder(n->right);
	cout<<n->value<<" ";
}

TreeNode* AVLTree::iterativeSearch(int val){
	if(root==NULL){
		return root;
	} else {
		TreeNode* temp = root;
		while(temp!=NULL){
			if(val==temp->value){
				return temp;
			} else if(val<temp->value) {
				temp = temp->left;
			} else {
				temp = temp->right;
			}
		}
		return NULL;
	}
}

int AVLTree::height(TreeNode* n){
	if(n==NULL){
		return -1;
	} else {
		int lheight = height(n->left);
		int rheight = height(n->right);
		
		if(lheight>rheight)
			return (lheight+1);
		else
			return (rheight+1);
	}
}

int AVLTree::getBalanceFactor(TreeNode* n){
	if(n==NULL)
		return -1;
	else
		return height(n->left) - height(n->right);
}

void AVLTree::printLevelOrderBFS(TreeNode* n){
	int height = AVLTree::height(n);
	for(int i=0; i<=height;i++){
		AVLTree::printGivenLevel(n, i);
	}
}

void AVLTree::printGivenLevel(TreeNode* n, int level){
	if(n==NULL){
		return;
	} else if(level==0){
		cout<<n->value<<" ";
	} else {
		printGivenLevel(n->left, level-1);
		printGivenLevel(n->right, level-1);
	}
}

TreeNode* AVLTree::insertNode(TreeNode* r, TreeNode* new_node){
	if(r==NULL){
		r=new_node;
		cout<<"Value inserted successfully"<<endl;
		return r;
	}
	
	if(new_node->value < r->value){
		r->left = insertNode(r->left, new_node);
	} else if(new_node->value > r->value){
		r->right = insertNode(r->right, new_node);
	} else {
		cout<<"No duplicate values allowed"<<endl;
		return r;
	}
	
	//rebalancing
	
	int bf = getBalanceFactor(r);
	
	//left-left imbalance
	if(bf>1 && new_node->value < r->left->value)
		return rightRotate(r);
	//right-right imbalance
	if(bf<-1 && new_node->value > r->right->value)
		return leftRotate(r);
	//left right imbalance
	if(bf>1 && new_node->value > r->left->value){
		r->left = leftRotate(r->left);
		return rightRotate(r);
	}
	//right left imbalance
	if(bf<-1 && new_node->value < r->right->value){
		r->right = rightRotate(r->right);
		return leftRotate(r);
	}
	
	//return the unchanged node pointer
	return r;
}

TreeNode* AVLTree::rightRotate(TreeNode* y){
	TreeNode* x = y->left;
	TreeNode* z = x->right;
	
	x->right = y;
	y->left = z;
	
	return x;
}

TreeNode* AVLTree::leftRotate(TreeNode* x){
	TreeNode* y = x->right;
	TreeNode* z = y->left;
	
	y->left = x;
	x->right = z;
	
	return y;
}

TreeNode* AVLTree::deleteNode(TreeNode* n, int v){
	if(n==NULL){
		return n;
	} else if(v<n->value){
		n->left = deleteNode(n->left, v);
	} else if(v>n->value){
		n->right = deleteNode(n->right, v);
	} else {
		if(n->left==NULL){ //node with only one right child or no child
			TreeNode* temp = n->right;
			delete n;
			return temp;
		} else if(n->right==NULL){//node with only left child
			TreeNode* temp = n->left;
			delete n;
			return temp;
		} else {//node with two children
			TreeNode* temp = minValueNode(n->right);
//			TreeNode* temp = maximumValueNode(n->left);
			n->value = temp->value;
			n->right = deleteNode(n->right, temp->value);
//			n->left = deleteNode(n->left, value);
		}
	}
	
	//rebalancing
	
	int bf = getBalanceFactor(n);
	
	if(bf>1 && getBalanceFactor(n->left)>=0){
	//left left imbalance
		return rightRotate(n);
	} else if(bf>1 && getBalanceFactor(n->left)<0){
	//left right imbalance
		n->left = leftRotate(n->left);
		return rightRotate(n);
	} else if(bf<-1 && getBalanceFactor(n->right)<=0){
	//right right imbalance
		return leftRotate(n);
	} else if(bf<-1 && getBalanceFactor(n->right)>0){
	//right left imbalance
		n->right = rightRotate(n->right);
		return leftRotate(n);
	}
	
	return n;
}

TreeNode* AVLTree::minValueNode(TreeNode* n){
	TreeNode* current = n;
	while(current->left!=NULL){
		current = current->left;
	}
	return current;
}

TreeNode* AVLTree::maxValueNode(TreeNode* n){
	TreeNode* current = n;
	while(current->right!=NULL){
		current = current->right;
	}
	return current;
}


int main(){
	int option, val;
	AVLTree obj;
	
	do{
		cout<<"What operation do you want to perform?"<<endl;
		cout<<"Select option number. Enter 0 to exit."<<endl;
		cout<<"1. Insert Node"<<endl;
		cout<<"2. Search Node"<<endl;
		cout<<"3. Delete Node"<<endl;
		cout<<"4. Print AVLTree values"<<endl;
		cout<<"5. Height of tree"<<endl;
		cout<<"6. Clear Screen"<<endl;
		cout<<"0. Exit Program"<<endl;
		
		cout<<"Choice: ";
		cin>>option;
		
		TreeNode* new_node = new TreeNode(); //to store in heap for global access
		
		switch(option){
			case 0:
				break;
			case 1:
				cout<<"Enter a value of tree node to insert in AVLTree: ";
				cin>>val;
				new_node->value = val;
				obj.root = obj.insertNode(obj.root, new_node);
				cout<<endl;
				break;
			case 2:
				cout<<"Enter a value to search in AVLTree: ";
				cin>>val;
				new_node = obj.iterativeSearch(val);
				if(new_node!=NULL){
					cout<<"Value found"<<endl;
				} else {
					cout<<"Value not found in AVLTree"<<endl;
				}
				break;
			case 3:
				cout<<"Enter value of tree node to be deleted in AVLTree: ";
				cin>>val;
				new_node = obj.iterativeSearch(val);
				if(new_node!=NULL){
					obj.root = obj.deleteNode(obj.root, val);
					cout<<"Value deleted"<<endl;
				} else {
					cout<<"Value not found in AVLTree."<<endl;
				}
				break;
			case 4:
				obj.print2D(obj.root, 5);
				cout<<"PreOrder: ";
				obj.printPreorder(obj.root);
				cout<<endl;
				cout<<"InOrder: ";
				obj.printInorder(obj.root);
				cout<<endl;
				cout<<"PostOrder: ";
				obj.printPostorder(obj.root);
				cout<<endl;
				cout<<"LevelOrder BFS: ";
				obj.printLevelOrderBFS(obj.root);
				cout<<endl;
				break;
			case 5:
				cout<<"TREE HEIGHT"<<endl;
				cout<<"Height: "<<obj.height(obj.root)<<endl;
				break;
			case 6:
				system("cls");
				break;
			default:
				cout<<"Invalid option!"<<endl;
		}
	}while(option!=0);
	
	return 0;
	
}