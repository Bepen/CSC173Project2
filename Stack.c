/*
CSC 173 Project 2
Created By Bepen Neupane and Sailesh Kaveti
NetID: bneupane skaveti
*/


//we modified the linked list from project 1
/*
 * File: Stack.c
 * Creator: George Ferguson
 * Created: Thu Jun 30 14:47:12 2016
 * Time-stamp: <Fri Aug  4 10:29:48 EDT 2017 ferguson>
 */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/**
 * Toplevel Stack structure.
 */
struct Stack {
    struct StackNode *first;
    struct StackNode *last;
};

/**
 * Structure for each element of a doubly-linked Stack.
 */
typedef struct StackNode {
    char *data;
    struct StackNode *next;
    struct StackNode *prev;
} StackNode;

/**
 * Allocate, initialize and return a new (empty) Stack.
 */
Stack *
Stack_new() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->first = stack->last = NULL;
    return stack;
}

static StackNode *
StackNode_new(char *data) {
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    if (node == NULL) {
	abort();
    }
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

/**
 * Free the memory used for the given Stack.
 * If boolean free_data_also is true, also free the data associated with
 * each element.
 */
void
Stack_free(Stack *stack, bool free_data_also) {
    // Free the elements
    StackNode *elt = stack->first;
    while (elt != NULL) {
	StackNode *next = elt->next;
	if (free_data_also && elt->data != NULL) {
	    free(elt->data);
	}
	free(elt);
	elt = next;
    }
    // Free the stack itself
    free(stack);
}

/**
 * Return true if the given Stack is empty.
 */
bool
Stack_is_empty(const Stack *stack) {
    return stack->first == NULL;
}

/**
 * Add the given void* value at the front of the given Stack.
 */
void
Stack_add_at_front(Stack *stack, char *data) {
    StackNode *node = StackNode_new(data);
    node->next = stack->first;
    if (stack->first != NULL) {
	stack->first->prev = node;
    }
    stack->first = node;
    if (stack->last == NULL) {
	stack->last = node;
    }
}

/**
 * Add the given void* value at the end of the given Stack.
 */
void
Stack_add_at_end(Stack *stack, char *data) {
    StackNode *node = StackNode_new(data);
    node->prev = stack->last;
    if (stack->last != NULL) {
	stack->last->next = node;
    }
    stack->last = node;
    if (stack->first == NULL) {
	stack->first = node;
    }
}

/**
 * Return true if then given Stack contains given void* value.
 */
bool
Stack_contains(const Stack *stack, char *data) {
    for (StackNode *node=stack->first; node != NULL; node=node->next) {
	if (node->data == data) {
	    return true;
	}
    }
    return false;
}

/**
 * Remove the given void* value from the given Stack if it is there.
 * Note that this does not free the data associated with the element.
 */
void
Stack_remove(Stack *stack, char *data) {
    for (StackNode *node=stack->first; node != NULL; node=node->next) {
	if (node->data == data) {
	    if (node == stack->first) {
		stack->first = node->next;
	    }
	    if (node == stack->last) {
		stack->last = node->prev;
	    }
	    if (node->prev != NULL) {
		node->prev->next = node->next;
	    }
	    if (node->next != NULL) {
		node->next->prev = node->prev;
	    }
	    free(node);
	    return;
	}
    }
}

/**
 * Return the void* value at the given index in the given Stack, or
 * NULL if there is no such.
 * Note that this means you can't store NULL in a Stack. C'est la vie.
 */
char *
Stack_element_at(Stack *stack, int index) {
    int i = 0;
    for (StackNode *node=stack->first; node != NULL; node=node->next) {
	if (i == index) {
	    return node->data;
	}
	i += 1;
    }
    return NULL;
}

/**
 * Remove and return the first element from the given Stack.
 * Returns NULL if the stack is empty.
 */
char *
Stack_pop(Stack *stack) {
    char *data = Stack_element_at(stack, 0);
    if (data != NULL) {
	Stack_remove(stack, data); // Removes first occurrence
    }
    return data;
}


/**
 * Print the given Stack to stdout, assuming that the values are
 * all null-terminated strings.
 */
void
Stack_print_string_stack(Stack *stack) {
    for (StackNode *node=stack->first; node != NULL; node=node->next) {
	     printf("%s", node->data);
	     if (node->next != NULL) {
	        printf(" ");
	     }
    }
    printf("\n");
}
