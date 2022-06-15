#include<iostream>

#define MAX 5

using namespace std;

class Stack {
	private:
		int top;
		int arr[MAX];
	public:
		Stack(){
			top = -1;
			for(int i=0; i<5; i++){
				arr[i] = 0;
			}
		}
		bool isEmpty();
		bool isFull();
		void push(int val);
		int pop();
		int count();
		int peek(int pos);
		void change(int pos, int val);
		void display();
		void enqueue();
};

bool Stack::isEmpty(){
			if(top == -1)
				return true;
			else
				return false;
		}
		
		bool Stack::isFull() {
			if(top == MAX-1)
				return true;
			else
				return false;
		}
		
		void Stack::push(int val){
			if(isFull())
				cout<<"Stack overflow"<<endl;
			else
				top++;
				arr[top] = val;
		}
		
		int Stack::pop(){
			if(isEmpty()) {
				cout<<"Stack underflow "<<endl;
				return 0;
			} else{
				int popValue = arr[top];
				arr[top] = 0;
				top--;
				return popValue;
			}
		}
		
		int Stack::count(){
			return top+1;
		}
		
		int Stack::peek(int pos){
			if(isEmpty()) {
				cout<<"Stack underflow "<<endl;
				return 0;
			} else {
				return arr[pos];
			}
			
		}
		
		void Stack::change(int pos, int val){
			arr[pos] = val;
			cout<<"Value changed at position "<<pos<<endl;
		}
		
		void Stack::display(){
			cout<<"All values in the stack are: "<<endl;
			for(int i=MAX-1; i>=0;i--){
				cout<<arr[i]<<"\t";
			}
			cout<<endl;
		}

int main(){
	Stack stack1;
	int option, position, value;
	
	cout<<endl<<"Welcome to STACK Implementation!"<<endl;
	do {
		cout<<endl<<"What Operation do you want to perform? Select Option Number. Enter 0 to Exit."<<endl;
		cout<<"1. push()"<<endl;
		cout<<"2. pop()"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. isFull()"<<endl;
		cout<<"5. peek()"<<endl;
		cout<<"6. count()"<<endl;
		cout<<"7. change()"<<endl;
		cout<<"8. display()"<<endl;
		cout<<"9. Clear Screen"<<endl<<endl;
		
		cout<<"Choice: ";
		cin>>option;
		cout<<endl;
		
		switch(option) {
			case 0:
				break;
			case 1:
				cout<<"Enter an item to push in the stack: ";
				cin>>value;
				stack1.push(value);
				break;
			case 2:
				cout<<"Pop functiion called -"<<endl<<" Popped value: "<<stack1.pop()<<endl;
				break;
			case 3:
				if(stack1.isEmpty())
					cout<<"Stack is Empty"<<endl;
				else
					cout<<"Stack is not Empty"<<endl;
				break;
			case 4:
				if(stack1.isFull())
					cout<<"Stack is Full"<<endl;
				else
					cout<<"Stack is not Full"<<endl;
				break;
			case 5:
				cout<<"Enter position of item you want to peek: ";
				cin>>position;
				cout<<"Peek function called - Value at position "<<position<<" is "<<stack1.peek(position)<<endl;
				break;
			case 6:
				cout<<"Count Function called - Number of items in the stack are: "<<stack1.count()<<endl;
				break;
			case 7:
				cout<<"Enter position of item you want to change: ";
				cin>>position;
				cout<<endl<<"Enter value of item you want to change: ";
				cin>>value;
				stack1.change(position, value);
				break;
			case 8:
				cout<<"Display Function Called - "<<endl;
				stack1.display();
				break;
			case 9:
				system("cls");
				break;
			default:
				cout<<"Invalid number"<<endl;
		}
		
	} while(option!=0);
	
	return 0;
}