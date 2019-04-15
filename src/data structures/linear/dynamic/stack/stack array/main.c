#include <stk_ary.h>

#include <stdio.h>
#include <stdlib.h>

void stk_ary_print(stk_ary_t *stk_ary)
{
    if (!stk_ary)
        return;

    printf("%-32s%-32s\n", "Top", "Capacity");
    printf("%-32d%-32d\n\n", stk_ary->top, stk_ary->capacity);
    printf("%-32s%-32s\n", "Item", "Memory Address");
    for (int i = stk_ary->top; i > -1; --i)
        printf("%-32d%-32p\n", stk_ary->items[i], &stk_ary->items[i]);
}

void menu()
{
    printf("- Stack(Array) -\n");
    printf("Print(q)\n");
    printf("Create(c)\n");
    printf("Push(p)\n");
    printf("Pop(r)\n");
    printf("Empty(q)\n");
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
    case 'e':
        printf("%d\n", stk_ary_empty(stk));
        break;
    case 'f':
        printf("%d\n", stk_ary_full(stk));
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