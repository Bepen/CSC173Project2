/*
CSC 173 Project 2
Created By Bepen Neupane and Sailesh Kaveti
NetID: bneupane skaveti
*/

//we modified the linked list from project 1
/*
 * File: Stack.h
 * Creator: George Ferguson
 * Created: Thu Jun 30 14:43:29 2016
 * Time-stamp: <Mon Sep  5 14:13:59 EDT 2016 ferguson>
 *
 * Singly-linked stack with end pointers.
 */

#ifndef _Stack_h_gf
#define _Stack_h_gf

#include <stdbool.h>

// Partial declaration
typedef struct Stack Stack;

/**
 * Allocate, initialize and return a new (empty) Stack.
 */
extern Stack *Stack_new();

/**
 * Free the memory used for the given Stack.
 * If boolean free_data_also is true, also free the data associated with
 * each element.
 */
extern void Stack_free(Stack *stack, bool free_data_also);

/**
 * Return true if the given Stack is empty.
 */
extern bool Stack_is_empty(const Stack *stack);

/**
 * Add the given void* value at the front of the given Stack.
 */
extern void Stack_add_at_front(Stack *stack, char *value);

/**
 * Add the given void* value at the end of the given Stack.
 */
extern void Stack_add_at_end(Stack *stack, char *value);

/**
 * Return true if then given Stack contains given void* value.
 */
extern bool Stack_contains(const Stack *stack, char *value);

/**
 * Remove the given void* value from the given Stack if it is there.
 * Note that this does not free the data associated with the element.
 */
extern void Stack_remove(Stack *stack, char *data);

/**
 * Return the void* value at the given index in the given Stack, or
 * NULL if there is no such.
 * Note that this means you can't store NULL in a Stack. C'est la vie.
 */
extern char *Stack_element_at(Stack *stack, int index);

/**
 * Remove and return the first element from the given Stack.
 * Returns NULL if the stack is empty.
 */
extern char *Stack_pop(Stack *stack);

/**
 * Print the given Stack to stdout, assuming that the values are
 * all null-terminated strings.
 */
extern void Stack_print_string_stack(Stack *stack);

#endif
