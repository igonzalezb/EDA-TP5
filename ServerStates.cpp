#include "ServerStates.h"
#include "events.h"

extern "C" {
#include "curses.h"
}

GenericState* Writing :: onData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("store data, send ACK");
	clrtoeol();

    return NULL;
}

GenericState* Writing :: onLastData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("store data, send LAST_ACK, close file");
   	clrtoeol();
    
    return new Idle(whereToWrite.getX(), whereToWrite.getY());
}

GenericState* Writing :: onTimeout(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
	move(p.getX(), p.getY());
    printw("resend ACK (only once per data block)");
  	clrtoeol();

    return NULL;
}

GenericState* Writing :: onError (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("close file");
	clrtoeol();
    
    return new Idle(whereToWrite.getX(), whereToWrite.getY());
}

GenericState* Writing :: onExit (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("close file and shut down");
	clrtoeol();
    
    return NULL;
}


GenericState* Reading :: onAck(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("send data");
	clrtoeol();
    
    return NULL;
}

GenericState* Reading :: onLastAck (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("close file");
	clrtoeol();
    
    return new Idle(whereToWrite.getX(), whereToWrite.getY());
}

GenericState* Reading :: onTimeout(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("resend data (only once per data block)");
	clrtoeol();
    
    return NULL;
}

GenericState* Reading :: onError (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
	
	move(p.getX(), p.getY());
    printw("close file");
    clrtoeol();
    
    return new Idle(whereToWrite.getX(), whereToWrite.getY());
}

GenericState* Reading :: onExit (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("close file and shut down");
    
    return NULL;
}


GenericState* Idle:: onRrq (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("open file, send first data block");
    clrtoeol();
    
    return new Reading(whereToWrite.getX(), whereToWrite.getY());
}

GenericState* Idle:: onWrq (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("open file");
    clrtoeol();
    
	return new Writing(whereToWrite.getX(), whereToWrite.getY());
}

GenericState* Idle::onExit (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("shut down");
	clrtoeol();
    
    return NULL;
}
