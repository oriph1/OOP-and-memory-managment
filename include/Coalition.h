#pragma once
#include <vector>
using std::vector;


class Coalition{
    public:
        Coalition(int agentId);
        void addParty(int partyId,int mandatsParty);
        int getId();
        int getMandats() const;
        int numOfParties() const;
        const vector<int> &partiesOfCoalition() const;
        
    private:
        int id;
        vector<int> agentsId;
        vector<int> partiesId; 
        int mandats;
};