#include "shell.h"

/**
 * List_len – it determines the length of a linked list
 * @h: The pointer to the first node
 *
 * Return: size of list
 */
size_t List_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * List_to_strings – it returns an array of strings of the list->str
 * @head: The pointer to the first node
 *
 * Return: array of strings
 */
char **List_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = List_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * Print_list - it prints all elements of a list_t linked list
 * @h: The pointer to the first node
 *
 * Return: size of list
 */
size_t Print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(Convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_Starts_with – it returns node whose string starts with a prefix
 * @node: The pointer to list head
 * @prefix: The string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_Starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = Starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_Node_index - it gets the index of a node
 * @head: The pointer to list the head
 * @node: The pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_Node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
