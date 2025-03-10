#include <stdio.h>
void waitingTime(int p[], int n,int bt[],int wt[]){
	wt[0]=0;
	for(int i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
	}
}
void turnAroundTime(int p[], int n, int bt[],int wt[],int tat[]){
	for(int i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
	}
}
void findavgTime(int p[],int n, int bt[]){
	int wt[n],tat[n],total_wt=0,total_tat=0;
	waitingTime(p,n,bt,wt);
	turnAroundTime(p,n,bt,wt,tat);
	printf("Process   Burst_Time   Waiting_time   Turn_around_time\n");
	for(int i=0;i<n;i++){
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		printf("    %d ",p[i]);
		printf("            %d",bt[i]);
		printf("             %d",wt[i]);
		printf("              %d\n",tat[i]);
	}
	printf("\n");
	printf("\n");
	printf("\nGant chart:\n ");
	for(int i=0;i<n;i++){
		printf("| P%d\t",p[i]);
	}
	printf("|\n");
	printf(" 0\t");
	int time=0;
	for(int i=0;i<n;i++){
		time+=bt[i];
		printf("%d\t",time);
	}
	float avg_wt=(float)total_wt/(float)n;
	float avg_tat=(float)total_tat/(float)n;
	printf("\nAverage WT=%f",avg_wt);
	printf("\n");
	printf("Average TAT=%f",avg_tat);
}
void main(){
	int n,temp,i,j;
	printf("Enter the no of processes:");
	scanf("%d",&n);
	int processes [n],bt[n];	
	for(int i=1;i<=n;i++){
		processes[i-1]=i;
		}
	for(int i=0;i<n;i++){
		printf("Enter burst time of process P%d:",i+1);
		scanf("%d",&bt[i]);
		}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
		if(bt[i]>bt[j]){
			temp=bt[i];
			bt[i]=bt[j];
			bt[j]=temp;
			temp=processes[i];
			processes[i]=processes[j];
			processes[j]=temp;
		}}
	}
	findavgTime(processes , n, bt);
}
