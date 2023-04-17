#include "JoinPolicy.h"
#include<iostream>
using namespace std;
#include "Party.h"
#include "Simulation.h"
#include <string>


int LastOfferJoinPolicy:: join(Party &a,Simulation &s){
    vector<int> &agentOffer= a.getAgentsOffers();
    return agentOffer[agentOffer.size()-1]; //return the last offer
}

JoinPolicy* LastOfferJoinPolicy::getPolicy(){
    return new LastOfferJoinPolicy();
}