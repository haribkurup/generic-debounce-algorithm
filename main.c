#include <stdio.h>
#include "ports.h"
#include "debounce.h"


/* Dummy gpio_select */
static int gpio_select(int gpio)
{
   sleep(5);
   return 1;
}

int main()
{

   int rc;

   // enable interrupts
   // set direction (rising edge / falling edge)

   while(1)
   {

      /* Use your function that catches interrupt instead of gpio_select() */
      if (gpio_select(IRQ5))
      {

         // turn off interrupt before debouncing

         rc = debounce(PORT_A, 0);

         if (rc)
         {
            // signal is valid - not noise
            // do your stuff here
            printf("Interrupt received.\n");
         }

         // turn on interrupt again
      }
   }

}