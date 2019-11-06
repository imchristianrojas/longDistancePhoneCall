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

double rate;
using namespace std;

double timeCal(string day,string time,double duration){
    int num;
    double total;
    double extraTime;
    
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
    hour = hour+minute;
    istringstream iss(hour);
    iss>>num;
    
    //cout<<num;
    if(day == "Sat" || day == "sat" ||day == "Sun" || day =="sun"){
    
        rate = 0.15;
        total = rate*duration;
        return total;
    
    }
    
    
    // use duration and time and see if they overlap and if they do change rate get differnece and multiply by rate and make a sum of total.
    
    
    if(num>=800&&num<=1800){

        rate = 0.40;
        total = duration*rate;
        return total;
    }
    else{
        if(duration+num>=800||duration+num<=1800){
            extraTime = duration+num;
            
            rate = 0.40;
            
            
        }
        rate = 0.25;
        total= duration*rate;
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
            
            //cout<<day<<" "<<time<<" "<<duration<<endl;
            
        }
    }
    
    
    
    return 0;
}
