#include <dll.h>

#include <stdio.h>
#include <stdlib.h>

void dll_print(dll_node_t *dll_node)
{
    if (!dll_node)
        return;

    printf("%-32d%-32p%-32p%-32p\n", dll_node->value, dll_node, dll_node->predecessor, dll_node->successor);
}

void menu()
{
    printf("- Doubly Linked List -\n");
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
    static dll_node_t *list = NULL;

    switch (cmd)
    {
    case 'q':
        printf("%-32s%-32s%-32s%-32s\n", "Value", "Memory Address", "Predecessor Memory Address", "Successor Memory Address");
        dll_traverse(list, dll_print);
        break;
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        dll_delete(list);
        list = dll_node(value, NULL, NULL);
        break;
    case 'b':
        printf("Value:");
        scanf("%d", &value);
        dll_prepend(list, value);
        dll_traverse(list, dll_print);
        break;
    case 'a':
        printf("Value:");
        scanf("%d", &value);
        dll_append(list, value);
        dll_traverse(list, dll_print);
        break;
    case 'i':
        printf("Index:");
        scanf("%d", &index);
        printf("Value:");
        scanf("%d", &value);
        dll_insert(list, value, index);
        break;
    case 'r':
        printf("Index:");
        scanf("%d", &index);
        dll_pop(list, index);
        break;
    case 't':
        dll_pop_first(&list);
        break;
    case 'z':
        dll_pop_last(list);
        break;
    case 'g':
        printf("Index:");
        scanf("%d", &index);
        dll_node_t *temp_node = dll_get(list, index);
        printf("%-32d%-32p%-32p%-32p\n", temp_node->value, temp_node, temp_node->predecessor, temp_node->successor);
        break;
    case 's':
        printf("Index:");
        scanf("%d", &index);
        printf("Value:");
        scanf("%d", &value);
        dll_set(list, index, value);
        break;
    case 'o':
        dll_reverse(&list);
        break;
    case 'l':
        printf("%lu\n", dll_length(list));
        break;
    case 'd':
        dll_delete(list);
        break;
    case 'm':
        menu();
        break;
    case 'e':
        dll_delete(list);
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