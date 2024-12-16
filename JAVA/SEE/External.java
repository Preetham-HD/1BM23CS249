/*
Create a package CIE which has two classes - Personal and
Internals. The class Personal has members like usn, name,
sem. The class Internals has an array that stores the
internal marks scored in five courses of the current
semester of the student. Create another package SEE
which has the class External which is a derived class of
Personal. This class has an array that stores the SEE marks
scored in five courses of the current semester of the
student. Import the two packages in a file that declares
the final marks of n students in all five courses
*/

package SEE;
import CIE.Personal;
public class External extends Personal{
public int[] exMarks=new int[5];
public External(String u,String name, int sem,int[] exmarks){
super(u,name,sem);
this.exMarks=exmarks;
}
}
