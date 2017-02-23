package com.company.University;

public class Discipline {
   private int id;
   private String disciplineName;
   private int durationInWeeks;

    public Discipline(int id, String disciplineName, int durationInWeeks) {
        this.id=id;
        this.disciplineName = disciplineName;
        this.durationInWeeks = durationInWeeks;
    }

    public int getId() {
        return id;
    }

    public String getDisciplineName() {
        return disciplineName;
    }

    public int getDurationInWeeks() {
        return durationInWeeks;
    }

    public void print() {
        System.out.println(this.getId()+" "+this.getDisciplineName()+" "+this.getDurationInWeeks());
    }
}
