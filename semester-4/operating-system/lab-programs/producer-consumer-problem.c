/*
=========================================================
Pseudocode for Producer-Consumer Problem (Bounded Buffer)

Initialize:
    buffer = array of size n
    mutex = 1       // To protect critical section
    empty = n       // Number of empty slots
    full = 0        // Number of filled slots
    in = 0          // Index for producer
    out = 0         // Index for consumer

Producer Process:
    DO
        Produce an item
        
        WAIT(empty)     // Decrease empty count (wait if 0)
        WAIT(mutex)     // Enter critical section
        
        buffer[in] = item
        in = (in + 1) % n
        
        SIGNAL(mutex)   // Leave critical section
        SIGNAL(full)    // Increase full count
    WHILE (true)

Consumer Process:
    DO
        WAIT(full)      // Decrease full count (wait if 0)
        WAIT(mutex)     // Enter critical section
        
        item = buffer[out]
        out = (out + 1) % n
        
        SIGNAL(mutex)   // Leave critical section
        SIGNAL(empty)   // Increase empty count
        
        Consume the item
    WHILE (true)
=========================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// The Array Buffer
int buffer[MAX];

// Simulating semaphores with integers
int mutex = 1;
int full = 0;
int empty = MAX;

// Pointers for the circular array
int in = 0, out = 0;

// Auto-incrementing item counter
int item_counter = 1; 

// Simulating the wait() semaphore operation (renamed to avoid macOS system clash)
void my_wait(int *s) {
    (*s)--;
}

// Simulating the signal() semaphore operation (renamed to avoid macOS system clash)
void my_signal(int *s) {
    (*s)++;
}

void produce() {
    my_wait(&empty); // Decrease empty slots
    my_wait(&mutex); // Enter critical section
    
    // Auto-assign the item without asking for user input
    buffer[in] = item_counter;
    printf("--> Produced item %d at buffer[%d]\n", buffer[in], in);
    
    item_counter++;      // Increment for the next production
    in = (in + 1) % MAX; // Circular array logic
    
    my_signal(&mutex); // Leave critical section
    my_signal(&full);  // Increase full slots
}

void consume() {
    my_wait(&full);  // Decrease full slots
    my_wait(&mutex); // Enter critical section
    
    int item = buffer[out];
    printf("--> Consumed item %d from buffer[%d]\n", item, out);
    
    out = (out + 1) % MAX; // Circular array logic
    
    my_signal(&mutex); // Leave critical section
    my_signal(&empty); // Increase empty slots
}

int main() {
    int choice;
    
    printf("\n--- Producer Consumer Array Simulation ---");
    printf("\n1. Produce\n2. Consume\n3. Exit\n");
    
    while (1) {
        printf("\nEnter your choice (1/2/3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Check if buffer is not full and mutex is available
                if ((mutex == 1) && (empty != 0)) {
                    produce();
                } else {
                    printf("Buffer is FULL! Cannot produce right now.\n");
                }
                break;
                
            case 2:
                // Check if buffer is not empty and mutex is available
                if ((mutex == 1) && (full != 0)) {
                    consume();
                } else {
                    printf("Buffer is EMPTY! Cannot consume right now.\n");
                }
                break;
                
            case 3:
                printf("Exiting...\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    }
    return 0;
}