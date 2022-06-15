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

string postfixToInfix(string postfix){
	stack<string> s;
	for(int i=0; i<postfix.length(); i++){
		if(isOperand(postfix[i])){
			string operand(1, postfix[i]);
			s.push(operand);
		} else {
			string operand1 = s.top();
			s.pop();
			string operand2 = s.top();
			s.pop();
			
			string expression = "("+operand2+postfix[i]+operand1+")";
			s.push(expression);
		}
	}
	return s.top();
}

int main(){
	string infix_exp, postfix_exp;
	
	cout<<"Enter a postfix expression: ";
	cin>>postfix_exp;
	
	cout<<"POSTFIX EXPRESSION: "<<postfix_exp<<endl;
	infix_exp = postfixToInfix(postfix_exp);
	cout<<endl<<"INFIX EXPRESSION: "<<infix_exp;
	
	return 0;
}