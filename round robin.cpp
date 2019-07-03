#include<stdio.h>
#include<stdlib.h>

void sort(int* a, int *b,int n){
	int k,j,key1,key2;
	for(int i=0; i<n; i++){
		j=i-1;
		k=i-1;
		key1=a[i];
		key2=b[i];
		while(j>=0 && key1<a[j]){
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
	int* bt1=(int*)malloc(no_of_processes*sizeof(int));
	int* ct=(int*)malloc(no_of_processes*sizeof(int));
	int index,tq,c,r=0,f=0;
	int rq[100][2];
	
	
	printf("Enter time quantum: ");
	scanf("%d",&tq);
	
	printf("\nat bt\n");
	for(int i=0; i<no_of_processes; i++){
		scanf("%d%d",&at[i],&bt[i]);
		bt1[i]=bt[i];
	}
	printf("\n");
	
	sort(at,bt,no_of_processes);
	// copy the contents of bt into bt1
	
	for(int i=0; i<no_of_processes; i++)
		bt1[i]=bt[i];
	
	// printing the arrival and burst time
	
	for(int j=0; j<no_of_processes; j++){
		printf("%d %d\n",at[j],bt[j]);
	}
	printf("\n");
	
	// complete time
	
	if(bt[0]>tq){
		c=at[0]+tq;
		bt[0]=bt[0]-tq;
		ct[0]=c;
		rq[r][0]=c;
		rq[r][1]=0;
		r++;
	}
	else{
		c=at[0]+bt[0];
		ct[0]=c;
	}
	int i=1;
	while(i<no_of_processes){
		if(r!=0 && at[i]<=rq[f][0]){ // 
			if(bt[i]>tq){
				c=c+tq;
				ct[i]=c;
				bt[i]=bt[i]-tq;
				rq[r][0]=c;
				rq[r][1]=i;
				r++;
			}
			else{
				c=c+bt[i];
				ct[i]=c;
			}
			i++;
		}
		else if(r==0){
			if(bt[i]>tq){
				c=c+tq;
				bt[i]=bt[i]-tq;
				rq[r][0]=ct[i];
				rq[r][1]=i;
				r++;
			}
			else{
				c=c+bt[i];
				ct[i]=c;
			}
			i++;
		}
		else{
			index=rq[f][1];
			f++;
			if(bt[index]>tq){
				c=c+tq;
				ct[index]=c;
				bt[index]=bt[index]-tq;
				rq[r][0]=ct[index];
				rq[r][1]=index;
				r++;
			}
			else{
				c=c+bt[index];
				ct[index]=c;
			}
		}
	}
	while(f<r){
		index=rq[f][1];
		f++;
		if(bt[index]>tq){
				c=c+tq;
				ct[index]=c;
				bt[index]=bt[index]-tq;
				rq[r][0]=ct[index];
				rq[r][1]=index;
				r++;
		}
		else{
				c=c+bt[index];
				ct[index]=c;
		}
	}
	
	int* tat=(int*)malloc(no_of_processes*sizeof(int));
	for(int i=0; i<no_of_processes; i++){
		tat[i]=ct[i]-at[i];
	}
	
	int* wt=(int*)malloc(no_of_processes*sizeof(int));
	for(int i=0; i<no_of_processes; i++){
		wt[i]=tat[i]-bt1[i];
	}
	
	printf("at     bt      ct       tat    wt\n");
	for(int i=0; i<no_of_processes; i++){
		printf("%d\t%d\t%d\t%d\t%d\n",at[i],bt1[i],ct[i],tat[i],wt[i]);
	}
	
}
