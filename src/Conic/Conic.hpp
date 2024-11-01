#pragma once
#include <iostream>
#include <Eigen/Dense>
#define GET_VARIABLE_NAME(Variable) (#Variable)


Eigen::VectorXd from_point_to_conic_equation(Eigen::Vector3d & v)
{
    Eigen::VectorXd result(6);
    result << v[0]*v[0], v[0]*v[1], v[1]*v[1], v[0]*v[2], v[1]*v[2], v[2]*v[2];
    return result;
}

bool respect_conic(double x, double y, Eigen::VectorXd & v, double const& epaisseur)
{
    return (v(0)*x*x + v(1)*x*y + v(2)*y*y + v(3)*x + v(4)*y + v(5) < epaisseur) && (v(0)*x*x + v(1)*x*y + v(2)*y*y + v(3)*x + v(4)*y + v(5) > -epaisseur);
}

double generateRandomDouble(double min, double max) {
    return min + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (max - min)));
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

        void set_coef_precise(int const& indice, double & value)
        {
            this->m_coef(indice) = value;
        }

        void set_coef(Eigen::VectorXd v)
        {
            this->m_coef = v;
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
            std::cout << "Les coefs de votre conique sont : " << "\n";
            std::cout << this->m_coef << "\n";
            std::cout << "Voici votre matrice de projection : " << "\n";
            std::cout << this->A << "\n";
        }

        void set_equation_from_matrix()
        {
            Eigen::JacobiSVD<Eigen::MatrixXd> svd (this->A, Eigen::ComputeThinU|Eigen::ComputeFullV);
            this->m_coef = svd.matrixV().rightCols(1);
        }

        void save_image(std::string name, double & epaisseur, float R = 1.0, float G = 1.0, float B = 1.0)
        {
            sil::Image image{1000/*width*/, 1000/*height*/};

            int const centerX{(image.width()-1)/2};
            int const centerY{(image.height()-1)/2};

            double scale = 100;

            for(int x{0}; x<image.width(); x++){
                for(int y{0}; y<image.height(); y++){
                    if(respect_conic((x-centerX)/scale,(y-centerY)/scale,this->m_coef, epaisseur))
                    {
                        image.pixel(x, y) = glm::vec3{R,G,B};
                    } 
                }
            }

        
            image.save(std::string{"src/Conic/output/"+ name + ".png"});
        }

        void conic_setup_random(double & randomScale)
        {

            std::vector<Eigen::Vector3d> randomList{
                Eigen::Vector3d{generateRandomDouble(-randomScale, randomScale),generateRandomDouble(-randomScale, randomScale),generateRandomDouble(-randomScale, randomScale)},
                Eigen::Vector3d{generateRandomDouble(-randomScale, randomScale),generateRandomDouble(-randomScale, randomScale),generateRandomDouble(-randomScale, randomScale)},
                Eigen::Vector3d{generateRandomDouble(-randomScale, randomScale),generateRandomDouble(-randomScale, randomScale),generateRandomDouble(-randomScale, randomScale)},
                Eigen::Vector3d{generateRandomDouble(-randomScale, randomScale),generateRandomDouble(-randomScale, randomScale),generateRandomDouble(-randomScale, randomScale)},
                Eigen::Vector3d{generateRandomDouble(-randomScale, randomScale),generateRandomDouble(-randomScale, randomScale),generateRandomDouble(-randomScale, randomScale)}
            };
            this->set_point(randomList);
            this->create_proj_matrix();
            this->set_equation_from_matrix();
        }

};


