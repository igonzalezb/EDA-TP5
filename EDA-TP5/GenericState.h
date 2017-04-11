#ifndef GenericState_h
#define GenericState_h

#include <cstdio>
#include "GenericEvent.h"

/* Base de un estado de la FSM. Se declaran funciones por default para cada posible evento
 * que pueda aparecer en cada estado. Cada funcion recibe un puntero a un objeto de la clase
 * GenericEvent y devuelve un puntero a un objeto de la clase GenericState.
 */
 
class GenericState
{
public:
	virtual GenericState* onRrq (GenericEvent * ev) {return NULL;}
    virtual GenericState* onWrq (GenericEvent * ev) {return NULL;}
    virtual GenericState* onData (GenericEvent * ev) {return NULL;}
    virtual GenericState* onLastData (GenericEvent * ev) {return NULL;}
    virtual GenericState* onAck(GenericEvent * ev) {return NULL;}
    virtual GenericState* onLastAck (GenericEvent * ev) {return NULL;}
    virtual GenericState* onTimeout(GenericEvent * ev) {return NULL;}
    virtual GenericState* onError (GenericEvent * ev) {return NULL;}
    virtual GenericState* onExit (GenericEvent * ev) {return NULL;}
    
};


#endif /* GenericState_h */
