#include<iostream>

using namespace std;

void swapArr(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

void selectionSort(int arr[], int len){
	//select an element one by one
	for(int i=0;i<len-1;i++){
		int min = i;
	
		//compare the element with every other element in array.	
		for(int j=i+1;j<len;j++){
			if(arr[j]<arr[min]){
				min = j;
			}
		}
		
		if(min != i){
			swapArr(&arr[min], &arr[i]);
		}
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
	
	selectionSort(myarr, arrlength);
	
	cout<<"sorted array: "<<endl;
	printArray(myarr, arrlength);
	
	return 0;
}