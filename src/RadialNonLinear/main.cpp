#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <sil/sil.hpp>
#include <functional>




int delta(int& xyi, int& xyc, int& k1, int& k2, int& r)
{
    return (xyi - xyc)*(k1*r*r + k2*r*r*r*r);
}

int r(int& xi, int& yi, int& xc, int& yc)
{
    return std::pow(xi - xc, 2) + std::pow(yi - yc, 2);
}


int main(){



    sil::Image imageRef{"src/RadialNonLinear/source/ressource.png"};

    sil::Image resultImage = imageRef;

    int xc = imageRef.width()/2; 
    int yc = imageRef.height()/2; 

    int k1 = 10e-10;
    int k2 = 10e-12;

    // auto r = [xc, yc](int a, int b) {
    //     return std::pow(a - xc, 2) + std::pow(b - yc, 2);
    // };

    for(int x{0}; x<imageRef.width(); x++)
    {
        for(int y{0}; y<imageRef.height(); y++)
        {
            int ri = r(x,y,xc,yc);
            int xichap = x + delta(x, xc, k1, k2, ri);
            int yichap = y + delta(y, yc, k1, k2, ri);
            if(!(xichap>=imageRef.width() || yichap>=imageRef.height() || yichap<0 || xichap<0) ){
                resultImage.pixel(x,y) = imageRef.pixel(xichap, yichap);
                std::cout << "coucou" << std::endl;
            }
            
        }
    }

    resultImage.save("src/RadialNonLinear/source/ressource_modif.png");

    return 0;
}