#include <stdio.h>
#include <stdlib.h>

#define BUTTON_PIN 1

int read_button(void) {
    return (rand() % 2);
}

int main(void) {
    printf("Button monitoring started on pin %d. \n", BUTTON_PIN);

    while (1) {
        int state = read_button();
        printf("Button state: %s\n", state ? "Pressed" : "Released");
        for (volatile int i = 0; i < 500000; i++);
    }
    return 0;
}