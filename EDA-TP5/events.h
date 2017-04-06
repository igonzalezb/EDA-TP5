
#ifndef events_h
#define events_h


#include <stdio.h>
#include "GenericEvent.h"

class rrq: public GenericEvent
{
    public:
        rrq ();
};

class wrq: public GenericEvent
{
    public:
        wrq ();
};

class data: public GenericEvent
{
    public:
        data ();
};

class last_data: public GenericEvent
{
public:
    last_data();
};


class ack: public GenericEvent
{
public:
    ack();
};

class last_ack: public GenericEvent
{
public:
    last_ack();
};

class timeout: public GenericEvent
{
    timeout();
};

class error: public GenericEvent
{
public:
    error();
};

class exit: public GenericEvent
{
public:
    exit();
};


#endif /* events_h */
