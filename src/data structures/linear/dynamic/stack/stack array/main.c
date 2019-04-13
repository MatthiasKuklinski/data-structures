#include <stk_ary.h>

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("- stk_ary -\n");
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
    case 'c':
        printf("Capcity:");
        scanf("%d", &capacity);
        stk = stk_ary(capacity);
    case 'p':
        printf("Value:");
        scanf("%d", &value);
        stk_ary_push(stk, value);
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