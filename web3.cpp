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
  
    bool ans;
    if((x==car2.x&&speed_x==car2.speed_x))
    {
            if((car2.y-y>0&&speed_y>car2.speed_y)*(car2.y-y<0&&speed_y>car2.speed_y))
            ans=true;
            else
            ans=false;
            return ans;
    }
    if((y==car2.y&&speed_y==car2.speed_y))
    {
            if((car2.x-x>0&&speed_x>car2.speed_x)(car2.x-x<0&&speed_x<car2.speed_x))
            ans=true;
            else
            ans=false;
            return ans;
    }
    return (((car2.y-y)/(double)(speed_y-car2.speed_y))==((car2.x-x)/(double)(speed_x-car2.speed_x)));
    
    }   
    double time_to_collision(car car2){
   
    double t=-1;
    
        if(this->detect_collision(car2)){
            //tx=min();
            if((x==car2.x&&speed_x==car2.speed_x))
            return (car2.y-y)/((double)(speed_y-car2.speed_y));
            if((y==car2.y&&speed_y==car2.speed_y))
            return (car2.x-x)/((double)(speed_x-car2.speed_x));
            return ((car2.y-y)/(double)(speed_y-car2.speed_y));
        }
        return t;

            
    }    
};
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
