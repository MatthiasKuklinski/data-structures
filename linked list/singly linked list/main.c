#include <sll.h>

#include <stdio.h>
#include <stdlib.h>

void sll_print(sll_node_t *sll_node)
{
    printf("%-32d%-32p%-32p\n", sll_node->element, sll_node, sll_node->next);
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
    status_code_t status_code = success;

    switch (cmd)
    {
    case 'q':
        sll_traverse(list, sll_print, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        sll_delete(&list, &status_code);
        list = sll_node(value, NULL, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'b':
        printf("Value:");
        scanf("%d", &value);
        sll_prepend(list, value, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'a':
        printf("Value:");
        scanf("%d", &value);
        sll_append(list, value, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'i':
        printf("Index:");
        scanf("%d", &index);
        printf("Value:");
        scanf("%d", &value);
        sll_insert(list, value, index, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'r':
        printf("Index:");
        scanf("%d", &index);
        sll_pop(&list, index, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 't':
        sll_pop_first(&list, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'z':
        sll_pop_last(&list, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'g':
        printf("Index:");
        scanf("%d", &index);
        printf("%d\n", sll_get(list, index, &status_code)->element);
        break;
    case 's':
        printf("Index:");
        scanf("%d", &index);
        printf("Value:");
        scanf("%d", &value);
        sll_set(list, index, value, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'o':
        sll_reverse(&list, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'l':
        printf("%d\n", sll_length(list, &status_code));
        printf("Status: %d\n", status_code);
        break;
    case 'd':
        sll_delete(&list, &status_code);
        printf("LIST: %p\n", list);
        printf("Status: %d\n", status_code);
        break;
    case 'm':
        menu();
        break;
    case 'x':
        sll_delete(&list, &status_code);
        printf("Status: %d\n", status_code);
        exit(0);
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