#include "ServerStates.hpp"
#include "events.hpp"

extern "C" {
#include "curses.h"
}

GenericState* Writing :: onData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: store data, send ACK");
    
    return NULL;
}

GenericState* Writing :: onLastData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: store data, send LAST_ACK, close file");
    
    GenericState* newState = new Idle();
    
    return newState;
}

GenericState* Writing :: onTimeout(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: resend ACK");
    
    return NULL;
}

GenericState* Writing :: onError (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: close file");
    
    GenericState* newState = new Idle();
    
    return newState;
}


GenericState* Writing :: onExit (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: close file and shut down");
    
    return NULL;
}

GenericState* Writing :: onRrq (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Writing :: onWrq (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Writing :: onAck(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Writing :: onLastAck (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}



GenericState* Reading :: onAck(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: send data");
    
    return NULL;
}


GenericState* Reading :: onLastAck (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
   move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: close file");
  
    GenericState* newState = new Idle();
    
    return newState;
}


GenericState* Reading :: onTimeout(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: resend data");

    
    return NULL;
}



GenericState* Reading :: onError (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
   move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: close file");
    
    GenericState* newState = new Idle();

    return newState;
}


GenericState* Reading :: onExit (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: close file and shut down");
    
    return NULL;
}

GenericState* Reading :: onRrq (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Reading :: onWrq (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Reading :: onData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Reading :: onLastData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}

GenericState* Idle:: onRrq (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Idle");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: open file");
    
    GenericState* newState = new Reading();
    return newState;
}

GenericState* Idle:: onWrq (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Idle");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: open file");
    
    GenericState* newState = new Writing();
    return newState;
}

GenericState* Idle:: onData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Idle");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Idle:: onLastData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Idle");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Idle:: onAck(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Idle");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}

GenericState* Idle :: onLastAck (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Idle");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Idle:: onTimeout(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Idle");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Idle:: onError (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Idle");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Idle::onExit (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Idle");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: shut down");
    
    return NULL;
}
