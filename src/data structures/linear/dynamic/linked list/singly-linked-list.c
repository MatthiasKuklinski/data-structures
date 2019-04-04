#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

void list_print(node_t *head);
void list_push(node_t *head, int val);

int main(int argc, char *argv[])
{
    const long length = strtol(argv[1], NULL, 10); // Convert char/string into long.
}

void list_print(node_t *head)
{
    node_t *current = head; // Set the current node

    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void list_push(node_t *head, int data)
{
    node_t *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = malloc(sizeof(node_t));
    current->next->data = data;
    current->next->next = NULL;
}