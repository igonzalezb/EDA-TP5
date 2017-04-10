#ifndef GenericState_h
#define GenericState_h

#include <cstdio>
#include "GenericEvent.h"




class GenericState
{
public:
	virtual GenericState* onRrq (GenericEvent * ev) {return NULL;};
    virtual GenericState* onWrq (GenericEvent * ev) {return NULL;};
    virtual GenericState* onData (GenericEvent * ev) {return NULL;};
    virtual GenericState* onLastData (GenericEvent * ev) {return NULL;};
    virtual GenericState* onAck(GenericEvent * ev) {return NULL;};
    virtual GenericState* onLastAck (GenericEvent * ev) {return NULL;};
    virtual GenericState* onTimeout(GenericEvent * ev) {return NULL;};
    virtual GenericState* onError (GenericEvent * ev) {return NULL;};
    virtual GenericState* onExit (GenericEvent * ev) {return NULL;};
    


};


#endif /* GenericState_h */
