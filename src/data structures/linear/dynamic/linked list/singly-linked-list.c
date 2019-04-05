#include "./include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("--- Singly Linked List ---\n");
    printf("0. Show Menu");
    printf("1. Print\n");
    printf("2. Create\n");
}

void controller(unsigned short cmd)
{
    int user_input;
    static node *list = NULL;

    switch (cmd)
    {
    case 1:
        sll_traverse(list, sll_print);
        break;
    case 2:
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
    unsigned short cmd = 0;

    menu();
    while (1)
    {
        printf("Enter a command:");
        scanf("%hu", &cmd);
        controller(cmd);
    }
}