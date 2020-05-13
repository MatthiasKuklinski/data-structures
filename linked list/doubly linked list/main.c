#include <dll.h>

#include <stdio.h>
#include <stdlib.h>

void dll_print(dll_node_t **dll_node)
{
    printf("%-32zu%-32p%-32p%-32p\n", (*dll_node)->element, (*dll_node), (*dll_node)->prev, (*dll_node)->next);
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
    static dll_node_t *list = NULL;

    switch (cmd)
    {
    case 'q':
        dll_traverse(&list, dll_print);
        break;
    case 'c':
        printf("Element:");
        scanf("%zu", &element);
        dll_dealloc(&list);
        list = dll_node_alloc(element, NULL, NULL);
        break;
    case 'b':
        printf("Element:");
        scanf("%zu", &element);
        dll_prepend(list, element);
        break;
    case 'a':
        printf("Element:");
        scanf("%zu", &element);
        dll_append(list, element);
        break;
    case 'i':
        printf("Index:");
        scanf("%zu", &index);
        printf("Element:");
        scanf("%zu", &element);
        dll_insert(list, element, index);
        break;
    case 'r':
        printf("Index:");
        scanf("%zu", &index);
        dll_pop(&list, index);
        break;
    case 't':
        dll_pop_first(&list);
        break;
    case 'z':
        dll_pop_last(&list);
        break;
    case 'g':
        printf("Index:");
        scanf("%zu", &index);
        printf("%zu\n", dll_get(list, index)->element);
        break;
    case 's':
        printf("Index:");
        scanf("%zu", &index);
        printf("Element:");
        scanf("%zu", &element);
        dll_set(list, index, element);
        break;
    case 'o':
        dll_reverse(&list);
        break;
    case 'l':
        printf("%zu\n", dll_length(list));
        break;
    case 'd':
        dll_dealloc(&list);
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