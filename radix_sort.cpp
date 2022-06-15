#include<iostream>

using namespace std;

int getMax(int arr[], int size){
	int maximum = arr[0];
	
	for(int i=1; i<size; i++){
		if(arr[i]>maximum){
			maximum = arr[i];
		}
	}
	
	return maximum;
}

void countingSort(int arr[], int size, int digit_multiplier){
	int output_arr[size];
	int range = 10;
	int count_arr[range]={0};
	
	for(int i=0; i<size; i++){
		count_arr[(arr[i]/digit_multiplier)%10]++;
	}
	
	for(int i=1; i<range; i++){
		count_arr[i] = count_arr[i]+count_arr[i-1];
	}
	
	//Place the elements from the input_arr to the output_arr using count_arr
	//start from the last index so as to have it in the ascending order
	for(int i=size-1; i>=0; i--){
		output_arr[count_arr[(arr[i]/digit_multiplier)%10]-1] = arr[i];
		//decrement the count for this arr[i]
		count_arr[(arr[i]/digit_multiplier)%10]--;
	}
	
	for(int i=0; i<size; i++){
		arr[i] = output_arr[i];
	}
}

void radixSort(int arr[], int size){
	//find max number in array
	int max = getMax(arr, size);
	
	//loop through the digits of the maximum value and increment by * 10
	for(int dig=1; (max/dig)>0; dig*=10){
		//apply counting sort on each digit
		countingSort(arr, size, dig);
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
		
	radixSort(myarr, size);
		
	cout<<"sorted array: "<<endl;
	printArray(myarr, arrlength);
	
	return 0;
}