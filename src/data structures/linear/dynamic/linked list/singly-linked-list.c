#include "./include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("--- Singly Linked List ---\n");
    printf("Menu(m)\n");
    printf("Print(p)\n");
    printf("Create(c)\n");
    printf("Insert(i)\n");
    printf("Free(f)\n");
    printf("Exit(e)\n");
}

void controller(const char cmd)
{
    int user_input;
    static node *list = NULL;

    switch (cmd)
    {
    case 'm':
        menu();
    case 'p':
        sll_traverse(list, sll_print);
        break;
    case 'c':
        printf("Enter the data:");
        scanf("%d", &user_input);
        list = sll_create(user_input, NULL);
        break;

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
        printf("Enter a command:");
        scanf("%s", &cmd);
        controller(cmd);
    }
}