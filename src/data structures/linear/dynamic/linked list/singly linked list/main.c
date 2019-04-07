#include "./include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("--- Singly Linked List ---\n");
    printf("Menu(m)\n");
    printf("Create(c)\n");
    printf("Prepend(b)\n");
    printf("Append(a)\n");
    printf("Insert(i)\n");
    printf("Delete(d)\n");
    printf("Length(l)\n");
    printf("Print(p)\n");
    printf("Free(f)\n");
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
        break;
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        sll_free(list);
        list = sll_create(value, NULL);
        break;
    case 'b':
        printf("Value:");
        scanf("%d", &value);
        sll_prepend(list, value);
        break;
    case 'a':
        printf("Value:");
        scanf("%d", &value);
        sll_append(list, value);
        break;
    case 'i':
        printf("Value:");
        scanf("%d", &value);
        printf("Index:");
        scanf("%d", &index);
        sll_insert(list, value, index);
        break;
    case 'd':
        printf("Index:");
        scanf("%d", &value);
        sll_delete(list, value);
        break;
    case 'l':
        printf("%d\n", sll_length(list));
        break;
    case 'p':
        sll_traverse(list, sll_print);
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
        printf("Command:");
        scanf(" %c", &cmd);
        controller(cmd);
    }
}