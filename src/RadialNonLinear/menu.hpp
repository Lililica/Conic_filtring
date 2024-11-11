#pragma once

#include <iostream>
#include <vector>
#include "raylib.h"
#include "utils.hpp"
#include <Eigen/Dense>


enum State {Accueil, Select_Droite, Show_droite};



class app
{

    private :
    /*
        Variables :
    */

        State m_state = State::Accueil;

        std::vector<button> m_button_list;

        std::vector<droite> m_listOfDroite;


        bool HaveToCreateALine = true;
        bool HaveToShowEveryLine = false;
        int indiceLineSelection{-1};
        std::vector<Color> vec_color {RED, BLUE, GREEN, BROWN, MAGENTA};
        
        bool FirstTimeToDrawLine = true;


    /*
        Functions :
    */ 

        void manage_line_selection();
        void draw_lines();

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

