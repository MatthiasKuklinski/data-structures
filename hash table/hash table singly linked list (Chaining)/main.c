#include <ht_sll.h>

#include <stdio.h>
#include <stdlib.h>

void ht_sll_print(ht_sll_node_t **ht_sll_node)
{
    ht_sll_node_t *temp = *ht_sll_node;
    while (temp)
    {
        printf("%s: %-32s ", temp->key, temp->element);
        temp = temp->next;
    }
    printf("\n");
}

void menu()
{
    printf("- Hash Table (Singly Linked List (Chaining)) -\n");
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
    ht_sll_node_t *result;
    static ht_sll_t *ht = NULL;

    switch (cmd)
    {
    case 'q':
        ht_sll_traverse(&ht, ht_sll_print);
        break;
    case 'c':
        printf("Capacity:");
        scanf("%lu", &capacity);
        ht = ht_sll_alloc(capacity);
        break;
    case 's':
        printf("Key:");
        scanf("%s", key);
        printf("%s", key);
        printf("Element:");
        scanf("%s", element);
        printf("%s", element);
        ht_sll_set(ht, key, element);
        break;
    case 'g':
        printf("Key:");
        scanf("%s", key);
        result = ht_sll_get(ht, key);
        if (result)
            printf("%s\n", result->element);
        break;
    case 'r':
        printf("Key:");
        scanf("%s", key);
        ht_sll_remove(ht, key);
        break;
    case 'd':
        ht_sll_dealloc(&ht);
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