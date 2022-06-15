#include<iostream>
#include<math.h>

using namespace std;

class MinHeap{
	public:
		int *harr;//heap array of elements
		int capacity;//maximum possible size of heap
		int heap_size;//current number of elements in heap
		
		MinHeap(int cap){
			harr=new int[cap];
			capacity=cap;
			heap_size=0;
		}
		
		int parent(int i);
		int left(int i);
		int right(int i);
		int getMin();
		int extraMin();
		void insertKey(int k);
		void decreaseKey(int i, int new_val);
		void deleteKey(int i);
		void heapify(int i);
		void linearSearch(int val);
		void printArray();
		int height();
};

void  swap(int* x, int* y){
	int* temp = x;
	x=y;
	y=temp;
}

void MinHeap::linearSearch(int val){
	for(int i=0; i<heap_size; i++){
		if(harr[i]==val){
			cout<<"Value Found!";
			return;
		}
	}
	cout<<"Value NOT Found!";
}

void MinHeap::printArray(){
	for(int i=0;i<heap_size; i++)
		cout<<harr[i]<<" ";
	cout<<endl;
}

int MinHeap::height(){
	return ceil(log2(heap_size+1))-1;
}

void MinHeap::insertKey(int k){
	if (heap_size==capacity){
		cout<<"Overflow: Heap full";
		return;
	}
	heap_size++;
	int i = heap_size-1;
	harr[i] = k;
	while(i!=0 && harr[parent(i)]>harr[i]){
		swap(harr[i], harr[parent(i)]);
		i=parent(i);
	}
}

void MinHeap::deleteKey(int i){
	decreaseKey(i, INT_MIN);
	//delete the root with the value we wanted to delete
	extraMin();
}

void MinHeap::decreaseKey(int i, int new_val){
	harr[i]=new_val;
	//swap the values until you reach the root
	while(i!=0 && harr[parent(i)]>harr[i]){
		swap(harr[i], harr[parent(i)]);
		i=parent(i);
	}
}

int MinHeap::parent(int i){
	return (i-1)/2;
}

int MinHeap::left(int i){
	return (2*i+1);
}

int MinHeap::right(int i){
	return (2*i+2);
}

int MinHeap::extraMin(){
	if(heap_size<=0){
		return INT_MAX;
	} else if(heap_size == 1){
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
	
	if(l<heap_size && harr[l]<harr[i]){
		smallest = l;
	} else if(r<heap_size && harr[r]<harr[smallest]){
		smallest = r;
	}
	if(smallest!=i){
		swap(harr[i],harr[smallest]);
		heapify(smallest);
	}
}

int main(){
	int s;
	cout<<"Enter size of Min heap: ";
	cin>>s;
	MinHeap obj(s);
	cout<<"Min heap created"<<endl;
	
	int option, val;
	do{
		cout<<"What operation do you want to perform?"
		<<" Select option number. Enter 0 to exit"<<endl;
		cout<<"1.  Insert key/node"<<endl;
		cout<<"2. Search key/node"<<endl;
		cout<<"3. Delete key/node"<<endl;
		cout<<"4. Get Min"<<endl;
		cout<<"5. Extract Min"<<endl;
		cout<<"6. Height of Heap"<<endl;
		cout<<"7. Print Heap values"<<endl;
		cout<<"8. Clear Screen"<<endl;
		cout<<"0. Exit Program"<<endl;
		
		cout<<"Option: ";
		cin>>option;
		
		switch(option){
			case 0:
				break;
			case 1:
				cout<<"Enter value to insert in heap: ";
				cin>>val;
				obj.insertKey(val);
				break;
			case 2:
				cout<<"Enter value to search in heap: ";
				cin>>val;
//				obj.searchKey(val);
				break;
			case 3:
				cout<<"Enter index of heap array to delete: ";
				cin>>val;
				obj.deleteKey(val);
				break;
			case 4:
				cout<<"Get min value: ";
//				cout<<obj.getMin()<<endl;
				break;
			case 5:
				cout<<"Extract min value: ";
				cout<<obj.extraMin()<<endl;
				break;
			case 6:
				cout<<"Heap Tree Height: ";
				cout<<obj.height()<<endl;
				break;
			case 7:
				cout<<"Print heap array: ";
				obj.printArray();
				break;
			case 8:
				system("cls");
				break;
			default:
				cout<<"Invalid option"<<endl;
		}
		
	}while(option!=0);

	
	return 0;
}