#ifndef GENERIC_EVENT_H
#define GENERIC_EVENT_H


#include <cstdint>



class GenericEvent
{
public:
	GenericEvent(int type) {ev=(uint32_t)type;};

	uint32_t type() { return ev; };

protected:
	uint32_t ev;

};



#endif //GENERIC_EVENT_H