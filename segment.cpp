#include <iostream>
#include "segment.h"

RoadSegment::RoadSegment()
{
    length=(rand()%(50-10 + 1) +10); // generate random length for each segment
}

int RoadSegment::getLength()
{
 return length;
}

double RoadSegment::getModifiers()
{
 return modifier;
}

//Asphalt class
AsphaltSegment::AsphaltSegment()
{
    modifier=1.0;   //default modifier
}
RoadSegment* AsphaltSegment::generateNeighbor()
{
    int random  = rand()%100 +1;    //random number generator
    if (random>=1&&random <=60)     //return random segment based on the percentage 
    {
        return new AsphaltSegment();
    }
    if (random>60&&random <=85)
    {
        return new CrumbledSegment();
    }
    if (random>85&&random <=95){
        return new GravelSegment();
    }
    return new DirtSegment();
}
void AsphaltSegment::toString()
{
 std::cout << "Asphalt - "<< length<< " units";
}
void AsphaltSegment::smallToString()
{
   std::cout << " A:"<< length;
}

//Crumble class
CrumbledSegment::CrumbledSegment()
{
    modifier=(rand()%(8-6 + 1) +6)/10.0;
}
RoadSegment* CrumbledSegment::generateNeighbor()
{
    int random  = rand()%100 +1;
    if (random>=1&&random <=40)
    {
        return new AsphaltSegment();
    }
    if (random>40&&random <=65)
    {
        return new CrumbledSegment();
    }
    if (random>65&&random <=90){
        return new GravelSegment();
    }
    return new DirtSegment();
}
void CrumbledSegment::toString()
{
 std::cout << "Crumble - "<< length<< " units";
}
void CrumbledSegment::smallToString()
{
   std::cout << " C:"<< length;
}

//Gravel class
GravelSegment::GravelSegment()
{
    modifier=(rand()%(6-3 + 1) +3)/10.0;
}
RoadSegment* GravelSegment::generateNeighbor()
{
    int random  = rand()%100 +1;
    if (random>=1&&random <=50)
    {
        return new AsphaltSegment();
    }
    if (random>50&&random <=85)
    {
        return new CrumbledSegment();
    }
    if (random>85&&random <=95){
        return  new GravelSegment();
    }
    return new DirtSegment();
}
void GravelSegment::toString()
{
 std::cout << "Gravel - "<< length<< " units";
}
void GravelSegment::smallToString()
{
   std::cout << " G:"<< length;
}

//Dirt Class
DirtSegment::DirtSegment()
{
    modifier=(rand()%(3 + 1))/10.0;
}
RoadSegment* DirtSegment::generateNeighbor()
{
    int random  = rand()%100 +1;
    if (random>=1&&random <=60)
    {
        return new AsphaltSegment();
    }
    if (random>60&&random <=90)
    {
        return new CrumbledSegment();
    }
    if (random>90&&random <=95){
        return new GravelSegment();
    }
    return new DirtSegment();
}
void DirtSegment::toString()
{
 std::cout << "Dirt - "<< length<< " units";
}
void DirtSegment::smallToString()
{
   std::cout << " D:"<< length;
}