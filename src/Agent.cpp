#include "Agent.h"
#include <iostream>
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy),mcoalition(agentId)
{
}

//Constructor for clone
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int otherCoalition) : mAgentId(agentId), mPartyId(partyId),mSelectionPolicy(selectionPolicy),mcoalition(otherCoalition)
{
}

//distructor
Agent:: ~Agent(){ 
    if(mSelectionPolicy)
        delete mSelectionPolicy;
    mSelectionPolicy = nullptr;
} 

 //copy Constructor
Agent::Agent(const Agent& other) :mAgentId(other.mAgentId), mPartyId(other.mPartyId),mSelectionPolicy(other.getSelectionPolicy()),mcoalition(other.mcoalition){
   
}
//move constructor
Agent::Agent(Agent&& other):mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(nullptr),mcoalition(other.mcoalition){
     mSelectionPolicy=other.mSelectionPolicy;
     other.mSelectionPolicy=nullptr;
}

//assignment operator
Agent& Agent::operator=(const Agent& other){
     if(this==&other)
        return *this;
    if(mSelectionPolicy)
        delete mSelectionPolicy;
    mAgentId=other.mAgentId;
    mPartyId=other.mPartyId;
    mSelectionPolicy=other.getSelectionPolicy();
    mcoalition=other.mcoalition;
    return *this;
}

//move assignment operator
Agent& Agent::operator=(Agent&& other){
        if(this==&other)
           return *this;
        
        if(mSelectionPolicy)
            delete mSelectionPolicy;
        mAgentId=other.mAgentId;
        mPartyId=other.mPartyId;
        mSelectionPolicy=other.mSelectionPolicy;
        mcoalition=other.mcoalition;
        other.mSelectionPolicy=nullptr;
        return *this;
}


//getters 
int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}
int Agent:: getCoalition()
{
    return mcoalition;
}
SelectionPolicy* Agent::getSelectionPolicy() const //return pointer to new selection policy
{
     return  mSelectionPolicy->getPolicy();
}

void Agent::step(Simulation &sim) //step of Agent 
{
   int idSelected =mSelectionPolicy->select(*this,sim); //select a party and get id 

   if(idSelected!=-1)
        sim.getPartyNonConst(idSelected).getOffer(*this); //offer the party to join 
}