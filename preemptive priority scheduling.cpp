#include<stdio.h>
#include<stdlib.h>
# define MAX_VALUE 9999;

void sort(int* a, int *b,int* pt,int *pro,int n){
	int j,key1,key2,key3,key4;
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

int findLeastPriority(int* priority, int* at, int ct,int n){
	int min_value=priority[0];
	int min_index=0;
	for(int i=0; i<n && at[i]<=ct; i++){
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
	int at[n],bt[n],bt1[n],pt[n],pt1[n],ct[n],tat[n],wt[n],pro[n];
	printf("\npriority at bt\n");
	for(int i=0; i<n; i++){
		scanf("%d%d%d",&pt[i],&at[i],&bt[i]);
		pro[i]=i+1;
	}
	
	sort(at,bt,pt,pro,n);
	for(int i=0; i<n; i++)
	{
		bt1[i]=bt[i];
		pt1[i]=pt[i];
	}
	// calculating complete time
	
	printf("\nGantt Chart\n");
	
	int prev_i,c,i,loop_count=n;
	i=findLeastPriority(pt,at,at[0],n);
	printf("p%d ",pro[i]);
	c=at[i]+1;
	ct[i]=c;
	bt[i]--;
	
	if(bt[i]==0)
	{
		pt[i]=MAX_VALUE;
		loop_count--;
	}
	
	while(loop_count>0)
	{
		//printf("lc=%d\n",loop_count);
		prev_i=i;
		i=findLeastPriority(pt,at,c,n);
		//printf("i=%d\n",i);
		if(prev_i!=i)
			printf("p%d ",pro[i]);
		c++;
		ct[i]=c;
		bt[i]--;
		if(bt[i]==0)
		{
			pt[i]=MAX_VALUE;
			loop_count--;
		}
	}
	
	// calculating waiting and turn around time
	float sum_tat=0.0,sum_wt=0.0;
	for(int i=0; i<n; i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt1[i];
		sum_tat=sum_tat+tat[i];
		sum_wt=sum_wt+wt[i];
	}
	
	
	
	printf("\n\npro     pt      at      bt      ct      tat     wt\n");
	for(int i=0; i<n; i++){
		printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pro[i],pt1[i],at[i],bt1[i],ct[i],tat[i],wt[i]);
	}
	
	printf("\nAvg Turn Around Time: %.2f\nAvg Waiting Time: %.2f\n",sum_tat/n,sum_wt/n);
}
