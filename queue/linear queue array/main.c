#include <lin_que_ary.h>

#include <stdio.h>
#include <stdlib.h>

void lin_que_ary_print(int **element)
{
    printf("%-32d%-32p\n", **element, *element);
}

void menu()
{
    printf("- Queue(Array) -\n");
    printf("Print(q)\n");
    printf("Create(c)\n");
    printf("Enqueue(p)\n");
    printf("Dequeue(r)\n");
    printf("Peek(g)\n");
    printf("Empty(e)\n");
    printf("Full(f)\n");
    printf("dealloc(d)\n");
    printf("Menu(m)\n");
    printf("Exit(x)\n");
}

void controller(const char cmd)
{
    int element = 0;
    long capacity = 0;
    static lin_que_ary_t *que = NULL;

    switch (cmd)
    {
    case 'q':
        lin_que_ary_traverse(que, lin_que_ary_print);
        break;
    case 'c':
        printf("Capacity:");
        scanf("%li", &capacity);
        que = lin_que_ary_alloc(capacity);
        break;
    case 'p':
        printf("Element:");
        scanf("%d", &element);
        lin_que_ary_enqueue(que, element);
        break;
    case 'r':
        lin_que_ary_dequeue(que);
        break;
    case 'g':
        printf("%d\n", lin_que_ary_peek(que));
        break;
    case 'e':
        printf("%d\n", lin_que_ary_is_empty(que));
        break;
    case 'f':
        printf("%d\n", lin_que_ary_is_full(que));
        break;
    case 'd':
        lin_que_ary_dealloc(&que);
        break;
    case 'm':
        menu();
        break;
    case 'x':
        lin_que_ary_dealloc(&que);
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