#include <sys/types.h>
#include "ports.h"


int read_port_a()
{
   int some_value = 0x01;
   // use your h/w API to read port
   return some_value;
}

int read_port_b()
{
   int some_value = 0x02;
   // use your h/w API to read port
   return some_value;
}

int read_port_c()
{
   int some_value = 0x04;
   // use your h/w API to read port
   return some_value;
}
