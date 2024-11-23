#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sil/sil.hpp>
#include <Eigen/Dense>


class chaleur
{
    public :

    /*
        VARIABLES :
    */

        int largeur;
        int hauteur;

        sil::Image InitialMap{0,0};

        /*
            FONCTIONS :
        */

        void setup_from_ifstream(std::ifstream& flux);
        void setup_image_from_map();


        void methode_explicite(int nbr_images);

    private :
    
    /*
        VARIABLES :
    */

        double h;
        double k;
        double conductivite;
        double densite;
        double capacite;
        std::vector<int> sourceChaleur;
        bool setupSource = false;
        bool setupMap = false;
        Eigen::MatrixXi MapCaractere;

        sil::Image currentImage{0,0};
        Eigen::MatrixXd CurrentMapDegre;

    /*
        FONCTIONS :
    */

};

glm::vec3 transforme_Degre_to_color(double degre=0.);


