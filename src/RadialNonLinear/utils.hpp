#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include "raylib.h"

#include <Eigen/Dense>


enum button_type {GO_TO_MENU, GO_TO_SELECTION, NEW_LINE_CALLED, SHOW_EVERY_LINE, FINISH_DRAW_LINE, RESOLUTION_PART};

void draw_point(std::vector<Vector2> & v, Color c);

struct button
{
    Vector2 m_pos {0,0};
    Vector2 m_taille {0,0};
    Color m_color {BLACK};
    const char* m_text {};
    Color m_color_col {WHITE};
    button_type m_type;
    int m_size{20};
};


struct droite
{
    std::vector<Vector2> listOfPoint;
    Color c;

    Vector2 droiteOrigin{0,0};
    Eigen::VectorXd droiteCoef;


    std::vector<double> distanceFromDroite;
    double residu;


    void setup_coef_droite_from_points();
    int norm();
    void setup_residu_and_distance();

};

float delta(float& xyi, float& xyc, double& k1, double& k2, float& r);

float r2(float& xi, float& yi, float& xc, float& yc);



