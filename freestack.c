#include "monty.h"
/**
* freestack - frees a doubly linked list
* @head: head of the stack
*
*
*
*/
void freestack(stack_t *head)
{
	stack_t *hold;

	hold = head;
	while (head)
	{
		hold = head->next;
		free(head);
		head = hold;
	}
}
