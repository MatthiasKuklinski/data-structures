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
    printf("Delete(d)\n");
    printf("Menu(m)\n");
    printf("Exit(x)\n");
}

void controller(const char cmd)
{
    int value, capacity = 0;
    static cir_que_ary_t *que = NULL;
    status_code_t status_code = success;

    switch (cmd)
    {
    case 'q':
        cir_que_ary_traverse(que, cir_que_ary_print, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'c':
        printf("Capacity:");
        scanf("%d", &capacity);
        que = cir_que_ary(capacity, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'p':
        printf("Value:");
        scanf("%d", &value);
        cir_que_ary_enqueue(que, value, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'r':
        cir_que_ary_dequeue(que, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'g':
        printf("%d\n", cir_que_ary_peek(que, &status_code));
        printf("Status: %d\n", status_code);
        break;
    case 'e':
        printf("%d\n", cir_que_ary_is_empty(que, &status_code));
        printf("Status: %d\n", status_code);
        break;
    case 'f':
        printf("%d\n", cir_que_ary_is_full(que, &status_code));
        printf("Status: %d\n", status_code);
        break;
    case 'd':
        cir_que_ary_delete(&que, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'm':
        menu();
        break;
    case 'x':
        cir_que_ary_delete(&que, &status_code);
        printf("Status: %d\n", status_code);
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