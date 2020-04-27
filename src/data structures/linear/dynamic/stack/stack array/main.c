#include <stk_ary.h>

#include <stdio.h>
#include <stdlib.h>

void stk_ary_print(stk_ary_t *stk_ary)
{
    if (!stk_ary)
        return;

    printf("%-32s%-32s\n", "Top Index", "Capacity");
    printf("%-32d%-32d\n\n", stk_ary->i, stk_ary->capacity);
    printf("%-32s%-32s\n", "Element", "Memory Address");
    for (int i = stk_ary->i; i > -1; --i)
        printf("%-32d%-32p\n", stk_ary->elements[i], &stk_ary->elements[i]);
}

void menu()
{
    printf("- Stack(Array) -\n");
    printf("Print(q)\n");
    printf("Create(c)\n");
    printf("Push(p)\n");
    printf("Pop(r)\n");
    printf("Peek(g)\n");
    printf("Empty(e)\n");
    printf("Full(f)\n");
    printf("Delete(d)\n");
    printf("Menu(m)\n");
    printf("Exit(x)\n");
}

void controller(const char cmd)
{
    int value;
    unsigned int capacity;
    static stk_ary_t *stk = NULL;

    switch (cmd)
    {
    case 'q':
        stk_ary_print(stk);
        break;
    case 'c':
        printf("Capacity:");
        scanf("%d", &capacity);
        stk = stk_ary(capacity);
        break;
    case 'p':
        printf("Value:");
        scanf("%d", &value);
        stk_ary_push(stk, value);
        stk_ary_print(stk);
        break;
    case 'r':
        stk_ary_pop(stk);
        stk_ary_print(stk);
        break;
    case 'g':
        printf("%d\n", stk_ary_peek(stk));
        break;
    case 'e':
        printf("%d\n", stk_ary_is_empty(stk));
        break;
    case 'f':
        printf("%d\n", stk_ary_is_full(stk));
        break;
    case 'd':
        stk_ary_delete(&stk);
        break;
    case 'm':
        menu();
        break;
    case 'x':
        stk_ary_delete(&stk);
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