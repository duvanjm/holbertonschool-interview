#include "search.h"

/**
 * linear_skip - search for the value
 * @list: pointer to the head of the skip list to search in
 * @value: value to search
 * Return: position of the value
 **/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *l_express, *prev;

	if list == NULL
		return (NULL);

	l_express = list->express;
	prev = list;

	for (; l_express; l_express = l_express->express;)
	{
		printf("index[%ul] = [%d]", l_express->index, l_express->n);
		if (!l_express->express || l_express->n >= value)
		{
			if (!l_express->express && l_express->n < value)
			{
				prev = l_express;
				for (; l_express->next; l_express = l_express->next)
					;
			}
			printf("Value found between indexes [%ul] and [%d]",
					prev->index, l_express->index);
			for (; prev; prev = prev->next)
			{
				printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
				if (prev->n > value)
					return (NULL);
				if (prev->n == value)
					return (prev);
			}
			break;
		}
		prev = l_express;
	}
	return (NULL);
} 
