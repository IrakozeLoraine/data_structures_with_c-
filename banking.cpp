#include<iostream>
#include<iomanip>
#include<time.h>
#include<ctime>
#include<fstream>
#include<vector>

using namespace std;

class Account {
	public:
		long acc_no;
		string names;
		string dob;
		string issue_date;
		float balance;
		Account* next;
		
		long generateAccountNumber() {
			return rand() % 10000000000 + 10000000000;
		}
		
		string generateIssueDate(){
            auto t = time(nullptr);
            auto tm = *localtime(&t);
            stringstream currentTime;
            currentTime << put_time(&tm, "%d-%m-%Y");
            return currentTime.str();
        }
        
        Account(){
        	acc_no = generateAccountNumber();
        	issue_date = generateIssueDate();
		}
};

class AccountList {
	public:
		Account* front;
		Account* rear;
		
		AccountList(){
			front=NULL;
			rear=NULL;
		}

		bool isAccountListEmpty(){
			if(front== NULL){
				return true;
			}
			return false;
		}

		Account* checkIfAccountExist(Account* account){
			Account* temp = front;
			while(temp!=NULL){
				if(temp->acc_no==account->acc_no){
					return temp;
				}
				temp = temp->next;
			}
			return NULL;
		}

		void enqueue(Account* account){
			if(isAccountListEmpty()){
				front = rear = account;
			}
			 else if (checkIfAccountExist(account))
			{
				cout<<"Account already exists"<<endl;
			}
			else {
				rear->next = account;
				rear = account;
			}
		}

		void display(){
			cout<<"Account Number - Holder Names - Date Of Birth - Date Of Issue - Balance "<<endl;
			Account* temp = front;
			while (temp!=NULL)
			{
				cout<<temp->acc_no<<"\t"<<temp->names<<"\t"<<temp->dob<<"\t"<<temp->issue_date<<"\t"<<temp->balance<<endl;
				temp=temp->next;
			}
			
		}
};

void create_account(AccountList* acc_list){
	int nberOfAccounts;
	ofstream file;
	file.open("accounts.txt",ios::app);

	cout<<"Enter number of accounts to create: ";
	cin>>nberOfAccounts;

	for (auto i = 0; i < nberOfAccounts; i++)
	{	
		Account* acc = new Account();
		cout<<"Enter acount holder names: ";
		cin.ignore();
		getline(cin, acc->names);
		cout<<"Enter birth date: ";
		cin>>acc->dob;
		cout<<"Enter initial deposit: ";
		cin>>acc->balance;
		
		cout<<"Account number for "<<acc->names<<" is: "<<acc->acc_no<<endl;
		acc_list->enqueue(acc);
		file<<acc->acc_no<<"\t"<<acc->names<<"\t"<<acc->dob<<"\t"<<acc->issue_date<<"\t"<<acc->balance<<endl;
	}
	file.close();
}

void get_all_accounts(AccountList* acc_list) {
	cout<<"Account Number - Holder Names - Date Of Birth - Date Of Issue - Balance "<<endl;
	ifstream file;
	file.open("accounts.txt");
	string line;
	while(getline(file, line)){
		cout<<line<<endl;
	}
	file.close();
}

void search_account(long account_number){
	ifstream file;
	file.open("accounts.txt");
	string line;
	while(getline(file, line)){
		if(line.find(to_string(account_number))!=string::npos){
			cout<<endl;
			cout<<line<<endl;
		}
	}
	file.close();
}

void tokenizestring(string const &str, const char delim, vector<string> &out) {
    // construct a stream from the string
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        out.push_back(token);
    }

	cout<<out[0]<<endl;
}

void update_balance(string action){
	ifstream file;
	ofstream newfile;
	file.open("accounts.txt");
	newfile.open("newaccounts.txt");
	string line;
	
	long account_number;
	float amount;
	cout<<"Enter account number: ";
	cin>>account_number;
	cout<<"Enter amount to "<<action<<": ";
	cin>>amount;
	
	while(getline(file, line)){
		if(line.find(to_string(account_number))!=string::npos){
			cout<<line<<endl;
			vector<string> words;
			tokenizestring(line, '\t', words);

			// while(getline(ss, token, '\t')){
			// 	if(i==5){
					float balance = stof(words[4]);
					if(action=="deposit"){
						balance += amount;
					} else {
						balance -= amount;
					}
					cout<<"Balance after transaction: "<<balance<<endl;
					
					newfile<<words[0] <<"\t"<<words[1]<< "\t"<<words[2]<<"\t"<<words[3]<< "\t"<<balance<<endl;
			// 	}
			// 	i++;
			// }
		} else {
			newfile<<line<<endl;
		}
	}
	file.close();
	newfile.close();
	remove("accounts.txt");
	rename("newaccounts.txt", "accounts.txt");
}

void menu(AccountList* account_list){
	int option;
	long account_number;
	
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
				create_account(account_list);
				break;
			case 2:
				cout<<"Enter account number: ";
				cin>>account_number;
				search_account(account_number);
				break;
			case 3:	
			 	update_balance("deposit");
				break;
			case 4:
				update_balance("withdraw");
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				get_all_accounts(account_list);
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
	AccountList* account_list = new AccountList();
	menu(account_list);
}