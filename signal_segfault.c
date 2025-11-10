/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Hunter Carroll
 * 
 * Brief summary of modifications:
 * Install handle_signal() function that prints when segmentation fault is received.
 * Handler returns without performing any other action.
 * Handles SIGSEGV signal.
 */


#include <stdio.h>
#include <signal.h>

void handle_signal() {
    // print message when segmentation faul tis received.
    printf("Segmentation fault received\n");
    return;
}

int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;

    signal(SIGSEGV, handle_signal);

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);


    // Return to exit the program
    return 0;
}