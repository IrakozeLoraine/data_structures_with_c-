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
		};
		Node(int k, int d){
			key=k;
			data=d;
			next=NULL;
		}
};

class Stack{
	public:
		Node* top;
		Stack(){
			top = NULL;
		}
		bool isEmpty();
		bool checkIfNodeExists(Node* n);
		void push(Node* n);
		int count();
		Node* pop();
		Node* peek();
		void display();
};

bool Stack::isEmpty(){
	if(top==NULL){
		return true;
	} else {
		return false;
	}
}

bool Stack::checkIfNodeExists(Node* n){
	Node* temp = top;
	bool exist = false;
	while(temp!=NULL){
		if(temp->key==n->key){
			exist = true;
			break;
		}
		temp = temp->next;
	}
	return exist;
}

void Stack::push(Node* n){
	if(top==NULL){
		top = n;
		cout<<endl<<"Node Pushed at the top successfully."<<endl;
	} else if(checkIfNodeExists(n)){
		cout<<endl<<"Node with key: "<<n->key<<" already exists. Try entering a new node with different key value."<<endl;
	} else {
		//push the new node onto the stack as the top
		Node* temp = top;
		top = n;
		top->next = temp;
		cout<<endl<<"Node Pushed successfully."<<endl;
	}
}

int Stack::count(){
	int count = 0;
	if(top == NULL){
		count = 0;
	} else {
		Node* temp = top;
		while(temp!=NULL){
			count++;
			temp = temp->next;
		}
	}
	return count;
}


Node* Stack::pop(){
	Node* temp = NULL;
	if(isEmpty()){
		cout<<endl<<"Stack underflow"<<endl;
	} else {
		temp = top;
		top = top->next;
	}
	return temp;
}

Node* Stack::peek(){
	if(isEmpty()){
		cout<<endl<<"Stack underflow"<<endl;
		return NULL;
	} else {
		return top;
	}
}

void Stack::display(){
	if(isEmpty()){
		cout<<endl<<"Stack underflow"<<endl;
	} else {
		Node* temp = top;
		while(temp!=NULL){
			cout<<"("<<temp->key<<", "<<temp->data<<")->";
			temp = temp->next;
		}
		cout<<endl<<"Total no of Nodes in the stack: "<<count()<<endl;
	}
}

int main(){
	Stack stack1;
	int option, key, data;
	
	cout<<endl<<"Welcome to STACK Implementation!"<<endl;
	do {
		cout<<endl<<"What Operation do you want to perform? Select Option Number. Enter 0 to Exit."<<endl;
		cout<<"1. push()"<<endl;
		cout<<"2. pop()"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. peek()"<<endl;
		cout<<"5. count()"<<endl;
		cout<<"6. display()"<<endl;
		cout<<"7. Clear Screen"<<endl<<endl;
		
		cout<<"Choice: ";
		cin>>option;
		cout<<endl;
		
		Node* new_node = new Node();
		
		switch(option) {
			case 0:
				break;
			case 1:
				cout<<"Enter a key of the node to push in the stack: ";
				cin>>key;
				cout<<"Enter an value of the node to push in the stack: ";
				cin>>data;
				new_node->key = key;
				new_node->data = data;
				stack1.push(new_node);
				break;
			case 2:
				cout<<"Pop functiion called - Popped value: "<<endl;
				new_node = stack1.pop();
				if(new_node!=NULL){
					cout<<"Top of stack is: ("<<new_node->key<<", "<<new_node->data<<")"<<endl;
				}
				delete new_node;
				break;
			case 3:
				if(stack1.isEmpty())
					cout<<"Stack is Empty"<<endl;
				else
					cout<<"Stack is not Empty"<<endl;
				break;
			case 4:
				cout<<"Peek function called:  "<<endl;
				new_node = stack1.peek();
				if(new_node!=NULL){
					cout<<"TOP of Stack is: ("<<new_node->key<<", "<<new_node->data<<")"<<endl;
				}
				break;
			case 5:
				cout<<"Count Function called - Number of items in the stack are: "<<stack1.count()<<endl;
				break;
			case 6:
				cout<<"Display Function Called - "<<endl;
				stack1.display();
				break;
			case 7:
				system("cls");
				break;
			default:
				cout<<"Invalid number"<<endl;
		}
		
	} while(option!=0);
	
	return 0;
}