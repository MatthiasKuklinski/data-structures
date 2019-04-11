#include <dll.h>

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("- Doubly Linked List -\n");
    printf("Print(p)\n");
    printf("Create(c)\n");
    printf("Prepend(b)\n");
    printf("Append(a)\n");
    printf("Length(l)\n");
    printf("Destroy(d)\n");
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
    case 'l':
        printf("%lu\n", dll_length(list));
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