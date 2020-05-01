#include <cir_que_ary.h>

#include <stdio.h>
#include <stdlib.h>

void cir_que_ary_print(cir_que_ary_t *cir_que_ary)
{
    if (!cir_que_ary || !(cir_que_ary->length > 0))
        return;

    printf("%-32s\n", "Capacity");
    printf("%-32d%-32d\n\n", cir_que_ary->length, cir_que_ary->capacity);
    printf("%-32s%-32s\n", "Item", "Memory Address");
    for (int i = cir_que_ary->front; i != cir_que_ary->rear; i = (i + 1) % cir_que_ary->capacity)
        printf("%-32d%-32p\n", cir_que_ary->elements[i], &cir_que_ary->elements[i]); 
    printf("%-32d%-32p\n", cir_que_ary->elements[cir_que_ary->rear], &cir_que_ary->elements[cir_que_ary->rear]); 
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
    int value;
    unsigned int capacity;
    static cir_que_ary_t *que = NULL;

    switch (cmd)
    {
    case 'q':
        cir_que_ary_print(que);
        break;
    case 'c':
        printf("Capacity:");
        scanf("%d", &capacity);
        que = cir_que_ary(capacity);
        break;
    case 'p':
        printf("Value:");
        scanf("%d", &value);
        cir_que_ary_enqueue(que, value);
        cir_que_ary_print(que);
        break;
    case 'r':
        cir_que_ary_dequeue(que);
        cir_que_ary_print(que);
        break;
    case 'g':
        printf("%d\n", cir_que_ary_peek(que));
        break;
    case 'e':
        printf("%d\n", cir_que_ary_is_empty(que));
        break;
    case 'f':
        printf("%d\n", cir_que_ary_is_full(que));
        break;
    case 'd':
        cir_que_ary_delete(&que);
        break;
    case 'm':
        menu();
        break;
    case 'x':
        cir_que_ary_delete(&que);
        break;
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