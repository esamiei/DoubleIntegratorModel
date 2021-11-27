#pragma once

#include "DoubleIntegrator.hpp"



class LQRControl: public DoubleInt{
public:
    LQRControl(Mat P_init,Vec x_init,double m,double u_lim);
    pair<double,Eigen::RowVector2d> LQRControlImp(Mat Q, double R, Vec x);
    ~LQRControl();

private:
    Mat P;
    double u_controlled{0};
    Eigen::RowVector2d K;
};