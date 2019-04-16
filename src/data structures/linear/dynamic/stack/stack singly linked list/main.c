#include <stk_sll.h>

#include <stdio.h>
#include <stdlib.h>

void stk_sll_print(stk_sll_node_t *stk_sll_node)
{
    printf("%d\n", stk_sll_node->value);
}

void menu()
{
    printf("- Stack(Singly Linked List) -\n");
    printf("Print(q)\n");
    printf("Create(c)\n");
    printf("Push(p)\n");
    printf("Pop(r)\n");
    printf("Empty(q)\n");
    printf("Delete(d)\n");
    printf("Menu(m)\n");
    printf("Exit(x)\n");
}

void controller(const char cmd)
{
    int value;
    static stk_sll_node_t *stk = NULL;

    switch (cmd)
    {
    case 'q':
        stk_sll_traverse(stk, stk_sll_print);
        break;
    case 'c':
        printf("Value:");
        scanf("%d", &value);
        stk = stk_sll(value, NULL);
        break;
    case 'p':
        printf("Value:");
        scanf("%d", &value);
        stk_sll_push(stk, value);
        stk_sll_traverse(stk, stk_sll_print);
        break;
    case 'r':
        stk_sll_pop(stk);
        stk_sll_traverse(stk, stk_sll_print);
        break;
    case 'd':
        stk_sll_delete(stk);
        break;
    case 'm':
        menu();
        break;
    case 'x':
        stk_sll_delete(stk);
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