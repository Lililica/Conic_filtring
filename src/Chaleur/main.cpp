#include <iostream>
#include <fstream>
#include <string>
#include "chaleur.hpp"


int main()
{

    std::ifstream monFlux("../src/Chaleur/Information.src");  

    if(monFlux) 
    {
        std::cout << "Fichier lu !" << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    
    
    chaleur FirstScene;
    FirstScene.setup_from_ifstream(monFlux);

    FirstScene.methode_explicite(10000);





    return 0;
}