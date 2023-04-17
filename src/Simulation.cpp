#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), mParties(mGraph.getParties()),coalitions()
{
    for(unsigned int i=0;i<agents.size();i++){
        coalitions.push_back(Coalition(agents[i].getId()));
    }
    updateParties();
}
void Simulation::updateParties(){
     for (auto i = (mParties).begin(); i != (mParties).end(); ++i)        
        (*i).updateParty(*this);
}

void Simulation::step()
{
    //Parties steps
    for(Party& p :mParties)        
        p.step(*this);
    //Agents steps
    for(Agent& a:mAgents)     
        a.step(*this);
    
}


bool Simulation::shouldTerminate() const
{
    int numOfJoinedParties=0;
    for(unsigned int i=0;i<coalitions.size();i++){
        if(coalitions[i].getMandats()>=61)
            return true;
        numOfJoinedParties+=coalitions[i].numOfParties();
    }
    if((unsigned) numOfJoinedParties==mParties.size())
        return true;
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}
Party &Simulation::getPartyNonConst(int partyId)
{
    return mGraph.getPartyNonConst(partyId);
}

Agent &Simulation:: getAgent(int AgentId){
    return mAgents[AgentId];
}

void Simulation::addAgent(Agent toAdd){
    mAgents.push_back(toAdd);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> ans;
    for (unsigned int i = 0; i < coalitions.size(); i++)
    {
        ans.push_back(coalitions[i].partiesOfCoalition());
    }
    
    return ans;
}
const vector<Coalition> &Simulation::getCoalitions() const{
    return coalitions;
}
int Simulation:: getMandat(int index) const{
    return (coalitions[index]).getMandats();
}
vector<Party> &Simulation:: getParties(){
    return mParties;
}
Coalition &Simulation::getCoalition(int id){
    return coalitions[id];
}
