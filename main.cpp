//
//  main.cpp
//  longDistancePhoneCall
//
//  Created by Christian on 11/5/19.
//  Copyright © 2019 Christian Rojas. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

double rate;
using namespace std;





double specialCase(double before,double after,int hr,int hr2){
    
    double total1,total2,bigTotal;
    
    if(hr>=8 && hr2<=18){
        total1 = 0.45*before;
        
    }
    if(hr2<8 || hr2>18){
        total2 = 0.25*after;
    }
    bigTotal = total1+total2;
    return bigTotal;
    
    
    
}

double timeCal(string day,string time,double duration){
   
    string totaltime;
    int hr,min,hr2;
    double num,total,extra,leftHand;
    
    extra = 1.0;
    
    string hour = (time.length()==5)? "  ":" ";
    string minute = "  ";
    int i;
    for(i = 0; i<time.length();i++){
        
        if(time[i]==':'){
            if(i==2){
                hour[0] = time[0];
                hour[1] = time[1];
                minute[0] = time[3];
                minute[1] = time[4];
                
            }
            else{
                hour[0] = time[0];
                minute[0] =time[2];
                minute[1] = time[3];
            }
        
        }
        
    }
    totaltime = hour+minute;
    istringstream tot(totaltime);
    tot>>num;
    istringstream iss(hour);
    iss>>hr;
    istringstream isl(minute);
    isl>>min;
    
    
    
    
    
    
    cout<<min;
    
    
    if(day == "Sat" || day == "sat" ||day == "Sun" || day =="sun"){
    
        rate = 0.15;
        total = rate*duration * extra;
        return total;
    
    }
    
    // use duration and time and see if they overlap and if they do change rate get differnece and multiply by rate and make a sum of total.
    if(min+duration>=60){
              
              hr2 = hr + 1;//if 25==1
              
              extra = min+duration-60;//rh
              extra = abs(extra);
              leftHand = 60-min;//lh
        return specialCase(leftHand,extra,hr,hr2);
        
        
    }
    
    
    if(hr>=8&&hr<=18){

            
        
        rate = 0.40;
        total = duration*rate*extra;
        return total;
        
    }
    else{
        rate = 0.25;
        total = duration*rate*extra;
        return total;
        
    }
    
    
    
    if(num>=800&&num<=1800){

        rate = 0.40;
        total = duration*rate*extra;
        return total;
    }
    else{
        if(duration+num>=800||duration+num<=1800){
            
            rate = 0.40;
            total = duration*rate*extra;
            
            
        }
        rate = 0.25;
        total= duration*rate*extra;
        return total;
        
        
        
    }
  
    
    
    return 0;
}

int main() {
    
    
    string day,time;
    double duration;
    
    ifstream myFile;
    myFile.open("call_history.txt");
    
    if(myFile.fail()){
        cerr<<"Cannot Open File!"<<endl;
        exit(1);
    }

    if(myFile.is_open()){
        while (!myFile.eof()) {
            
            myFile>>day>>time>>duration;
            cout<<timeCal(day,time,duration)<<endl;;
            
            cout<<day<<" "<<time<<" "<<duration<<endl;
            
        }
    }
    
    
    return 0;
}
