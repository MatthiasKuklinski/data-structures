#include "./include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("--- Singly Linked List ---\n");
    printf("Menu(m)\n");
    printf("Print(p)\n");
    printf("Create(c)\n");
    printf("Insert(i)\n");
    printf("Free(f)\n");
    printf("Exit(e)\n");
}

void controller(const char cmd)
{
    int value, index;
    static node *list = NULL;

    switch (cmd)
    {
    case 'm':
        menu();
    case 'p':
        sll_traverse(list, sll_print);
        break;
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        sll_free(list);
        list = sll_create(value, NULL);
        break;
    case 'i':
        printf("Value:");
        scanf("%d", &value);
        printf("Index:");
        scanf("%d", &index);
        if (index < sll_length(list))
            sll_insert(list, value, index);
        break;
    case 'f':
        sll_free(list);
        break;
    case 'e':
        sll_free(list);
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
        printf("Enter a command:");
        scanf("%c", &cmd);
        controller(cmd);
    }
}