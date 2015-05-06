#include "debounce.h"
#include "ports.h"

#define BIT(N) (1<<(N))

/* Prototype declaration */
static int get_sample_reading(int port_address, int pin_number);



/*****************************************************************************
 
 debounce:
 
 Samples a pin of particular port when an interrupt occurs and
 checks that it is actually an interrupt and not some electrical
 noise.

*****************************************************************************/

int debounce(int port_address, int pin_number)
{

   int level[DEBOUNCE_COUNT];
   int not_noise = 1;
   int i;

   usleep(DEBOUNCE_TIME_MICRO_SEC);
   level[0] = get_sample_reading(port_address, pin_number);

   for (i = 1; i < DEBOUNCE_COUNT; i++)
   {
      usleep(DEBOUNCE_TIME_MICRO_SEC); // don't sleep after last reading
      level[i] = get_sample_reading(port_address, pin_number);
   }

   for (i = 0; i < DEBOUNCE_COUNT - 1; i++)
   {
      if (level[i] != level[i + 1] || level[i] == -1)
      {
         not_noise = 0;
      }
   }

   return not_noise;

}


/*****************************************************************************

get_sample_reading:

Reads the state of specified pin and port and returns it.

*****************************************************************************/

static int get_sample_reading(int port_address, int pin_number)
{
   switch (port_address)
   {
   case PORT_A:
      return (BIT(pin_number) & read_port_a());
      break;

   case PORT_B:
      return (BIT(pin_number) & read_port_b());
      break;

   case PORT_C:
      return (BIT(pin_number) & read_port_c());
      break;

   default:
      return -1;
   }
}
