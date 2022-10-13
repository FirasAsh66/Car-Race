#include "race.h"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
Race::Race() // random length if the user chose to 
{
    length=(rand()%(50-10 + 1) +10);
}

Race::Race(int length) // user based track
{
    this->length=length;
}

RoadSegment* Race::getSegment()
{
    int random = rand()%4; // equal amount of distribution for the first segment
    if(random==0) 
    {
        return new AsphaltSegment();
    }
    else if(random==1) 
    {
        return new CrumbledSegment();
    }
    else if(random==2) 
    {
        return new GravelSegment();
    }
    else
    {
        return new DirtSegment();
    }
}

Racer* Race::getRacer(int i) // random assignment of racers
{   
    i++;
    int random = rand()%6; // equal amount of distribution for each racer
    if(random==0) 
    {
        return new StreetRacer(i);
    }
    else if(random==1) 
    {
        return new SteadyRacer(i);
    }
    else if(random==2) 
    {
        return new ToughRacer(i);
    }
    else if(random==3) 
    {
        return new MarioRacer(i);
    }
    else if(random==4) 
    {
        return new LoserRacer(i);
    }
    else 
    {
        return new DrunkRacer(i);
    }
}

void Race::runRace()
{
    int winnerIndex =-1; 
    raceTrack = new RoadSegment*[length]; //pointer to pointer of type RoadSegment
    raceTrack[0] = getSegment(); //assign the first segment randomly
    tracker = new int[8]; 
    for(int i=1; i<length; i++)
    {
        raceTrack[i] = raceTrack[i-1]->generateNeighbor(); //each segment generate the next one
        
    }
    tracker = new int[8];
    racers = new Racer*[8]; 
    for(int i=0; i<8; i++)
    {
        racers[i]=getRacer(i); // assign random racer with their id's
        tracker[i]=0; //intilize the tracker
    }
    int count = 0;
    while(winnerIndex==-1) //as long as the winner is not set then keep looping 
    {   
        count++; //race counter
        for (int i=0 ; i<8 ; i++)
        {
        if (racers[i]->getCurrentProgress()>=raceTrack[tracker[i]]->getLength())
        {
            racers[i]->resetProgress(); // reset to start new segment
            tracker[i]+=1; // move to new segment
        }
        if (tracker[i] >= length) // if the tracker is above or the same length of the track then we have a winner
        {
             // change the condition to end the loop+ assign the winner
             winnerIndex=i; 
             count = winnerIndex; 
             getWinner(winnerIndex); 
             
        } 
        else // make progress couse no winners based on segment modifiers
        {
            racers[i]->makeProgress(raceTrack[tracker[i]]->getModifiers());
        }
        }

        if (!(count==winnerIndex))
        {
        outputDivider(count);
        outputTrack(raceTrack,length);
        cout<<endl;
        outputRacers(racers,raceTrack,tracker,winnerIndex);
        }
 
    }
    
}
void Race::getWinner(int index) //prints the winner of the race
{
    index=index +1 ;
    cout<< "The winner is racer #"<<index;  
}
void Race::outputRacers(Racer** racers,RoadSegment** raceTrack,int* tracker,int index)
{
   
    for (int i = 0; i < 8; i++)
    {
        racers[i]->toString(); //basic tostring
         cout<<" into Segment #" << (1 + tracker[i])  << " ";
         raceTrack[tracker[i]]->toString(); // based on the tracker it gets the segment
         cout<<" long"<<endl;
         
    }
    if(index !=-1)
    { 
        index=index +1;
        cout<< "The winner is racer #"<<index;  
    }
}

void Race::outputTrack(RoadSegment** raceTrack,int length) 
{ 
   
    for(int i = 0; i< length; i++)
    raceTrack[i]->smallToString(); // loop throgh the tracks and print them out
    cout << "- ";
}

void Race::outputDivider(int count) //basic devider
{ 
    cout<<"///////////////////////////////////////////////////"<< endl;
    cout<<"Update #"<< count<< " ! "<< endl;
    cout<<"----------"<<endl;
}