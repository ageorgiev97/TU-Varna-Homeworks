package com.company.Persons;

import com.company.University.Discipline;
import com.company.Interfaces.CanAddDiciplines;

import java.util.ArrayList;

public class Student extends Person implements CanAddDiciplines {
    private String personalId;
    private String major;
    private int yearInUniversity;
    private float avrgGrade;
    private ArrayList<Discipline> disciplines;



    public Student(String name, String personalId) {
        super(name,personalId);
        this.disciplines = new ArrayList<>();
    }

    public Student(String name, String personalId, String major, int yearInUniversity, float grade) {
        super(name,personalId);
        this.major = major;
        this.yearInUniversity = yearInUniversity;
        this.avrgGrade = grade;
    }



    @Override
    public void addDiscipline(Discipline discipline){
        this.disciplines.add(discipline);
    }


    public void print() {
        System.out.println(this.getPersonalId()+" "+this.getName());
        System.out.println("Average Grade: "+this.avrgGrade);
        System.out.println("Year in university: "+this.yearInUniversity);
        for (Discipline discipline : disciplines) {
            discipline.print();
        }
    }
}
