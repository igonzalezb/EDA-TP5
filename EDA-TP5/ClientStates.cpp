#include "ClientStates.h"

extern "C" {
#include "curses.h"
}
#include "events.h"


/* CLIENT: On state Reading, DATA event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al DATA event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */

GenericState* Reading :: onData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: store data, send ACK");
    
    return NULL;
}

/* CLIENT: On state Reading, LAST_DATA event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al LAST_DATA event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */
GenericState* Reading :: onLastData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: store data, send ACK, close file");
    
    return NULL;
}

/* CLIENT: On state Reading, TIMEOUT event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al TIMEOUT event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */

GenericState* Reading :: onTimeout(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: resend ACK");
    
    return NULL;
}

/* CLIENT: On state Reading, ERROR event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al ERROR event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */
GenericState* Reading :: onError (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: close file");
    
    return NULL;
}

/* CLIENT: On state Reading, EXIT event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al EXIT event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */
GenericState* Reading :: onExit (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: close file and shut down");
    
    return NULL;
}

/* CLIENT: On state Reading, ACK event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al ACK event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */

GenericState* Reading :: onAck(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}

/* CLIENT: On state Reading, LAST_ACK event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al LAST_ACK event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */

GenericState* Reading :: onLastAck (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Reading");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}


/* CLIENT: On state Writing, ACK event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al ACK event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */

GenericState* Writing :: onAck(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: send data");
    
    return NULL;
}

/* CLIENT: On state Writing, LAST_ACK event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al LAST_ACK event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */
GenericState* Writing :: onLastAck (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: close file");
    
    return NULL;
}

/* CLIENT: On state Writing, TIMEOUT event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al TIMEOUT event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */

GenericState* Writing :: onTimeout(GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: resend data");
    
    return NULL;
}

/* CLIENT: On state Writing, ERROR event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al ERROR event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */

GenericState* Writing :: onError (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: close file");
    
    return NULL;
}

/* CLIENT: On state Writing, EXIT event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al EXIT event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */
GenericState* Writing :: onExit (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: close file and shut down");
    
    return NULL;
}

/* CLIENT: On state Writing, DATA event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al DATA event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */
GenericState* Writing :: onData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
/* CLIENT: On state Writing, LAST_DATA event
 * Funcion que imprime en pantalla el Estado actual y la accion ejecutada
 * correspondiente al LAST_DATA event.
 *
 * Recibe: puntero a GenericEvent donde se encuentran almacenadas las 
 * coordenadas en donde escribir.
 *
 * Devuelve un puntero al estado siguiente, si este no se modifica, 
 * devuelve NULL.
 */
GenericState* Writing :: onLastData (GenericEvent * event)
{
    SimulationEvent * ev = (SimulationEvent *)event;
    Point p = ev->getWhereToWrite();
    
    move((unsigned int)p.getX(), (unsigned int)p.getY());
    printw("Estado = Writing");
    
    move((unsigned int)p.getX()+3, (unsigned int)p.getY());
    printw("Accion ejecutada: N/A");
    
    return NULL;
}
