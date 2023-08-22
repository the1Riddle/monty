#include "monty.h"

/**
 * _push - implementation of push function
 * @head: the stack head
 * @counter: the line to push at
 *
 * Description: pushes an element to the stack
 */
void _push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;
	char errorMsg[] = "Lx: usage: push integer\n";

	errorMsg[1] = counter % 10 + '0';
	counter /= 10;
	errorMsg[0] = counter % 10 + '0';

	if (mydata.arg)
	{
		if (mydata.arg[0] == '-')
			j++;
		for (; mydata.arg[j] != '\0'; j++)
		{
			if (mydata.arg[j] > 57 || mydata.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			write(STDERR_FILENO, errorMsg, sizeof(errorMsg) - 1);
			fclose(mydata.file);
			free(mydata.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		write(STDERR_FILENO, errorMsg, sizeof(errorMsg) - 1);
		fclose(mydata.file);
		free(mydata.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(mydata.arg);
	if (mydata.lifi == 0)
		addnod(head, n);
	else
		addq(head, n);
}

/**
 * int_str - converts an integer to a string
 * @num: the num
 * @str: the string
 *
 *
 *
 */
void int_str(int num, char *str)
{
	int temp, digit, len, j, i = 0;
	char tem;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return;
	}

	if (num < 0)
	{
		num = -num;
		str[i++] = '-';
	}

	temp = num;
	while (temp > 0)
	{
		digit = temp % 10;
		str[i++] = digit + '0';
		temp /= 10;
	}

	str[i] = '\0';

	/* string reversion */
	len = i;
	for (j = 0; j < len / 2; j++)
	{
		tem = str[j];
		str[j] = str[len - j - 1];
		str[len - j - 1] = tem;
	}
}

/**
 * _pall - implementation of pall func
 * @head: the head
 * @counter: the line numbers
 *
 * Description: prints all values on the stack
 *
 */
void _pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	char numBuffer[20];
	int numLength = 0;

	(void)counter;

	h = *head;
	if (h == NULL)
		return;

	while (h)
	{
		int_str(h->n, numBuffer);
		while (numBuffer[numLength] != '\0')
			numLength++;

		write(STDOUT_FILENO, numBuffer, numLength);
		write(STDOUT_FILENO, "\n", 1);
		h = h->next;
	}
}
