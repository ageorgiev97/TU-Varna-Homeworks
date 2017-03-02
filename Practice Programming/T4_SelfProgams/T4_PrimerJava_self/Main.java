/* Self-програма JavaExample
 * от Александър Росенов Георгиев, СИТ курс: I, група:2, фак. номер:61662147
 * e-mail: aleksandar.r.georgiev@gmail.com
 */

package com.company;

import com.company.University.Discipline;
import com.company.University.University;

import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Welcome to our virtual univerisity!");

        System.out.println("How should we name your univesity?");
        String nameOfUniversity = sc.nextLine();

        University mainUniversity = new University(nameOfUniversity);



      int command;
        do {
            System.out.println("Main Menu:");
            System.out.println("1. Add Students to the university");
            System.out.println("2. Add Disciplines to the university");
            System.out.println("3. Add Discipline from the list to Student");
            System.out.println("4. Print info for student");
            System.out.println("5. Exit");
            command = Integer.parseInt(sc.nextLine());
            switch (command){
                case 1:
                    System.out.println("How many students you want to add?");
                    int numberOfStudents = Integer.parseInt(sc.nextLine());
                    mainUniversity.addStudentsToUniversity(numberOfStudents);
                    break;
                case 2:
                    System.out.println("Id of Discipline:");
                    int tmpDisciplineId = Integer.parseInt(sc.nextLine());
                    System.out.println("Name of discipline:");
                    String tmpNameOfDiscipline = sc.nextLine();
                    System.out.println("Duration in weeks:");
                    int tmpDurationInWeeks = Integer.parseInt(sc.nextLine());

                    Discipline tmpDiscipline =new Discipline(tmpDisciplineId,tmpNameOfDiscipline,tmpDurationInWeeks);
                    mainUniversity.addDiscipline(tmpDiscipline);
                    break;
                case 3:
                    System.out.println("Student id:");
                    String lookingForId = sc.nextLine();
                    mainUniversity.addDisciplineToStudent(lookingForId);
                    break;
                case 4:
                    System.out.println("Student id:");
                    String lookingForIdtoPrint = sc.nextLine();
                    mainUniversity.findAndPrintStudentInfo(lookingForIdtoPrint);
                    break;
                case 5:
                    System.out.println("Bye!");
                    break;

                    default:
                        System.out.println("Wrong value!");

            }

        }while (command!=5);




    }
}
