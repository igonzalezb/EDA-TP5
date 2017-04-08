#ifndef GENERIC_EVENT_H
#define GENERIC_EVENT_H


typedef enum tuvieja {ACK, LAST_ACK, DATA, LAST_DATA, TIMEOUT, ERROR, EXIT, EVENT_COUNT} event_t;


class GenericEvent
{
public:
	GenericEvent(int type) {ev=(event_t)type;}

	event_t type() { return ev; }

protected:
	event_t ev;

};



#endif //GENERIC_EVENT_H