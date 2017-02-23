package com.company.Persons;

public abstract class Person {
    String name;
    String personalId;

    protected Person(String name, String personalId) {
        this.name = name;
        this.personalId=personalId;
    }

    public String getName() {
        return name;
    }

    public String getPersonalId() {
        return personalId;
    }
}
