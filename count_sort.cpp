#include<iostream>

using namespace std;

void countingSort(int input_arr[], int size, int range){
	int output_arr[size];
	int count_arr[range];
	
	//initialize values on the count_arr to zero according to the range
	for(int i=0; i<range; i++){
		count_arr[i] = 0;
	}
	
	//count each element in the input_arr and place the count at the appropriate index of the count_arr
	for(int i=0; i<size; i++){
		++count_arr[input_arr[i]];
	}
	
	//modify the count_arr by adding cummulative counts
	for(int i=1; i<range; i++){
		count_arr[i] = count_arr[i]+count_ar r[i-1];
	}
	
	//Place the elements from the input_arr to the output_arr using count_arr
	for(int i=0; i<size; i++){
		output_arr[--count_arr[input_arr[i]]] = input_arr[i];
	}
	//copy the output_arr to the input_arr
	for(int i=0; i<size; i++){
		input_arr[i] = output_arr[i];
	}
	
}

void printArray(int arr[], int len){
	for(int i=0; i<len; i++){
		cout<<arr[i]<<" ";	
	}
	cout<<endl;
}

int main(){
		
	int size;
	cout<<"Enter size of the array: ";
	cin>>size;
	
	int range;
	cout<<"Enter range of the unique elements not greater than 10: ";
	cin>>range;
	
	if(range>10){
		cout<<"Your range is greater than 10. Try again later";
	} else {	
		cout<<"Enter "<<size<<" number of elements of the array: "<<endl;
		int myarr[size];
		
		for(int i=0;i<size;i++){
			cin>>myarr[i];
		}
		
		int arrlength = sizeof(myarr)/sizeof(myarr[0]);
		
		cout<<"unsorted array: "<<endl;
		printArray(myarr, arrlength);
		
		countingSort(myarr, size, range);
		
		cout<<"sorted array: "<<endl;
		printArray(myarr, arrlength);
	}
	
	return 0;
}