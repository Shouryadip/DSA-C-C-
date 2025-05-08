#include<stdio.h>
#include<limits.h>
#define MAX 20
int arr[MAX][MAX];
int n;
int visit[MAX];
int key[MAX];
void readGraph(){
	FILE *fp;
	fp=fopen("abc.txt","r");
	if(fp==NULL){
		printf("ERROR:\n");
		return;
	}
	fscanf(fp,"%d",&n);
	printf("The number of vertex is %d\n",n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&arr[i][j]);
		}
	}
	fclose(fp);
	return;
}
void showGraph(){
	printf("The adj matrix is: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
}
int index_min(int a[]){
	int min=INT_MAX;
	int minIndex=-1;
	for(int i=0;i<n;i++){
		if(a[i]<min && visit[i]==0){
			min=a[i];
			minIndex=i;
		}
	}
	return minIndex;
}
void dijkstra(int s){
	for(int i=0;i<n;i++){
		visit[i]=0;
		key[i]=INT_MAX;
	}
	key[s]=0;
	for(int j=0;j<n;j++){
		int u=index_min(key);
		if(u==-1)
			break;
		visit[u]=1;
		for(int v=0;v<n;v++){
			if(arr[u][v]!=0 && visit[v]==0 && key[u]+arr[u][v]<key[v]){
				key[v]=key[u]+arr[u][v];
			}
		}
	}
	printf("\n");
}
int main(){
	readGraph();
	showGraph();
	char v;
	printf("ENter the vertex: ");
	scanf("%c",&v);
	v=(int)v;
	v-=65;
	dijkstra(v);
	printf("From source: %c\n",v+65);
	printf("vertex     cost\n");
	for(int i=0;i<n;i++){
		if(visit[i]==1){
			printf("%c      %d\n",i+65,key[i]);
		}
		else{
			printf("%c   No path from source\n",i+65);
		}
	}
	return 0;
}
