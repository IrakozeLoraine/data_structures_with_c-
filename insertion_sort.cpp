#include<iostream>

using namespace std;

void insertionSort(int arr[], int len){
	//pick the element next to the sorted part.
	for(int i = 1; i<len; i++){
		int j=i-1;
		int picked_element = arr[i];
		while(j>=0 && arr[j]>picked_element){
			//shift all elements to make space for the picked_element.
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = picked_element;
	}
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
	
	insertionSort(myarr, arrlength);
	
	cout<<"sorted array: "<<endl;
	printArray(myarr, arrlength);
	
	return 0;
}