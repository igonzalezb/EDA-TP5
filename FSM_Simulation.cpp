#include "FSM_Simulation.h"
extern "C" {
#include "curses.h"
}


GenericState* genericSimulation(GenericEvent * ev);


SimulationEvent :: SimulationEvent(int type, unsigned int x, unsigned int y, string name) : GenericEvent (type)
{
	wheretoWrite.setX(x);
	wheretoWrite.setY(y);
	this->name = name;
}


SimulationState :: SimulationState(string name, unsigned int x, unsigned int y)
{
	move(x,y);
	printw("%s", &name[0]);
	clrtoeol();
	whereToWrite.setX(x);
	whereToWrite.setY(y);
}

GenericState* SimulationState :: onRrq (GenericEvent * ev) { return genericSimulation(ev); }
GenericState* SimulationState :: onWrq (GenericEvent * ev) { return genericSimulation(ev); }
GenericState* SimulationState :: onAck(GenericEvent * ev) { return genericSimulation(ev); }
GenericState* SimulationState :: onLastAck (GenericEvent * ev) { return genericSimulation(ev); }
GenericState* SimulationState :: onTimeout(GenericEvent * ev) { return genericSimulation(ev); }
GenericState* SimulationState :: onError (GenericEvent * ev) { return genericSimulation(ev); }
GenericState* SimulationState :: onExit (GenericEvent * ev) { return genericSimulation(ev); }
GenericState* SimulationState :: onData (GenericEvent * ev) { return genericSimulation(ev); }
GenericState* SimulationState :: onLastData (GenericEvent * ev) { return genericSimulation(ev); }

GenericState* genericSimulation(GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("N/A");
	clrtoeol();
        
    return NULL;
}


