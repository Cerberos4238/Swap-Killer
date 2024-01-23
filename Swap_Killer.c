#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

//Should I run?

int running = 1;

//SIGINT signal ( CTRL+C)
void sigint_handler(int signo) {
    if (signo == SIGINT) {
        printf("\nArret du programme...\n");
        running = 0;
    }
}

int main() {
    //SIGINT management signal
    signal(SIGINT, sigint_handler);


    long long int total_memory_allocated = 0;
    void *memory_block;

    while (running) {
        //Give the memory size you want
        memory_block = malloc(15096);

        /*if (memory_block == NULL) {
            //In case if all the memory is used
            break;*/
            
        }

        //Fullfill the memory with zeros
        memset(memory_block, 0, 15096);

        

        total_memory_allocated += 15096;

        //Free the memory before leaving
    free(memory_block);
    
    }
