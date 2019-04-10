#include "./include/doubly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("--- Doubly Linked List ---\n");
    printf("Menu(m)\n");
    printf("Construct(c)\n");
    printf("Exit(e)\n");
}

void controller(const char cmd)
{
    int value;
    unsigned int index;
    static dll_node_t *list = NULL;

    switch (cmd)
    {
    case 'm':
        menu();
        break;
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        list = dll_construct(value, NULL, NULL);
        break;
    default:
        break;
    }
}

int main()
{
    char cmd;

    menu();
    while (1)
    {
        printf("Cmd:");
        scanf(" %s", &cmd);
        controller(cmd);
    }
}