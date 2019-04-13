#include <stk_array.h>

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("- Stack -\n");
    printf("Menu(m)\n");
    printf("Exit(e)\n");
}

void controller(const char cmd)
{
    int value;

    switch (cmd)
    {
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