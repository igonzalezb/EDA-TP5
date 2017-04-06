#include "events.h"

rrq:: rrq()
{
    ev = RRQ_;
}

wrq:: wrq()
{
    ev=WRQ_;
}

data:: data()
{
    ev=DATA_;
}

last_data:: last_data ()
{
    ev=LAST_DATA_;
}

ack::ack ()
{
    ev=ACK_;
}

last_ack::last_ack()
{
    ev=LAST_ACK_;
}

timeout::timeout()
{
    ev=TIMEOUT_;
}

error::error()
{
    ev=ERROR_;
}

exit::exit()
{
    ev=EXIT_;
}
