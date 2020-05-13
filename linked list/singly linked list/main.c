#include <stdio.h>

#include "sll.h"

void sll_print(sll_node_t **sll_node)
{
    printf("%-32d%-32p%-32p\n", (*sll_node)->element, (*sll_node), (*sll_node)->next);
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
    size_t index, element;
    static sll_node_t *list = NULL;

    switch (cmd)
    {
    case 'q':
        sll_traverse(&list, sll_print);
        break;
    case 'c':
        printf("Element:");
        scanf("%zu", &element);
        sll_dealloc(&list);
        list = sll_node_alloc(element, NULL);
        break;
    case 'b':
        printf("Element:");
        scanf("%zu", &element);
        sll_prepend(list, element);
        break;
    case 'a':
        printf("Element:");
        scanf("%zu", &element);
        sll_append(list, element);
        break;
    case 'i':
        printf("Index:");
        scanf("%zu", &index);
        printf("Element:");
        scanf("%zu", &element);
        sll_insert(list, element, index);
        break;
    case 'r':
        printf("Index:");
        scanf("%zu", &index);
        sll_pop(&list, index);
        break;
    case 't':
        sll_pop_first(&list);
        break;
    case 'z':
        sll_pop_last(&list);
        break;
    case 'g':
        printf("Index:");
        scanf("%zu", &index);
        printf("%d\n", sll_get(list, index)->element);
        break;
    case 's':
        printf("Index:");
        scanf("%zu", &index);
        printf("Element:");
        scanf("%zu", &element);
        sll_set(list, index, element);
        break;
    case 'o':
        sll_reverse(&list);
        break;
    case 'l':
        printf("%zu\n", sll_length(list));
        break;
    case 'd':
        sll_dealloc(&list);
        break;
    case 'm':
        menu();
        break;
    case 'x':
        exit(0);
        break;
    default:
        break;
    }
}

int main()
{
    char cmd = '\0';

    menu();
    while (1)
    {
        printf("Cmd:");
        scanf("%s", &cmd);
        controller(cmd);
    }
}