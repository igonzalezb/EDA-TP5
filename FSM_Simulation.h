#ifndef SIMULATION_STATE_H
#define SIMULATION_STATE_H

#include "GenericState.h"
#include "Point.h"
#include <string>

using namespace std;

class SimulationState : public GenericState
{
public:
    SimulationState(string name, unsigned int x, unsigned int y);

	virtual GenericState* onRrq (GenericEvent * ev);
    virtual GenericState* onWrq (GenericEvent * ev);
    virtual GenericState* onData (GenericEvent * ev);
    virtual GenericState* onLastData (GenericEvent * ev);
    virtual GenericState* onAck(GenericEvent * ev);
    virtual GenericState* onLastAck (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);

protected:
	Point whereToWrite;
};


class SimulationEvent : public GenericEvent
{
public:
	SimulationEvent(int type, unsigned int x, unsigned int y, string name);

	string getName() { return name; }
	Point getWhereToWrite() { return wheretoWrite; }

protected:
	Point wheretoWrite;
	string name;
};

#endif //SIMULATION_STATE_H
