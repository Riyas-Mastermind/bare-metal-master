#include <stdio.h>
#define LED_PIN 0

void delay_one_sec(void) {
    volatile unsigned long i;
    for (i = 0; i < 1000000UL; i++); 
}

int main(void){
    printf("LED toggle started on pin %d, \n", LED_PIN);

    while(1){
        printf("LED 'ON'\n");
        delay_one_sec();

        printf("LED 'OFF'\n");
        delay_one_sec();
    }
    return 0;
}