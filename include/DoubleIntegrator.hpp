#pragma once

#include "globals.hpp"




class DoubleInt{
    public:
        DoubleInt()=default;
        DoubleInt(Vec x_init,double m,double u_lim);
        Vec DoubleIntImpl(double u);
        ~DoubleInt();
    private:
        Vec x;
    protected:   
        Mat A;
        Vec B;
        double m;
        double u_lim;

};