#include <dll.h>

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("--- Doubly Linked List ---\n");
    printf("Print(p)\n");
    printf("Construct(c)\n");
    printf("Destruct(d)\n");
    printf("Menu(m)\n");
    printf("Exit(e)\n");
}

void controller(const char cmd)
{
    int value;
    static dll_node_t *list = NULL;

    switch (cmd)
    {
    case 'm':
        menu();
        break;
    case 'p':
        dll_traverse(list, dll_print);
        break;
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        dll_destruct(list);
        list = dll_node(value, NULL, NULL);
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