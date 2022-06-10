#include <string>
#pragma once
#include <vector>

class Vlucht
{
private:
    int prijs;
public:
    //constructor
    Vlucht(int prijs);
    Vlucht();
    //getters
    int getPrijs();
};

class Rit
{
private:
    int kilometers;
public:
    //constructor
    Rit(int kilometers);
    Rit();
    //getters
    int getKilometers();
};

class Treinrit
{
private:
    int minuten;
public:
    //constructor
    Treinrit(int minuten);
    Treinrit();
    //getters
    int getMinuten();
};

class Stap
{
private:
    Vlucht vlucht;
    Rit rit;
    Treinrit treinrit;
    std::string soortStap;
    std::string begin;
    std::string eind;
    int getal;
public:
    //consructors
    Stap(Vlucht vlucht,std::string begin, std::string eind);
    Stap(Rit rit,std::string begin, std::string eind);
    Stap(Treinrit treinrit,std::string begin, std::string eind);
    Stap(std::string begin, std::string eind);
    //getters
    std::string getBegin();
    std::string getEind();
    int getSoortStap();
    int getGetal();

};

std::vector<Stap> stappenGenereren();