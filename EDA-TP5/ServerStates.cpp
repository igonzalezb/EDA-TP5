#include "ServerStates.h"
#include "events.h"

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
    printw("Accion ejecutada: close file");
    
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
    printw("Accion ejecutada: close file");
    
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

GenericState* onWrq (GenericEvent * event)
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

