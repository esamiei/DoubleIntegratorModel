#include<iostream>
#include<vector>

using namespace std;

const double dT=0.1;

class Eom{
public:
	Eom(double x1_init, double x2_init){
		x1=x1_init;
		x2=x2_init;
	}
	vector<double> EomImpl(double u){
		x1=x1+dT*x2;
		x2=x2+dT*u;
		vector<double> state;
		state.push_back(x1);
		state.push_back(x2);
		return state;
	}
	~Eom(){
		cout<<"object is being deleted"<<"\n";
	};

private:
	double x1,x2;
};


int main(){
	double x1_init=0;
	double x2_init=0;
	double u=1.0;       // u=[-1,1]
	double time=5.0;
	int steps=time/dT;
	vector<double> state;

	Eom eom(x1_init,x2_init);
	for(int i=0;i<steps;i++){
		if (i<(time/2/dT)){
			u=1.0;
		}else{
			u=-1.0;
		}
		state=eom.EomImpl(u);
		cout<<"time(s)="<<(i*dT);
		cout<<"    		Position(m)="<<state[0];
		cout<<"    		speed(m/s)="<<state[1]<<"\n";
	}
	
	return 0;
}