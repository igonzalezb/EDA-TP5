
#ifndef ServerStates_h
#define ServerStates_h

#include <stdio.h>


#include "GenericState.h"
#include "GenericEvent.h"
#include "FSM_Simulation.h"
#include <string>


using namespace std;




class Idle : public SimulationState
{
public:
    Idle (unsigned int x, unsigned int y) : SimulationState ("Idle", x, y){};
    
    virtual GenericState* onRrq (GenericEvent * ev);
    virtual GenericState* onWrq (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev); 
};
 

class Writing : public SimulationState
{
public:
    Writing(unsigned int x, unsigned int y) : SimulationState ("Writing", x, y){};
    
    virtual GenericState* onData (GenericEvent * ev);
    virtual GenericState* onLastData (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);
};


class Reading : public SimulationState
{
public:
    Reading(unsigned int x, unsigned int y) : SimulationState ("Reading", x, y){};
     
    virtual GenericState* onAck(GenericEvent * ev);
    virtual GenericState* onLastAck (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);
};

#endif /* ServerStates_h */
