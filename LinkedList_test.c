/*
 * File: LinkedList_test.c
 * Creator: George Ferguson
 * Created: Wed Sep  7 17:59:30 2016
 * Time-stamp: <Fri Aug  4 10:04:36 EDT 2017 ferguson>
 *
 * Test program for LinkedList library.
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedList.c"

int
main(int argc, char **argv) {
    LinkedList *list = LinkedList_new();
    printf("new list =");
    LinkedList_print_string_list(list);

    printf("adding three elements: ");
    LinkedList_add_at_end(list, "foo");
    LinkedList_add_at_end(list, "bar");
    LinkedList_add_at_end(list, "baz");
    LinkedList_print_string_list(list);
    return 0;
}
