#include<iostream>

using namespace std;

int main(){
	
	int myarray[5][5];
	int myarray1[2][2] = {1,2,3,4};
	int myarray2[3][3] = {{1,1,1},{2,2,2},{3,3,3}};	

	for(int i=0; i<3; i++){
		for(int j=0; j<3;j++){
			cout<<myarray2[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl<<"Enter values for a 2x2 matrix: ";
	for(int i=0; i<2; i++){
		for(int j=0; j<2;j++){
			cin>>myarray1[i][j];
		}
		cout<<endl;
	}
	
	for(int i=0; i<2; i++){
		for(int j=0; j<2;j++){
			cout<<myarray1[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int A[2][2], B[2][2], addition[2][2], substraction[2][2];
	
	cout<<endl<<"Enter values for 2-D array A: ";
	for(int i=0; i<2; i++){
		for(int j=0; j<2;j++){
			cin>>A[i][j];
		}
		cout<<endl;
	}
	
	cout<<endl<<"Enter values for 2-D array B: ";
	for(int i=0; i<2; i++){
		for(int j=0; j<2;j++){
			cin>>B[i][j];
		}
		cout<<endl;
	}
	
//	addition
	for(int i=0; i<2; i++){
		for(int j=0; j<2;j++){
			addition[i][j] = A[i][j]+B[i][j];
		}
	}
	
//	substraction
	for(int i=0; i<2; i++){
		for(int j=0; j<2;j++){
			substraction[i][j] = A[i][j]-B[i][j];
		}
	}
	
	
	cout<<endl<<"Sum of A and B: ";
	for(int i=0; i<2; i++){
		for(int j=0; j<2;j++){
			cout<<addition[i][j]<<" ";
		}
	}
	
	cout<<endl<<"Substraction of A and B: ";
	for(int i=0; i<2; i++){
		for(int j=0; j<2;j++){
			cout<<substraction[i][j]<<" ";
		}
	}
	
	
	return 0;
}