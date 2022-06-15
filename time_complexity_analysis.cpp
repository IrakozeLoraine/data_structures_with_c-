#include<iostream>

using namespace std;

void sumOfNumbers1(double n){
	double sum = 0;
	for(int i=1;i<=n;i++){
		sum = sum+1;
	}
	cout<<"Method 1: Sum of "<<n<<" numbers is: "<<sum<<endl;
}

void sumOfNumbers2(double n){
	double sum = (n*(n+1))/2;
	cout<<"Method 2: Sum of "<<n<<" numbers is: "<<sum<<endl;
}

int main(){
	double num;
	cout<<"Enter number to which you want the sum: ";
	cin>>num;
	sumOfNumbers2(num);
	return 0;
}