#ifndef GENERIC_FSM
#define GENERIC_FSM


#include "GenericEvent.h"
#include "GenericState.h"

class GenericFSM
{
public:
	GenericFSM() {;};
	GenericFSM(GenericState * firstState) { currentState = firstState; };
	void dispach(GenericEvent& ev);
	~GenericFSM() { delete currentState ;};
	void setState(GenericState * state) {currentState = state;};
private:

protected:
	GenericState *currentState;

};


#endif //GENERIC_FSM
