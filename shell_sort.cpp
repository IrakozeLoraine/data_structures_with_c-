#include<iostream>

using namespace std;

void bubbleSort(int arr[], int size){
	int total_loops = 0;
	for(int i=0; i<size; i++){
		for(int j=0; j<size-i-1; j++){
			if(arr[j]>arr[j+1]){
				//swap the values
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]=temp;
			}
			total_loops++;
		}
		total_loops++;
	}
	cout<<endl<<"Total loops: "<<total_loops<<endl;
}

void shellSort(int arr[], int size){
	int total_loops = 0;
	
	//narrow down the iteration by specifying a certain interval
	for(int gap = size/2; gap>0; gap/=2){
		//iterate through all the values in the gap array
		for(int j = gap; j<size; j++){
			//compare the value at the gap with the current item and swap them
			int i = 0;
			int temp = arr[j];
			//iterate in order to move forward and backward as per gap
			for(i=j; (i>=gap && arr[i-gap]>temp); i-=gap){
				arr[i] = arr[i-gap];
				total_loops++;
			}
			arr[i] = temp;
			total_loops++;
		}
		total_loops++;
	}
	cout<<endl<<"Total number of loops: "<<total_loops<<endl;
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
	
	cout<<"Enter "<<size<<" number of elements of the array: "<<endl;
	int myarr[size];
	int myarr2[size];
		
	for(int i=0;i<size;i++){
		cin>>myarr[i];
		myarr2[i] = myarr[i];
	}
		
	int arrlength = sizeof(myarr)/sizeof(myarr[0]);
		
	cout<<"unsorted array: "<<endl;
	printArray(myarr, arrlength);
		
	shellSort(myarr, size);
		
	cout<<"sorted array: "<<endl;
	printArray(myarr, arrlength);
	
	//comparing bubble sort with shell sort
	cout<<"unsorted array: "<<endl;
	printArray(myarr2, arrlength);
		
	bubbleSort(myarr2, size);
		
	cout<<"sorted array: "<<endl;
	printArray(myarr2, arrlength);
	
	
	
	return 0;
}