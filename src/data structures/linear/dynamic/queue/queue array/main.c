#include <que_ary.h>

#include <stdio.h>
#include <stdlib.h>

void que_ary_print(que_ary_t *que_ary)
{
    if (!que_ary)
        return;

    printf("%-32s\n", "Capacity");
    printf("%-32d\n\n", que_ary->capacity);
    printf("%-32s%-32s\n", "Item", "Memory Address");
    for (int i = 0; i < que_ary->capacity; ++i)
        printf("%-32d%-32p\n", que_ary->items[i], &que_ary->items[i]);
}

void menu()
{
    printf("- Queue(Array) -\n");
    printf("Print(q)\n");
    printf("Create(c)\n");
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
    case 'd':
        que_ary_delete(&que);
        break;
    case 'm':
        menu();
        break;
    case 'x':
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