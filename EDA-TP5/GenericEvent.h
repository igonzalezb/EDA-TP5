#ifndef GENERIC_EVENT_H
#define GENERIC_EVENT_H

/* Switch de compilacion, dependiendo si soy el server o el cliente incluyo
 * server.h o client.h respectivamente 
 */

#define	CLIENT	1	
#define SERVER	0

#define I_AM	CLIENT

#if I_AM == CLIENT
#include "client.h"
#elif I_AM == SERVER
#include "server.h"
#else
#error	"This program must emulate either a CLIENT or a SERVER in a TFTP connection"
#endif


// Base de un evento
class genericEvent
{
public:
	event_t type() // devuelve el tipo de evento que es 
	{
		return ev;
	}
protected:
	event_t ev; //tipo de evento

private:

};


#endif //GENERIC_EVENT_H
