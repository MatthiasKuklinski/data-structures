#include "./include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("--- Singly Linked List ---\n");
    printf("Menu(m)\n");
    printf("Create(c)\n");
    printf("Insert(i)\n");
    printf("Length(l)\n");
    printf("Print(p)\n");
    printf("Delete(d)\n");
    printf("Exit(e)\n");
}

void controller(const char cmd)
{
    int value, index;
    static node_t *list = NULL;

    switch (cmd)
    {
    case 'm':
        menu();
    case 'p':
        sll_traverse(list, sll_print);
        break;
    case 'l':
        sll_length(list);
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        // sll_delete(list);
        list = sll_create(value, NULL);
        break;
    case 'i':
        printf("Value:");
        scanf("%d", &value);
        printf("Index:");
        scanf("%d", &index);
        // sll_insert(list, value, index);
        break;
    case 'd':
        sll_delete(list);
        break;
    case 'e':
        sll_delete(list);
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
        printf("Command:");
        scanf("%c", &cmd);
        controller(cmd);
    }
}