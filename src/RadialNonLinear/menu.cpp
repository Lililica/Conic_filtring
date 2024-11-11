#include "menu.hpp"





void app::show_my_menu(){

    for(button actualButton : this->m_button_list)
    {
        if(!CheckCollisionPointRec(GetMousePosition(), Rectangle{actualButton.m_pos.x, actualButton.m_pos.y, actualButton.m_taille.x, actualButton.m_taille.y}))
        {
            DrawRectanglePro(Rectangle{actualButton.m_pos.x, actualButton.m_pos.y, actualButton.m_taille.x, actualButton.m_taille.y},
                            Vector2{0,0},
                            0.,
                            actualButton.m_color);

            DrawText(actualButton.m_text, actualButton.m_pos.x + 5, actualButton.m_pos.y + 5, actualButton.m_size, WHITE);
        }else{
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if(actualButton.m_type == button_type::GO_TO_SELECTION){
                    this->m_state = State::Select_Droite;
                    this->setup_menu();
                }
                if(actualButton.m_type == button_type::GO_TO_MENU){
                    this->m_state = State::Accueil;
                    this->setup_menu();
                }
                if(actualButton.m_type == button_type::NEW_LINE_CALLED){
                    HaveToCreateALine = true;
                }
                if(actualButton.m_type == button_type::SHOW_EVERY_LINE){
                    HaveToShowEveryLine = !HaveToShowEveryLine;
                }
                if(actualButton.m_type == button_type::FINISH_DRAW_LINE){
                    this->m_state = State::Show_droite;
                    this->FirstTimeToDrawLine = true;
                    this->setup_menu();
                }
                
            }


            DrawRectanglePro(Rectangle{actualButton.m_pos.x, actualButton.m_pos.y, actualButton.m_taille.x*1.5f, actualButton.m_taille.y*1.5f},
                            Vector2{0,0},
                            0.,
                            actualButton.m_color_col);

            DrawText(actualButton.m_text, actualButton.m_pos.x + 5, actualButton.m_pos.y + 5, actualButton.m_size*1.5, BLACK);

        }
    }




}


void app::setup_menu(){
    if(this->m_state == State::Accueil)
    {
        this->m_button_list = std::vector<button>{};
        this->m_button_list.push_back(button{Vector2{30,30},
                                            Vector2{250,30},
                                            BLACK,
                                            "SELECT YOUR POINTS",
                                            WHITE,
                                            button_type::GO_TO_SELECTION});
    }
    if(this->m_state == State::Select_Droite)
    {
        this->m_button_list = std::vector<button>{};
        this->m_button_list.push_back(button{Vector2{20,20},
                                            Vector2{110,17},
                                            BLACK,
                                            "GO BACK TO MENU",
                                            WHITE,
                                            button_type::GO_TO_MENU,
                                            10});

        this->m_button_list.push_back(button{Vector2{20,50},
                                            Vector2{60,17},
                                            BLACK,
                                            "New line",
                                            WHITE,
                                            button_type::NEW_LINE_CALLED,
                                            10});
        this->m_button_list.push_back(button{Vector2{20,80},
                                            Vector2{115,17},
                                            BLACK,
                                            "Show Every Lines",
                                            WHITE,
                                            button_type::SHOW_EVERY_LINE,
                                            10});
        this->m_button_list.push_back(button{Vector2{20,140},
                                            Vector2{130,17},
                                            BLACK,
                                            "Finish to draw lines",
                                            WHITE,
                                            button_type::FINISH_DRAW_LINE,
                                            10});
    }
    if(this->m_state == State::Show_droite){
        this->m_button_list = std::vector<button>{};
        this->m_button_list.push_back(button{Vector2{20,20},
                                            Vector2{110,17},
                                            BLACK,
                                            "GO BACK TO MENU",
                                            WHITE,
                                            button_type::GO_TO_MENU,
                                            10});

    }
}


void app::draw_content()
{
    if(this->m_state == State::Select_Droite)
    {

        /*
            PARTIE POUR AFFICHER LA BONNE IMAGE (pour l'instant une image prédéfini...)
        */

        DrawTexturePro(this->m_texture[0], 
                    Rectangle{0,float(m_texture[0].height),float(m_texture[0].width),-float(m_texture[0].height)}, 
                    Rectangle{200,200,float(m_texture[0].width),float(m_texture[0].height)},
                    Vector2{0., 0.},
                    0.,
                    WHITE);  

        
        /*
            PARTIE POUR GERER LES POINTS
        */


        this->manage_line_selection();




    }
    if(this->m_state == State::Show_droite)
    {
        /*
            PARTIE POUR AFFICHER LA BONNE IMAGE (pour l'instant une image prédéfini...)
        */

        DrawTexturePro(this->m_texture[0], 
                    Rectangle{0,float(m_texture[0].height),float(m_texture[0].width),-float(m_texture[0].height)}, 
                    Rectangle{200,200,float(m_texture[0].width),float(m_texture[0].height)},
                    Vector2{0., 0.},
                    0.,
                    WHITE);  

        
        /*
            PARTIE POUR GERER LES POINTS
        */

       this->draw_lines();
        
    }
}

void app::manage_line_selection(){


    if(HaveToShowEveryLine){
        for(int i{0}; i<m_listOfDroite.size(); ++i)
        {
            draw_point(m_listOfDroite[i].listOfPoint, m_listOfDroite[i].c);
        }
    }else{
        if(HaveToCreateALine){
            this->m_listOfDroite.push_back(droite{});
            HaveToCreateALine = false;
            indiceLineSelection = this->m_listOfDroite.size()-1;
            m_listOfDroite[indiceLineSelection].c = this->vec_color[indiceLineSelection%5];
        }


        if(CheckCollisionPointRec(GetMousePosition(),Rectangle{200,200,float(m_texture[0].width),float(m_texture[0].height)}))
        {
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                this->m_listOfDroite[indiceLineSelection].listOfPoint.push_back(GetMousePosition());
            }
        }
        draw_point(m_listOfDroite[indiceLineSelection].listOfPoint, m_listOfDroite[indiceLineSelection].c);
        

    }


}

void app::draw_lines(){

    if(this->FirstTimeToDrawLine){
        this->global_residu = 0.;
        for(droite & d : this->m_listOfDroite)
        {
            d.setup_coef_droite_from_points();
            d.setup_residu_and_distance();    
            this->global_residu += d.residu;        
        }
        FirstTimeToDrawLine = false;
    
    }



    for(droite d : this->m_listOfDroite){
        DrawLineEx(Vector2{d.droiteOrigin.x, d.droiteOrigin.y}, Vector2{float(d.droiteOrigin.x + d.droiteCoef(1)), float(d.droiteOrigin.y - d.droiteCoef(0))}, 3,d.c);
        DrawLineEx(Vector2{d.droiteOrigin.x, d.droiteOrigin.y}, Vector2{float(d.droiteOrigin.x - d.droiteCoef(1)), float(d.droiteOrigin.y + d.droiteCoef(0))}, 3,d.c);
    }

    

   

}