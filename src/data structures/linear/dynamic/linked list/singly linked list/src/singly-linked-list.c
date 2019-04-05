#include "../include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void sll_print(node *data)
{
    printf("%d\n", data->data);
}

node *sll_create(const int value, const node *successor)
{
    node *temp_node = malloc(sizeof(node)); // Allocate memory.
    if (!temp_node)                         // Check if mempory was successfully allocated.
    {
        printf("Error creating a new node: memory allocation failed.\n"); // Print the error message to the user.
        exit(0);                                                          // Exit the program if no memory could be allocated.
    }
    temp_node->value = value;    // Populate the node with the passed in data.
    temp_node->next = successor; // Declare the node to represent the end of the list.

    return temp_node; // Return a pointer to the new node.
}

void sll_traverse(const node *head, const callback cb)
{
    while (!head) // Iterate through the list.
    {
        cb(head);          // Execute the callback.
        head = head->next; // Point to the successor of the current node.
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
    if (!head) // Check if the list was initialized.
    {
        printf("Error inserting a new node: head of list is uninitialized.\n");
        return;
    }

    node *temp_node = head;
    for (int i = 1; i <= index; i++)
    {
        if (i == index)
        {
            if (i == 0) // Insert at the beginning of the list.
            {
                temp_node = head;
                head->next = sll_create(temp_node->data, temp_node->next);
                head->data = data;
                return;
            }

            temp_node->next = sll_create(data, temp_node->next); // Insert at the requested index at the list.
            return;
        }

        temp_node = temp_node->next;

        if (!temp_node)
        {
            temp_node = sll_create(data, NULL); // Insert at the end of the list (if the requested index is greater than the list length).
            return;
        }
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