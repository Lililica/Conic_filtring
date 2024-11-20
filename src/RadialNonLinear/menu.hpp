#pragma once

#include <iostream>
#include <vector>
#include "raylib.h"
#include "utils.hpp"
#include <Eigen/Dense>
#include <sil/sil.hpp>



enum State {Accueil, Select_Droite, Show_droite, Show_resolution};



class app
{

    private :
    /*
        Variables :
    */

        State m_state = State::Accueil;

        std::vector<button> m_button_list;

        std::vector<droite> m_listOfDroite;
        Eigen::VectorXd FinalK;


        bool HaveToCreateALine = true;
        bool HaveToShowEveryLine = false;
        int indiceLineSelection{-1};
        std::vector<Color> vec_color {RED, BLUE, GREEN, BROWN, MAGENTA};
        
        bool FirstTimeToDrawLine = true;
        bool ok = true;


    /*
        Functions :
    */ 

        void manage_line_selection();
        void draw_lines();
        Eigen::VectorXd find_kn();
        double Residu_from_k(double k1, double k2, float xc, float yx);
        Eigen::VectorXd system_resolution_non_lineaire(Eigen::VectorXd& Jacob, int iteration, Vector2 xyc, Eigen::VectorXd originK);
        // Eigen::VectorXd find_delta_A_from_equation(Eigen::VectorXd& Jacob, double& lamda, Vector2 xyc);


    public :
    /*
        Variables :
    */

        std::vector<Texture2D> m_texture;
        bool ButtonIsClickedThisFrame = false;
        double global_residu;



    /*
        Functions :
    */ 

        void show_my_menu();

        void setup_menu();

        void draw_content();


};

