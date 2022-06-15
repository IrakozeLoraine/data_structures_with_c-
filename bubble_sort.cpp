#include<iostream>

using namespace std;

void swapArr(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

void bubbleSort(int arr[], int len){
	int rounds = 0;
	for(int i=0;i<len;i++){
		rounds++;
		for(int j=0; j<len-i-1; j++){
			if(arr[j]>arr[j+1]){
				swapArr(&arr[j], &arr[j+1]);
			}
		}
	}
	cout<<"No of rounds: "<<rounds<<endl;
}

void optimizedbubbleSort(int arr[], int len){
	int rounds = 0;
	for(int i=0;i<len;i++){
		rounds++;
		bool flag = false;
		//iterate until you reach the sorted part.
		for(int j=0; j<len-i-1; j++){
			if(arr[j]>arr[j+1]){
				flag=true;
				swapArr(&arr[j], &arr[j+1]);
			}
		}
		if(flag==false){
			break;
		}
	}
	cout<<"No of rounds: "<<rounds<<endl;
}

void printArray(int arr[], int len){
	for(int i=0; i<len; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int myarr[5];
	cout<<"Enter 5 integers in random order: "<<endl;
	
	for(int i=0;i<5;i++){
		cin>>myarr[i];
	}
	
	int arrlength = sizeof(myarr)/sizeof(myarr[0]);
	
	cout<<"unsorted array: "<<endl;
	printArray(myarr, arrlength);
	
	optimizedbubbleSort(myarr, arrlength);
	
	cout<<"sorted array: "<<endl;
	printArray(myarr, arrlength);
	
	return 0;
}