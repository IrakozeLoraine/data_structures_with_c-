#include<iostream>
using namespace std;

class Node {
	public:
		int key;
		int data;
		Node* next;
		
		Node(){
			key=0;
			data=0;
			next=NULL;
		}
		
		Node(int k, int d){
			key = k;
			data = d;
		}
};

class SinglyLinkedList{
	public:
		Node* head;
		
		SinglyLinkedList(){
			head = NULL;	
		}
		
		SinglyLinkedList(Node *n){
			head = n;
		}
		Node* checkIfNodeExists(int k){
			Node* temp = NULL;
			Node* ptr= head;
			while(ptr!=NULL){
				if(ptr->key==k){
					temp = ptr;
				}
				ptr= ptr->next;
			}
			return temp;
		}
		
		void appendNode(Node* n){
			if(checkIfNodeExists(n->key)!=NULL){
				cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;
			} else {
				if(head==NULL){
					head = n;
					cout<<"Node appended "<<endl;
				} else {
					Node* ptr = head;
					while(ptr->next!=NULL){
						ptr= ptr->next;
					}
					ptr->next = n;
					cout<<"Node appended "<<endl;
				}
			}
		}
		
		void prependNode(Node* n){
			if(checkIfNodeExists(n->key)!=NULL){
				cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;	
			} else {
				n->next = head;
				head = n;
				cout<<"Node prepended "<<endl;
			}
		}

		void insertNodeBefore(int k, Node* n){
			Node *ptr = checkIfNodeExists(k);
			if(ptr==NULL){
				cout<<"No node exists with key value "<<k<<endl;
			} else {
				if(checkIfNodeExists(n->key)!=NULL){
					cout<<"Node already exists with key value: "<<n->key<<". Insert another node with different key value."<<endl;
				} else {
					Node* temp = NULL;
					Node* prevptr = head;
					Node* currentptr = head->next;
					//finding the pointer to add before
					while(currentptr!=NULL){
						if(currentptr == ptr){
							temp = currentptr;
							currentptr = NULL;
						} else {
							currentptr = currentptr->next;
						}
					}
					//adding before the pointer
					if(temp !=NULL){
						prevptr->next = n;
						n->next = temp;
						cout<<"Node inserted."<<endl;
					} else {
						cout<<"Node doesn't exist with key value: "<<k<<endl;
					}
				}
			}
		}	

		void insertNodeAfter(int k, Node *n){
			Node* ptr = checkIfNodeExists(k);
			
			if(ptr==NULL){
				cout<<"No node exists with key value: "<<k<<endl;
			} else {
				if(checkIfNodeExists(n->key)!=NULL){
					cout<<"Node already exists with key value: "<<n->key<<". Insert another node with different key value."<<endl;	
				}
				else {
					n->next = ptr->next;
					ptr->next = n;
					cout<<"Node inserted."<<endl;
				}
			}
		}
		
		void deleteNodeByKey(int k){
			if(head == NULL){
				cout<<"Linked list already empty. Can't delete. "<<endl;
			} else {
				if(head->key ==k){
					head = head->next;
					cout<<"Node Unlliked with key value: "<<k<<endl;
				} else {
					Node* temp = NULL;
					Node* prevptr = head;
					Node* currentptr = head->next;
					
					while(currentptr!=NULL){
						if(currentptr->key==k){
							temp = currentptr;
							currentptr=NULL;
						} else {
							prevptr = currentptr;
							currentptr = currentptr->next;
						}
					}
					
					if(temp!=NULL){
						prevptr->next = temp->next;
						cout<<"Node Unliked with key value: "<<k<<endl;
					} else {
						cout<<"Node doesn't exist with key value: "<<k<<endl;
					}
				}
			}
		}

		void deleteAllNodes(){
			if(head ==NULL){
				cout<<"Linked list already empty. Can't delete. "<<endl;
			} else {
				head = NULL;
				cout<<"All nodes successfully deleted."<<endl;
			}
		}

		void updateNodeByKey(int k, int d){
			Node* ptr = checkIfNodeExists(k);
			if(ptr==NULL){
				cout<<"Node doesn't exist with key value "<<k<<endl;
			} else {
				ptr->data = d;
				cout<<"Node data updated successfully."<<endl;
			}
		}
		
		void displayList(){
			if(head == NULL){
				cout<<"No nodes in singly linked list."<<endl;
			} else {
				cout<<endl<<"Singly linked list values: ";
				Node* temp = head;
				
				while(temp!=NULL){
					cout<<"("<<temp->key<<", "<<temp->data<<") --> ",
					temp = temp->next;
				}
			}
		}
};

int main(){
	
	SinglyLinkedList s;
	int option;
	int key1, k1, data1;
	
	cout<<"Welcome to Singly Linked List Implementation"<<endl;
	do{
		cout<<endl<<"What operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
		cout<<"1. appendNode()"<<endl;
		cout<<"2. prependNode()"<<endl;
		cout<<"3. insertNodeBefore()"<<endl;
		cout<<"4. insertNodeAfter()"<<endl;
		cout<<"5. deleteNodeByKey()"<<endl;
		cout<<"6. deleteAllNodes()"<<endl;
		cout<<"7. updateNodeByKey()"<<endl;
		cout<<"8. displayList()"<<endl;
		cout<<"9. Clear screen"<<endl;
		
		cout<<"Choice: ";
		cin>>option;
		
		Node* n1 = new Node();
		
		switch(option){
			case 0:
				break;
			case 1:
				cout<<"Append Node Operation"<<endl;
				cout<<"Enter key of the Node to be appended: ";
				cin>>key1;
				cout<<endl<<"Enter data of the Node to be appended: ";
				cin>>data1;
				
				n1->key = key1;
				n1->data = data1;
				s.appendNode(n1);
				
				break;
			case 2:
				cout<<"Prepend Node Operation"<<endl;
				cout<<"Enter key of the Node to be appended: ";
				cin>>key1;
				cout<<endl<<"Enter data of the Node to be appended: ";
				cin>>data1;
				
				n1->key = key1;
				n1->data = data1;
				s.prependNode(n1);
				
				break;
			case 3:
				cout<<"Inserting Node Before Operation"<<endl;
				cout<<"Enter key of the existing Node before which you want to insert this new Node: ";
				cin>>k1;
				cout<<"Enter key of the new Node: ";
				cin>>key1;
				cout<<endl<<"Enter data of the new Node: ";
				cin>>data1;
				
				n1->key = key1;
				n1->data = data1;
				s.insertNodeBefore(k1, n1);
				
				break;
			case 4:
				cout<<"Inserting Node After Operation"<<endl;
				cout<<"Enter key of the existing Node after which you want to insert this new Node: ";
				cin>>k1;
				cout<<"Enter key of the new Node: ";
				cin>>key1;
				cout<<endl<<"Enter data of the new Node: ";
				cin>>data1;
				
				n1->key = key1;
				n1->data = data1;
				s.insertNodeAfter(k1, n1);
				
				break;
			case 5:
				cout<<"Delete Node By Key Operation"<<endl;
				cout<<"Enter key of the Node to be deleted: ";
				cin>>k1;
				s.deleteNodeByKey(k1);
				
				break;
			case 6:
				cout<<"Delete All Node Operation"<<endl;
				s.deleteAllNodes();
				
				break;
			case 7:
				cout<<"Update Node By Key Operation"<<endl;
				cout<<"Enter Key of the node to be updated: ";
				cin>>key1;
				cout<<"Enter new data for this node: ";
				cin>>data1;
				s.updateNodeByKey(key1, data1);
				
				break;
			case 8:
				s.displayList();
				break;
			case 9:
				system("cls");
				break;
			default:
				cout<<"Invalid input"<<endl;	
		}
		
	}while(option!=0);
	
	return 0;
}
