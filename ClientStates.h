//
//  ClientStates.h
//  tp5
//
//  Created by Martu Maspero on 4/9/17.
//  Copyright © 2017 mmaspero. All rights reserved.
//

#ifndef ClientStates_h
#define ClientStates_h

#include <cstdio>
#include "GenericState.h"
#include "GenericEvent.h"
#include "FSM_Simulation.h"


using namespace std;


class Reading : public SimulationState
{
public:
    Reading(unsigned int x, unsigned int y) : SimulationState ("Reading", x, y){};
    
    virtual GenericState* onData (GenericEvent * ev);
    virtual GenericState* onLastData (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);
};


class Writing : public SimulationState
{
public:
    Writing(unsigned int x, unsigned int y) : SimulationState ("Writing", x, y){};
    
    virtual GenericState* onAck(GenericEvent * ev);
    virtual GenericState* onLastAck (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);   
};
#endif /* ClientStates_h */
