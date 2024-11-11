#include "utils.hpp"

void draw_point(std::vector<Vector2> & v, Color c)
{
    for(Vector2 p : v)
    {
        DrawCircle(p.x, p.y, 3., c);
    }
}


void droite::setup_coef_droite_from_points()
{
    Eigen::MatrixXd M(listOfPoint.size(), 3);

    for(int i{0}; i<this->listOfPoint.size(); ++i)
    {
        M(i,0) = this->listOfPoint[i].x;
        M(i,1) = this->listOfPoint[i].y;
        M(i,2) = 1;

        droiteOrigin.x += this->listOfPoint[i].x;
        droiteOrigin.y += this->listOfPoint[i].y;
    }

    std::cout << M << std::endl;

    Eigen::JacobiSVD<Eigen::MatrixXd> svd (M, Eigen::ComputeThinU|Eigen::ComputeFullV);
    this->droiteCoef = svd.matrixV().rightCols(1) * 5e5;

    droiteOrigin.x = droiteOrigin.x/this->listOfPoint.size();
    droiteOrigin.y = droiteOrigin.y/this->listOfPoint.size();

    std::cout << droiteCoef << std::endl;

    std::cout << droiteOrigin.x << " and " << droiteOrigin.y << std::endl;
}

void droite::setup_residu_and_distance()
{
    distanceFromDroite = std::vector<double>(this->listOfPoint.size());

    for(int i{0}; i<this->listOfPoint.size(), ++i)
    {
        
    }
}