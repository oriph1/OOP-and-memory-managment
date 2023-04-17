#pragma once
#include <string>
#include <vector>
#include "JoinPolicy.h"
using std::string;
using std::vector;
class Simulation;
class Agent;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    ~Party(); //distructor
    Party(const Party&); //copy Constructor
    Party(Party&&); //move constructor
    Party& operator=(const Party&); //assignment operator
    Party& operator=(Party&&);//move assignment operator
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    vector<int> &getAgentsOffers();
    vector<int> &getCoalitionOffers();
    void getOffer(Agent&);
    int getId() const;
    JoinPolicy* getJoinPolicy() const;
    int getCoalition() const;
    int getTimer() const;
    void updateParty(Simulation &s);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<int> agentsOffersId;
    vector<int> coalitionOffersId;
    int timer;
    int coalition;
};
