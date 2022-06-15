#include<iostream>
#include<stack>

using namespace std;

bool isOperand(char c){
	if((c>='a' && c<='z')||(c>='A'&& c<='Z')){
		return true;
	} else {
		return false;
	}
}

string prefixToInfix(string prefix){
	stack<string> s;
	
	for(int i=prefix.length()-1; i>=0; i--){
		if(isOperand(prefix[i])){
			string operand(1, prefix[i]);
			s.push(operand);
		} else {
			string operand1 = s.top();
			s.pop();
			string operand2 = s.top();
			s.pop();
			
			string expression = "("+operand1+prefix[i]+operand2+")";
			s.push(expression);
		}
	}
	
	return s.top();
}

int main(){
	string infix_exp, prefix_exp;
	
	cout<<"Enter a prefix expression: ";
	cin>>prefix_exp;
	
	cout<<"PREFIX EXPRESSION: "<<prefix_exp<<endl;
	infix_exp = prefixToInfix(prefix_exp);
	cout<<endl<<"INFIX EXPRESSION: "<<infix_exp;
	
	return 0;
}