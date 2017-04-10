
#ifndef events_h
#define events_h
 
#define	CLIENT	1	
#define SERVER	0

#define I_AM	CLIENT

#include "GenericEvent.h"
#include "FSM_Simulation.h"
#include "Point.h"
#include <string>

using namespace std;


#if I_AM == CLIENT
enum eventos{ACK, LAST_ACK, DATA, LAST_DATA, TIMEOUT, ERROR, EXIT};
#else
enum eventos{ACK, LAST_ACK, DATA, LAST_DATA, TIMEOUT, ERROR, EXIT, RRQ, WRQ};
#endif



#if I_AM == SERVER

class Rrq: public SimulationEvent
{
public:
	Rrq (unsigned int x, unsigned int y) : SimulationEvent (RRQ, x, y, "RRQ"){;}

};

class Wrq: public SimulationEvent
{
public:
	Wrq (unsigned int x, unsigned int y) : SimulationEvent (WRQ, x, y, "WRQ"){;}
};
#endif

class Data: public SimulationEvent
{
public:
	Data (unsigned int x, unsigned int y) : SimulationEvent (DATA, x, y, "DATA"){;}
};

class LastData: public SimulationEvent
{
public:
	LastData (unsigned int x, unsigned int y) : SimulationEvent (LAST_DATA, x, y, "LAST DATA"){;}
};


class Ack: public SimulationEvent
{
public:
	Ack (unsigned int x, unsigned int y) : SimulationEvent (ACK, x, y, "ACK"){;}
};

class LastAck: public SimulationEvent
{
public:
	LastAck (unsigned int x, unsigned int y) : SimulationEvent (LAST_ACK, x, y, "LAST ACK"){;}
};

class Timeout: public SimulationEvent
{
public:
	Timeout (unsigned int x, unsigned int y) : SimulationEvent (TIMEOUT, x, y, "TIMEOUT"){;}
};

class Error: public SimulationEvent
{
public:
	Error (unsigned int x, unsigned int y) : SimulationEvent (ERROR, x, y, "ERROR"){;}
};

class Exit: public SimulationEvent
{
public:
	Exit (unsigned int x, unsigned int y) : SimulationEvent (EXIT, x, y, "EXIT"){;}
};


#endif /* events_h */
