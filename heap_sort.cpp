#include<iostream>

using namespace std;

class MinHeap {
	public:
		int *harr;
		int capacity;
		int heap_size;
		
		MinHeap(int cap){
			heap_size = cap;
			capacity = cap;
			harr = new int[cap];
		}
		
		void heapSort();
		
		void printArray();
		
		int parent(int i){
			return (i-1)/2;
		}
		
		int left(int i){
			return (2*i+1);
		}
		
		int right(int i){
			return (2*i+2);
		}
		int getMin(){
			return harr[0];
		}
		void heapify(int i);
		
		int extractMin();
		
		void getUnsortedArray();
};

void MinHeap::printArray(){
	for(int i=0; i<heap_size; i++){
		cout<<harr[i]<<" ";	
	}
	cout<<endl;
}

void MinHeap::heapSort(){
	//declare a temporary array to store the sorted values.
	int temp[capacity];
	
	for(int j=0; j<capacity; j++){
		temp[j] = extractMin();
		cout<<temp[j]<<" ";
	}
}

void MinHeap::getUnsortedArray(){
	cout<<"Enter "<<capacity<<" number of elements of the array: "<<endl;
	for(int i=0;i<capacity;i++){
		cin>>harr[i];
	}
}

int MinHeap::extractMin(){
	if(heap_size<=0){
		return INT_MAX;
	} else if(heap_size==1){
		heap_size--;
		return harr[0];
	} else {
		int root = harr[0];
		harr[0] = harr[heap_size-1];
		heap_size--;
		heapify(0);
		return root;
	}
}

void MinHeap::heapify(int i){
	int l = left(i);
	int r = right(i);
	
	int smallest = i;

	if(l<heap_size&& harr[l]<harr[i]){
		smallest = l;
	} 
	if(r<heap_size && harr[r]<harr[smallest]){
		smallest = r;
	}
			
	if(smallest!=i){
		swap(harr[i], harr[smallest]);
		heapify(smallest);
	}
}

int main(){
	int size;
	cout<<"Enter size of the array: ";
	cin>>size;
	
	MinHeap obj(size);
	
	obj.getUnsortedArray();
	
	cout<<"unsorted array: "<<endl;
	obj.printArray();

	//heapify the array
	for(int i=size/2-1; i>=0; i--){
		obj.heapify(i);
	}

	obj.heapSort();
	
	return 0;
}