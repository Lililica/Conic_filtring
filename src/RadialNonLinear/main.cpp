#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <sil/sil.hpp>
#include <functional>
#include "raylib.h"

#include "utils.hpp"
#include "menu.hpp"





int main(){



  
  
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