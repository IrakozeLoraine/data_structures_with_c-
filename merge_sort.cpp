#include<iostream>

using namespace std;


void merge(int arr[], int left, int middle, int right){
	int i = left; //starting index for left subarray,
	int j = middle+1; //starting index for right subarray,
	int k = left;// starting index for the temporary(merged) array.
	
	int size = (right-left)+1;
	int temp[size];
	
	while(i<=middle && j<=right){
		if(arr[i]<arr[j]){
			temp[k] = arr[i];
			i++; k++;
		} else {
			temp[k] = arr[j];
			j++; k++;
		}
	}
	
	while(i<=middle){
		temp[k] = arr[i]; //copying all elements from the left subarray to temp as it is
		i++; k++;
	}
	
	while(j<=right){
		temp[k] = arr[j]; //copying all elements from the right subarray to temp as it is
		j++; k++;
	}
	
	//copying the temp array to our normal array
	
	for(int p=left; p<=right; p++){
		arr[p] = temp[p];
	}
	
}

void mergeSort(int arr[], int left, int right){
	if(left<right){
		int middle = (left+right)/2;
		
		mergeSort(arr, left, middle);
		
		mergeSort(arr, middle+1, right);
		
		merge(arr, left, middle, right);
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
	
	cout<<"Enter "<<size<<" number of elements of the array: "<<endl;
	int myarr[size];
	
	for(int i=0;i<size;i++){
		cin>>myarr[i];
	}
	
	int arrlength = sizeof(myarr)/sizeof(myarr[0]);
	
	cout<<"unsorted array: "<<endl;
	printArray(myarr, arrlength);
	
	mergeSort(myarr, 0, (arrlength-1));
	
	cout<<"sorted array: "<<endl;
	printArray(myarr, arrlength);
	

	
	return 0;
}