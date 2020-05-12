#include <ht_sll.h>

#include <stdio.h>
#include <stdlib.h>

void ht_sll_print(ht_node_sll_t *ht_node_sll)
{
    while (ht_node_sll)
    {
        printf("%s: %-32s ", ht_node_sll->key, ht_node_sll->element);
        ht_node_sll = ht_node_sll->next;
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
    char key[32], element[32];
    ht_node_sll_t *result;
    static ht_sll_t *ht = NULL;
    status_code_t status_code = success;

    switch (cmd)
    {
    case 'q':
        ht_sll_traverse(ht, ht_sll_print, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'c':
        printf("Capacity:");
        scanf("%lu", &capacity);
        ht = ht_sll(capacity, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 's':
        printf("Key:");
        scanf("%s", key);
        printf("Element:");
        scanf("%s", element);
        ht_sll_set(ht, key, element, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'g':
        printf("Key:");
        scanf("%s", key);
        result = ht_sll_get(ht, key, &status_code);
        if (result)
            printf("%s\n", result->element);
        printf("Status: %d\n", status_code);
        break;
    case 'r':
        printf("Key:");
        scanf("%s", key);
        ht_sll_remove(ht, key, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'd':
        ht_sll_delete(&ht, &status_code);
        printf("Status: %d\n", status_code);
        break;
    case 'm':
        menu();
        break;
    case 'x':
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