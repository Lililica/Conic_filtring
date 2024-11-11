#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <sil/sil.hpp>
#include <functional>
#include "raylib.h"

#include "utils.hpp"
#include "menu.hpp"



int delta(int& xyi, int& xyc, double& k1, double& k2, int& r)
{
    return (xyi - xyc)*(k1*r + k2*r*r);
}

int r2(int& xi, int& yi, int& xc, int& yc)
{
    return std::pow(xi - xc, 2) + std::pow(yi - yc, 2);
}


int main(){



    sil::Image imageRef{"src/RadialNonLinear/source/ressource.png"};

    sil::Image resultImage = imageRef;

    int xc = imageRef.width()/2; 
    int yc = imageRef.height()/2; 

    double k1 = 10e-10;
    double k2 = 8e-13;

    // auto r = [xc, yc](int a, int b) {
    //     return std::pow(a - xc, 2) + std::pow(b - yc, 2);
    // };

    for(int x{0}; x<imageRef.width(); x++)
    {
        for(int y{0}; y<imageRef.height(); y++)
        {
            int ri = r2(x,y,xc,yc);
            int xichap = x - delta(x, xc, k1, k2, ri);
            int yichap = y - delta(y, yc, k1, k2, ri);
            if(!(xichap>=imageRef.width() || yichap>=imageRef.height() || yichap<0 || xichap<0) ){
                resultImage.pixel(x,y) = imageRef.pixel(xichap, yichap);
            }
            
        }
    }

    resultImage.save("src/RadialNonLinear/source/ressource_modif.png");

  
  
    /*________________________________________________________________
    
        BEGIN TO SETUP THE WINDOW
    
    __________________________________________________________________*/

   
    // Initialisation Window _________________________________________

    InitWindow(1200, 900, "Radial Non Linear Projet Maths");

    // Load Ressources _______________________________________________

    app App;

    Image imageDeBase = LoadImage("/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/src/RadialNonLinear/source/ressource.png");
    App.m_texture.push_back(LoadTextureFromImage(imageDeBase));

    UnloadImage(imageDeBase);

    // Setup Variables _______________________________________________

    

    
    App.setup_menu();


    // Start the program _____________________________________________


    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(GRAY);



        // DrawTexturePro(textDeBase, 
        //             Rectangle{0,float(textDeBase.height),float(textDeBase.width),-float(textDeBase.height)}, 
        //             Rectangle{0,0,float(textDeBase.width),float(textDeBase.height)},
        //             Vector2{0., 0.},
        //             0.,
        //             WHITE);  

        // if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){App.ButtonIsClickedThisFrame = true;}


        App.draw_content();

        App.show_my_menu();
        

        // App.ButtonIsClickedThisFrame = false;






        EndDrawing();
    }

    // Unload ressources _____________________________________________

    for(Texture2D texture : App.m_texture) UnloadTexture(texture);
    

    // Close utilities for the window ________________________________

    CloseWindow();

    return 0;
}