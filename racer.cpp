#include <iostream>
#include "racer.h"

Racer::Racer()
{
    carNumber=0; //inlize 
}
void Racer::resetProgress()
{
    currentProgress = 0.0;
}
double Racer::getCurrentProgress()
{ 
    return currentProgress;
}
//Street racer class
StreetRacer::StreetRacer(int id)
{
    carNumber=id;   // new id
    speed =  (rand()%(70-55 + 1) +55)/10.0; //random speed between 5.5 to 7.0
}
void StreetRacer::makeProgress(double modifier)
{ 
    currentProgress+=(speed*modifier)+0.5;
}
void StreetRacer::toString()
{
    std::cout<<"Racer #"<<carNumber<<" StreetRacer - "<<currentProgress<<" units";
}
//Steady Racer class
SteadyRacer::SteadyRacer(int id)
{
    carNumber=id;   
    speed =  (rand()%(40-30 + 1) +30)/10.0; //random speed between 3.0 to 4.0
}
void SteadyRacer::makeProgress(double modifier)
{ 
    currentProgress+=speed;
}
void SteadyRacer::toString()
{
    std::cout<<"Racer #"<<this->carNumber<<" SteadyRacer - "<<currentProgress<<" units";
}

//Tough Racer class
ToughRacer::ToughRacer(int id)
{
    carNumber=id;
    speed =  (rand()%(30-20 + 1) +20)/10.0; //random speed between 2.0 to 3.0
}
void ToughRacer::makeProgress(double modifier)
{ 
    double bonusSpeed= 5 * (1.0 - modifier);
    currentProgress+=speed+bonusSpeed;
}
void ToughRacer::toString()
{
    std::cout<<"Racer #"<<this->carNumber<<" ToughRacer - "<<currentProgress<<" units";
}

//Drunk Racer class
DrunkRacer::DrunkRacer(int id)
{
    carNumber=id;
    speed =  (rand()%(20-10 + 1) +10)/10.0; //random speed between 1.0 to 2.0
}
void DrunkRacer::makeProgress(double modifier)
{ 
    currentProgress+=speed+1;
}
void DrunkRacer::toString()
{
    std::cout<<"Racer #"<<this->carNumber<<" DrunkRacer - "<<currentProgress<<" units";
}

//Mario Racer class
MarioRacer::MarioRacer(int id)
{
    carNumber=id;
    speed =  (rand()%(55-45 + 1) +45)/10.0; //random speed between 4.5 to 5.5
}
void MarioRacer::makeProgress(double modifier)
{ 
    currentProgress+=speed+1/modifier;  // modifier gives boost 
}
void MarioRacer::toString()
{
    std::cout<<"Racer #"<<this->carNumber<<" MarioRacer - "<<currentProgress<<" units";
}
//Loser Racer class
LoserRacer::LoserRacer(int id)
{
    carNumber=id;
    speed =  (rand()%(20 + 1) )/10.0; //random speed between 0.0 to 2.0
}
void LoserRacer::makeProgress(double modifier)
{ 
    currentProgress+=speed*modifier*modifier; // double affect of modifier
}
void LoserRacer::toString()
{
    std::cout<<"Racer #"<<this->carNumber<<" LoserRacer - "<<currentProgress<<" units";
}