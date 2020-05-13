#include <cir_que_ary.h>

#include <stdio.h>
#include <stdlib.h>

void cir_que_ary_print(int *element)
{
    printf("%-32d%-32p\n", *element, element);
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
    int value, capacity = 0;
    static cir_que_ary_t *que = NULL;
    status_t status = success;

    switch (cmd)
    {
    case 'q':
        cir_que_ary_traverse(que, cir_que_ary_print, &status);
        printf("Status: %d\n", status);
        break;
    case 'c':
        printf("Capacity:");
        scanf("%d", &capacity);
        que = cir_que_ary_alloc(capacity, &status);
        printf("Status: %d\n", status);
        break;
    case 'p':
        printf("Value:");
        scanf("%d", &value);
        cir_que_ary_enqueue(que, value, &status);
        printf("Status: %d\n", status);
        break;
    case 'r':
        cir_que_ary_dequeue(que, &status);
        printf("Status: %d\n", status);
        break;
    case 'g':
        printf("%d\n", cir_que_ary_peek(que, &status));
        printf("Status: %d\n", status);
        break;
    case 'e':
        printf("%d\n", cir_que_ary_is_empty(que, &status));
        printf("Status: %d\n", status);
        break;
    case 'f':
        printf("%d\n", cir_que_ary_is_full(que, &status));
        printf("Status: %d\n", status);
        break;
    case 'd':
        cir_que_ary_dealloc(&que, &status);
        printf("Status: %d\n", status);
        break;
    case 'm':
        menu();
        break;
    case 'x':
        cir_que_ary_dealloc(&que, &status);
        printf("Status: %d\n", status);
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