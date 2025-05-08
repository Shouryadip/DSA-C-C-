#include<stdio.h>
#include<limits.h>
#define MAX 20
int arr[MAX][MAX];
int n;
int mst[MAX];

int key[MAX];
int parent[MAX];

void readGraph(){
	FILE *fp;
	fp=fopen("abc.txt","r");
	if(fp==NULL){
		printf("ERROR\n");
		return;
	}
	fscanf(fp,"%d",&n);
	printf("The number of vertex is: %d\n",n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&arr[i][j]);
		}
	}
	fclose(fp);
	return;
}
void showGraph(){
	printf("The adj Matrix is: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
int min_index(int a[]){
	int min=INT_MAX;
	int minIndex=-1;
	for(int i=0;i<n;i++){
		if(a[i]<min && mst[i]==0){
			min=a[i];
			minIndex=i;
		}
	}
	return minIndex;
}
void prims(int s){
	for(int i=0;i<n;i++){
		mst[i]=0;
		key[i]=INT_MAX;
		parent[i]=-2;
	}
	key[s]=0;
	parent[s]=-1;
	for(int j=0;j<n;j++){
		int u=min_index(key);
		mst[u]=1;
		for(int v=0;v<n;v++){
			if(arr[u][v]!=0 && mst[v]==0 && arr[u][v]<key[v]){
				parent[v]=u;
				key[v]=arr[u][v];
			}
		}
	}
	printf("\n");
}
int main(){
	readGraph();
	showGraph();
	char v;
	printf("Enter the start vertex: \n");
	v=(int)v;
	v-=65;
	prims(v);
	int total_cost=0;
	printf("Edges     cost\n");
	for(int i=0;i<n;i++){
		if(parent[i]!=0){
			printf("%c   %c   %d\n",parent[i]+65,i+65,key[i]);
			total_cost+=key[i];
		}
	}
	printf("The total cost of mst is %d\n",total_cost);
	return 0;
}
