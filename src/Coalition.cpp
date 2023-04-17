#include "Coalition.h"
#include <iostream>

//constructor 
Coalition:: Coalition(int agentId):id(agentId),agentsId(),partiesId(),mandats(0){
    agentsId.push_back(agentId);
}

void Coalition:: addParty(int partyId,int mandatsParty){
    partiesId.push_back(partyId);
    mandats+=mandatsParty;
}   
//getters
int Coalition:: getId(){
    return id;
}
int Coalition:: getMandats() const{
    return mandats;
}
int Coalition:: numOfParties() const{
    return partiesId.size();
}
const vector<int> &Coalition:: partiesOfCoalition() const{
    return partiesId;
}
