#include <stdio.h>
void implimentFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocate[processes];
    int occupied[blocks];
    for(int i = 0; i < processes; i++)
 {
  allocate[i] = -1;
 }
 for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++) 
        { 
        if (!occupied[j] && blockSize[j] >= processSize[i])
            {
                allocate[i] = j;
                occupied[j] = 1;
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("P%d \t\t%d \t\t", i+1, processSize[i]);
        if (allocate[i] != -1)
            printf("B%d\n",allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void main()
{
 int m,n;
 printf("Enter the no of blocks: ");
 scanf("%d",&m);
 printf("Enter the no of process: ");
 scanf("%d",&n);
    int blockSize[m];
    int processSize[n];
    printf("Enter the block size:\n ");
    for(int i=0;i<m;i++){
     printf("Block %d: ",i+1);
     scanf("%d",&blockSize[i]);
    }
    printf("Enter the process size:\n ");
    for(int i=0;i<n;i++){
     printf("process %d: ",i+1);
     scanf("%d",&processSize[i]);
    }
    implimentFirstFit(blockSize, m, processSize, n);
}
