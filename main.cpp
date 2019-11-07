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



double caluclate(string day,string time,int duration){
    
    
    string days[7] = {"Su","Mo","Tu","We","Th","Fr","Sa"};
    int dayId,newHour,newMin,initialHour;

    double total,difference,newDuration;
    difference = 1;
    newDuration = 1;
    
    
   string hour = (time.length()==5)? "  ":" ";
    string min = "  ";
    int x;
    for(x = 0; x<time.length();x++){
        if (time[x]==':') {
            if(x==2){
            hour[0] = time[0];
            hour[1] = time[1];
            min[0] = time[3];
            min[1]= time[4];
        }
            else{
                hour[0] = time[0];
                min[0] = time[2];
                min[1] = time[3];
            }
    }
    }
    
    istringstream iss(hour);
    iss>>newHour;
    istringstream drake(min);
    drake>>newMin;
    
    initialHour = newHour;//before it changes if it changes
    
    for(dayId = 0;dayId<7;dayId++){
        if(days[dayId] == day){
            dayId = dayId;
            break;
        }
    }
   
    

    if(duration+newMin>=60){
    
        difference = (duration+newMin)-60;//right hand side
        newDuration = duration-difference;//left hand side
        newHour++;
        
    }
    
    
    if(dayId==0){//Fine tune this part
        if(newHour==24){
            newHour=0;
        }
    }
    else if (dayId!=0){
        if(newHour==24){
            newHour=0;
            dayId++;
        }
    }
    
    switch (dayId) {
        case 0:
            //Sunday special case.
            if(newHour>=0){
                total = (0.15*newDuration)+(0.25*difference);
                return total;
            }
            else{
                total = duration*0.15;
                return total;
            }
            
        case 1://Monday
            if(initialHour>=8 && initialHour<=18&& initialHour == newHour){//if there is not hour changes
                rate = 0.40;
                total = rate*duration;
                return total;
            }
            else if((initialHour<8||initialHour>18)&&initialHour==newHour){
                rate = 0.25;
                total = rate*duration;
               
                return total;
            }
            if(newHour>=8){//morning rate to afternoon rate;
                total = (0.25* newDuration)+(0.45*difference);
                
                return total;
            }
            else if(newHour>=18){
                total = (0.40*newDuration)+(0.25*difference);//afternoon to morning rate
        
                return total;
                
            }
            
            break;
        case 2://Tuesday
            if(initialHour>=8 && initialHour<=18&& initialHour == newHour){//if there is not hour changes
                rate = 0.40;
                total = rate*duration;
                return total;
            }
            else if((initialHour<8||initialHour>18)&&initialHour==newHour){
                rate = 0.25;
                total = rate*duration;
                return total;
            }
            if(newHour>=8){//morning rate to afternoon rate;
                total = (0.25* newDuration)+(0.40*difference);
                return total;
            }
            else if(newHour>=18){
                total = (0.40*newDuration)+(0.25*difference);//afternoon to morning rate
                return total;
            }
            break;
        case 3://Wendsday
            if(initialHour>=8 && initialHour<=18&& initialHour == newHour){//if there is not hour changes
                rate = 0.40;
                total = rate*duration;
                return total;
            }
            else if((initialHour<8||initialHour>18)&&initialHour==newHour){
                rate = 0.25;
                total = rate*duration;
                return total;
            }
            if(newHour>=8){//morning rate to afternoon rate;
                total = (0.25* newDuration)+(0.40*difference);
                return total;
            }
            else if(newHour>=18){
                total = (0.40*newDuration)+(0.25*difference);//afternoon to morning rate
                return total;
            }
            
            break;
        case 4://Thursday
            if(initialHour>=8 && initialHour<=18&& initialHour == newHour){//if there is not hour changes
                rate = 0.40;
                total = rate*duration;
                return total;
            }
            else if((initialHour<8||initialHour>18)&&initialHour==newHour){
                rate = 0.25;
                total = rate*duration;
                return total;
            }
            if(newHour>=8){//morning rate to afternoon rate;
                total = (0.25* newDuration)+(0.40*difference);
                return total;
            }
            else if(newHour>=18){
                total = (0.40*newDuration)+(0.25*difference);//afternoon to morning rate
                return total;
            }
            
            break;
        case 5://Friday
            if(initialHour>=8 && initialHour<=18&& initialHour == newHour){//if there is not hour changes
                rate = 0.40;
                total = rate*duration;
                return total;
            }
            else if((initialHour<8||initialHour>18)&&initialHour==newHour){
                rate = 0.25;
                total = rate*duration;
                return total;
            }
            if(newHour>=8){//morning rate to afternoon rate;
                total = (0.25* newDuration)+(0.40*difference);
                return total;
            }
            else if(newHour>=18){
                total = (0.40*newDuration)+(0.25*difference);//afternoon to morning rate
                return total;
            }
        
            break;
        case 6://Saturday
            rate = 0.15;
            total = rate*duration;
            return total;
            
            break;
        
        
    }
    
    return 0;
}





int main() {
    
    string day,time;
    int duration;
    
    ifstream myFile;
    myFile.open("call_history.txt");
    
    if(myFile.fail()){
        cerr<<"Cannot Open File!"<<endl;
        exit(1);
    }

    if(myFile.is_open()){
        while (!myFile.eof()) {
            myFile>>day>>time>>duration;
            cout<<caluclate(day,time,duration)<<endl;
            
            
        }
    }
    myFile.close();
    
    return 0;
}
