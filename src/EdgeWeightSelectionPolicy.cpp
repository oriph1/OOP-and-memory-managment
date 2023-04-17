#include "SelectionPolicy.h"
#include<iostream>
using namespace std;
#include "Agent.h"
#include "Simulation.h"


int EdgeWeightSelectionPolicy:: select(Agent &agent, Simulation &s){
 	vector<Party> &parties= s.getParties();
	int maxWeight=0,partyId=-1;

	for(unsigned int i=0;i<parties.size();i++){		
			if(!checkParty(parties[i],agent,s))
				continue;

			//check if bigger than max     
			int weight= s.getGraph().getEdgeWeight(parties[i].getId(),agent.getPartyId());
			if(weight>= maxWeight){
				maxWeight=weight; 
				partyId=parties[i].getId();
			}
	}
	return partyId;
}
SelectionPolicy* EdgeWeightSelectionPolicy::getPolicy(){
	return new EdgeWeightSelectionPolicy();
};

bool SelectionPolicy::checkParty(Party &p,Agent &a, Simulation &s){
	if(s.getGraph().getEdgeWeight(p.getId(),a.getPartyId())==0 || p.getState()==Joined) //check if neighbor
				return false;
			
	//check if already got an offer from the same coalition
	vector<int> &coalitions= p.getCoalitionOffers(); //change to pointer or rference
	for(unsigned int i=0; i<coalitions.size();i++){
	 	if(coalitions[i]==a.getCoalition()){
				return false;
			}
		}
	return true;
}