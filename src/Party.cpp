#include "Party.h"
#include "Agent.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),agentsOffersId(),coalitionOffersId(),timer(3), coalition((-1))
{
}

//distructor
Party:: ~Party(){ 
    if(mJoinPolicy)
        delete mJoinPolicy;
    mJoinPolicy = nullptr;
} 

 //copy Constructor
Party::Party(const Party& other): mId(other.getId()), mName(other.getName()), mMandates(other.getMandates()),mJoinPolicy(other.getJoinPolicy()), mState(other.getState()),agentsOffersId(),coalitionOffersId() ,timer(other.getTimer()),coalition(other.getCoalition()){
    
    //take the offers from other
    for(int i=0; i<(int)other.agentsOffersId.size();i++){ 
        agentsOffersId.push_back(other.agentsOffersId[i]);
    }
     for(int i=0; i<(int)other.coalitionOffersId.size();i++){
        coalitionOffersId.push_back(other.coalitionOffersId[i]);
    }
}
//move constructor
Party::Party(Party&& other):mId(other.getId()),mName(other.getName()),mMandates(other.getMandates()),mJoinPolicy(other.mJoinPolicy) ,mState(other.getState()),agentsOffersId(other.agentsOffersId),coalitionOffersId(other.coalitionOffersId),
    timer (other.getTimer()),coalition(other.getCoalition()){
    other.mJoinPolicy=nullptr;
}

//assignment operator
Party& Party::operator=(const Party& other){
    if(this==&other)
        return *this;
    if(mJoinPolicy)
        delete mJoinPolicy;
    mId=other.getId();
    mName=other.getName();
    mMandates=other.getMandates();
    mJoinPolicy=other.getJoinPolicy();
    mState=other.getState();
    timer = other.getTimer();   
    coalition=other.getCoalition();
    agentsOffersId=other.agentsOffersId;
    coalitionOffersId=other.coalitionOffersId;
    return *this;
}

//move assignment operator
Party& Party::operator=(Party&& other){
    if(this==&other)
        return *this;
    if(mJoinPolicy)
        delete mJoinPolicy;
    mId=other.getId();
    mName=other.getName();
    mMandates=other.getMandates();
    mJoinPolicy=other.mJoinPolicy;
    other.mJoinPolicy=nullptr;
    mState=other.getState();
    timer = other.getTimer();   
    coalition=other.getCoalition();
    agentsOffersId=other.agentsOffersId;
    coalitionOffersId=other.coalitionOffersId;
    return *this;
}

//getters
State Party::getState() const
{
    return mState;
}
int Party::getId() const
{
    return mId;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

JoinPolicy* Party::getJoinPolicy() const
{
     return  mJoinPolicy->getPolicy();
}
void Party::setState(State state)
{
    mState = state;
}
vector<int> &Party::getAgentsOffers()
{
    return agentsOffersId;
}
void Party:: getOffer(Agent& agent) //get offer from agent 
{
	agentsOffersId.push_back(agent.getId());
	coalitionOffersId.push_back(agent.getCoalition());
	if (mState == Waiting)
	         mState =CollectingOffers;
}
vector<int> &Party:: getCoalitionOffers(){
    return coalitionOffersId;
}

int Party::getCoalition() const{
    return coalition;
}

int Party::getTimer() const{
    return timer;
}

//update for the first round
void Party::updateParty(Simulation &s){
    for (unsigned int i = 0; i < s.getAgents().size(); i++)
    {
        if(s.getAgents()[i].getPartyId()==mId){ //check if the party belong to any coalition
            mState=Joined;
            coalition=s.getAgent(s.getAgents()[i].getId()).getCoalition(); //update coalition field
            s.getCoalition(coalition).addParty(mId,mMandates);//update in coalition 
            return;
        }
    }
}

void Party::step(Simulation &s)
{
    if (mState == Joined){ //check if this is possible to check the status
        return;
    }
    
    if (mState == CollectingOffers){
        timer--;
        if (timer == 0){
            int idOffer= mJoinPolicy->join(*this,s);
            mState=Joined;
            //using clone constructor
            Agent& agentToClone= s.getAgent(idOffer);
            Agent newAgent(s.getAgents().size(),mId,agentToClone.getSelectionPolicy(),agentToClone.getCoalition());
            coalition=agentToClone.getCoalition();
            s.getCoalition(coalition).addParty(mId,mMandates);
            s.addAgent(newAgent);
        }   
    }
}
