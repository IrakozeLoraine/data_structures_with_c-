#include<iostream>
#include<fstream>

using namespace std;

class Animal{
	public:
		virtual void eat(){
			cout<<"I am eating generic food";
		}
};

class Dog: public Animal {
	public:
		void eat(){
			cout<<"I am eating dog food";
		}
};

void function1(Animal *sample){
	sample->eat();
}

int main(){
//	
//Animal *ptr;
//Dog dogObj;
//
//ptr = &dogObj;
//
//function1(ptr);

	char arr[100];
	cout<<"Enter your name and age: ";
	cin.getline(arr, 100);
	
	fstream myfile("xyz.txt", ios::out|ios::app);
	myfile<<arr;
	myfile.close();
	cout<<"file write operation performed successfully"<<endl<<endl;
	
	cout<<"Reading from file operation started"<<endl;
	char arr1[100];
	
	ifstream obj("xyz.txt");
	obj.getline(arr1, 100);
	cout<<"array content: "<<arr1<<endl;
	cout<<"file read operation performed successfully"<<endl;
	
	
	return 0;
}