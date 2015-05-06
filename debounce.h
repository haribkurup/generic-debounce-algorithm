#ifndef __DEBOUNCE_H_
#define __DEBOUNCE_H_

#define DEBOUNCE_COUNT              2
#define DEBOUNCE_TIME_MILLI_SEC     10
#define DEBOUNCE_TIME_MICRO_SEC     DEBOUNCE_TIME_MILLI_SEC * 1000

int debounce(int port_address, int pin_number);

#endif