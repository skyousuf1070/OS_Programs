#include<stdio.h>
#include<stdlib.h>
# define MAX_VALUE 9999;

void sort(int* a, int *b,int* pt,int *pro,int n){
	int k,j,key1,key2,key3,key4;
	for(int i=1; i<n; i++){
		j=i-1;
		key1=a[i];
		key2=b[i];
		key3=pt[i];
		key4=pro[i];
		while(j>=0 && key1<a[j]){
			a[j+1]=a[j];
			b[j+1]=b[j];
			pro[j+1]=pro[j];
			pt[j+1]=pt[j];
			j--;
		}
		a[j+1]=key1;
		b[j+1]=key2;
		pt[j+1]=key3;
		pro[j+1]=key4;
	}
}

int findLeastPriority(int* priority,int n){
	int min_value=priority[0];
	int min_index=0;
	for(int i=1; i<n; i++){
		if(priority[i]<min_value){
			min_value=priority[i];
			min_index=i;
		}
	}
	return min_index;
}

int findLeastPriority(int* priority, int* at, int ct){
	int min_value=priority[0];
	int min_index=0;
	for(int i=0; at[i]<=ct; i++){
		if(priority[i]<min_value){
			min_value=priority[i];
			min_index=i;
		}
	}
	return min_index;
}

int main(){
	int n;
	printf("Enter no of processes: ");
	scanf("%d",&n);
	int at[n],bt[n],pt[n],pt1[n],ct[n],tat[n],wt[n],pro[n];
	printf("\npriority at bt\n");
	for(int i=0; i<n; i++){
		scanf("%d%d%d",&pt[i],&at[i],&bt[i]);
		pro[i]=i+1;
	}
	
	int c,i=0,index=1;
	sort(at,bt,pt,pro,n);
	for(int i=0; i<n; i++)
		pt1[i]=pt[i];
	
	// calculating complete time
	
	printf("Gantt Chart\n");
	c=at[0]+bt[0];
	ct[0]=c;
	pt[0]=MAX_VALUE;
	printf("p%d ",pro[0]);
	while(index<n){
		if(ct[i]>=at[n-1]){
			i=findLeastPriority(pt,n);
			pt[i]=MAX_VALUE;
			printf("p%d ",pro[i]);
			c+=bt[i];
			ct[i]=c;
		}
		else{
			i=findLeastPriority(pt,at,c);
			pt[i]=MAX_VALUE;
			printf("p%d ",pro[i]);
			c+=bt[i];
			ct[i]=c;
		}
		index++;
	}
	
	// calculating waiting and turn around time
	float sum_tat=0,sum_wt=0;
	for(int i=0; i<n; i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		sum_tat+=tat[i];
		sum_wt+=wt[i];
	}
	
	printf("\n\npro     pt      at      bt      ct      tat     wt\n");
	for(int i=0; i<n; i++){
		printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pro[i],pt1[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	
	printf("\nAvg Turn Around Time: %.2f\nAvg Wating Time: %.2f\n",sum_tat/n,sum_wt/n);
}
