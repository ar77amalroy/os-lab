#include<stdio.h>
void main(){
	int n;
	printf("Enter the num of processes:");
	scanf("%d",&n);
	
	int bt[n],wt[n],tat[n],pr[n],pid[n];
	int avgt=0,avgw=0;
	
	for(int i=0;i<n;i++){
		printf("Enter bt and priority for process %d:",i+1);
		scanf("%d %d",&bt[i],&pr[i]);
		pid[i]=i+1;
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(pr[i]>pr[j]){
				int temp=pr[i];
				pr[i]=pr[j];
				pr[j]=temp;
				
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				
				temp=pid[i];
				pid[i]=pid[j];
				pid[j]=temp;
			}
		}
	}
	wt[0]=0;
	for(int i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
	}
	for(int i=0;i<n;i++){
		tat[i]=wt[i]+bt[i];
	}
	for(int i=0;i<n;i++){
		avgt+=tat[i];
		avgw+=wt[i];
	}
	printf("\nPID\tBT\tPriority\tWT\tTAT\n");
	for(int i=0;i<n;i++){
		printf("P%d\t%d\t%d\t\t%d\t%d\n",pid[i],bt[i],pr[i],wt[i],tat[i]);
	}
	avgt/=n;
	avgw/=n;
	printf("\nGantt Chart:\n|");
	for(int i=0;i<n;i++){
		printf("P%d |",pid[i]);
	}
	printf("\n0  ");
	for(int i=0;i<n;i++){
		printf(" %d ",tat[i]);
	}
	printf("\n\nAvg WT=%d\n",avgw);
	printf("Avg TAT=%d\n",avgt);
}
