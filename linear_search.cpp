#include<iostream>

using namespace std;

void linearSearch(int arr[], int num){
	int flag = -1;
	
	for(int i=0;i<5;i++){
		if(arr[i]==num){
			cout<<"Element found at position: "<<i+1<<endl;
			flag = 0;
		}
	}
	
	if(flag == -1){
		cout<<"No element found"<<endl;
	}
	
}

int main(){
	
	int arr[5];
	int num;
	
	cout<<"Please enter 5 elements of the array"<<endl;
	
	for(int i=0;i<5;i++){
		cin>>arr[i];
	}
	
	cout<<"Please enter an element to search: ";
	cin>>num;
	
	linearSearch(arr, num);
	
	return 0;
}