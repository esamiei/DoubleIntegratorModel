#include "DoubleIntegrator.hpp"


DoubleInt::DoubleInt(Vec x_init, double m, double u_lim): x(x_init), m(m), u_lim(u_lim), A(2,2), B(2){
  A<<0,1,
     0,0;
  B<<0,
     1/m;      
}
Vec DoubleInt::DoubleIntImpl(double u){ 
    Mat I(2,2);
    I.setIdentity();  
    double u_lim{1.0};
    GlobalFCN globalfcn_obj;
    x=(I+A*DT)*x+B*DT*globalfcn_obj.sat_fcn(u,u_lim);
    return x;
}

DoubleInt::~DoubleInt(){}




