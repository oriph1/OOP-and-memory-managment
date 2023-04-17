#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"
#include "Coalition.h"
#include "Party.h"

using std::string;
using std::vector;
class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    Agent &getAgent(int AgentId);
    void addAgent(Agent toAdd);
    const vector<Coalition> &getCoalitions() const;
    int getMandat(int index) const;
    vector<Party> &getParties();
    Party & getPartyNonConst(int partyId);
    Coalition &getCoalition(int id);
    void updateParties();

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Party> &mParties;
    vector<Coalition> coalitions; 
};
