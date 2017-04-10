#ifndef CLIENT_H
#define CLIENT_H

#include "GenericEvent.h"

//eventos:


//teclas correspondientes a cada evento:
#define ACK_K		'a'
#define LAST_ACK_K	'l'
#define DATA_K		'd'
#define LAST_DATA_K	'b'
#define TIMEOUT_K	't'
#define ERROR_K		'e'
#define EXIT_K		'q'


GenericEvent * eventGenerator();


#endif //CLIENT_H