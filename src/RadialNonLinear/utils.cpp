#include "utils.hpp"

void draw_point(std::vector<Vector2> & v, Color c)
{
    for(Vector2 p : v)
    {
        DrawCircle(p.x, p.y, 3., c);
    }
}

float delta(float& xyi, float& xyc, double& k1, double& k2, float& r)
{
    return (xyi - xyc)*(k1*r + k2*r*r);
}

float r2(float& xi, float& yi, float& xc, float& yc)
{
    return std::pow(xi - xc, 2) + std::pow(yi - yc, 2);
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


    Eigen::JacobiSVD<Eigen::MatrixXd> svd (M, Eigen::ComputeThinU|Eigen::ComputeFullV);
    this->droiteCoef = svd.matrixV().rightCols(1);

    {
        double temp = this->droiteCoef(0);
        this->droiteCoef(0) = this->droiteCoef(1);
        this->droiteCoef(1) = temp;
    }

    droiteOrigin.x = droiteOrigin.x/this->listOfPoint.size();
    droiteOrigin.y = droiteOrigin.y/this->listOfPoint.size();


}

void droite::setup_residu_and_distance()
{
    distanceFromDroite = std::vector<double>(this->listOfPoint.size());
    this->residu = 0.;

    for(int i{0}; i<this->listOfPoint.size(); ++i)
    {
        distanceFromDroite[i] = std::abs(Eigen::Vector3d{listOfPoint[i].x,listOfPoint[i].y,1.}.transpose()*droiteCoef)/std::pow(droiteCoef(0)*droiteCoef(0) + droiteCoef(1)*droiteCoef(1), 0.5);
        this->residu += distanceFromDroite[i];
    }

    

    this->residu = this->residu/this->listOfPoint.size();
}


