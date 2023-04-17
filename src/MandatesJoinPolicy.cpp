#include "JoinPolicy.h"
#include<iostream>
#include "Simulation.h"
#include <string>
using namespace std;
#include "Party.h"

int MandatesJoinPolicy:: join(Party &a,Simulation &s){
    vector<int> &coalitionsOffers= a.getCoalitionOffers();
	int maxMandat=0;
	int index=-1;

	//check the offers by coalition id
	for(unsigned int i =0; i<coalitionsOffers.size();i++){
		int numOfMandats= s.getMandat(coalitionsOffers[i]);
		if(numOfMandats>maxMandat){
			maxMandat=numOfMandats;	
			index= i;
        }
	}
	return (a.getAgentsOffers())[index]; //return the agent id 
}
JoinPolicy* MandatesJoinPolicy::getPolicy(){
	return new MandatesJoinPolicy();
}