Create a class Account that stores customer name, account number and type of account. From this derive the classes Cur-acct and Sav-acct to make them more specific to their requirements. Include the necessary methods in
order to achieve the following tasks:

a) Accept deposit from customer and update the balance.
b) Display the balance.
c) Compute and deposit interest
d) Permit withdrawal and update the balance

Check for the minimum balance, impose penalty if necessary and update the balance.


class Account{
String name;
int accountNo;
String type;
double balance;
void displayBal(){
System.out.println("the current balance is:"+this.balance);
}
void deposit(double amount){
this.balance=this.balance+amount;
this.displayBal();
}
void withdrawl(double amount){
if(this.balance>=amount){
this.balance=this.balance-amount;
this.displayBal();
}
else System.out.println("cannot withdraw, insufficient balance");
}
void displayDetails(){
System.out.println("Name:"+this.name);
System.out.println("Account No:"+this.accountNo);
System.out.println("Account type:"+this.type);
this.displayBal();
}
}
class Savings extends Account{
Savings(String name,int no,double bal){
this.name=name;
this.accountNo=no;
this.type='savings';
this.balance=bal;
}
void interest(){
double interest=this.balance*0.03;
System.out.println("the interest is "+interest);
this.balance=this.balance+interest;
this.displayBal();
}
}
class Current extends Account{
Current(String name,int no,double bal){
this.name=name;
this.accountNo=no;
this.type='current';
this.balance=bal;
}
void penalty(){
if(this.balance<1000.0){
double penalty=500.0;
this.balance=this.balance-penalty;
this.displayBal();
}}
}
class Mainn{
public static void main(String[] args){
Savings s1=new Savings("Person1",101,1500.0);
s1.deposit(500.0);
s1.withdraw(200.0);
s1.interest();
s1.displayDetails();
}}


/*
OUTPUT:
the deposited amount is 500.0
the current balance is:2000.0
the withdrawed amount is 200.0
the current balance is:1800.0
the interest is 54.0
the current balance is:1854.0
Details:
Name:Person1
Account No:101
Account type:savings
the current balance is:1854.0
------------------------------------------------------------------------------------------------------------
the deposited amount is 5000.0
the current balance is:6500.0
the withdrawed amount is 2000.0
the current balance is:4500.0
the current balance is:4500.0
Details:
Name:Person2
Account No:201
Account type:current
the current balance is:4500.0
------------------------------------------------------------------------------------------------------------

*/
