#include <iostream>
#include <Eigen/Dense>
#include <sil/sil.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

double generateRandomDouble(double min, double max) {
    return min + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (max - min)));
}

Eigen::VectorXd from_point_to_conic_equation(Eigen::Vector3d & v)
{
    Eigen::VectorXd result(6);
    result(0) = v[0]*v[0];
    result(1) = v[0]*v[1];
    result(2) = v[1]*v[1];
    result(3) = v[0]*v[2];
    result(4) = v[1]*v[2];
    result(5) = v[2]*v[2];
    return result;
}


bool respect_conic(double x, double y, Eigen::VectorXd & v)
{
    return (v(0)*x*x + v(1)*x*y + v(2)*y*y + v(3)*x + v(4)*y + v(5) < 1) && (v(0)*x*x + v(1)*x*y + v(2)*y*y + v(3)*x + v(4)*y + v(5) > -1);
}

int main(int, char**){

    std::srand(static_cast<unsigned int>(std::time(0)));

    double randomValueSet = 100000.;

    std::vector<Eigen::Vector3d> pointList{
        Eigen::Vector3d{generateRandomDouble(-randomValueSet, randomValueSet),generateRandomDouble(-randomValueSet, randomValueSet),generateRandomDouble(-randomValueSet, randomValueSet)},
        Eigen::Vector3d{generateRandomDouble(-randomValueSet, randomValueSet),generateRandomDouble(-randomValueSet, randomValueSet),generateRandomDouble(-randomValueSet, randomValueSet)},
        Eigen::Vector3d{generateRandomDouble(-randomValueSet, randomValueSet),generateRandomDouble(-randomValueSet, randomValueSet),generateRandomDouble(-randomValueSet, randomValueSet)},
        Eigen::Vector3d{generateRandomDouble(-randomValueSet, randomValueSet),generateRandomDouble(-randomValueSet, randomValueSet),generateRandomDouble(-randomValueSet, randomValueSet)},
        Eigen::Vector3d{generateRandomDouble(-randomValueSet, randomValueSet),generateRandomDouble(-randomValueSet, randomValueSet),generateRandomDouble(-randomValueSet, randomValueSet)}
    };

    Eigen::MatrixXd A(6,6);
    for(int i{0}; i<pointList.size(); ++i)
    {
        for(int k{0}; k<pointList.size()+1; ++k)
        {
            A(i,k) = from_point_to_conic_equation(pointList[i])[k];
        }
    }
    std::cout << A << "\n";

    // A.push_back(Eigen::VectorXd(6));
    Eigen::JacobiSVD<Eigen::MatrixXd> svd (A, Eigen::ComputeThinU|Eigen::ComputeFullV);
    Eigen::VectorXd sol = svd.matrixV().rightCols(1);

    // Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU|Eigen::ComputeFullV);
    // Eigen::VectorXd sol(5);
    // sol << 1,10,1,100,1;
    // // std::cout << vecNull << "\n";
    // Eigen::VectorXd sol = A.colPivHouseholderQr().solve(vecNull);
    std::cout <<  sol << "\n";

    sil::Image image{500/*width*/, 500/*height*/};

    int const centerX{(image.width()-1)/2};
    int const centerY{(image.height()-1)/2};

    double scale = 10;

    for(int x{0}; x<image.width(); x++){
        for(int y{0}; y<image.height(); y++){
            if(respect_conic((x-centerX)/scale,(y-centerY)/scale,sol))
            {
                // std::cout << "x : " << x << " y : " << y << "\n";
                image.pixel(x, y) = glm::vec3{1.f};
            } 
        }
    }

    image.save("output/Random10.png");



}
