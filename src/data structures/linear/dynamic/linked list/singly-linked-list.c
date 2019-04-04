#include <stdio.h>
#include <stdlib.h>

// Types
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef void (*callback)(node *data);

// Functions
node *sll_create(int data, node *successor);
void sll_traverse(node *head, callback cb);
int sll_length(node *head);
void sll_insert(node *head, int data, int index);
void sll_free(node *head);

// Callback Implementations
void sll_print(node *data)
{
    printf("%d\n", data->data);
}

int main(int argc, char *argv[])
{
    const long length = strtol(argv[1], NULL, 10); // Convert char/string into long.
    node *list;
    for (int i = 0; i < length; ++i)
    {
        if (sll_length(list) < 1)
            list = sll_create(i, NULL);
        else
            sll_insert(list, i, i);
    }
    
    sll_traverse(list, sll_print);
    sll_free(list);
}

node *sll_create(int data, node *successor)
{
    node *temp_node = malloc(sizeof(node));
    if (temp_node == NULL) // Check if mempory was successfully allocated.
    {
        printf("Error creating a new node: memory allocation failed.\n"); // Print the error message to the user.
        exit(0);                                                          // Exit the program if no memory was available.
    }
    temp_node->data = data;      // Populate the node with the passed in data.
    temp_node->next = successor; // Declare the node to represent the end of the list.

    return temp_node; // Return a pointer to the new node.
}

void sll_traverse(node *head, callback cb)
{
    node *temp_node = head;
    while (temp_node != NULL)
    {
        cb(temp_node);
        temp_node = temp_node->next;
    }
}

int sll_length(node *head)
{
    node *temp_node = head;
    int length = 0;
    while (temp_node != NULL)
    {
        ++length;
        temp_node = temp_node->next;
    }
    return length;
}

void sll_insert(node *head, int data, int index)
{
    if (index == 0)
    {
        head = sll_create(data, head);
        return;
    }

    node *temp_node = head;
    for (int i = 0; i < index; i++)
    {
        if (i == index - 1)
        {
            temp_node->next = sll_create(data, temp_node->next);
            return;
        }

        temp_node = temp_node->next;
    }
}

void sll_free(node *head)
{
    node *temp_node;

    while (temp_node != NULL)
    {
        temp_node = head;
        head = head->next;
        free(temp_node);
    }
}