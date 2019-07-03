#include<stdio.h>
#include<stdlib.h>

void sort(int* a, int *b,int st,int n){
	int k,j,key1,key2;
	for(int i=st; i<n; i++){
		j=i-1;
		k=i-1;
		key1=a[i];
		key2=b[i];
		while(j>=st && key1<a[j]){
			a[j+1]=a[j];
			b[k+1]=b[k];
			j--;
			k--;
		}
		a[j+1]=key1;
		b[k+1]=key2;
	}
}

int main(){
	int no_of_processes;
	printf("Enter How many no of processes you have? : ");
	scanf("%d",&no_of_processes);
	printf("\n");
	
	int* at=(int*)malloc(no_of_processes*sizeof(int));
	int* bt=(int*)malloc(no_of_processes*sizeof(int));
	
	printf("at bt\n");
	for(int i=0; i<no_of_processes; i++){
		scanf("%d%d",&at[i],&bt[i]);
	}
	printf("\n");
	
	sort(at,bt,0,no_of_processes);
	
	// printing the burst time
	
	for(int j=0; j<no_of_processes; j++){
				printf("%d %d\n",at[j],bt[j]);
			}
	printf("\n");
	
	
	int* ct=(int*)malloc(no_of_processes*sizeof(int));
	
	ct[0]=at[0]+bt[0];
	for(int i=1;i<no_of_processes;i++){
		if(ct[i-1]>at[i]){
			sort(bt,at,i,no_of_processes);/*
			for(int j=i; j<no_of_processes; j++){
				printf("%d %d\n",at[j],bt[j]);
			}*/
			ct[i]=ct[i-1]+bt[i];
		}
		else{
			ct[i]=at[i]+bt[i];
		}
		printf("%d %d %d\n",at[i],bt[i],ct[i]);
	}
	
	int* tat=(int*)malloc(no_of_processes*sizeof(int));
	for(int i=0; i<no_of_processes; i++){
		tat[i]=ct[i]-at[i];
	}
	
	int* wt=(int*)malloc(no_of_processes*sizeof(int));
	for(int i=0; i<no_of_processes; i++){
		wt[i]=tat[i]-bt[i];
	}
	
	printf("at     bt      ct       tat    wt\n");
	for(int i=0; i<no_of_processes; i++){
		printf("%d\t%d\t%d\t%d\t%d\n",at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	
}
