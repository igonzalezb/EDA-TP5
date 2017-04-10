#include "GenericFSM.h"
#include "events.h"


void GenericFSM :: dispach(GenericEvent& ev)
{
	GenericState * newState = NULL;
	
	switch (ev.type()) {
		case DATA:
			newState = currentState->onData(&ev);
		break;

		case LAST_DATA:
			newState = currentState->onLastData(&ev);
		break;

		case ACK:
			newState = currentState->onAck(&ev);
		break;
				
		case LAST_ACK:
			newState = currentState->onLastAck(&ev);
		break;
				
		case TIMEOUT:
			newState = currentState->onTimeout(&ev);
		break;
				
		case ERROR:
			newState = currentState->onError(&ev);
		break;

		case EXIT:
			newState = currentState->onExit(&ev);
		break;
#if I_AM == SERVER
		case RRQ:
			newState = currentState->onRrq(&ev);
		break;

		case WRQ:
			newState = currentState->onWrq(&ev);
		break;
#endif
	}

	if (newState != NULL)
	{
		delete currentState;
		currentState = newState;
	}
}