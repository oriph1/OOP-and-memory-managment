#pragma once
#include<iostream>
using namespace std;
using std::string;
#include <string>
class Agent;
class Party;
class Simulation;

class SelectionPolicy {
    public:
        virtual int select(Agent &agent,Simulation &s) =0;
        virtual ~SelectionPolicy() = default;
        virtual SelectionPolicy* getPolicy()=0;
        bool checkParty(Party &p,Agent &a, Simulation &s);
 };

class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
       virtual int select(Agent &agent,Simulation &s);
        SelectionPolicy* getPolicy();
        
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        virtual int select(Agent &agent,Simulation &s);
        SelectionPolicy* getPolicy();
 };