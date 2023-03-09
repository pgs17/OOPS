#include <iostream>
#include<fstream>
#include <string>
#include <map>
using namespace std;
#define MinBalance 500
class insufficientfunds{};

class account {
private:
long accountnumber;
string first_name;
string last_name;
float balance;
static long nextaccountnumber;
public:
account();
account(string f,string l,float b){
    first_name=f;
    last_name=l;
    balance=b;
    accountnumber=nextaccountnumber;
    nextaccountnumber++;
}
string getfirstname(){
    return first_name;
}
string getlastname(){
    return last_name;
}
void setbalance(float b){
    balance=b;
}
float getbalance(){
    return balance;
}
long getaccountnumber(){
    return accountnumber;
}
static void setlastaccountnumber(long accountnumber){
       nextaccountnumber=accountnumber;
}
static long getlastaccountnumber(){
    return nextaccountnumber;
}
void deposit(float amount){
    
    balance=balance + amount;
}
void withdraw(float amount){
    if(balance-amount<MinBalance){
        throw insufficientfunds();
    }
    balance-=amount;
}
friend ofstream & operator<<(ofstream &ofs,account &acc);
friend ifstream & operator>>(ifstream &ifs,account &acc);
friend ostream & operator<<(ostream &c,account &acc);
 };
  long account :: nextaccountnumber=1;
 ofstream & operator<<(ofstream &ofs,account &acc){
      ofs<<acc.accountnumber<<endl;
      ofs<<acc.first_name<<endl;
      ofs<<acc.last_name<<endl;
      ofs<<acc.balance<<endl;
      return ofs;
}
 ifstream & operator>>(ifstream &ifs,account &acc){
ifs>>acc.accountnumber;
ifs>>acc.first_name;
ifs>>acc.last_name;
ifs>>acc.balance;
return ifs;
}
 ostream & operator<<(ostream &c,account &acc){
c<<"first name"<<acc.first_name<<endl;
c<<"last name"<<acc.last_name<<endl;
c<<"account number"<<acc.accountnumber<<endl;
c<<"balance is"<<acc.balance<<endl;
return c;
}
class bank {
private:
map<long,account> accounts;
public:
bank();
account openaccount(string fname,string lname,float balance);
account balanceenquiry(long accountnumber);
account withdrawal(long accountnumber,float balance);
account deposit(long accountnumber,float balance);
void closeaccount(long accountnumber);
void showallaccounts();
~bank();
};

int main(int argc, char const *argv[])
{
    bank b;
    account acc;
    int choice;
    string fname,lname;
     long accountnumber;
     float balance;
     float amount;
     cout<<"banking system"<<endl;
     do{
        cout<< "tselect one option below:\n";
        cout<<"t1 open an account\n";
        cout<<"t2 balance inquiry\n";
        cout<<"t3 deposit\n";
        cout<<"t4 withdrawl\n";
        cout<<"t5 close an account\n";
        cout<< "t6 show all accounts\n" ;
        cout<<"t7 exit";
        cout<<"Enter Your Choice:\n";
        cin>> choice;
        switch(choice){
            case 1:
             cout<<"Enter Your First Name:\n";
             cin>>fname;
             cout<<"enter your last name:\n";
             cin>>lname;
             cout<<"enter initial balance:\n";
             cin>>balance;
             acc=b.openaccount(fname,lname,balance);
             cout<<"congrats account has been created \n";
             cout<<acc;
             break;
             case 2:
             cout<<"enter account number:\n";
             cin>>accountnumber;
             acc=b.balanceenquiry(accountnumber);
             cout<<"account details are :"<<endl;
             cout<<acc;
             break;
             case 3:
             cout<<"enter the account number:"<<endl;
             cin>>accountnumber;
             cout<<"enter amount:"<<endl;
             cin>>amount;
             acc=b.deposit(accountnumber,amount);
             cout<<"amount is deposited"<<endl;
             cout<<acc;
             break;

             case 4:
             cout<<"enter account number :" <<endl;
             cin>>accountnumber;
             cout<<"enter amount:"<<endl;
             cin>>amount;
             acc=b.withdrawal(accountnumber,amount);
             break;
             case 5:
             cout<<"enter account number :"<<endl;
             cin>>accountnumber;
             b.closeaccount(accountnumber);
             cout<<"account is closed"<<endl;
             break;
             case 6:
             b.showallaccounts();
             break;
             case 7: break;
             default:
             cout<<"enter correct choice"<<endl;
             exit(0);
        }
     }while(choice !=7);

    return 0;
}
bank::bank()
{
account account;
ifstream infile;
infile.open("Bank.data");
if(!infile)
{
//cout<<"Error in Opening! File Not Found!!"<<endl;
return;
}
while(!infile.eof())
{
infile>>account;
account.insert(pair<long,accounts>(account.getlastaccountnumber(),account));
}
account::setlastaccountnumber(account.getlastaccountnumber());
infile.close();
}
account bank::openaccount(string fname,string lname,float balance)
{
ofstream outfile;
account account(fname,lname,balance);
accounts.insert(pair<long,account>(account.getlastaccountnumber(),account));
outfile.open("Bank.data", ios::trunc);
map<long,account>::iterator itr;
for(itr=accounts.begin();itr!=accounts.end();itr++)
{
outfile<<itr->second;
}
outfile.close();
return account;
}
account bank::balanceenquiry(long accountNumber)
{
map<long,account>::iterator itr=accounts.find(accountNumber);
return itr->second;
}
account bank::deposit(long accountNumber,float amount)
{
map<long,account>::iterator itr=accounts.find(accountNumber);
itr->second.deposit(amount);
return itr->second;
}
account bank::withdrawal(long accountNumber,float amount)
{
map<long,account>::iterator itr=accounts.find(accountNumber);
itr->second.withdraw(amount);
return itr->second;
}
void bank::closeaccount(long accountNumber)
{
map<long,account>::iterator itr=accounts.find(accountNumber);
cout<<"Account Deleted"<<itr->second;
accounts.erase(accountNumber);
}
void bank::showallaccounts()
{
map<long,account>::iterator itr;
for(itr=accounts.begin();itr!=accounts.end();itr++)
{
cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
}
}
bank::~bank()
{
ofstream outfile;
outfile.open("Bank.data", ios::trunc);
map<long,account>::iterator itr;
for(itr=accounts.begin();itr!=accounts.end();itr++)
{
outfile<<itr->second;
}
outfile.close();
}


