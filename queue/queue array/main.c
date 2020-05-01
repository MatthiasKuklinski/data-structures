#include <que_ary.h>

#include <stdio.h>
#include <stdlib.h>

void que_ary_print(que_ary_t *que_ary)
{
    if (!que_ary)
        return;

    printf("%-32s\n", "Capacity");
    printf("%-32d%-32d\n\n", que_ary->length, que_ary->capacity);
    printf("%-32s%-32s\n", "Item", "Memory Address");
    for (int i = que_ary->front; i <= que_ary->rear && que_ary->length > 0; ++i)
        printf("%-32d%-32p\n", que_ary->elements[i], &que_ary->elements[i]);
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
    static que_ary_t *que = NULL;

    switch (cmd)
    {
    case 'q':
        que_ary_print(que);
        break;
    case 'c':
        printf("Capacity:");
        scanf("%d", &capacity);
        que = que_ary(capacity);
        break;
    case 'p':
        printf("Value:");
        scanf("%d", &value);
        que_ary_enqueue(que, value);
        que_ary_print(que);
        break;
    case 'r':
        que_ary_dequeue(que);
        que_ary_print(que);
        break;
    case 'g':
        printf("%d\n", que_ary_peek(que));
        break;
    case 'e':
        printf("%d\n", que_ary_is_empty(que));
        break;
    case 'f':
        printf("%d\n", que_ary_is_full(que));
        break;
    case 'd':
        que_ary_delete(&que);
        break;
    case 'm':
        menu();
        break;
    case 'x':
        que_ary_delete(&que);
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