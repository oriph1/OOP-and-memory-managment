#pragma once

#include <vector>
#include "SelectionPolicy.h"
class Simulation;
class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy,int otherCoalition);
    ~Agent(); //distructor
    Agent(const Agent&); //copy Constructor
    Agent(Agent&&); //move constructor
    Agent& operator=(const Agent&); //assignment operator
    Agent& operator=(Agent&&);//move assignment operator
    int getPartyId() const;
    int getId() const;
    void step(Simulation &s);
    int getCoalition();
    SelectionPolicy* getSelectionPolicy() const;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mcoalition;
};
