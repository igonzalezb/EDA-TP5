
#ifndef events_h
#define events_h


#include <stdio.h>
#include "GenericEvent.h"

// SE CREA UNA CLASE PARA CADA EVENTO

/* Evento RRQ
 * Se llama a su contructor cada vez que se genera un evento de este tipo,
 * donde setea que el tipo de evento es RRQ para luego poder reconocerlo.
 */

class rrq: public GenericEvent
{
    public:
        rrq ();//Constructor
};


/* Evento WRQ
 * Se llama a su contructor cada vez que se genera un evento de este tipo,
 * donde setea que el tipo de evento es WRQ para luego poder reconocerlo.
 */

class wrq: public GenericEvent
{
    public:
        wrq ();//Constructor
};

/* Evento DATA
 * Se llama a su contructor cada vez que se genera un evento de este tipo,
 * donde setea que el tipo de evento es DATA para luego poder reconocerlo.
 */
class data: public GenericEvent
{
    public:
        data ();//Constructor
};

/* Evento LAST_DATA
 * Se llama a su contructor cada vez que se genera un evento de este tipo,
 * donde setea que el tipo de evento es LAST_DATA para luego poder reconocerlo.
 */

class last_data: public GenericEvent
{
public:
    last_data();//Constructor
};

/* Evento ACK
 * Se llama a su contructor cada vez que se genera un evento de este tipo,
 * donde setea que el tipo de evento es ACK para luego poder reconocerlo.
 */

class ack: public GenericEvent
{
public:
    ack();//Constructor
};

/* Evento LAST_ACK
 * Se llama a su contructor cada vez que se genera un evento de este tipo,
 * donde setea que el tipo de evento es LAST_ACK para luego poder reconocerlo.
 */

class last_ack: public GenericEvent
{
public:
    last_ack();//Constructor
};

/* Evento TIMEOUT
 * Se llama a su contructor cada vez que se genera un evento de este tipo,
 * donde setea que el tipo de evento es TIMEOUT para luego poder reconocerlo.
 */

class timeout: public GenericEvent
{
    timeout();//Constructor
};

/* Evento ERROR
 * Se llama a su contructor cada vez que se genera un evento de este tipo,
 * donde setea que el tipo de evento es ERROR para luego poder reconocerlo.
 */

class error: public GenericEvent
{
public:
    error();//Constructor
};

/* Evento EXIT
 * Se llama a su contructor cada vez que se genera un evento de este tipo,
 * donde setea que el tipo de evento es EXIT para luego poder reconocerlo.
 */

class exit: public GenericEvent
{
public:
    exit();//Constructor
};


#endif /* events_h */
