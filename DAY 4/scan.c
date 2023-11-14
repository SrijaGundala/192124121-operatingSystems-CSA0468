#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100
#define MAX_CYLINDERS 200

void calculateSeekTime(int requests[], int numRequests, int initialHeadPosition) {
    int totalSeekTime = 0;
    int currentHeadPosition = initialHeadPosition;
    int direction = 1;
    int i, j;

    for (i = 0; i < numRequests - 1; i++) {
        for (j = 0; j < numRequests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    printf("Disk I/O Seek Sequence for %s: %d", "srija", currentHeadPosition);

    while (1) {
        for (i = 0; i < numRequests; i++) {
            if (direction == 1 && requests[i] >= currentHeadPosition) {
                totalSeekTime += abs(currentHeadPosition - requests[i]);
                currentHeadPosition = requests[i];
                printf(" -> %d", currentHeadPosition);
            } else if (direction == -1 && requests[i] <= currentHeadPosition) {
                totalSeekTime += abs(currentHeadPosition - requests[i]);
                currentHeadPosition = requests[i];
                printf(" -> %d", currentHeadPosition);
            }
        }
        direction = -direction;
        if (direction == 1 && currentHeadPosition == MAX_CYLINDERS) {
            break;
        } else if (direction == -1 && currentHeadPosition == 0) {
            break;
        }
    }

    printf("\nTotal Disk I/O Seek Time for %s: %d\n", "srija", totalSeekTime);
}

int main() {
    int numRequests, initialHeadPosition;
    int requests[MAX_REQUESTS];
    int i;

    printf("Enter the number of disk I/O requests for %s: ", "srija");
    scanf("%d", &numRequests);
    printf("Enter the initial head position for %s: ", "srija");
    scanf("%d", &initialHeadPosition);
    printf("Enter the disk I/O requests for %s:\n", "srija");

    for (i = 0; i < numRequests; i++) {
        printf("Request %d for %s: ", i + 1, "srija");
        scanf("%d", &requests[i]);
    }

    calculateSeekTime(requests, numRequests, initialHeadPosition);

    return 0;
}

