#include "monty.h"

/**
 * addnod - Adds a new node to the beginning of the linked list.
 * @head: Pointer to the head of the linked list.
 * @n: Value to be stored in the new node.
 *
 * Description: function creates a new node with the given value and adds it to
 * the beginning of the linked list. If memory allocation fails, an error
 * message is written to stderr and the program exits.
 */
void addnod(stack_t **head, int n)
{

	stack_t *new_node, *hold;

	hold = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (hold)
		hold->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * _add - adds the top two elements of the stack
 * @head: Pointer to the top of the stack
 * @counter: Line number where the function is called
 *
 *
 */
void _add(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	int stack_length = 0, sum;
	char error_message[] = "LXXX: Not enough elements to perform addition\n";

	/* Count the number of elements in the stack */
	while (current)
	{
		current = current->next;
		stack_length++;
	}

	if (stack_length < 2)
	{
		error_message[1] = '0' + (counter / 100) % 10;
		error_message[2] = '0' + (counter / 10) % 10;
		error_message[3] = '0' + counter % 10;
		/* print the error message to STDERR */
		write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
		fclose(mydata.file);
		free(mydata.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	/* calculates the sum of the top two elements */
	sum = (*head)->n + (*head)->next->n;
	/* updates the second element with the sum */
	(*head)->next->n = sum;
	/* updates the head pointer and free the old top element */
	current = *head;
	*head = (*head)->next;
	free(current);
}

/**
 * addq - add node to the tail of the stack
 * @n: the new value to be addded
 * @head: head of the stack
 *
 *
 *
*/
void addq(stack_t **head, int n)
{
	stack_t *new_node, *hold;

	hold = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		write(2, "Error\n", strlen("Error\n"));
	}
	new_node->n = n;
	new_node->next = NULL;
	if (hold)
	{
		while (hold->next)
			hold = hold->next;
	}
	if (!hold)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		hold->next = new_node;
		new_node->prev = hold;
	}
}
