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
    static stk_ary_t *stk_ary = NULL;

    switch (cmd)
    {
    case 'c':
        unsigned int capacity;
        printf("Capcity:");
        scanf("%d", &capacity);
        stk_ary = stk_ary(capacity);
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