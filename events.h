
#ifndef events_h
#define events_h
 
#define	CLIENT	1	
#define SERVER	0

#define I_AM	CLIENT

#include "GenericEvent.h"
#include "Point.h"
#include <string>

using namespace std;

class SimulationEvent : public GenericEvent
{
public:
	SimulationEvent(int type, unsigned int x, unsigned int y, string name) : GenericEvent (type)
	{
		wheretoWrite.setX(x);
		wheretoWrite.setY(y);
		this->name = name;
	}

		//Car(const string& _licensePlate, long _motorId,
		//ChildSeat * _childSeat)
		//: Vehicle(_licensePlate, _motorId),
		//childSeat(_childSeat) {}

	string getName() { return name; }
	Point getWhereToWrite() { return wheretoWrite; }
//	void writeIn(int x, int y);

protected:
	Point wheretoWrite;
	string name;
};


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
