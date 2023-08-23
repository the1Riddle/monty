#include "monty.h"
/**
 * _swap - swaps the values of the top two elements of the stack
 * @head: a double pointer to the head node of the stack
 * @counter: the counter for error reporting
 *
 *
 */
void _swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, hold;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	/* checking if there are enough elements to perform the swap */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(mydata.file);
		free(mydata.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	/* If there are at least 2 elements, perform the swap */
	h = *head;
	hold = h->n;
	h->n = h->next->n;
	h->next->n = hold;
}

/**
 * _nop - the entry point.
 * @head: a pointer to the top of the stack.
 * @counter: the number of the current instruction
 *
 * Description: this code does not perform any operation in perticular,
 * its work is just to move to the next instruction
 *
 */
void _nop(stack_t **head, unsigned int counter)
{
	(void)counter;
	(void)head;
}
