#include <iostream>
#include <Eigen/Dense>

int main(int, char**){

    Eigen::MatrixXd A;
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU|Eigen::ComputeFullV);
    Eigen::VectorXd x = svd.matrixV().rightCols(1);
}
