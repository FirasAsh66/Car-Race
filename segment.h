#pragma once
#ifndef Segment_H
#define Segment_h

class RoadSegment
{
protected:   
    int length;
    double modifier;
public:
    RoadSegment();
    virtual RoadSegment* generateNeighbor()=0; // returns a new race segments 
     int getLength();
     double getModifiers(); 
     virtual void toString()=0; //to give details about the segments
     virtual void smallToString() = 0; // to display the track 
};

class AsphaltSegment: public RoadSegment
{
 protected:
   RoadSegment* generateNeighbor(); // returns the new road segment
 public:
   AsphaltSegment(); 
   void toString(); 
   void smallToString();
};
class CrumbledSegment :public RoadSegment
{
 protected:
    RoadSegment* generateNeighbor();
 public:
    CrumbledSegment();
    void toString();
    void smallToString();
};

class GravelSegment :public RoadSegment
{
 protected:
    RoadSegment* generateNeighbor();
 public:
    GravelSegment();
    void toString();
    void smallToString();
};

class  DirtSegment :public RoadSegment
{
 protected:

    RoadSegment* generateNeighbor();
 public:
    DirtSegment();
    void toString();
    void smallToString();
};

#endif