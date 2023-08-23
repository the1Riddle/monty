#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global - my data truct
 * @arg: arguments passed
 * @file: pointer to monty file
 * @content: the contents
 * @lifi: flag change stack queues
 *
 * Description: carries values through the program
 */
typedef struct data_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} data_s;

void addnod(stack_t **head, int n);
void freestack(stack_t *head);
void _add(stack_t **head, unsigned int counter);
void addq(stack_t **head, int n);
void _swap(stack_t **head, unsigned int counter);
int main(int argc, char *argv[]);
void f_pop(stack_t **head, unsigned int counter);
void f_pint(stack_t **head, unsigned int counter);
void _push(stack_t **head, unsigned int counter);
void _pall(stack_t **head, unsigned int counter);
void _nop(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
extern data_s mydata;

#endif /* end of file */
