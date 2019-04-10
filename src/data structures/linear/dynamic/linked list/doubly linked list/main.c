#include "./include/doubly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("--- Doubly Linked List ---\n");
    printf("Menu(m)\n");
    printf("Construct(c)\n");
    printf("Destruct(d)\n");
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
        dll_destruct(list);
        list = dll_construct(value, NULL, NULL);
        break;
    case 'd':
        dll_destruct(list);
        break;
    case 'e':
        dll_destruct(list);
        exit(0);
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