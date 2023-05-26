#include "main.h"
/**
 * add_sep_node_end - adds a separator found at the end
 * of a sep_list.
 * @head: head of linked list.
 * @sep: separator found (; | &) semicolon and bitwise
 * Return: address of the head
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep, new->next = NULL;
	temp = *head;

	if (temp == NULL)
		*head = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (*head);
}

/**
 * free_sep_list - frees a sep_list
 * @head: head of linked list
 * Return: no return
 */

void free_sep_list(sep_list **head)
{
	sep_list *temp, *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - adds a command line at the end
 * of a linelist
 * @head: head of linked list.
 * @line: command line
 * Return: address of the head
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line, new->next = NULL;
	temp = *head;

	if (temp == NULL)
		*head = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (*head);
}

/**
 * free_line_list - frees a linelist
 * @head: head of linked list.
 * Return: no return (nothing)
 */
void free_line_list(line_list **head)
{
	line_list *temp, *cur;

	if (head != NULL)
	{
		cur = *head;
		while ((temp = cur) != NULL)
		{
			cur = cur->next;
			free(temp);
		}
		*head = NULL;
	}
}
