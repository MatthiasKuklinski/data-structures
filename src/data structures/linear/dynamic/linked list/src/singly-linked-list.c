#include "../include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void sll_print(node *data)
{
    printf("%d\n", data->data);
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
    node *temp_node = head;
    for (int i = 1; i <= index; i++)
    {
        if (i == index)
        {
            if (i == 0)
            {
                temp_node = head;
                head->next = sll_create(temp_node->data, temp_node->next);
                head->data = data;
                return;
            }
            temp_node->next = sll_create(data, temp_node->next);
            return;
        }

        temp_node = temp_node->next;
    }
}

void sll_free(node *head)
{
    node *temp_node;

    while ((temp_node = head) != NULL)
    {
        head = head->next;
        free(temp_node);
    }
}