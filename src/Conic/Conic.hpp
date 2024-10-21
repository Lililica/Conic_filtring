#pragma once
#include <iostream>
#include <Eigen/Dense>


class Conic
{
private:
    Eigen::VectorXd m_coef(6);
public:
    Conic(double& a, double& b, double& c, double& d, double& e, double& f)
    {
        this->m_coef << a,b,c,d,e,f;
    }
    ~Conic()
    {
    }

    double get_norm() const
    {
        return std::pow(m_coef(0)*m_coef(0) + m_coef(1)*m_coef(1) + m_coef(2)*m_coef(2) + m_coef(3)*m_coef(3) + m_coef(4)*m_coef(4) + m_coef(5)*m_coef(5),0.5)
    }
};


