#include "chaleur.hpp"


void chaleur::setup_from_ifstream(std::ifstream& flux)
{
    int compteur = 0;
    for(std::string l; std::getline(flux,l);)
    {
        std::cout << "Setup the line : " << l << "\n";

        if(this->setupSource)
        {
            if(compteur<this->sourceChaleur.size())
            {
                this->sourceChaleur[compteur] = std::stoi(l);
                ++compteur;
                continue;
            }else{
                this->setupSource = false;
                this->MapCaractere = Eigen::MatrixXi(this->hauteur, this->largeur);
                this->CurrentMapDegre = Eigen::MatrixXd(this->hauteur, this->largeur);
                this->InitialMap = sil::Image{this->largeur, this->hauteur};
                

                int indiceSourceChaleur = 0;

                for(int x{0}; x<this->hauteur; ++x)
                {
                    for(int y{0}; y<this->largeur; ++y)
                    {
                        char pixelChar = l[x*this->largeur + y];
                        this->MapCaractere(x,y) = pixelChar-48;
                        switch (this->MapCaractere(x,y))
                        {
                            case 0:
                                this->InitialMap.pixel(y,this->hauteur-1-x) = glm::vec3{1.,1.,1.};
                                break;
                            
                            case 1:
                                this->InitialMap.pixel(y,this->hauteur-1-x) = transforme_Degre_to_color(this->sourceChaleur[indiceSourceChaleur]);
                                this->CurrentMapDegre(x,y) = double(this->sourceChaleur[indiceSourceChaleur]);
                                indiceSourceChaleur++;
                                break;

                            case 2:
                                this->InitialMap.pixel(y,this->hauteur-1-x) = glm::vec3{0.,1.,0.};
                                this->CurrentMapDegre(x,y) = 0;
                                break;
                            
                            default:
                                break;
                        }
                    }
                }
                std::cout << this->MapCaractere << std::endl;
                std::cout << this->CurrentMapDegre << std::endl;
                this->InitialMap.save(std::string{"src/Chaleur/output/InitMap.png"});
            }
        }


        std::string firstWord = l.substr(0, l.find(" "));
        if(firstWord == "largeur")
            this->largeur = std::stoi(l.substr(firstWord.size(), l.size()));
        else if(firstWord == "hauteur")
            this->hauteur = std::stoi(l.substr(firstWord.size(), l.size()));
        else if(firstWord == "h")
            this->h = std::stod(l.substr(firstWord.size(), l.size()));
        else if(firstWord == "k")
            this->k = std::stod(l.substr(firstWord.size(), l.size()));
        else if(firstWord == "conductivite")
            this->conductivite = std::stod(l.substr(firstWord.size(), l.size()));
        else if(firstWord == "densite")
            this->densite = std::stod(l.substr(firstWord.size(), l.size()));
        else if(firstWord == "capacite")
            this->capacite = std::stod(l.substr(firstWord.size(), l.size()));
        else if(firstWord == "source"){
            this->sourceChaleur = std::vector<int>(std::stoi(l.substr(firstWord.size(), l.size())));
            this->setupSource = true;
        }
    }
}


glm::vec3 transforme_Degre_to_color(double degre)
{
    // Le degré doit être compris entre -20° et 60°
    if(degre<1. && degre>-1.)
        return glm::vec3{1.,1.,1.};
    return glm::vec3{(degre + 20)/80., 0., 1-((degre + 20)/80.)};
}


void chaleur::methode_explicite(int nbr_images)
{
    this->currentImage = this->InitialMap;
    for(int i{0}; i<nbr_images; ++i)
    {
        // std::cout << "Temps n°" << i << " :" << "\n";
        this->currentImage = this->InitialMap;
        for(int x{1}; x<this->hauteur-1; ++x)
        {
            for(int y{1}; y<this->largeur-1; ++y)
            {
                double teta_ij = this->CurrentMapDegre(x,y);
                double teta_im1j = this->CurrentMapDegre(x-1,y);
                double teta_ip1j = this->CurrentMapDegre(x+1,y);
                double teta_ijm1 = this->CurrentMapDegre(x,y-1);
                double teta_ijp1 = this->CurrentMapDegre(x,y+1);
                double alpha = (this->k*this->conductivite)/(this->densite*this->capacite*this->h*this->h);
                double beta = 0.;
                this->CurrentMapDegre(x,y) = teta_ij + alpha*(teta_ijm1 + teta_ijp1 + teta_im1j + teta_ip1j - 4*teta_ij) + beta;
                this->currentImage.pixel(y,this->hauteur-1-x) = transforme_Degre_to_color(this->CurrentMapDegre(x,y));
            }
        }
        if(i%100==0)
            this->currentImage.save(std::string{"src/Chaleur/test/frame"+ std::to_string(i) + ".png"});

    }
}