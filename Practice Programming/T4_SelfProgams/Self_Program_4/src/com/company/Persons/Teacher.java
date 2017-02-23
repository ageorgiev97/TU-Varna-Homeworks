package com.company.Persons;

import com.company.University.Discipline;

public class Teacher extends Person {
    private String title;
    private Discipline discipline;

    public Teacher(String name, String personalId, String title, Discipline discipline) {
        super(name,personalId);
        this.title = title;
        this.discipline = discipline;
    }
}
