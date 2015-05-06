#ifndef __PORTS_H_
#define __PORTS_H_

/* Port address definitions - change as per your h/w specification */

#define BASE_ADDRESS    0x00008000
#define PORT_OFFSET     0x100

#define PORT_A    (BASE_ADDRESS + PORT_OFFSET + 0x5)
#define PORT_B    (BASE_ADDRESS + PORT_OFFSET + 0x6)
#define PORT_C    (BASE_ADDRESS + PORT_OFFSET + 0x7)

#define IRQ5      241
#define IRQ6      129

int read_port_a();
int read_port_b();
int read_port_c();


#endif