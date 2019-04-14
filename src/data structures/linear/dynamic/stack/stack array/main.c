#include <stk_ary.h>

#include <stdio.h>
#include <stdlib.h>

void stk_ary_print(stk_ary_t *stk_ary)
{
    int n = stk_ary->top;
    
    while (n >= 0)
    {
        printf("%-32d%-32p\n", stk_ary->array[n], &stk_ary->array[n--]);
    }
}

void menu()
{
    printf("- Stack(Array) -\n");
    printf("Print(x)\n");
    printf("Create(c)\n");
    printf("Push(p)\n");
    printf("Menu(m)\n");
    printf("Exit(e)\n");
}

void controller(const char cmd)
{
    int value;
    unsigned int capacity;
    static stk_ary_t *stk = NULL;

    switch (cmd)
    {
    case 'x':
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
    case 'm':
        menu();
        break;
    case 'e':
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