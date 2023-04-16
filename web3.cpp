#include<iostream>
#include<stdio.h>
#include<string>
#include <stdlib.h>

using namespace std;
class car{
    public: 
    string make;
    string model;
    int year;
     int t;         //time how much car travelled
    int speed_x ;    //speed of car in x direction
    int speed_y;
    int speed_z;
    int x; int y;int z;    
   
    void input(string ma,string mo,int ye,int t1,int sx,int sy,int sz,int x1,int y1,int z1){
        make=ma;
        model=mo;
        year=ye;
        t=t1;
        speed_x=sx;
          speed_y=sy;
          speed_z=sz;

        x=x1;y=y1;z=z1;
       
    }   

    void accelerate(int speed_increment_x,int speed_increment_y,int speed_increment_z){
        speed_x+=speed_increment_x;
        speed_y+=speed_increment_y;
        speed_z+=speed_increment_z;
        cout<<speed_x<<"  "<<speed_y<<"  "<<speed_z<<endl;

    }
     void brake(int speed_decrement_x,int speed_decrement_y,int speed_decrement_z){
        speed_x-=speed_decrement_x;
        speed_y-=speed_decrement_y;
        speed_z-=speed_decrement_z;
        cout<<speed_x<<"  "<<speed_y<<"  "<<speed_z<<endl;
    }
    void move(){
        x+=(speed_x*t);
        y+=(speed_y*t);
        z+=(speed_z*t);
    }

    bool detect_collision(car car2){

    int tempx1=x,tempy1=y,tempz1=z,tempx2=car2.x,tempy2=car2.y,tempz2=car2.z;
    move();
    car2.move();
    bool ansx,ansy,ansz;
     /*we check if cordinates of car1 were initially less tham car 2 but after 
           calling move function it became greater or not.if yes then they collide 
            otherwise not*/
    ansx=(tempx1<tempx2&&x>=car2.x)||(tempx1>tempx2&&x<=car2.x); 
    ansy=(tempy1<tempy2&&y>=car2.y)||(tempy1>tempy2&&y<=car2.y);
    ansz=(tempz1<tempz2&&z>=car2.z)||(tempz1>tempz2&&z<=car2.z);   
     
    x=tempx1;y=tempy1;car2.x=tempx2;car2.y=tempy2;z=tempz1;car2.z=tempz2;     //we are resetting the coordinates of cars to initial ones as they got changed after calling move function
    return (ansx||ansy)||(ansx||ansz)||(ansz||ansy);
    }   
    double time_to_collision(car car2){
     
    double tx=-1.0,ty=-1.0,tz=-1.0;
    
        if(this->detect_collision(car2)){
            tx=(car2.x-x)/((double)(speed_x-car2.speed_x));
            ty=(car2.y-y)/((double)(speed_y-car2.speed_y));
            tz=(car2.z-z)/((double)(speed_z-car2.speed_z));
            if(tx>0&&ty>0&&tz>0)
            return min(tx,min(tz,ty));         //we are finding minimum of the times of collision in the 3 directions
            if(tx>0&&ty<0&&tz<0)                 //this means cars are colliding only in x not in y or z
            return tx;
             if(tx<0&&ty>0&&tz<0)
            return ty;
             if(tx<0&&ty<0&&tz>0)
            return tz;
             if(tx>0&&ty>0&&tz<0)         //this means cars are colliding in x and y not in z
            return min(tx,ty);
             if(tx>0&&ty<0&&tz>0)
            return min(tx,tz);
             if(tx<0&&ty>0&&tz>0)
            return min(ty,tz);
        }
        return min(tx,min(ty,tz));          //if cars collide in neither of the 3 directions
    }         
};
int main(){
    car car1;
    car car2;
     car1.input("tata","nexon",2001,10,0,0,0,0,0,0);
     car2.input("tata","nexon",2001,10,-1,-2,0,5,9,0);
     cout<<"would collide or not: "<<car1.detect_collision(car2)<<endl;
     cout<<car1.time_to_collision(car2)<<endl;
     return 0;
    }