#include <stk_ary.h>

#include <stdio.h>
#include <stdlib.h>

void stk_ary_print(int **element)
{
    printf("%-32d%-32p\n", **element, *element);
}

void menu()
{
    printf("- Stack (Array) -\n");
    printf("Print(q)\n");
    printf("Allocate(a)\n");
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
    int element = 0;
    long capacity = 0;
    static stk_ary_t *stk = NULL;

    switch (cmd)
    {
    case 'q':
        stk_ary_traverse(stk, stk_ary_print);
        break;
    case 'a':
        printf("Capacity:");
        scanf("%li", &capacity);
        stk = stk_ary_alloc(capacity);
        break;
    case 'p':
        printf("Element:");
        scanf("%d", &element);
        stk_ary_push(stk, element);
        break;
    case 'r':
        stk_ary_pop(stk);
        break;
    case 'g':
        printf("%d", stk_ary_peek(stk));
        break;
    case 'e':
        printf("%hu\n", stk_ary_is_empty(stk));
        break;
    case 'f':
        printf("%hu\n", stk_ary_is_full(stk));
        break;
    case 'd':
        stk_ary_dealloc(&stk);
        break;
    case 'm':
        menu();
        break;
    case 'x':
        stk_ary_dealloc(&stk);
        exit(0);
    default:
        break;
    }
}

int main()
{
    char cmd = '\0';

    menu();
    while (1)
    {
        printf("Cmd:");
        scanf("%s", &cmd);
        controller(cmd);
    }
}