#pragma once
#include <iostream>
#include <Eigen/Dense>


Eigen::VectorXd from_point_to_conic_equation(Eigen::Vector3d & v)
{
    Eigen::VectorXd result(6);
    result << v[0]*v[0], v[0]*v[1], v[1]*v[1], v[0]*v[2], v[1]*v[2], v[2]*v[2];
    return result;
}

class Conic
{
    private:
        Eigen::VectorXd m_coef;
        std::vector<Eigen::Vector3d> m_pointList;
        Eigen::MatrixXd A;
    public:
        Conic(){ 
            this->m_coef = Eigen::VectorXd(6);
            this->m_pointList = std::vector<Eigen::Vector3d>(6);
            this->A = Eigen::MatrixXd(5,6);}
        Conic(double& a, double& b, double& c, double& d, double& e, double& f)
        {
            this->m_coef << a,b,c,d,e,f;
        }
        ~Conic()
        {
        }

        double get_norm() const
        {
            return std::pow(m_coef(0)*m_coef(0) + m_coef(1)*m_coef(1) + m_coef(2)*m_coef(2) + m_coef(3)*m_coef(3) + m_coef(4)*m_coef(4) + m_coef(5)*m_coef(5),0.5);
        }

        Eigen::VectorXd get_coef(){ return this->m_coef;}
        std::vector<Eigen::Vector3d> get_point(){ return this->m_pointList;}
        Eigen::MatrixXd get_proj_matrix() {return this->A;}

        void set_point(std::vector<Eigen::Vector3d> & v)
        {
            this->m_pointList = v;
        }

        void set_coef(int const& indice, double & value)
        {
            this->m_coef(indice) = value;
        }

        void create_proj_matrix()
        {
            for(int i{0}; i<this->m_pointList.size(); ++i)
            {
                for(int k{0}; k<this->m_pointList.size()+1; ++k)
                {
                    this->A(i,k) = from_point_to_conic_equation(this->m_pointList[i])[k];
                }
            }
        }

        void display_conic() const{
            
        }

};


