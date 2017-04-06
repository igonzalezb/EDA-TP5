#ifndef GenericState_h
#define GenericState_h

#include <stdio.h>



typedef enum {a} StateType;

class GenericState
{
public:
    virtual GenericState* onRrq ();
    virtual GenericState* onWrq ();
    virtual GenericState* onData ();
    virtual GenericState* onLastData ();
    virtual GenericState* onAck();
    virtual GenericState* onLastAck ();
    virtual GenericState* onTimeout();
    virtual GenericState* onError ();
    virtual GenericState* onExit ();
    
protected:
    StateType state; // no se que poner en el enum
    

};


#endif /* GenericState_h */
