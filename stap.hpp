#include <string>

class Vlucht
{
private:
    float prijs;
public:
    //constructor
    Vlucht(float prijs);
    //getters
    float getPrijs();
    //setters
    void setPrijs(float prijs);
};

class Rit
{
private:
    int kilometers;
public:
    //constructor
    Rit(int kilometers);
    //getters
    int getKilometers();
    //setters
    void setKilometers(int kilometers);
};

class Treinrit
{
private:
    int minuten;
public:
    //constructor
    Treinrit(int minuten);
    //getters
    int getMinuten();
    //setters
    void setMinuten(int minuten);
};

class Stap
{
private:
    Vlucht vlucht;
    Rit rit;
    Treinrit treinrit;
    std::string soortStap;
public:
    //consructors
    Stap(Vlucht vlucht);
    Stap(Rit rit);
    Stap(Treinrit treinrit);
};