/* Create two classes- Student and Internals. 

    The class Personal has members like usn, name, sem.

    The class internals has an array that stores the internal marks scored in five courses of the current  semester of the student. 


Create another class External which is a derived class of Student. This class has an array that stores the SEE marks scored in five courses of the current semester of the student. 

*/
import java.util.*;
class Student {
String usn;
private String name;
int sem;
Student(String usn,String name,int sem){
this.usn=usn;
this.name=name;
this.sem=sem;
}
void setSem(int sem){
this.sem=sem;
}
String getName(){
return this.name;
}
}
class Internal extends Student{
int[] imarks=new int[5];
Internal(String u,String n,int sem,int[] arr){
super(u,n,sem);
this.imarks=arr;
}
int[] getI(){
return this.imarks;
}
void display(){
System.out.println("Name:"+super.getName());
System.out.println("USN:"+super.usn);
System.out.println("Sem:"+super.sem);
}
}
class Externals extends Internal{

int[] emarks=new int[5];
Externals(String u,String n,int sem,int[] arr,int[] arr2){
super(u,n,sem,arr);
this.emarks=arr2;
}
void displayDetails(){
super.display();
int[] i=super.getI();
System.out.println("Internal marks:"+Arrays.toString(i));
System.out.println("Externals:"+Arrays.toString(emarks));
}
}
class Students{
public static void main(String[] args){
int[] in={47,45,48,49,41};
int[] ex={99,97,88,83,86};
Externals extnl=new Externals("1BM23CS249","Preetham",3,in,ex);
extnl.displayDetails();
}
}

/*

OUTPUT:

Name:Preetham
USN:1BM23CS249
Sem:3
Internal marks:[47, 45, 48, 49, 41]
Externals:[99, 97, 88, 83, 86]
*/
