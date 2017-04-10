#include "ClientStates.h"

extern "C" {
#include "curses.h"
}
#include "events.h"



GenericState* Reading :: onData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("store data, send ACK");
    clrtoeol();

    return NULL;
}

GenericState* Reading :: onLastData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("store data, send LAST ACK, close file");
	clrtoeol();
    
    return NULL;
}

GenericState* Reading :: onTimeout(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("resend ACK (once per data block)");
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
   
    return NULL;
}

GenericState* Reading :: onExit (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();

    move(p.getX(), p.getY());
    printw("close file and shut down");
	clrtoeol();
    
    return NULL;
}


GenericState* Writing :: onAck(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("send data");
    clrtoeol();

    return NULL;
}

GenericState* Writing :: onLastAck (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("close file");
    clrtoeol();

    return NULL;
}

GenericState* Writing :: onTimeout(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move(p.getX(), p.getY());
    printw("resend data (only once per data block)");
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

    return NULL;
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
