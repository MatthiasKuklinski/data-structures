#include <sll.h>

#include <stdio.h>
#include <stdlib.h>

void sll_print(sll_node_t *sll_node)
{
    if (!sll_node)
        return;

    printf("%-32d%-32p%-32p\n", sll_node->value, sll_node, sll_node->successor);
}

void menu()
{
    printf("- Singly Linked List -\n");
    printf("Print(q)\n");
    printf("Create(c)\n");
    printf("Prepend(b)\n");
    printf("Append(a)\n");
    printf("Insert(i)\n");
    printf("Pop(r)\n");
    printf("Pop first(t)\n");
    printf("Pop last(z)\n");
    printf("Get(g)\n");
    printf("Set(s)\n");
    printf("Reverse(o)\n");
    printf("Length(l)\n");
    printf("Delete(d)\n");
    printf("Menu(m)\n");
    printf("Exit(e)\n");
}

void controller(const char cmd)
{
    int value;
    unsigned int index;
    static sll_node_t *list = NULL;

    switch (cmd)
    {
    case 'q':
        printf("%-32s%-32s%-32s\n", "Value", "Memory Address", "Successor Memory Address");
        sll_traverse(list, sll_print);
        break;
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        sll_delete(list);
        list = sll_node(value, NULL);
        break;
    case 'b':
        printf("Value:");
        scanf("%d", &value);
        sll_prepend(list, value);
        sll_traverse(list, sll_print);
        break;
    case 'a':
        printf("Value:");
        scanf("%d", &value);
        sll_append(list, value);
        sll_traverse(list, sll_print);
        break;
    case 'i':
        printf("Index:");
        scanf("%d", &index);
        printf("Value:");
        scanf("%d", &value);
        sll_insert(list, value, index);
        sll_traverse(list, sll_print);
        break;
    case 'r':
        printf("Index:");
        scanf("%d", &index);
        sll_pop(list, index);
        sll_traverse(list, sll_print);
        break;
    case 't':
        sll_pop_first(&list);
        sll_traverse(list, sll_print);
        break;
    case 'z':
        sll_pop_last(list);
        sll_traverse(list, sll_print);
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
        sll_traverse(list, sll_print);
        break;
    case 'o':
        sll_reverse(&list);
        sll_traverse(list, sll_print);
        break;
    case 'l':
        printf("%d\n", sll_length(list));
        break;
    case 'd':
        sll_delete(list);
        break;
    case 'm':
        menu();
        break;
    case 'x':
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