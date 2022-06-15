#include<iostream>
#include<stack>

using namespace std;

bool isOperator(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
		return true;
	} else {
		return false;
	}
}

int precedence(char c){
	if(c=='^'){
		return 3;
	} else if(c=='*'|| c=='/'){
		return 2;
	} else if(c=='+'||c=='-'){
		return 1;
	} else {
		return -1;
	}
}

string reverse(string element){
	string result;
	
	for(int i=element.length()-1; i>=0;i--){
		result += element[i];
	}
	return result;
}

string InfixToPrefix(stack<char> s, string infix){
	//reverse the infix
	string prefix;
	
	infix = reverse(infix);
	
	//reverse the brackets as well ()
	for(int i=0; i<infix.length(); i++){
		if(infix[i]=='('){
			infix[i] = ')';
		} else if (infix[i]==')'){
			infix[i] = '(';
		}
	}
	
	for(int i=0; i<infix.length(); i++){
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z')){
			//if it is an operand
			prefix +=infix[i];
		} else if(infix[i]=='('){
			s.push(infix[i]);
		} else if(infix[i] ==')'){
			while((s.top()!='(') && (!s.empty())){
				prefix+=s.top();
				s.pop();
			}
			if(s.top()=='('){
				s.pop();
			}
		} else if(isOperator(infix[i])){
			if(s.empty()){
				s.push(infix[i]);
			} else if(precedence(infix[i])>precedence(s.top())){
				s.push(infix[i]);
			} else if((precedence(infix[i])==precedence(s.top())) && (infix[i]=='^')) {
				while((precedence(infix[i])==precedence(s.top())) && (infix[i]=='^')){
					prefix += s.top();
					s.pop();
				}
				s.push(infix[i]);
			} else if(precedence(infix[i])==precedence(s.top())) {
				s.push(infix[i]);
			} else {
				while((!s.empty()) && (precedence(infix[i])<precedence(s.top()))){
					prefix += s.top();
					s.pop();
				}
				s.push(infix[i]);
			}
		}
	}
	
	//print the elements that are remaining in the stack
	while(!s.empty()){
		prefix += s.top();
		s.pop();
	}
	//reverse the prefix again
	prefix = reverse(prefix);
	
	return prefix;
}

int main(){
	string infix_exp, prefix_exp;
	
	cout<<"Enter an infix expression: ";
	cin>>infix_exp;
	
	stack <char> s;
	cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
	
	prefix_exp = InfixToPrefix(s, infix_exp);
	cout<<endl<<"PREFIX EXPRESSION: "<<prefix_exp;
	
	return 0;
}