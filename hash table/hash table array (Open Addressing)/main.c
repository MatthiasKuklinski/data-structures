#include <ht_ary.h>

#include <stdio.h>
#include <stdlib.h>

void ht_ary_print(ht_ary_entry_t **ht_ary_entry)
{
    if (*ht_ary_entry)
        printf("%s: %-32s\n", (*ht_ary_entry)->key, (*ht_ary_entry)->element);
    else 
        printf("\n");
}

void menu()
{
    printf("- Hash Table (Array (Open Addressing)) -\n");
    printf("Print(q)\n");
    printf("Create(c)\n");
    printf("Set(s)\n");
    printf("Get(g)\n");
    printf("Remove(r)\n");
    printf("Delete(d)\n");
    printf("Menu(m)\n");
    printf("Exit(x)\n");
}

void controller(const char cmd)
{
    unsigned long capacity = 0;
    char key[32];
    char element[32];
    ht_ary_entry_t *result;
    static ht_ary_t *ht = NULL;

    switch (cmd)
    {
    case 'q':
        ht_ary_traverse(&ht, ht_ary_print);
        break;
    case 'c':
        printf("Capacity:");
        scanf("%lu", &capacity);
        ht = ht_ary_alloc(capacity);
        break;
    case 's':
        printf("Key:");
        scanf("%s", key);
        printf("%s", key);
        printf("Element:");
        scanf("%s", element);
        printf("%s", element);
        ht_ary_set(ht, ht_ary_entry_alloc(key, element));
        break;
    case 'g':
        printf("Key:");
        scanf("%s", key);
        result = ht_ary_get(ht, key);
        if (result)
            printf("%s\n", result->element);
        break;
    case 'r':
        printf("Key:");
        scanf("%s", key);
        ht_ary_remove(ht, key);
        break;
    case 'd':
        ht_ary_dealloc(&ht);
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
    char cmd = '\0';

    menu();
    while (1)
    {
        printf("Cmd:");
        scanf("%s", &cmd);
        controller(cmd);
    }
}