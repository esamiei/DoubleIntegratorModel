#include "DoubleIntegrator.hpp"
#include "LQRcontrol.hpp"


namespace plt = matplotlibcpp;

int main(){

    // state variables 
    vector<double> posx;
    vector<double> velx;
    vector<double> time;
    vector<double> u_controlled;
    Vec x_init(2);
    x_init<<-50,1.2;
    double m{1};
    double u_lim{1};

    //controller vars
    Mat P_init(2,2);
    Mat Q(2,2);
    double R=500.5;
    P_init<<0.1,0,
            0,0.1;
    Q<<1,0,
       0,1;        
    
    double final_time=50;
    double u=0.0;
    int step=final_time/DT;
    
    DoubleInt doubleint(x_init,m,u_lim);
    LQRControl lqrcontrol(P_init,x_init,m,u_lim);

    for(int i=0;i<step;i++){
    /* Bang Bang Control
        if(i<final_time/2/DT){
            u=1.0;
        }else
            u=-1.0;
    */        
        Vec x=doubleint.DoubleIntImpl(u);
        pair<double,Eigen::RowVector2d> Actuator=lqrcontrol.LQRControlImp(Q,R,x);
        u=Actuator.first;
        Eigen::RowVector2d K=Actuator.second;
        cout<<"time(s)="<<i*DT;
        cout<<"     position(m)="<<x[0];
        cout<<"             speed(m)="<<u<<"\n";
        posx.push_back(x[0]);
        velx.push_back(x[1]);
        time.push_back(i*DT);
        GlobalFCN globalfcn_obj;
        u_controlled.push_back(globalfcn_obj.sat_fcn(u,u_lim));

    }
    plt::title("Double integrator model");
    plt::subplot(3,1,1);
    plt::plot(time,posx);
    plt::xlabel("time(s)");
    plt::ylabel("position");
    plt::subplot(3,1,2);
    plt::plot(time,velx);
    plt::xlabel("time(s)");
    plt::ylabel("velx");
    plt::subplot(3,1,3);
    plt::plot(time,u_controlled);
    plt::xlabel("time(s)");
    plt::ylabel("control signal");
    plt::show();


    return 0;
}