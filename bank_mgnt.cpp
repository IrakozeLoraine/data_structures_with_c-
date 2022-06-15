#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

class Account {
	public:
		int acc_no;
		string name;
		int balance;
		char acc_type;
		
		bool create_account();
		void show_account();
		void modify_account();
		void deposit(int amount);
		void withdraw(int amount);
};

bool Account::create_account(){
	int flag = false;
	int answer;
	cout<<"Enter account number: ";
	cin>>acc_no;
	cout<<"Enter acount holder name: ";
	cin>>name;
	cout<<"Enter account type (C for Current/S for Saving): ";
	cin>>acc_type;
	cout<<"Enter initial amount (>=5000 for Saving and >=10000 for Current): ";
	cin>>answer;
	if(acc_type=='S' && answer<5000){
		cout<<"Saving account must have initial of atleast 5,000"<<endl;
	} else if(acc_type=='C' && answer<10000){
		cout<<"Current account must have initial of atleast 10,000"<<endl;
	} else {
		balance = answer;
		cout<<"Account Created Successfully."<<endl;
		flag = true;
	}
	return flag;
}

void Account::show_account(){
	cout<<"Account number: "<<acc_no<<endl;
	cout<<"Account holder: "<<name<<endl;
	cout<<"Account type: "<<acc_type<<endl;
	cout<<"Balance Amount: "<<balance<<endl;
}

void Account::modify_account(){
	int ch;
	cout<<"Enter account number: ";
	Account::show_account();
	
	cout<<"What would you like to modify: "<<endl;
	cout<<"1. Account holder name"<<endl;
	cout<<"2. Account Type"<<endl;
	cout<<"3. Account Balance Amouunt"<<endl;
	
	cout<<"Choice: ";
	cin>>ch;
	
	switch(ch){
		case 1:
			cout<<"Enter new account holder name: ";
			cin>>name;
			break;
		case 2:
			cout<<"Enter account type (Current/Saving): ";	
			cin>>acc_type;
			break;
		case 3:
			cout<<"Enter balance amount: ";
			cin>>balance;
			break;
		default:
			cout<<"Invalid input";
	}
}

void Account::deposit(int amount) {
	balance = balance + amount;
}

void Account::withdraw(int amount) {
	balance = balance - amount;
}

void write_account(){
	Account acc;
	bool is_created = acc.create_account();
	if(is_created){
		fstream outfile;
		outfile.open("bank_account.txt", ios::app);
		outfile<<acc.acc_no<<" "<<acc.name<<" "<<acc.acc_type<<" "<<acc.balance<<endl;
		outfile.close();
	} else {
		cout<<"This account creation failed. Please try again with precise information"<<endl;
	}
}

vector<string> explode(const string& str, const char& ch){
	string next;
	vector<string> result;
	
	stringstream ss(str);
	string line;
	
	while(getline(ss, line, ' ')){
		result.push_back(line);
	}
	return result;
}


void get_all_accounts(){
	//open the file
	
	cout<<endl<<"ACCOUNTS LIST"<<endl<<endl;
	
	ifstream inFile;
	inFile.open("bank_account.txt");
	if(inFile.is_open()){
		//process file
		string line;
		while(!inFile.eof()){
			getline(inFile, line);
			if(inFile.good()){
				cout<<line<<endl;
			}
		}
		cout<<endl;
		inFile.close();
	} else {
		cout<<"Failed to open file"<<endl;
		exit(-1);
	}
}

void menu(){
	int option, num;
	
	do{
		cout<<"\t===== WELCOME TO BANK MANAGEMENT SYSTEMS =====  |"<<endl;
		cout<<"\t|\t\t1. CREATE ACCOUNT\t\t|"<<endl;
		cout<<"\t|\t\t2. BANK ENQUIRY\t\t\t|"<<endl;
		cout<<"\t|\t\t3. DEPOSIT AMOUNT\t\t|"<<endl;
		cout<<"\t|\t\t4. WITHDRAW AMOUNT\t\t|"<<endl;
		cout<<"\t|\t\t5. CLOSE ACCOUNT\t\t|"<<endl;
		cout<<"\t|\t\t6. MODIFY ACCOUNT\t\t|"<<endl;
		cout<<"\t|\t\t7. ACCOUNTS LIST\t\t|"<<endl;
		cout<<"\t|\t\t8. EXIT\t\t\t\t|"<<endl<<endl;
		
		cout<<"\t\tOption (1-8): ";
		cin>>option;
		
		system("cls");
		switch(option){
			case 1:
				write_account();
				break;
			case 2:
				cout<<"Enter account number: ";
				cin>>num;
//				bank_enquiry(num);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				get_all_accounts();
				break;
			case 8:
				cout<<endl<<"\t\tThanks For Using Our Services!"<<endl;
				break;
			default:
				cout<<endl<<"\t\tUnknown Option! Please Choose from 1 to 8"<<endl;
		}
	}while(option!=8);
}

int main(){
	menu();
	return 0;
}