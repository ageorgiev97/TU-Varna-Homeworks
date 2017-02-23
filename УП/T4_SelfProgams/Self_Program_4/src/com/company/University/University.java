package com.company.University;

import com.company.Interfaces.CanAddDiciplines;
import com.company.Persons.Student;
import com.company.Persons.Teacher;

import java.util.ArrayList;
import java.util.Scanner;

public class University implements CanAddDiciplines {
    private String name;
    private ArrayList<Student> students;
    private ArrayList<Teacher> teachers;
    private ArrayList<Discipline> disciplines;

    public University(String name) {
        this.name=name;
        this.students=new ArrayList<>();
        this.teachers=new ArrayList<>();
        this.disciplines=new ArrayList<>();
    }

    public void addStudent(Student student){
        this.students.add(student);
    }

    public void addStudentsToUniversity(int howManyStudents){
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < howManyStudents; i++) {
            System.out.println("Student "+(i+1)+":");
            System.out.println("Name:");
            String tmpName = sc.nextLine();
            System.out.println("Id:");
            String tmpId = sc.nextLine();
            System.out.println("Major:");
            String tmpMajor = sc.nextLine();
            System.out.println("Year in university:");
            int tmpYear = Integer.parseInt(sc.nextLine());
            System.out.println("Average grade:");
            float tmpAvrgGrade = Float.parseFloat(sc.nextLine());


            Student tmp = new Student(tmpName,tmpId,tmpMajor,tmpYear,tmpAvrgGrade);
            this.addStudent(tmp);

        }
    }

    @Override
    public void addDiscipline(Discipline discipline){
        this.disciplines.add(discipline);
    }

    public void showDisciplines(){
        for (Discipline discipline : disciplines) {
            discipline.print();
        }
    }

    public void addDisciplineToStudent(String personalId){
        Scanner sc = new Scanner(System.in);
        for (Student student : students) {
            if (student.getPersonalId().equals(personalId)){
                System.out.println("Chose discipline id from the disciplines bellow:");
                this.showDisciplines();
                String choise = sc.nextLine();

                for (Discipline discipline : disciplines) {
                    if (choise.equals(discipline.getId())){
                        student.addDiscipline(discipline);
                    }
                }

            }
        }

    }


    public void addTeacher(Teacher teacher){
        this.teachers.add(teacher);
    }

    public void findAndPrintStudentInfo(String lookingForIdtoPrint) {
        for (Student student : students) {
            if (student.getPersonalId().equals(lookingForIdtoPrint)){
                student.print();
            }
        }
    }
}
