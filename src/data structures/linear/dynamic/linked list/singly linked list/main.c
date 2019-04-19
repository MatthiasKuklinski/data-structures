#include <sll.h>

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("- Singly Linked List -\n");
    printf("Menu(m)\n");
    printf("Construct(c)\n");
    printf("Destruct(d)\n");
    printf("Prepend(b)\n");
    printf("Append(a)\n");
    printf("Insert(i)\n");
    printf("Pop(r)\n");
    printf("Pop first(t)\n");
    printf("Pop last(z)\n");
    printf("Get(g)\n");
    printf("Set(s)\n");
    printf("Length(l)\n");
    printf("Print(p)\n");
    printf("Reverse(v)");
    printf("Exit(e)\n");
}

void controller(const char cmd)
{
    int value;
    unsigned int index;
    static sll_node_t *list = NULL;

    switch (cmd)
    {
    case 'm':
        menu();
        break;
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        sll_delete(list);
        list = sll_node(value, NULL);
        break;
    case 'd':
        sll_delete(list);
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
        printf("Index:");
        scanf("%d", &index);
        printf("Value:");
        scanf("%d", &value);
        sll_insert(list, value, index);
        break;
    case 'r':
        printf("Index:");
        scanf("%d", &index);
        sll_pop(list, index);
        break;
    case 't':
        list = sll_pop_first(list);
        break;
    case 'z':
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
        sll_set(list, index, value);
        break;
    case 'l':
        printf("%d\n", sll_length(list));
        break;
    case 'p':
        sll_traverse(list, sll_print);
        break;
    case 'v':
        list = sll_reverse(list);
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
        printf("Cmd:");
        scanf(" %s", &cmd);
        controller(cmd);
    }
}