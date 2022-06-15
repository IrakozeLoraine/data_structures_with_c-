#include<iostream>
using namespace std;

class Node {
	public:
		int key;
		int data;
		Node* next;
		
		Node(){
			key = 0;
			data = 0;
			next = NULL;
		}
		
		Node(int k, int d){
			key = k;
			data = d;
			next = NULL;
		}
};

class CircularLinkedList{
	public:
		Node* head;
		
		CircularLinkedList(){
			head = NULL;
		}
		
		Node* checkIfNodeExists(int k){
			Node* temp = NULL;
			Node* ptr = head;
			
			if(ptr==NULL){
				return temp;
			} else {
				do{
					if(ptr->key == k){
						temp = ptr;
					} 
					ptr = ptr->next;
				}while(ptr!=head);
				
				return temp;
			}
		}
		
		void appendNode(Node* n){
			if(checkIfNodeExists(n->key)!=NULL){
				cout<<"Node already exists with key value: "<<n->key<<". Append another node with a different key value."<<endl;
			} else {
				if(head == NULL){
					head = n;
					n->next = head;
					cout<<"Node appended at the head."<<endl;
				} else {
					Node* ptr = head;
					//traverse until you reach the last node
					while(ptr->next != head){
						ptr = ptr->next;
					}
					ptr->next = n;
					//backlinking
					n->next = head;
					cout<<"Node appended."<<endl;
				}
			}
		}
		
		void prependNode(Node* n){
			if(checkIfNodeExists(n->key)!=NULL){
				cout<<"Node already exists with key value: "<<n->key<<". Prepend another node with a different key value."<<endl;
			} else {
				if(head==NULL) {
					head = n;
					n->next = head;
					cout<<"Node prepended at the head."<<endl;
				} else {
					Node* ptr = head;
					//traverse until you reach the last node
					while(ptr->next!=head){
						ptr = ptr->next;
					}
					ptr->next = n;
					n->next = head;
					head = n;
					cout<<"Node prepended."<<endl;
				}
			}
		}
		
		void insertNodeBefore(int k, Node* n){
			Node* ptr = checkIfNodeExists(k);
			if(ptr==NULL){
				cout<<"Node doesn't exist with key value: "<<k<<endl;
			} else {
				if(checkIfNodeExists(n->key)!=NULL){
					cout<<"Node already exists with key value: "<<n->key<<". Insert another node with different key value."<<endl;
				} else if(ptr==head){
					Node* temp = head;
					//traverse until you reach the last node
					while(temp->next!=head){
						temp = temp->next;
					}
					
					n->next = head;
					temp->next = n;
					head = n;
					
					cout<<"Node added at the head"<<endl;
				} else {
					Node* temp = NULL;
					Node* prevptr = head;
					Node* currentptr = head->next;
					
					while(currentptr!=NULL){
						if(currentptr->key == k){
							temp = currentptr;
							currentptr =NULL;
						} else{
							prevptr = prevptr->next;
							currentptr = currentptr->next;
						}
					}
					
					if(temp==NULL){
						cout<<"Node with key value: "<<k<<" does not exist."<<endl;
					} else {
						prevptr->next = n;
						n->next = ptr;
						cout<<"Node inserted in between."<<endl;
					}
				}
			}
		}

		void insertNodeAfter(int k, Node* n){
			Node* ptr = checkIfNodeExists(k);
			if(ptr==NULL){
				cout<<"Node doesn't exist with key value: "<<k<<endl;
			} else {
				if(checkIfNodeExists(n->key)!=NULL){
					cout<<"Node already exists with key value: "<<n->key<<". Insert another node with different key value."<<endl;
				} else {
					if(ptr->next == head) {
						n->next = head;
						ptr->next = n;
						cout<<"Node inserted at the End"<<endl;
					} else {
						n->next = ptr->next;
						ptr->next = n;
						cout<<"Node inserted in between"<<endl;
					}
				}
			}
		}

		void deleteNodeByKey(int k){
			Node* ptr = checkIfNodeExists(k);
			if(ptr==NULL){
				cout<<"Node doesn't with key value: "<<k<<". Can't delete."<<endl;
			} else {
				if(head==NULL){
					cout<<"Circular linked list already Empty. Can't delete"<<endl;
				} else if(ptr == head) {
					//one node in the list
					if(head->next == NULL){
						head = NULL;
					} else{
						Node* currentptr = head;
						while(currentptr->next!=head){
							currentptr = currentptr->next;
						}
						currentptr->next = head->next;
						head = head->next;
						cout<<"Node unlinked with key value: "<<k<<endl;
					}
				} else {
					Node* temp = NULL;
					Node* prevptr = head;
					Node* currentptr = head->next;
					//identify the exact node to remove and its previous node.
					while(currentptr!=NULL){
						if(currentptr->key == k){
							temp = currentptr;
							currentptr =NULL;
						} else {
							prevptr = prevptr->next;
							currentptr = currentptr->next;
						}
					}
					
					if(temp==NULL){
						cout<<"Node not found with key value: "<<k<<". Can't delete."<<endl;
					} else {
						prevptr->next = temp->next;
						cout<<"Node unlinked with key value: "<<k<<endl;
					}
				}
			}
		}
		
		void updateNodeByKey(int k, int d){
			Node* ptr = checkIfNodeExists(k);
			if(ptr!=NULL){
				ptr->data = d;
				cout<<"Node data updated successfully."<<endl;
			} else {
				cout<<"Node doesn't with key value: "<<k<<". Can't delete."<<endl;
				
			}
		}
		
		void displayList(){
			if(head == NULL){
				cout<<"No Nodes in the circular linked list."<<endl;
			} else {
				cout<<endl<<"Head address: "<<head<<endl;
				cout<<"Circular linked list: "<<endl;
				
				Node* temp = head;
				
				do{
					cout<<"("<<temp->key<<", "<<temp->data<<", "<<temp->next<<") -->";
					temp = temp->next;                       
				}while(temp!=head);
			}
		}
};

int main(){
	
	CircularLinkedList c;
	int option;
	int key1, k1, data1;
	
	cout<<"Welcome to Doubly Linked List Implementation"<<endl;
	do{
		cout<<endl<<"What operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
		cout<<"1. appendNode()"<<endl;
		cout<<"2. prependNode()"<<endl;
		cout<<"3. insertNodeBefore()"<<endl;
		cout<<"4. insertNodeAfter()"<<endl;
		cout<<"5. deleteNodeByKey()"<<endl;
		cout<<"6. updateNodeByKey()"<<endl;
		cout<<"7. displayList()"<<endl;
		cout<<"8. Clear screen"<<endl;
		
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
				c.appendNode(n1);
				
				break;
			case 2:
				cout<<"Prepend Node Operation"<<endl;
				cout<<"Enter key of the Node to be appended: ";
				cin>>key1;
				cout<<endl<<"Enter data of the Node to be appended: ";
				cin>>data1;
				
				n1->key = key1;
				n1->data = data1;
				c.prependNode(n1);
				
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
				c.insertNodeBefore(k1, n1);
				
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
				c.insertNodeAfter(k1, n1);
				
				break;
			case 5:
				cout<<"Delete Node By Key Operation"<<endl;
				cout<<"Enter key of the Node to be deleted: ";
				cin>>k1;
				c.deleteNodeByKey(k1);
				
				break;
			case 6:
				cout<<"Update Node By Key Operation"<<endl;
				cout<<"Enter Key of the node to be updated: ";
				cin>>key1;
				cout<<"Enter new data for this node: ";
				cin>>data1;
				c.updateNodeByKey(key1, data1);
				
				break;
			case 7:
				c.displayList();
				break;
			case 8:
				system("cls");
				break;
			default:
				cout<<"Invalid input"<<endl;	
		}
		
	}while(option!=0);
	
	return 0;
}