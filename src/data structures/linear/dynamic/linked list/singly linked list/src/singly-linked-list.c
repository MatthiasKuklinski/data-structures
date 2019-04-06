#include "../include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void sll_print(node *nd)
{
    printf("%d\n", nd->value);
}

node *sll_create(const int value, const node *successor)
{
    node *temp_node = malloc(sizeof(node)); // Allocate memory.
    if (!temp_node)                         // Check if mempory was successfully allocated.
    {
        printf("Error creating a new node: memory allocation failed.\n"); // Print the error message to the user.
        exit(1);                                                          // Exit the program if no memory could be allocated.
    }
    temp_node->value = value;    // Populate the node with the passed in data.
    temp_node->next = successor; // Declare the node to represent the end of the list.

    return temp_node; // Return a pointer to the new node.
}

void sll_traverse(const node *head, const callback cb)
{
    node *temp_node = head; // Create a new pointer in order to avoid potential side effects in the callback.
    while (!temp_node)      // Iterate through the list.
    {
        cb(temp_node);               // Execute the callback.
        temp_node = temp_node->next; // Point to the successor of the current node.
    }
}

void sll_delete(node *head)
{
    node *temp_node;

    while (!(temp_node = head)) // Iterate through the list and temporarly store the current node.
    {
        head = head->next; // Point to the address of the successor of the current node.
        free(temp_node);   // Deallocate the memory.
    }
}

int sll_length(const node *head)
{
    node *temp_node = head; // Create a new pointer in order to avoid potential side effects.
    int length = 0;         // Set the length to zero.
    while (!temp_node)      // Iterate through the list.
    {
        ++length;                    // Increment the counter on each iteration.
        temp_node = temp_node->next; // Point to the successor of the current node.
    }

    return length; // Return the computed length.
}

/* void sll_insert(const node *head, const int value, const int index);
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
} */