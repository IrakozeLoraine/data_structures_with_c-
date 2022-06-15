#include<iostream>

#define MAX 5
using namespace std;

class Queue {
	private:
		int front;
		int rear;
		int arr[MAX];
	
	public:
		Queue(){
			front = rear = -1;
			for(int i=0;i<MAX;i++){
				arr[i]=0;
			}
		}
		
	bool isEmpty() {
		if(front<0||front>rear)
			return true;
		else 
			return false;
	}
	
	bool isFull(){
		if(rear==MAX-1)
			return true;
		else
			return false;
	}
	void enqueue(int val){
		if(isFull()){
			cout<<"Queue is full";
		} else if(isEmpty()){
			front = rear = 0;
		} else {
			rear++;
		}
		arr[rear] = val;
	}
	
	int dequeue() {
		int deletedVal;
		if(isEmpty()){
			cout<<"Queue is empty";
			return 0;
		} else if(front==rear) {
			deletedVal =arr[front];
			arr[front] = 0;
			front = rear = -1;
		} else {
			deletedVal =arr[front];
			arr[front] = 0;
			front++;
		}
		return deletedVal;
	}
	
	int count() {
		return (rear-front)+1;
	}
	
	void display() {
		cout<<"All values in the Queue are: "<<endl;
		for(int i=0;i<MAX;i++){
			cout<<arr[i]<<"\t";
		}
		cout<<endl;
	}
};

int main() {
	Queue queue1;
	int option, position, value;
	
	cout<<endl<<"Welcome to QUEUE Implementation!"<<endl;
	do {
		cout<<endl<<"What Operation do you want to perform? Select Option Number. Enter 0 to Exit."<<endl;
		cout<<"1. Enqueue()"<<endl;
		cout<<"2. Dequeue()"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. isFull()"<<endl;
		cout<<"5. count()"<<endl;
		cout<<"6. display()"<<endl;
		cout<<"7. Clear Screen"<<endl<<endl;
		
		cout<<"Choice: ";
		cin>>option;
		cout<<endl;
		
		switch(option) {
			case 0:
				break;
			case 1:
				cout<<"Enque Operation "<<endl;
				cout<<"Enter a value to enqueue in this queue: ";
				cin>>value;
				queue1.enqueue(value);
				break;
			case 2:
				cout<<"Dequeue Operation "<<endl;
				cout<<"Dequeued Value: "<<queue1.dequeue()<<endl;
				break;
			case 3:
				if(queue1.isEmpty())
					cout<<"Queue is empty"<<endl;
				else
					cout<<"Queue is not empty"<<endl;
				break;
			case 4:
				if(queue1.isFull())
					cout<<"Queue is full"<<endl;
				else
					cout<<"Queue is not full"<<endl;
				break;
			case 5:
				cout<<"Count Operation Called"<<endl;
				cout<<"Number of items in Queue "<<queue1.count()<<endl;
				break;
			case 6:
				cout<<"Display Function Called"<<endl;
				queue1.display();
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