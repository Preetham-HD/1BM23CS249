/*
Write a Java  program that demonstrates handling of exceptions in inheritance tree. Create a base class called “Father” and derived class called “Son” which extends the base class. In Father class, implement a constructor which takes the age and throws the exception WrongAge( ) when
the input age<0. 
In Son class, implement a constructor that uses both father and son’s age and throws an
exception if son’s age is >=father’s age.


*/

class WrongAgeException extends Exception{
WrongAgeException(String message){
super(message);
}
}
class Father{
int fatherAge;
public Father(int age) throws WrongAgeException {
if(age<=0){
throw new WrongAgeException("Father's age cannot be less than or equal to 0");
}
this.fatherAge=age;
}
}
class Son extends Father{
int sonAge;
 public Son(int age1, int age2) throws WrongAgeException {
super(age1);
this.sonAge=age2;
if(sonAge>=fatherAge){
throw new WrongAgeException("son's age cannot be greater than the father's age");
}
}
}
class FatherSon{
public static void main(String[] args){
try{
Father f1=new Father(-25);
}
catch(Exception e){
System.out.println(e.getMessage());
}
try{
Son s1=new Son(34,36);
}
catch(Exception e){
System.out.println(e.getMessage());
}
}
}

/*
output:
Father's age cannot be less than or equal to 0
son's age cannot be greater than the father's age

*/
