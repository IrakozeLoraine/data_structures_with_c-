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

class BST {
	public:
		TreeNode* root;
		
		BST(){
			root = NULL;
		}
		
		bool isEmpty();
		void insertNode(TreeNode* new_node);
		TreeNode* insertRecursiveNode(TreeNode* r, TreeNode* new_node);
		void print2D(TreeNode* n, int space);
		void printPreorder(TreeNode* n);
		void printInorder(TreeNode* n);
		void printPostorder(TreeNode* n);
		void printLevelOrderBFS(TreeNode* n);
		void printGivenLevel(TreeNode* n, int level);
		TreeNode* iterativeSearch(int val);
		int height(TreeNode* n);
		TreeNode* deleteNode(TreeNode* n, int v);
		TreeNode* minValueNode(TreeNode* n);
		TreeNode* maxValueNode(TreeNode* n);
};

bool BST::isEmpty(){
	if(root == NULL)
		return true;
	else
		return false;
}

void BST::print2D(TreeNode* n, int space){
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

void BST::insertNode(TreeNode* new_node){
	if(root==NULL){
		root = new_node;
		cout<<"Value inserted as root node."<<endl;
	} else {
		TreeNode* temp = root;
		while(temp!=NULL){
			if(new_node->value==temp->value){
				cout<<"Value already added. No duplicates allowed"<<endl;
				break;
			} else if((new_node->value<temp->value)&&(temp->left==NULL)){
				temp->left = new_node;
				cout<<"Value inserted to the left"<<endl;
				break;
			} else if(new_node->value<temp->value){
				temp = temp->left;
			} else if((new_node->value>temp->value)&&(temp->right==NULL)){
				temp->right = new_node;
				cout<<"Value inserted to the right"<<endl;
				break;
			} else {
				temp = temp->right;
			}
		}
	}
}

TreeNode* BST::insertRecursiveNode(TreeNode* r, TreeNode* new_node){
	if(r==NULL){
		r=new_node;
		return r;
	} else if(new_node->value < r->value){
		r->left = insertRecursiveNode(r->left, new_node);
	} else if(new_node->value > r->value){
		r->right = insertRecursiveNode(r->right, new_node);
	} else {
		cout<<"No duplicate values allowed"<<endl;
		return r;
	}
	return r;
}

void BST::printPreorder(TreeNode* n){
	if(n==NULL)
		return;
	cout<<n->value<<" ";
	printPreorder(n->left);
	printPreorder(n->right);
}

void BST::printInorder(TreeNode* n){
	if(n==NULL)
		return;
	printInorder(n->left);
	cout<<n->value<<" ";
	printInorder(n->right);
}

void BST::printPostorder(TreeNode* n){
	if(n==NULL)
		return;
	printPostorder(n->left);
	printPostorder(n->right);
	cout<<n->value<<" ";
}

TreeNode* BST::iterativeSearch(int val){
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

int BST::height(TreeNode* n){
	if(n==NULL){
		return -1;
	} else {
		int lheight = height(n->left);
		int rheight = height(n->right);
		
		if(lheight>rheight){
			return (lheight+1);
		} else {
			return (rheight+1);
		}
	}
}

void BST::printLevelOrderBFS(TreeNode* n){
	int height = BST::height(n);
	for(int i=0; i<=height;i++){
		BST::printGivenLevel(n, i);
	}
}

void BST::printGivenLevel(TreeNode* n, int level){
	if(n==NULL){
		return;
	} else if(level==0){
		cout<<n->value<<" ";
	} else {
		printGivenLevel(n->left, level-1);
		printGivenLevel(n->right, level-1);
	}
}

TreeNode* BST::deleteNode(TreeNode* n, int v){
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
	return n;
}

TreeNode* BST::minValueNode(TreeNode* n){
	TreeNode* current = n;
	while(current->left!=NULL){
		current = current->left;
	}
	return current;
}

TreeNode* BST::maxValueNode(TreeNode* n){
	TreeNode* current = n;
	while(current->right!=NULL){
		current = current->right;
	}
	return current;
}


int main(){
	int option, val;
	BST obj;
	
	do{
		cout<<"What operation do you want to perform?"<<endl;
		cout<<"Select option number. Enter 0 to exit."<<endl;
		cout<<"1. Insert Node"<<endl;
		cout<<"2. Search Node"<<endl;
		cout<<"3. Delete Node"<<endl;
		cout<<"4. Print BST values"<<endl;
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
				cout<<"Enter a value of tree node to insert in BST: ";
				cin>>val;
				new_node->value = val;
				obj.root = obj.insertRecursiveNode(obj.root, new_node);
//				obj.insertNode(new_node);
				cout<<endl;
				break;
			case 2:
				cout<<"Enter a value to search in BST: ";
				cin>>val;
				new_node = obj.iterativeSearch(val);
				if(new_node!=NULL){
					cout<<"Value found"<<endl;
				} else {
					cout<<"Value not found in BST"<<endl;
				}
				break;
			case 3:
				cout<<"Enter value of tree node to be deleted in BST: ";
				cin>>val;
				new_node = obj.iterativeSearch(val);
				if(new_node!=NULL){
					obj.deleteNode(obj.root, val);
					cout<<"Value deleted"<<endl;
				} else {
					cout<<"Value not found in BST."<<endl;
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