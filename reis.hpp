#include "stap.hpp"
#include <vector>
#include <string>
#pragma once

class IComparable
{
public:
    virtual Stap compareTo() = 0;
};

class Route
{
private:
    std::vector<Stap> stappen;
    std::string begin;
    std::string eind;
    int kosten;
public:
    //constructor
    Route(Stap stap,int kosten);

    //setters
    void updateRoute(Stap stap,int kosten);

    //getters
    int getKosten();
    std::string getEind();
};


class Reis : public IComparable
{
private:
    std::vector<Route> routes;
    std::vector<Stap> stappen;
    std::string einde;
public:
    //constructor
    Reis(Stap stap);
    

    //getters
    std::vector<Route> getRoutes();
    std::vector<Stap> getStappen();
    std::string getEinde();

    //setters
    void updateRoutes(Route route);
    void updateStappen(Stap stap);

    //function
    int berekenKosten(Stap stap);

    //override interface functie
    Stap compareTo() override;
}; 

