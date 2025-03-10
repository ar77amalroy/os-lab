#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SEGSIZE 100

int main(int argc, char *argv[])
{
    int shmid,extra_shmids[5];
    key_t key;
    char *segptr;
    char buff[] = "hello how are you?";

    // Generate key for shared memory
    key = ftok(".", 's');

    for (int i = 0; i < 5; i++) {
        extra_shmids[i] = shmget(IPC_PRIVATE, SEGSIZE, IPC_CREAT | 0666);
    }
    // Try to create shared memory segment
    if ((shmid = shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        // If the segment already exists, access it
        if ((shmid = shmget(key, SEGSIZE, 0)) == -1)
        {
            perror("shmget");
            exit(1);
        }
        else
        {
            printf("Shared memory segment already exists. Using existing segment.\n");
        }
    }
    else
    {
        printf("Creating a new shared memory segment\n");
        printf("SHMID: %d\n", shmid);
    }

     system("ipcs -m");    // Attach to the shared memory segment
    if ((segptr = (char *)shmat(shmid, 0, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }

    // Write data to shared memory
    printf("Writing data to shared memory...\n");
    strcpy(segptr, buff);
    printf("DONE\n");

    // Read data from shared memory
    printf("Reading data from shared memory...\n");
    printf("DATA: %s\n", segptr);
    printf("DONE\n");

    // Detach from shared memory segment
    if (shmdt(segptr) == -1)
    {
        perror("shmdt");
        exit(1);
    }

    // Remove shared memory segment
    printf("Removing shared memory segment...\n");
    if (shmctl(shmid, IPC_RMID, 0) == -1)
    {
        perror("shmctl");
        printf("Can't Remove Shared memory Segment...\n");
    }
    else
    {
        printf("Removed Successfully\n");
    }

    return 0;
}
