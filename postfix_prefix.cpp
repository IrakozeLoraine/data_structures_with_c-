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

string postfixToPrefix(string postfix){
	stack<string> s;
	string prefix;
	
	for(int i=0; i<postfix.length();i++){
		if(isOperand(postfix[i])){
			string operand(1, postfix[i]);
			s.push(operand);
		} else {
			string operation1 = s.top();
			s.pop();
			string operation2 = s.top();
			s.pop();
			
			string expression = postfix[i]+operation2+operation1;
			s.push(expression);
		}
	}
	return s.top();
}


int main(){
	string postfix_exp, prefix_exp;
	
	cout<<"Enter an postfix expression: ";
	cin>>postfix_exp;
	
	stack <char> s;
	cout<<"POSTFIX EXPRESSION: "<<postfix_exp<<endl;
	
	prefix_exp = postfixToPrefix(postfix_exp);
	cout<<endl<<"PREFIX EXPRESSION: "<<prefix_exp;
	
	return 0;
}