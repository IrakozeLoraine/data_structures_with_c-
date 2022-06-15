#include<iostream>
using namespace std;


//fibonacci series with recursion
int fib(int n){
	if(n<=1)
		return n;
	return fib(n-1)+fib(n-2);
}

int main(){
	
	int num1, num2, num3;
	
	cout<<"Enter 1st number to check: ";
	cin>>num1;

	cout<<"Enter 2nd number to check: ";
	cin>>num2;

	//swapping two variables
	cout<<"Entered numbers: num1: "<<num1<<", num2: "<<num2<<endl;
	
	//using third varirable.
	num3 = num1;
	num1=num2;
	num2=num3;
	cout<<"After swapping using 3rd variable: num1: "<<num1<<", num2: "<<num2<<endl;
	
	//using third
	num1=num1+num2;
	num2=num1-num2;
	num1=num1-num2;

	cout<<"After swapping without using 3rd variable: num1: "<<num1<<", num2: "<<num2<<endl;

	
	/*	
	
	finding leap year
	every leap year is divisible by 4.
	if year is divisible by both 100 and 400 then it is a leap year otherwise not
	if year is not divisible by 100 but is divisible by 4 then it is a leap year
	
	*/
	
	int year;
	cout<<end<<"Enter a year to check if its leap year or not: ";
	cin>>year;
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				cout<<"It is a leap year"<<endl;
			} else {
				cout<<"Not a leap year"<<endl;
			}
		} else {
			cout<<"It is a leap year"<<endl;
		}
	} else {
		cout<<"Not a leap year"<<endl;
	}

//factorial of a number using while loop

	int x, fact;
	cout<<"Enter a number to calculate its factorial: ";
	cin>>x;
	
	fact = x;
	
	while(x>1){
		x--; 
		fact = fact*x;
	}
	cout<<"Factorial value: "<<fact<<endl;


//	palindrome numbers

	int pal, digit, rev=0, palcpy;
	cout<<"Enter a number to check if its a palindrome or not: ";
	cin>>pal;
	
	palcpy=pal;
	while(pal!=0){
		digit = pal%10;
		rev = (rev*10)+digit;
		pal = pal/10;
	}
	
	if(palcpy==rev){
		cout<<"Palindrome"<<endl;
	} else {
		cout<<"Not a palindrome"<<endl;
	}

//	fibonacci series
	
	int first=0, second=1, next, fib;
	cout<<"Enter number of terms to be printed in the fibonacci series: ";
	cin>>fib;

	for(int i=0; i<fib; i++){
		cout<<first<<endl;
		next = first+second;
		first = second;
		second = next;
	}
	
	return 0;

}