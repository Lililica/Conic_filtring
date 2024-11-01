#include <iostream>
#include <Eigen/Dense>
#include <sil/sil.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Conic.hpp"
#include <cmath>
#include <filesystem>
#include <opencv2/opencv.hpp>

// magick convert -delay 10 -loop 0 *.png animation.gif

bool respect(double x, double y, Eigen::VectorXd & v, double const& epaisseur)
{
    return (v(0)*x*x + v(1)*x*y + v(2)*y*y + v(3)*x + v(4)*y + v(5) < epaisseur) && (v(0)*x*x + v(1)*x*y + v(2)*y*y + v(3)*x + v(4)*y + v(5) > -epaisseur);
}


int main(int, char**){

    std::srand(static_cast<unsigned int>(std::time(0)));

    double randomValueSet = 1000000.;


    Conic conic_test;

    conic_test.conic_setup_random(randomValueSet);
    conic_test.display_conic();

    double epaisseur {0.005};

    // conic_test.save_image("test4",epaisseur);


    Conic C;
    Conic C1;
    Conic C2;

    C1.conic_setup_random(randomValueSet);
    C2.conic_setup_random(randomValueSet);

    double t = 0;


    sil::Image image{1500/*width*/, 1500/*height*/};
    int const centerX{(image.width()-1)/2};
    int const centerY{(image.height()-1)/2};

    double scale = 100;

    for(int i{0}; i<30; ++i){
        t += 0.2;

        Eigen::VectorXd C_coef = std::cos(t)*C1.get_coef()/C1.get_norm() + std::sin(t)*C2.get_coef()/C2.get_norm();

        float r = (std::sin(t + 0) + 1) / 2; // Normaliser entre 0 et 1
        float g = (std::sin(t + 2 * M_PI / 3) + 1) / 2; // Décalage pour le vert
        float b = (std::sin(t + 4 * M_PI / 3) + 1) / 2;

        C.set_coef(C_coef);
        C.save_image(std::string{"image"}+std::to_string(i), epaisseur, r, g, b);

        
        for(int x{0}; x<image.width(); x++){
            for(int y{0}; y<image.height(); y++){
                if(respect((x-centerX)/scale, (y-centerY)/scale, C_coef, epaisseur))
                {
                    image.pixel(x, y) = glm::vec3{r,g,b};
                } 
            }
        }
    }

        
    image.save(std::string{"src/Conic/pngTest/test4.png"});

    



}
