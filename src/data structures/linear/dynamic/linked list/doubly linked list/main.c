#include <dll.h>

#include <stdio.h>
#include <stdlib.h>

void dll_print(dll_node_t *node)
{
    printf("%-32d%-32p%-32p%-32p\n", node->value, node, node->predecessor, node->successor);
}

void menu()
{
    printf("- Doubly Linked List -\n");
    printf("Print(p)\n");
    printf("Create(c)\n");
    printf("Prepend(b)\n");
    printf("Append(a)\n");
    printf("Insert(i)\n");
    printf("Length(l)\n");
    printf("Size(v)\n");
    printf("Destroy(d)\n");
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
    case 'm':
        menu();
        break;
    case 'p':
        dll_traverse(list, dll_print);
        break;
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        dll_destroy(list);
        list = dll_node(value, NULL, NULL);
        break;
    case 'b':
        printf("Value:");
        scanf("%d", &value);
        dll_prepend(list, value);
        break;
    case 'a':
        printf("Value:");
        scanf("%d", &value);
        dll_append(list, value);
        break;
    case 'i':
        printf("Index:");
        scanf("%d", &index);
        printf("Value:");
        scanf("%d", &value);
        dll_insert(list, value, index);
        break;
    case 'l':
        printf("%lu\n", dll_length(list));
        break;
    case 'v':
        printf("%lu\n", dll_size(list));
        break;
    case 'd':
        dll_destroy(list);
        break;
    case 'e':
        dll_destroy(list);
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