
#ifndef ServerStates_h
#define ServerStates_h

#include <stdio.h>


#include "GenericState.h"
#include "GenericEvent.h"
#include <string>


using namespace std;

class SimulationState : public GenericState
{
public:
    SimulationState(string name) {this->name = name;}
    
    
protected:
    string name;
};


class Idle : public SimulationState
{
    
public:
    Idle () : SimulationState ("Idle"){};
    
    virtual GenericState* onRrq (GenericEvent * ev);
    virtual GenericState* onWrq (GenericEvent * ev);
  
};
 

class Writing : public SimulationState

{
public:
    Writing() : SimulationState ("Writing"){};
    
    virtual GenericState* onData (GenericEvent * ev);
    virtual GenericState* onLastData (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);
};


class Reading : public SimulationState
{
public:
    Reading() : SimulationState ("Reading"){};
    
    
    virtual GenericState* onAck(GenericEvent * ev);
    virtual GenericState* onLastAck (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);
};

#endif /* ServerStates_h */
