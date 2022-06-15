#include<iostream>

using namespace std;

class Node {
	public:
		int key;
		int data;
		Node* next;
		Node* prev;
		
		Node(){
			key=0;
			data=0;
			next=NULL;
			prev=NULL;
		}
		
		Node(int k, int d){
			key=k;
			data=d;
		}
};

class DoublyLinkedList{
	public:
		Node* head;
		DoublyLinkedList(){
			head = NULL;
		
		}

		DoublyLinkedList(Node *n){
			head = n;
		}
		
		Node* checkIfNodeExists(int k){
			Node* temp = NULL;
			Node* ptr = head;
			while(ptr!=NULL){
				if(ptr->key == k){
					temp = ptr;
				}
				ptr = ptr->next;
			}
			return temp;
		}
		
		void appendNode(Node* n){
			if(checkIfNodeExists(n->key)!=NULL){
				cout<<"Node Already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;
			} else {
				if(head==NULL){
					head = n;
					cout<<"Node appended as head node."<<endl;
				} else {
					Node* ptr = head;
					while(ptr->next!=NULL){
						ptr = ptr->next;
					}
					ptr->next = n;
					n->prev = ptr;
					cout<<"Node appended"<<endl;
				}
			}
		}
		
		void prependNode(Node *n){
			if(checkIfNodeExists(n->key)!=NULL){
				cout<<"Node Already exists with key value: "<<n->key<<". Prepend another node with different key value"<<endl;
			} else {
				if(head==NULL){
					head = n;
					cout<<"Node prepended as head node."<<endl;
				} else {
					head->prev = n;
					n->next = head;
					head = n;
					cout<<"Node prepended"<<endl;
				}
			}
		}
		
		void insertNodeBefore(int k, Node* n){
			Node* ptr = checkIfNodeExists(k);
			if(ptr==NULL) {
				cout<<"No node exists with key value: "<<k<<endl;
			} else {
				if(checkIfNodeExists(n->key)!=NULL){
					cout<<"Node already exists with key value: "<<n->key<<". insert another node with a different key value"<<endl;
				} else {
					Node* previousNode = ptr->prev;
					
					if(previousNode==NULL){
						//this is the head node
						head = n;
						head->next = ptr;
						ptr->prev = head;
						cout<<"Node inserted at the head."<<endl;
					} else {
						previousNode->next = n;
						n->prev = previousNode;
						n->next = ptr;
						ptr->prev = n;
						cout<<"Node inserted in between."<<endl;
					}
				}
			}
		}
		
		void insertNodeAfter(int k, Node* n){
			Node* ptr = checkIfNodeExists(k);
			if(ptr==NULL){
				cout<<"No node exists with key value: "<<k<<endl;
			} else {
				if(checkIfNodeExists(n->key)!=NULL){
					cout<<"Node already exists with key value: "<<n->key<<". insert another node with a different key value"<<endl;
				} else {
					Node* nextNode = ptr->next;
					if(nextNode==NULL){
						ptr->next = n;
						n->prev = ptr;
						
						cout<<"Node inserted at the end"<<endl;
					} else {
						n->next = nextNode;
						nextNode->prev = n;
						n->prev = ptr;
						ptr->next = n;
						cout<<"Node inseted in between"<<endl;
					}
				}
			}
		}
		
		void deleteNodeByKey(int k){
			Node* ptr = checkIfNodeExists(k);
			
			if(ptr == NULL){
				cout<<"No node with key value: "<<k<<endl;
			} else {
				if(head ==NULL){
					cout<<"Doubly linked list is already empty. Can't delete"<<endl;
				} else {
					Node* prevNode = ptr->prev;
					Node* nextNode = ptr->next;
					
					if(nextNode == NULL){
						prevNode->next = NULL;
						cout<<"Node deleted at the end.";
					} else {
						prevNode->next = nextNode;
						nextNode->prev = prevNode;
						cout<<"Node deleted in between";
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
 			if(head ==NULL){
 				cout<<"No Nodes in Doubly linked list"<<endl;
			} else {
				Node* ptr = head;
				cout<<"Doubly linked list values: ";
				while(ptr!=NULL) {
					cout<<"("<<ptr->key<<", "<<ptr->data<<") <--> ";
					ptr = ptr->next;
				}
			}
		 }
};
int main(){
	
	DoublyLinkedList d;
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
				d.appendNode(n1);
				
				break;
			case 2:
				cout<<"Prepend Node Operation"<<endl;
				cout<<"Enter key of the Node to be appended: ";
				cin>>key1;
				cout<<endl<<"Enter data of the Node to be appended: ";
				cin>>data1;
				
				n1->key = key1;
				n1->data = data1;
				d.prependNode(n1);
				
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
				d.insertNodeBefore(k1, n1);
				
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
				d.insertNodeAfter(k1, n1);
				
				break;
			case 5:
				cout<<"Delete Node By Key Operation"<<endl;
				cout<<"Enter key of the Node to be deleted: ";
				cin>>k1;
				d.deleteNodeByKey(k1);
				
				break;
			case 6:
				cout<<"Delete All Node Operation"<<endl;
				d.deleteAllNodes();
				
				break;
			case 7:
				cout<<"Update Node By Key Operation"<<endl;
				cout<<"Enter Key of the node to be updated: ";
				cin>>key1;
				cout<<"Enter new data for this node: ";
				cin>>data1;
				d.updateNodeByKey(key1, data1);
				
				break;
			case 8:
				d.displayList();
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