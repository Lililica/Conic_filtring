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

  
  
    /*
    
        BEGIN TO SETUP THE WINDOW
    
    */

   

    InitWindow(800, 600, "Radial Non Linear Projet Maths");

    Image imageDeBase = LoadImage("/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/src/RadialNonLinear/source/ressource.png");
    Texture2D textDeBase = LoadTextureFromImage(imageDeBase);

    UnloadImage(imageDeBase);

    std::vector<Vector2> listOfPoint;

    // Boucle principale
    while (!WindowShouldClose()) {
        // Démarrer le dessin
        BeginDrawing();
        ClearBackground(RAYWHITE);



        DrawTexturePro(textDeBase, 
                    Rectangle{0,float(textDeBase.height),float(textDeBase.width),-float(textDeBase.height)}, 
                    Rectangle{0,0,float(textDeBase.width),float(textDeBase.height)},
                    Vector2{0., 0.},
                    0.,
                    WHITE);  

        draw_point(listOfPoint);

        DrawText("Menu :", 20,20, 30, BLUE);

        // Fin du dessin
        EndDrawing();
    }

    UnloadTexture(textDeBase);


    // Détruire la fenêtre
    CloseWindow();

    return 0;
}