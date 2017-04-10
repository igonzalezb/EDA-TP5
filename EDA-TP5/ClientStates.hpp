//
//  ClientStates.hpp
//  tp5
//
//  Created by Martu Maspero on 4/9/17.
//  Copyright © 2017 mmaspero. All rights reserved.
//

#ifndef ClientStates_hpp
#define ClientStates_hpp

#include <stdio.h>
#include "GenericState.hpp"
#include "GenericEvent.hpp"
#include <string>


using namespace std;

class SimulationState : public GenericState
{
public:
    SimulationState(string name) {this->name = name;}
    
    
protected:
    string name;
};

class Reading : public SimulationState
{
public:
    Reading() : SimulationState ("Reading"){};
    
    virtual GenericState* onData (GenericEvent * ev);
    virtual GenericState* onLastData (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);
    virtual GenericState* onRrq (GenericEvent * ev);
    virtual GenericState* onWrq (GenericEvent * ev);
    virtual GenericState* onAck(GenericEvent * ev);
    virtual GenericState* onLastAck (GenericEvent * ev);
    
};


class Writing : public SimulationState
{
public:
    Writing() : SimulationState ("Writing"){};
    
    
    virtual GenericState* onAck(GenericEvent * ev);
    virtual GenericState* onLastAck (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);
    virtual GenericState* onData (GenericEvent * ev);
    virtual GenericState* onLastData (GenericEvent * ev);
    virtual GenericState* onRrq (GenericEvent * ev);
    virtual GenericState* onWrq (GenericEvent * ev);
    
};
#endif /* ClientStates_hpp */
