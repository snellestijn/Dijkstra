#include "reis.hpp"
#include "stap.hpp"
#include <string>

Route::Route(Stap stap,int kosten){
    this->stappen.push_back(stap);
    this->kosten = kosten;
    begin = "A";
    eind = stap.getEind();
}
void Route::updateRoute(Stap stap, int kosten){
    this->stappen.push_back(stap);
    this->kosten += kosten;
    this->eind = stap.getEind();
}
int Route::getKosten(){return this->kosten;}
std::string Route::getEind(){return this->eind;}

Reis::Reis(Stap stap){
    updateStappen({stap});
    this->einde = "H";
    this->routes.push_back(Route(stap,stap.getGetal()));
}
std::vector<Route> Reis::getRoutes(){return this->routes;}
std::vector<Stap> Reis::getStappen(){return this->stappen;}
std::string Reis::getEinde(){return this->einde;}
void Reis::updateRoutes(Route route,Stap stap){
    for (Route rout : this->routes){
        if (rout.getEind() == stap.getBegin()){
            this->routes.push_back(rout);
        }
    }
}
void Reis::verwijderStap(Stap stap){
    for (int i = 0; i < this->stappen.size();i++){
        if (stappen[i].getEind() == stap.getEind()){
            stappen.erase(stappen.begin()+i);
        }
    }
}
void Reis::updateStappen(std::vector<Stap> stappen){
    for (Stap stap : stappen){
        this->stappen.push_back(stap);
    }
}

int Reis::berekenKosten(Stap stap){
    int soort = stap.getSoortStap();
    int kosten;
    switch (soort)
    {
    case 1:
        kosten = stap.getGetal();       //de prijs zelf
        break;
    case 2:
        kosten = (16*stap.getGetal())/60;   //16 euro per uur
        break;
    case 3:
        kosten = 0.12*stap.getGetal();  //12 euro per 100 kilometer
        break;
    default:
        kosten = 0;
        break;
    }
    return kosten;
}

Stap Reis::compareTo(){
    Stap goedkoopste = this->stappen[0];
    int laagsteprijs;
    for (Stap stapje:this->stappen){
        int prijs = 0;
        for (Route rout : this->routes){
            if (rout.getEind() == stapje.getBegin()){
                prijs += rout.getKosten();
            }
        }
        prijs += this->berekenKosten(stapje);
        if (prijs < laagsteprijs){
            laagsteprijs = prijs;
            goedkoopste = stapje;
        }    
    }
    return goedkoopste;
}