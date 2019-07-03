#include<stdio.h>
#include<stdlib.h>

int main(){
	int no_of_processes;
	printf("Enter How many no of processes you have? : ");
	scanf("%d",&no_of_processes);
	printf("\n");
	
	int* bt=(int*)malloc(no_of_processes*sizeof(int));
	int* ct=(int*)malloc(no_of_processes*sizeof(int));
	int* tat=(int*)malloc(no_of_processes*sizeof(int));
	int* wt=(int*)malloc(no_of_processes*sizeof(int));
	
	printf("bt\n");
	for(int i=0; i<no_of_processes; i++){
		scanf("%d",&bt[i]);
	}
	printf("\n");
	
	/*	
	for(int i=0; i<no_of_processes; i++){
		printf("%d %d\n",at[i],bt[i]);
	}
	*/
	
	int sum_tat=0,sum_wt=0;
	ct[0]=bt[0];
	tat[0]=ct[0];
	wt[0]=tat[0]-bt[0];
	for(int i=1;i<no_of_processes;i++){
		ct[i]=bt[i]+ct[i-1];
		tat[i]=ct[i];
		wt[i]=tat[i]-bt[i];
		sum_tat+=tat[i];
		sum_wt+=wt[i];
	}
	
	printf("at     bt      ct       tat    wt\n");
	for(int i=0; i<no_of_processes; i++){
		printf("%d\t%d\t%d\t%d\t%d\n",0,bt[i],ct[i],tat[i],wt[i]);
	}
	
	printf("Avg Turn Around Time: %d\nAvg Wating Time: %d\n",sum_tat/no_of_processes,sum_wt/no_of_processes);
}
