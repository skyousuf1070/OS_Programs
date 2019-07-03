#include<stdio.h>
#include<stdlib.h>

int main(){
	int no_of_processes;
	printf("Enter no.of processes: ");
	scanf("%d",&no_of_processes);
	
	int* pro=(int *)malloc(no_of_processes*sizeof(int));
	int* bt=(int*)malloc(no_of_processes*sizeof(int));
	for(int i=0; i<no_of_processes; i++){
		printf("Enter Burst Time of process %d: ",i+1);
		scanf("%d",&bt[i]);
		pro[i]=i+1;
	}
	printf("\n");
	
	// sort the burst time
	int j,k,key,pro_key;
	for(int i=1; i<no_of_processes; i++){
		j=i-1;
		key=bt[i];
		pro_key=pro[i];
		k=i-1;
		while(j>=0 && key<bt[j]){
			bt[j+1]=bt[j];
			pro[k+1]=pro[k];
			j--;
			k--;
		}
		bt[j+1]=key;
		pro[k+1]=pro_key;
	}
	
	// printing the burst time
	/*
	for(int i=0; i<no_of_processes; i++){
		printf("%d\t%d\n",pro[i],bt[i]);
	}
	printf("\n");
	*/
	
	int* ct=(int*)malloc(no_of_processes*sizeof(int));
	ct[0]=bt[0];
	for(int i=1;i<no_of_processes;i++){
		ct[i]=bt[i]+ct[i-1];
	}
	
	int* tat=(int*)malloc(no_of_processes*sizeof(int));
	for(int i=0; i<no_of_processes; i++){
		tat[i]=ct[i]-0;
	}
	
	int* wt=(int*)malloc(no_of_processes*sizeof(int));
	for(int i=0; i<no_of_processes; i++){
		wt[i]=tat[i]-bt[i];
	}
	
	printf("process at     bt      ct       tat    wt\n");
	for(int i=0; i<no_of_processes; i++){
		printf("%d\t0\t%d\t%d\t%d\t%d\n",pro[i],bt[i],ct[i],tat[i],wt[i]);
	}
	
	
}
