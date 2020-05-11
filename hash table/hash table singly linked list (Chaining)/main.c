#include <ht_sll.h>

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("- Hash Table (Singly Linked List (Chaining)) -\n");
    printf("Create(c)\n");
    printf("Set(s)\n");
    printf("Get(g)\n");
    printf("Menu(m)\n");
    printf("Exit(x)\n");
}

void controller(const char cmd)
{
    unsigned long capacity = 0;
    char key[48], element[48];
    static ht_sll_t *ht = NULL;
    status_code_t status_code = success;

    switch (cmd)
    {
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
        printf("%s\n", ht_sll_get(ht, key, &status_code));
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