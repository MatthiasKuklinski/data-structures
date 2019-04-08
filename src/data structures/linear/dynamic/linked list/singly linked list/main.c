#include "./include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("--- Singly Linked List ---\n");
    printf("Menu(m)\n");
    printf("Construct(c)\n");
    printf("Destruct(d)\n");
    printf("Prepend(p)\n");
    printf("Append(a)\n");
    printf("Insert(i)\n");
    printf("Pop(pp)\n");
    printf("Pop first(ppf)\n");
    printf("Pop last(ppl)\n");
    printf("Get(g)\n");
    printf("Set(s)\n");
    printf("Length(l)\n");
    printf("Print(pt)\n");
    printf("Exit(e)\n");
}

void controller(const char cmd)
{
    int value;
    unsigned int index;
    static node_t *list = NULL;

    switch (cmd)
    {
    case 'm':
        menu();
        break;
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        sll_destruct(list);
        list = sll_construct(value, NULL);
        break;
    case 'd':
        sll_destruct(list);
        break;
    case 'p':
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
        printf("Index:");
        scanf("%d", &index);
        printf("Value:");
        scanf("%d", &value);
        sll_insert(list, value, index);
        break;
    case 'pp':
        scanf("%d", &index);
        sll_pop(list, index);
        break;
    case 'ppf':
        sll_pop_first(list);
        break;
    case 'ppl':
        sll_pop_last(list);
        break;
    case 'g':
        printf("Index:");
        scanf("%d", &index);
        printf("%p\n", sll_get(list, index));
        break;
    case 's':
        printf("Index:");
        scanf("%d", &index);
        printf("Value:");
        scanf("%d", &value);
        printf("%p\n", sll_set(list, index, value));
        break;
    case 'l':
        printf("%d\n", sll_length(list));
        break;
    case 'pt':
        sll_traverse(list, sll_print);
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
        scanf(" %s", &cmd);
        controller(cmd);
    }
}