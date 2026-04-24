#include <stdio.h>

#define LED_PIN 0

int i;

void loop() {
    for (i=0; i<50; i++);
}


int main(void){
    printf("LED toggle started on pin %d. \n", LED_PIN);

    while(1) {
        printf("LED 'ON' \n");
        loop();

        printf("LED 'OFF' \n");
        loop();
    }
    return 0;
}