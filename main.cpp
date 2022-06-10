#include <iostream>
#include "stap.hpp"
#include "reis.hpp"
#include <string>
#include <vector>



int main(){
//maken van alle stappen
std::vector<Stap> stappen = stappenGenereren();

//zet de eerste stap in de reis
Reis reis = Reis(Stap("A","A"));
for (Stap stap : reis.getStappen()){
    std::cout << stap.getBegin() << "\n";
    std::cout << stap.getEind();    
}

/* 
Geen tijd meer over gehad om het algoritme verder uit te werken in het programma.
Hier boven staat een klein testvoorbeeld van de eerste stap die gezet moet worden.
*/


return 0;

};