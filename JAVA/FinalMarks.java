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

import CIE.*;
import SEE.*;

public class FinalMarks {
    public static void main(String[] args) {
 
        External[] students = {
            new External("1BM23CS001", "Preetham", 3, new int[]{80, 85, 90, 75, 88}),
            new External("1BM23CS002", "Raghu", 3, new int[]{70, 80, 85, 60, 75})
        };

        Internals[] internalMarks = {
            new Internals(new int[]{20, 22, 24, 19, 23}),
            new Internals(new int[]{18, 20, 22, 17, 21})
        };

       
        System.out.println("Final Marks of Students:");
        for (int i = 0; i < students.length; i++) {
            System.out.println("Student " + (i + 1) + " (" + students[i].name + ", USN: " + students[i].usn + "):");
            for (int j = 0; j < 5; j++) {
                int finalMarks = internalMarks[i].imarks[j] + students[i].exMarks[j] / 2;
                System.out.println("Course " + (j + 1) + ": " + finalMarks);
            }
            System.out.println();
        }
    }
}
