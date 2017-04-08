#ifndef CLIENT_STATES_H
#define CLIENT_STATES_H

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

class Reading : public SimulationState
{
public:
	Reading() : SimulationState ("Reading"){};

	virtual GenericState* onData (GenericEvent * ev);
    virtual GenericState* onLastData (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);
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
};

#endif //CLIENT_STATES_H