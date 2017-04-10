#include "ClientStates.hpp"

extern "C" {
#include "curses.h"
}
#include "events.hpp"



GenericState* Reading :: onData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: store data, send ACK");
    
    return NULL;
}

GenericState* Reading :: onLastData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: store data, send ACK, close file");
    
    return NULL;
}

GenericState* Reading :: onTimeout(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: resend ACK");
    
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
    
    return NULL;
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
GenericState* Reading :: onAck(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Reading :: onLastAck (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
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
    printw("Accion ejecutada: send data");
    
    return NULL;
}


GenericState* Writing :: onLastAck (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: close file");
    
    return NULL;
}


GenericState* Writing :: onTimeout(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: resend data");
    
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
    
    return NULL;
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

GenericState* Writing :: onData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
GenericState* Writing :: onLastData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
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
