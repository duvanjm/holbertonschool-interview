#include "lists.h"

/**
 * insert_node -  inserts a number into a sorted singly linked list
 * @head: head of list
 * @number: numbert to insert
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number);
{
    listint_t *newnode, *head2;

	head2 = *head;
	newnode = malloc(sizeof(listint_t));

	if (newnode == NULL)
		return (NULL);
	newnode->n = number;

	if (*head == NULL)
	{
		newnode->next = NULL;
		*head = newnode;
		return (newnode);
	}

	if (head2->n > newnode->n)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}

	while (head2->next != NULL)
	{
		if (head2->next->n >= newnode->n)
		{
			newnode->next = head2->next;
			head2->next = newnode;
			return (newnode);
		}
		head2 = head2->next;
	}

	newnode->next = head2->next;
	head2->next = newnode;

	return (newnode);
}
