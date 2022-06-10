#include "stap.hpp"
#include <string>
#include "reis.hpp"


Vlucht::Vlucht(int prijs){
    this->prijs = prijs;
}
Vlucht::Vlucht(){
    return;
}
int Vlucht::getPrijs(){
    return this->prijs;
}

Rit::Rit(int kilometers){
    this->kilometers = kilometers;
}
Rit::Rit(){
    return;
}
int Rit::getKilometers(){return this->kilometers;}

Treinrit::Treinrit(int minuten){
    this->minuten = minuten;
}
Treinrit::Treinrit(){
    return;
}
int Treinrit::getMinuten(){return this->minuten;}

Stap::Stap(Vlucht vlucht, std::string begin,std::string eind){
    this->vlucht = vlucht;
    this->soortStap = "vlucht";
    this->begin = begin;
    this->eind = eind;
    this->getal = vlucht.getPrijs();
}
Stap::Stap(Rit rit, std::string begin,std::string eind){
    this->rit = rit;
    this->soortStap = "rit";
    this->begin = begin;
    this->eind = eind;
    this->getal = rit.getKilometers();
}
Stap::Stap(Treinrit treinrit, std::string begin,std::string eind){
    this->treinrit = treinrit;
    this->soortStap = "treinrit";
    this->begin = begin;
    this->eind = eind;
    this->getal = treinrit.getMinuten();
}
Stap::Stap(std::string begin,std::string eind){
    this->begin = begin;
    this->eind = eind;
    this->getal = 0;
}
std::string Stap::getBegin(){return this->begin;}
std::string Stap::getEind(){return this->eind;}
int Stap::getSoortStap(){
    if (soortStap == "vlucht"){return 1;}
    if (soortStap == "rit"){return 2;}
    if (soortStap == "treinrit"){return 3;}
    else {return 0;}
}
int Stap::getGetal(){return this->getal;}

