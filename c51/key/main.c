/*
 */

#include <mcs51/8051.h>

void timer() __interrupt 1;

unsigned int counter;

void main(void) {
    P1_4 = 0;
    P1_3 = 1;
    P1_2 = 1;
    P1_1 = 1;
    P1_0 = 0;
    P0 = 0x00;
    // Insert code
    TMOD = 0x01;
    TH0 = 0xFC;
    TL0 = 0x67;
    TR0 = 1;
    ET0 = 1;
    EA = 1;
    while(1)
        ;
}

void timer() __interrupt 1 {
    TH0 = 0xFC;
    TL0 = 0x67;
    counter++;
    if(counter == 1000) {
        counter = 0;
        P0_0 = !P0_0;
    }
}
