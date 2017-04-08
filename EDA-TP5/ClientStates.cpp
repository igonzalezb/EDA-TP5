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
	printw("Estado = Reading");

	move((unsigned int)p.getX(), (unsigned int)p.getY()+3);
	printw("Accion ejecutada: store data, send ACK");

	return NULL;
}

GenericState* Reading :: onLastData (GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Reading");

	move((unsigned int)p.getX(), (unsigned int)p.getY()+3);
	printw("Accion ejecutada: store data, send ACK, close file");

	return NULL;
}

GenericState* Reading :: onTimeout(GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Reading");

	move((unsigned int)p.getX(), (unsigned int)p.getY()+3);
	printw("Accion ejecutada: resend ACK");

	return NULL;
}






GenericState* Writing :: onAck(GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Writing");

	move((unsigned int)p.getX(), (unsigned int)p.getY()+3);
	printw("Accion ejecutada: send data");

	return NULL;
}


GenericState* Writing :: onLastAck (GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Writing");

	move((unsigned int)p.getX(), (unsigned int)p.getY()+3);
	printw("Accion ejecutada: close file");

	return NULL;
}


GenericState* Writing :: onTimeout(GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Writing");

	move((unsigned int)p.getX(), (unsigned int)p.getY()+3);
	printw("Accion ejecutada: resend data");

	return NULL;
}



GenericState* Writing :: onError (GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Writing");

	move((unsigned int)p.getX(), (unsigned int)p.getY()+3);
	printw("Accion ejecutada: close file");

	return NULL;
}


GenericState* Writing :: onExit (GenericEvent * event)
{
	SimulationEvent * ev = (SimulationEvent *)event;
	Point p = ev->getWhereToWrite();

	move((unsigned int)p.getX(), (unsigned int)p.getY());
	printw("Estado = Writing");

	move((unsigned int)p.getX(), (unsigned int)p.getY()+3);
	printw("Accion ejecutada: close file");

	return NULL;
}
