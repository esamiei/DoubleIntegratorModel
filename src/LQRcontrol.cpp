#include "LQRcontrol.hpp"

LQRControl::LQRControl(Mat P_init,Vec x_init, double m, double u_lim): P(P_init), DoubleInt::DoubleInt(x_init,m,u_lim), K(1,2){  // define a defualt constructor in the parent class
}
pair<double,Eigen::RowVector2d> LQRControl::LQRControlImp(Mat Q, double R,Vec x){
    //infinte horizon LQR
    Mat I(2,2);
    I.setIdentity();
    Mat Ad=(I+A*DT);
    Vec Bd=B*DT;

    

    P=Ad.transpose()*P*Ad-((Ad.transpose()*P*Bd)/(R+Bd.transpose()*P*Bd))*(Bd.transpose()*P*Ad)+Q;



    K=((Ad.transpose()*P*Bd)/(R+Bd.transpose()*P*Bd));

cout<<K;

    u_controlled=-K*x;
    return make_pair(u_controlled,K);
}
LQRControl::~LQRControl(){}
