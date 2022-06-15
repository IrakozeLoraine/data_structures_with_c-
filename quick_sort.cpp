#include<iostream>

using namespace std;

void swapArr(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

int partition(int arr[], int start, int end){
	int pivot = arr[end];
	int pindex = start;
	
	//format the array so that the values smaller than pivot are under it
	// and the greater ones are above
	for(int i = start; i<end; i++){
		if(arr[i]<pivot) {
			swap(arr[i], arr[pindex]);
			pindex++;
		}
	}
	
	swap(arr[pindex], arr[end]);
	
	return pindex;
}

void quickSort(int arr[], int start, int end){
	if(start<end){
		int p = partition(arr, start, end);
		quickSort(arr, start, (p-1));
		quickSort(arr, (p+1), end);
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
	
	quickSort(myarr, 0, (arrlength-1));
	
	cout<<"sorted array: "<<endl;
	printArray(myarr, arrlength);

return 0;	
}