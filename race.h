#pragma once
#ifndef Race_H
#define Race_h
#include "racer.h"
#include "segment.h"

class Race {
    private:    
        RoadSegment** raceTrack; //creat the track for the race 
        int length; // length of the race track
        int* tracker; //track for progress made by the cars
        Racer** racers; //the racers lives  here
        void outputTrack(RoadSegment**,int); 
        void outputRacers(Racer**,RoadSegment**,int*,int);
        void outputDivider(int); 
        RoadSegment* getSegment(); //randomly generated segment
        Racer* getRacer(int); //randomly generated racer
        void getWinner(int); // display the winner the winner
    public:
        Race(); //constructor that generates the race randomly
        Race(int); // constructor that takes length from the users
        void runRace(); // all the race happens in here
        
};
#endif 