#include<stdio.h>
void implementBestFit(int bSize[], int blocks, int pSize[], int processes)
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
       int indexPlaced=-1;
       for(int j=0;j<blocks;j++){
         if(bSize[j]>=pSize[i] && !occupied[j]){
          if(indexPlaced==-1)
           indexPlaced=j;
          else if(bSize[j]<bSize[indexPlaced])
           indexPlaced=j;
         }
       }
       if(indexPlaced!=-1){
         allocate[i]=indexPlaced;
         occupied[indexPlaced]=1;
       }
       
       
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("P%d \t\t%d \t\t", i+1, pSize[i]);
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
    int bSize[m];
    int pSize[n];
    printf("Enter the block size:\n ");
    for(int i=0;i<m;i++){
     printf("Block %d: ",i+1);
     scanf("%d",&bSize[i]);
    }
    printf("Enter the process size:\n ");
    for(int i=0;i<n;i++){
     printf("process %d: ",i+1);
     scanf("%d",&pSize[i]);
    }
    implementBestFit(bSize, m, pSize, n);
}	
		

