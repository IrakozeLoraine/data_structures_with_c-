#include<iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int x){
	while(left<=right){
		int mid = left + ((right-left)/2);
		if(arr[mid] == x){
			return mid;
		} else if(arr[mid]<x){
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	return -1;
}

int binarySearchUsingRecursion(int arr[], int left, int right, int x){
	if(left<=right){
		int mid = left + ((right-left)/2);
		
		if(arr[mid]==x){
			return mid;
		} else if(arr[mid]<x){
			binarySearchUsingRecursion(arr, mid+1, right, x);
		} else {
			binarySearchUsingRecursion(arr, left, mid+1, x);
		}
	}
}

int main(){
	int num;
	int myarr[10];
	int arrlength = sizeof(myarr)/sizeof(myarr[0]);
	int output;
	
	cout<<"Enter 10 integers in ASCENDING ORDER"<<endl;
	for(int i=0;i<10;i++){
		cin>>myarr[i];
	}
	cout<<"Enter number that you want to search in the Array: ";
	cin>>num;
	
//	output = binarySearch(myarr, 0, 9, num);
	output = binarySearchUsingRecursion(myarr, 0, arrlength-1, num);
	
	if(output==-1){
		cout<<"No match found"<<endl;
	} else {
		cout<<"Math found at index position "<<output<<endl;
	}
	
	return 0;
}