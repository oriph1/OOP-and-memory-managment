#pragma once
#include<iostream>
using std::string;
class Party;
class Simulation;
class JoinPolicy {
public:
    virtual int join(Party &a,Simulation &s)=0;
    virtual ~JoinPolicy() = default;
    virtual JoinPolicy* getPolicy()=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        virtual int join(Party &a,Simulation &s);
        JoinPolicy* getPolicy();
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        virtual int join(Party &a,Simulation &s);
        JoinPolicy* getPolicy();
};