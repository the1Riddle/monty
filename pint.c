#include "monty.h"
/**
 * f_pint - prints from the top
 * @head: stack the head
 * @counter: line_number
 * Return: nil return
*/
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(mydata.file);
		free(mydata.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
