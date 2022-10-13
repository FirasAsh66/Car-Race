/*
Author: Ash Ashour
Date: 11/18/2021
Description: this program creats differante segments and racers with diffirent functionlity then combines it and a race class to run it and in main we intilize it.
Usage: main
*/
#include<iostream>
#include "race.h"
#include "time.h"
using std::cout;
using std::endl;
int main (int argc , char** argv)
{
    srand(time(NULL));
    int choice=0;
    int length;
    Race* r;
    cout<<"Welcome to the Racer Derby!"<<endl;
    cout<<"Would you like to:"<<endl;
    do{
    cout<< "1 - Determine the length of the race"<<endl;
    cout<< "2 - Run a random race"<<endl;
    cout<< "-1 - Exit"<<endl;
    std::cin>>choice;
    if(choice==1){     
         do{
     cout<< "Enter the length between 10-50:";
        std::cin >> length;
        }while (length>50||length<10);
        r = new Race(length);
        r->runRace();
        break;
    }
    else if(choice==2)
    {
        r=new Race();
        r->runRace();
        break;
    }
    else if(choice==-1)
    { 
        cout<< "Goodbye!";
    } 
    }while (choice!=-1);
    return 0;
} 