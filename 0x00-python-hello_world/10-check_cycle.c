#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - function hecks if a singly-linked list contains a cycle.
 * @list: singly-linked list.
 *
 * Return: 0 if no cycle,
 * otherwise, return 1  if there's a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *j, *v;

	if (list == NULL || list->next == NULL)
		return (0);

	j = list->next;
	v = list->next->next;

	while (j && v && v->next)
	{
		if (j == v)
			return (1);

		j = j->next;
		v = v->next->next;
	}

	return (0);
}
