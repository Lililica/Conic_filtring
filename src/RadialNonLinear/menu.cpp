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

            DrawText(actualButton.m_text, actualButton.m_pos.x + 5, actualButton.m_pos.y + 5, actualButton.m_size, actualButton.m_color_col);
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
                if(actualButton.m_type == button_type::RESOLUTION_PART){
                    this->m_state = State::Show_resolution;
                    this->setup_menu();
                }
                
            }


            DrawRectanglePro(Rectangle{actualButton.m_pos.x, actualButton.m_pos.y, actualButton.m_taille.x*1.5f, actualButton.m_taille.y*1.5f},
                            Vector2{0,0},
                            0.,
                            actualButton.m_color_col);

            DrawText(actualButton.m_text, actualButton.m_pos.x + 5, actualButton.m_pos.y + 5, actualButton.m_size*1.5, actualButton.m_color);

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
        this->m_button_list.push_back(button{Vector2{20,50},
                                            Vector2{150,25},
                                            BLACK,
                                            "Give me a solution !",
                                            WHITE,
                                            button_type::RESOLUTION_PART,
                                            15});
    }
    if(this->m_state == State::Show_resolution){
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
                    Rectangle{0,0,float(m_texture[0].width),float(m_texture[0].height)}, 
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
                    Rectangle{0,0,float(m_texture[0].width),float(m_texture[0].height)}, 
                    Rectangle{200,200,float(m_texture[0].width),float(m_texture[0].height)},
                    Vector2{0., 0.},
                    0.,
                    WHITE);  

        
        /*
            PARTIE POUR GERER LES POINTS
        */

       this->draw_lines();
        
    }
    if(this->m_state == State::Show_resolution){
        if(this->ok)
        {
            this->FinalK = this->find_kn();
            ok = false;

            sil::Image imageRef{"src/RadialNonLinear/source/ressource.png"};

            sil::Image resultImage = imageRef;

            float xc = imageRef.width()/2; 
            float yc = imageRef.height()/2; 

            double k1 = this->FinalK(0);
            double k2 = this->FinalK(1);

            // double k1 = 9.82724e-16;
            // double k2 = 1.11423e-10;

            // auto r = [xc, yc](int a, int b) {
            //     return std::pow(a - xc, 2) + std::pow(b - yc, 2);
            // };

            for(float x{0}; x<imageRef.width(); x++)
            {
                for(float y{0}; y<imageRef.height(); y++)
                {
                    float ri = r2(x,y,xc,yc);
                    float xichap = x - delta(x, xc, k1, k2, ri);
                    float yichap = y - delta(y, yc, k1, k2, ri);
                    if(!(xichap>=imageRef.width() || yichap>=imageRef.height() || yichap<0 || xichap<0) ){
                        resultImage.pixel(x,y) = imageRef.pixel(xichap, yichap);
                    }
                    
                }
            }

            resultImage.save("src/RadialNonLinear/source/ressource_modif.png");


            Image imageDeModif = LoadImage("/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/src/RadialNonLinear/source/ressource_modif.png");
            this->m_texture.push_back(LoadTextureFromImage(imageDeModif));

        }


        DrawTexturePro(this->m_texture[0], 
                    Rectangle{0,0,float(m_texture[0].width),float(m_texture[0].height)}, 
                    Rectangle{100,300,float(m_texture[0].width)/1.5f,float(m_texture[0].height)/1.5f},
                    Vector2{0., 0.},
                    0.,
                    WHITE);  


        DrawTexturePro(this->m_texture[1], 
                    Rectangle{0,float(m_texture[0].height),float(m_texture[0].width),-float(m_texture[0].height)}, 
                    Rectangle{600,300,float(m_texture[0].width)/1.5f,float(m_texture[0].height)/1.5f},
                    Vector2{0., 0.},
                    0.,
                    WHITE);  




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
        DrawLineEx(Vector2{d.droiteOrigin.x, d.droiteOrigin.y}, Vector2{float(d.droiteOrigin.x + d.droiteCoef(0)), float(d.droiteOrigin.y - d.droiteCoef(1))}, 2,d.c);
        DrawLineEx(Vector2{d.droiteOrigin.x, d.droiteOrigin.y}, Vector2{float(d.droiteOrigin.x - d.droiteCoef(0)), float(d.droiteOrigin.y + d.droiteCoef(1))}, 2,d.c);
    }


    // std::cout << this->global_residu << std::endl;
    DrawText(TextFormat("Votre Residu est : %04.05f", this->global_residu) , 100, 850, 30, WHITE);

   

}




Eigen::VectorXd app::find_kn()
{

    /*
        Conditions initiales
    */

    double k1 = 0;
    double k2 = 0;

    Eigen::VectorXd originK(2);
    originK(0) = k1;
    originK(1) = k2;

    double dk1 = 10e-10;
    double dk2 = 10e-15;


    // Rectangle{200,200,float(m_texture[0].width),float(m_texture[0].height)}

    float xc = 200 + float(this->m_texture[0].width)/2.;
    float yc = 200 + float(this->m_texture[0].height)/2.;

    Vector2 xyc = Vector2{xc,yc};


    Eigen::VectorXd Jacob(2);
    std::cout << "residu pre-calcul (global_residu) : " << this->global_residu << " et Residu après calcul : " << this->Residu_from_k(k1, k2, xc, yc) << " and " << this->Residu_from_k(dk1, k2, xc, yc) << " and " << this->Residu_from_k(k1, dk2, xc, yc) << std::endl;
    std::cout << "k1 = " << k1 << " k2 = " << k2 << " dk1 = " << dk1 << " dk2 = " << dk2 << std::endl;
    std::cout << "Diff : " << this->Residu_from_k(dk1, k2, xc, yc) - this->global_residu << " and " << this->Residu_from_k(k1, dk2, xc, yc) - this->global_residu << std::endl;

    Jacob(0) = (this->Residu_from_k(dk1, k2, xc, yc) - this->global_residu)/dk1;
    Jacob(1) = (this->Residu_from_k(k1, dk2, xc, yc) - this->global_residu)/dk2;

    std::cout << Jacob << std::endl;

    int it = 100;

    Eigen::VectorXd finalA = system_resolution_non_lineaire(Jacob, it, xyc, originK);

    std::cout << "Final k1 and k2 : " << std::endl;
    std::cout << finalA << std::endl;

    return finalA;

}



double app::Residu_from_k(double k1, double k2, float xc, float yc)
{
    double residuResult = 0.;

    for(droite d : this->m_listOfDroite)
    {
        for(Vector2 &point : d.listOfPoint)
        {
            float ri = r2(point.x,point.y,xc,yc);
            point.x = point.x + delta(point.x, xc, k1, k2, ri);
            point.y = point.y - delta(point.y, yc, k1, k2, ri);
        }
        d.setup_residu_and_distance();
        residuResult += d.residu;
    }
    return residuResult;
}


Eigen::VectorXd app::system_resolution_non_lineaire(Eigen::VectorXd& Jacob, int iteration, Vector2 xyc, Eigen::VectorXd originK)
{
    Eigen::VectorXd originalK = originK;
    double lambda = 10e-3*Jacob.transpose()*Jacob;
    for(int i{0}; i<iteration; ++i)
    {
        int compteur = 0;
        bool accept = false;

        while(!accept)
        {
            Eigen::MatrixXd A = Jacob*Jacob.transpose() + lambda*Eigen::MatrixXd::Identity(2,2);
            Eigen::MatrixXd B = -Jacob*this->Residu_from_k(originalK(0), originalK(1),xyc.x,xyc.y);
            Eigen::VectorXd DeltaA = A.colPivHouseholderQr().solve(B);

            std::cout << "Tentative n°" << compteur << " :" << std::endl;

            double newK1 = originalK(0) + DeltaA(0);
            double newK2 = originalK(1) + DeltaA(1);

            double newResidu = std::abs(this->Residu_from_k(newK1, newK2, xyc.x, xyc.y));
            double ancienResidu = std::abs(this->Residu_from_k(originalK(0), originalK(1),xyc.x,xyc.y));


            std::cout << "Origink1 = " << originalK(0) << " et Origink2 = " << originalK(1) << std::endl;
            std::cout << "Newk1 = " << newK1 << " et Newk2 = " << newK2 << std::endl;
            std::cout << "Mon nouveau residu = " << newResidu << " et ancien = " << ancienResidu << std::endl;

            if(newResidu <  ancienResidu)
            {
                originalK(0) = newK1;
                originalK(1) = newK2;
                lambda /= 10.;
                accept = true; 
            }else{
                lambda *= 10;
            }

            compteur++;
            
            if(compteur>iteration)
            {
                return originalK;
            }
        }
    }

    return originalK;
}



