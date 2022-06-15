#include<iostream>

using namespace std;

int factorial_rec(int n){
	if(n<=1){
		return 1;
	} else {
		return (n*factorial_rec(n-1));
	}
}

int factorial(int n){
	int fact = 1;
	for(int i=1; i<=n; i++){
		fact *= i;
	}
	return fact;
}

int main(){
	int num;
	
	cout<<"Enter number you want to find factorial for: ";
	cin>>num;
	
	cout<<num<<" has a factorial of "<<factorial_rec(num);
	
	return 0;
}