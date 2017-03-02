package com.company.Interfaces;


import com.company.University.Discipline;

import java.util.ArrayList;

public interface CanAddDiciplines {
    ArrayList<Discipline> disciplines = new ArrayList<>();

    public void addDiscipline(Discipline discipline);


}
