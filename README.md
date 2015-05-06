GENERIC DEBOUNCING ALGORITHM
----------------------------

The project implements a simple and generic debouncing algorithm that verifies that
a received signal is an interrupt and not some electrical noise.

The ports.h will behave as a wrapper on top of your hardware API. You need to use
your hardware provided APIs to read and write data from ports.