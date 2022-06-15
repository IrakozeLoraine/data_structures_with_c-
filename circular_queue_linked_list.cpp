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
			key=k;
			data=d;
			next=NULL;
		}
};

class CircularQueue{
	public:
		Node* front,*rear;
		
		CircularQueue(){
			front=rear=NULL;
		}
		
		bool isEmpty();
		bool checkIfNodeExists(Node* n);
		void enqueue(Node* n);
		Node* dequeue();
		int count();
		void display();
};

bool CircularQueue::isEmpty(){
	if(front==NULL&&rear==NULL)
		return true;
	else
		return false;
}

bool CircularQueue::checkIfNodeExists(Node* n){
	Node* temp = front;
	bool exists = false;
	if(temp!=NULL){
		do{
			if(temp->key == n->key){
				exists = true;
				break;
			}
			temp = temp->next;	
		}while(temp!=front);
	}
	return exists;
}

void CircularQueue::enqueue(Node* n){
	if(isEmpty()){
		front = n;
		rear = n;
		n->next = front;
		cout<<"Node enqueued at the head"<<endl;
	} else if(checkIfNodeExists(n)){
		cout<<"Node with key value: "<<n->key<<" already exists. Try adding a new node with a different key value."<<endl;
	} else {
		rear->next = n;
		rear = n;
		n->next = front;
		cout<<"Node enqueued successfully."<<endl;
	}
}

int CircularQueue::count(){
	int count = 0;
	Node* temp = front;
	if(isEmpty()){
		count = 0;
	} else {
		do{
			count++;
			temp = temp->next;
		}while(temp!=front);
	}
	return count;
}

Node* CircularQueue::dequeue(){
	Node* temp = NULL;
	if(isEmpty()){
		cout<<"Queue is already empty."<<endl;
	} else {
		if(front==rear){
			temp = front;
			front = rear = NULL;
		} else {
			temp = front;
			front = front->next;
			rear->next = front;
		}
	}
	return temp;
}

void CircularQueue::display(){
	if(isEmpty()){
		cout<<"Queue is empty"<<endl;
	} else {
		Node* temp = front;
		do{
			cout<<"("<<temp->key<<", "<<temp->data<<")-> ";
			temp = temp->next;
		}while(temp!=front);
		cout<<"("<<temp->key<<", "<<temp->data<<")"<<endl;
	}
}

int main(){
	CircularQueue queue1;
	int option, key, data;
	
	cout<<endl<<"Welcome to QUEUE Implementation!"<<endl;
	do {
		cout<<endl<<"What Operation do you want to perform? Select Option Number. Enter 0 to Exit."<<endl;
		cout<<"1. Enqueue()"<<endl;
		cout<<"2. Dequeue()"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. count()"<<endl;
		cout<<"5. display()"<<endl;
		cout<<"6. Clear Screen"<<endl<<endl;
		
		cout<<"Choice: ";
		cin>>option;
		cout<<endl;
		
		Node* new_node = new Node();
		
		switch(option) {
			case 0:
				break;
			case 1:
				cout<<"Enque Operation "<<endl;
				cout<<"Enter the key of the node to be enqueued: ";
				cin>>key;
				cout<<"Enter the data of the node to be enqueued: ";
				cin>>data;
				new_node->key = key;
				new_node->data = data;
				queue1.enqueue(new_node);
				break;
			case 2:
				cout<<"Dequeue Operation called "<<endl;
				new_node = queue1.dequeue();
				if(new_node!=NULL){
					cout<<"Dequeued Value: ("<<new_node->key<<", "<<new_node->data<<")"<<endl;
				}
				delete new_node;
				break;
			case 3:
				if(queue1.isEmpty())
					cout<<"Queue is empty"<<endl;
				else
					cout<<"Queue is not empty"<<endl;
				break;
			case 4:
				cout<<"Count Operation Called"<<endl;
				cout<<"Number of items in Queue "<<queue1.count()<<endl;
				break;
			case 5:
				cout<<"Display Function Called"<<endl;
				queue1.display();
				break;
			case 6:
				system("cls");
				break;
			default:
				cout<<"Invalid number"<<endl;
		}
		
	} while(option!=0);
	
	return 0;
}