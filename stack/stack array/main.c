#include <stk_ary.h>

#include <stdio.h>
#include <stdlib.h>

void stk_ary_print(int element)
{
    printf("%-32d%-32p\n", element, &element);
}

void menu()
{
    printf("- Stack(Array) -\n");
    printf("Print(q)\n");
    printf("Create(c)\n");
    printf("Push(p)\n");
    printf("Pop(r)\n");
    printf("Peek(g)\n");
    printf("Is empty(e)\n");
    printf("Is full(f)\n");
    printf("Delete(d)\n");
    printf("Menu(m)\n");
    printf("Exit(x)\n");
}

void controller(const char cmd)
{
    int value, capacity = 0;
    static stk_ary_t *stk = NULL;
    status_code_t status_code = success;

    switch (cmd)
    {
    case 'q':
        stk_ary_traverse(stk, stk_ary_print, &status_code);
        break;
    case 'c':
        printf("Capacity:");
        scanf("%d", &capacity);
        stk = stk_ary(capacity, &status_code);
        break;
    case 'p':
        printf("Value:");
        scanf("%d", &value);
        stk_ary_push(stk, value, &status_code);
        break;
    case 'r':
        stk_ary_pop(stk, &status_code);
        break;
    case 'g':
        printf("%d\n", stk_ary_peek(stk, &status_code));
        break;
    case 'e':
        printf("%d\n", stk_ary_is_empty(stk, &status_code));
        break;
    case 'f':
        printf("%d\n", stk_ary_is_full(stk, &status_code));
        break;
    case 'd':
        stk_ary_delete(&stk, &status_code);
        break;
    case 'm':
        menu();
        break;
    case 'x':
        stk_ary_delete(&stk, &status_code);
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