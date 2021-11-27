#pragma once

//define c++ libraries
#include<iostream>
#include<vector>
#include<cmath>
#include "Eigen/Dense"
#include<utility>
#include "matplotlibcpp.h"


using namespace std;


typedef Eigen::Matrix<double,2,2> Mat;
typedef Eigen::Matrix<double,2,1> Vec;



//define functions and variables

constexpr double DT=0.01;


class GlobalFCN{    
public:
    double sat_fcn(double x, double xlim){
    return std::max(std::min(x,xlim),-xlim);
}
};
