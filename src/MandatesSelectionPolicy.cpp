#include "SelectionPolicy.h"
#include<iostream>
using namespace std;
#include "Simulation.h"
#include "Agent.h"


int MandatesSelectionPolicy:: select(Agent &agent,Simulation &s){
	vector<Party> &parties= s.getParties();
	int maxMandats=0;
	int partyId=-1;
	for(unsigned int i=0;i<parties.size();i++){
	        if(!checkParty(parties[i],agent,s))
				continue;

			//check if bigger than max 
			if((parties[i].getMandates()> maxMandats)){
			    maxMandats=parties[i].getMandates();
			    partyId=parties[i].getId();
            }
	}
	return partyId;
}


SelectionPolicy* MandatesSelectionPolicy::getPolicy(){
	return new MandatesSelectionPolicy();
}