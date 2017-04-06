#ifndef GenericState_h
#define GenericState_h

#include <stdio.h>
#include "GenericEvent.h"


typedef enum {a} StateType;

class GenericState
{
public:
    virtual GenericState* onRrq (GenericEvent * ev);
    virtual GenericState* onWrq (GenericEvent * ev);
    virtual GenericState* onData (GenericEvent * ev);
    virtual GenericState* onLastData (GenericEvent * ev);
    virtual GenericState* onAck(GenericEvent * ev);
    virtual GenericState* onLastAck (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);
    
protected:
    StateType state; // no se que poner en el enum
    

};


#endif /* GenericState_h */
