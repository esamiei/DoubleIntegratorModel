import matplotlib.pyplot as plt
import numpy as np
from scipy import linalg

dt=0.01

class DoubleInt:
    def __init__(self, x1,x2):
        self.x1=x1
        self.x2=x2
        
    def Imp(self,u):
        self.x1=self.x1+x2*dt
        self.x2=self.x2+u*dt
        return self.x1,self.x2
    
def visualizer(pos,vel,time):   
    plt.subplot(211)
    plt.plot(time,pos)
    plt.subplot(212)
    plt.plot(time,vel)
    
if __name__=='__main__':
    x1,x2=0.0,0.0
    u=1.0
    step=100
    pos=[]
    vel=[]
    time=[]
    sol=DoubleInt(x1,x2)
    for i in range(100):
        if (i<=step/2):
            u=1.0
        else:
            u=-1.0
        x1,x2=sol.Imp(u)
        pos.append(x1)
        vel.append(x2)
        time.append(i*dt)
    visualizer(pos,vel,time)
        
        
        
    
    
    
    

        
        
        
        
        