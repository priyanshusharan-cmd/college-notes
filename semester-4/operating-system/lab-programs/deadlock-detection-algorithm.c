/*
Algorithm: Deadlock Detection Algorithm

1. Start.
2. Read the number of processes and resources.
3. Input the Allocation Matrix.
4. Input the Request Matrix.
5. Input the Available Resources vector.
6. Initialize Work = Available.
7. For each process:
   a) If its Allocation is zero, mark it as finished.
   b) Otherwise, mark it as unfinished.
8. Find an unfinished process whose Request is less than or equal to Work.
9. If such a process is found:
   a) Add its Allocation to Work.
   b) Mark the process as finished.
   c) Add the process to the safe sequence.
10. Repeat Steps 8 and 9 until no more processes can be satisfied.
11. Check all processes:
    a) If every process is finished, the system is in a Safe State.
    b) Otherwise, the system is in Deadlock State.
12. Display the Safe Sequence if no deadlock exists.
13. Display the Deadlocked Processes if deadlock exists.
14. Stop.
    */

#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[n][m];
    int request[n][m];
    int available[m];
    int work[m];
    int finish[n];
    int safeSequence[n];

    printf("Enter the allocation matrix:\n");

    for(i = 0; i < n; i++) {
        printf("Process %d: ", i);

        for(j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the request matrix:\n");

    for(i = 0; i < n; i++) {
        printf("Process %d: ", i);

        for(j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    printf("Enter the available resources: ");

    for(i = 0; i < m; i++) {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    for(i = 0; i < n; i++) {

        int allZero = 1;

        for(j = 0; j < m; j++) {

            if(allocation[i][j] != 0) {
                allZero = 0;
                break;
            }
        }

        if(allZero)
            finish[i] = 1;
        else
            finish[i] = 0;
    }

    int count = 0;

    while(count < n) {

        int found = 0;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                int possible = 1;

                for(j = 0; j < m; j++) {

                    if(request[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {

                    for(k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }

                    safeSequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    int deadlock = 0;

    for(i = 0; i < n; i++) {

        if(finish[i] == 0) {
            deadlock = 1;
            break;
        }
    }

    if(deadlock) {

        printf("\nSystem is in DEADLOCK state.\n");

        printf("Deadlocked processes are: ");

        for(i = 0; i < n; i++) {

            if(finish[i] == 0)
                printf("P%d ", i);
        }

        printf("\n");
    }
    else {

        printf("\nSystem is in safe state.\n");

        printf("Safe Sequence is: ");

        for(i = 0; i < n; i++) {
            printf("P%d ", safeSequence[i]);
        }

        printf("\n");
    }

    return 0;
}

/*
OUTPUT
Enter the number of processes: 5
Enter the number of resources: 3

Enter the allocation matrix:
Process 0: 0 1 0
Process 1: 2 0 0
Process 2: 3 0 3
Process 3: 2 1 1
Process 4: 0 0 2

Enter the request matrix:
Process 0: 0 0 0
Process 1: 2 0 2
Process 2: 0 0 0
Process 3: 1 0 0
Process 4: 0 0 2

Enter the available resources:
0 0 0

System is in DEADLOCK state.
Deadlocked processes are: P1 P3 P4
*/
