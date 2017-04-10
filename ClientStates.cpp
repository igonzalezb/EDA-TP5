#include "ClientStates.h"
extern "C" { 
#include "curses.h"
}
#include "events.h"



GenericState* Reading :: onData (GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Reading\t\t");

	move((unsigned int)p.getX()+3, (unsigned int)p.getY());
	printw("Accion ejecutada: store data, send ACK\t\t");

	return NULL;
}

GenericState* Reading :: onLastData (GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Reading\t\t");

	move((unsigned int)p.getX()+3, (unsigned int)p.getY());
	printw("Accion ejecutada: store data, send ACK, close file\t\t");

	return NULL;
}

GenericState* Reading :: onTimeout(GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Reading\t\t");

	move((unsigned int)p.getX()+3, (unsigned int)p.getY());
	printw("Accion ejecutada: resend ACK\t\t");

	return NULL;
}


GenericState* Reading :: onError (GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Reading\t\t");

	move((unsigned int)p.getX()+3, (unsigned int)p.getY());
	printw("Accion ejecutada: close file\t\t");

	return NULL;
}


GenericState* Reading :: onExit (GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Reading\t\t");

	move((unsigned int)p.getX()+3, (unsigned int)p.getY());
	printw("Accion ejecutada: close file\t\t");

	return NULL;
}




GenericState* Writing :: onAck(GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Writing\t\t");

	move((unsigned int)p.getX()+3, (unsigned int)p.getY());
	printw("Accion ejecutada: send data\t\t");

	return NULL;
}


GenericState* Writing :: onLastAck (GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Writing\t\t");

	move((unsigned int)p.getX()+3, (unsigned int)p.getY());
	printw("Accion ejecutada: close file\t\t");

	return NULL;
}


GenericState* Writing :: onTimeout(GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Writing\t\t");

	move((unsigned int)p.getX()+3, (unsigned int)p.getY());
	printw("Accion ejecutada: resend data\t\t");

	return NULL;
}



GenericState* Writing :: onError (GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Writing\t\t");

	move((unsigned int)p.getX()+3, (unsigned int)p.getY());
	printw("Accion ejecutada: close file\t\t");

	return NULL;
}


GenericState* Writing :: onExit (GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Writing\t\t");

	move((unsigned int)p.getX()+3, (unsigned int)p.getY());
	printw("Accion ejecutada: close file\t\t");

	return NULL;
}
