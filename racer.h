#pragma once
#ifndef Racer_H
#define Racer_h
class Racer
{
    protected: 
        int carNumber;
        double speed;
        double currentProgress;
    public:
        Racer();
        double getCurrentProgress();
        void resetProgress(); // progres back to zero
        virtual void makeProgress(double)=0;// pure virtual function to be overridden by derived
        virtual void toString()=0; // pure virtual function to be overridden by derived
};
class StreetRacer: public Racer
{
    public:
    StreetRacer(int); // constructor that takes an int as an ID
    void makeProgress(double); //to make the racers move
    void toString(); //display the racers
};
class SteadyRacer: public Racer
{
    public:
    SteadyRacer(int);
    void makeProgress(double);
    void toString();
};
class ToughRacer: public Racer
{
    public:
    ToughRacer(int);
    void makeProgress(double);
    void toString();
};

//3 new objects for Extra credit
class DrunkRacer: public Racer
{
    public:
    DrunkRacer(int);
    void makeProgress(double);
    void toString();
};
class MarioRacer: public Racer
{
    public:
    MarioRacer(int);
    void makeProgress(double);
    void toString();
};
class LoserRacer: public Racer
{
    public:
    LoserRacer(int);
    void makeProgress(double);
    void toString();
};
#endif