#include <que_ary.h>

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("- Queue(Array) -\n");
    printf("Create(c)\n");
    printf("Menu(m)\n");
    printf("Exit(x)\n");
}

void controller(const char cmd)
{
    int value;
    unsigned int capacity;
    static que_ary_t *stk = NULL;

    switch (cmd)
    {
    case 'c':
        printf("Capacity:");
        scanf("%d", &capacity);
        stk = que_ary(capacity);
        break;
    case 'm':
        menu();
        break;
    case 'x':
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