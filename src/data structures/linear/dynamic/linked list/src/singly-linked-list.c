#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("--- C Linked List Demonstration --- \n\n");
    printf("1. Create a singly linked list\n");
}

void controller(unsigned short cmd) {
    switch (cmd)
    {
        case 1:
            printf("Executing code...\n");
            break;
    
        default:
            break;
    }
}

int main() {
    unsigned short cmd = 0;

    menu();
    while(1) {
        printf("Enter a command:");
        scanf("%hu", &cmd);
        controller(cmd);
    }
}