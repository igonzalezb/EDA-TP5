#ifndef ClientStates_h
#define ClientStates_h

#include <stdio.h>
#include "GenericState.h"
#include "GenericEvent.h"
#include <string>


using namespace std;

class SimulationState : public GenericState
{
public:
    SimulationState(string name) {this->name = name;}
    
    
protected:
    string name;
};

// CLASES CON CADA ESTADO POSIBLE PARA EL CLIENTE 

/* Estado Reading 
 * El cliente hizo un RRQ. Cada metodo es una redefinicion de los metodos de GenericState.
 * Realizan la accion correspondiente a cada evento que se recibe. 
 */

class Reading : public SimulationState
{
public:
    Reading() : SimulationState ("Reading"){};
    
    virtual GenericState* onData (GenericEvent * ev);
    virtual GenericState* onLastData (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);
    virtual GenericState* onAck(GenericEvent * ev);
    virtual GenericState* onLastAck (GenericEvent * ev);
    
};

/* Estado Reading 
 * El cliente hizo un WRQ. Cada metodo es una redefinicion de los metodos de GenericState.
 * Realizan la accion correspondiente a cada evento que se recibe. 
 */

class Writing : public SimulationState
{
public:
    Writing() : SimulationState ("Writing"){};
    
    
    virtual GenericState* onAck(GenericEvent * ev);
    virtual GenericState* onLastAck (GenericEvent * ev);
    virtual GenericState* onTimeout(GenericEvent * ev);
    virtual GenericState* onError (GenericEvent * ev);
    virtual GenericState* onExit (GenericEvent * ev);
    virtual GenericState* onData (GenericEvent * ev);
    virtual GenericState* onLastData (GenericEvent * ev);
    
};
#endif /* ClientStates_h */
