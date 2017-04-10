#include "events.h"


#if I_AM == SERVER
rrq:: rrq()
{
    ev = RRQ;
}

wrq:: wrq()
{
    ev=WRQ;
}
#endif


data:: data()
{
    ev=DATA;
}

last_data:: last_data ()
{
    ev=LAST_DATA;
}

ack::ack ()
{
    ev=ACK;
}

last_ack::last_ack()
{
    ev=LAST_ACK;
}

timeout::timeout()
{
    ev=TIMEOUT;
}

error::error()
{
    ev=ERROR;
}

exit::exit()
{
    ev=EXIT;
}
