#include<stdio.h>
#include<stdlib.h>

void sort(int* a, int *b,int n){
	int j,k,key,pro_key;
	for(int i=1; i<n; i++){
		j=i-1;
		k=i-1;
		key=a[i];
		pro_key=b[i];
		while(j>=0 && key<a[j]){
			a[j+1]=a[j];
			b[k+1]=b[k];
			j--;
			k--;
		}
		a[j+1]=key;
		b[k+1]=pro_key;
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
	
	sort(at,bt,no_of_processes);
	/*	
	for(int i=0; i<no_of_processes; i++){
		printf("%d %d\n",at[i],bt[i]);
	}
	*/
	
	int* ct=(int*)malloc(no_of_processes*sizeof(int));
	ct[0]=at[0]+bt[0];
	for(int i=1;i<no_of_processes;i++){
		if(ct[i-1]>at[i])
			ct[i]=bt[i]+ct[i-1];
		else
			ct[i]=(at[i]-ct[i-1])+bt[i]+ct[i-1];
	}
	int* tat=(int*)malloc(no_of_processes*sizeof(int));
	int* wt=(int*)malloc(no_of_processes*sizeof(int));
	int sum_tat=0,sum_wt=0;
	for(int i=0; i<no_of_processes; i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		sum_tat+=tat[i];
		sum_wt+=wt[i];
	}
	
	printf("at     bt      ct       tat    wt\n");
	for(int i=0; i<no_of_processes; i++){
		printf("%d\t%d\t%d\t%d\t%d\n",at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	
	printf("Avg Turn Around Time: %d\nAvg Wating Time: %d\n",sum_tat/no_of_processes,sum_wt/no_of_processes);
}
