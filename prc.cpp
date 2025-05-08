/*#include<stdio.h>
#define MAX 20
int a[MAX][MAX];
int visit[MAX];
int n;
int Q[MAX];
int front=-1,rear=-1;
int isEmpty(){
	if(front==rear)
		return 1;
	return 0;
}
void insert(int m){
	rear=rear+1;
	Q[rear]=m;
}
int del(){
	front=front+1;
	return Q[front];
}
void readGraph(){
	FILE *fp;
	fp=fopen("abc.txt","r");
	if(fp==NULL)
		printf("Error:");
	fscanf(fp,"%d",&n);
	printf("The vertex is: %d",n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&a[i][j]);
		}
	}
	fclose(fp);
	return;
}
void showGraph(){
	printf("The Adjacent matrix is: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void bfs(int v){
	for(int i=0;i<n;i++)
		visit[i]=0;
	insert(v);
	visit[v]=1;
	while(isEmpty()==0){
		i=del();
		printf("%c -> "i+65);
		for(int j=0;j<n;j++){
			if(a[i][j]==1){
				if(visit[j]==0){
					insert(j);
					visit[j]==1;
				}
			}
		}
	}
}
int main(){
	char v;
	printf("Enter the 1st vertex: \n");
	scanf("%c",&v);
	v=(int)v;
	v-=65;
	printf("BFS: \n");
	bfs(v);
	return 0;
}

#include<stdio.h>
#define MAX 20
int a[MAX][MAX];
int visit[MAX];
int n;
int s[MAX];
int top=-1;
int isEmpty(){
	if(top==-1)
		return 1;
	return 0;
}
void insert(int value){
	s[top++]=value;
}
int del(){
	return s[top--];
}
void readGraph(){
	FILE *fp;
	fp=fopen("exp.txt","r");;
	if(fp==NULL){
		printf("ERROR:");
		return;
	}
	fscanf(fp,"%d",&n);
	printf("The number of vertex: %d",n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",a[i][j]);
		}
	}
	fclose(fp);
	return;
}
void showGraph(){
	printf("The adj matrix is: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void dfs(int v){
	for(int i=0;i<n;i++){
		visit[i]=0;
	}
	insert(v);
	visit[v]=1;
	while(isEmpty()==0){
		i=del();
		printf("%c -> ",i+65);
		for(int j=0;j<n;j++){
			if(a[i][j]==0){
				if(visit[j]==0){
					insert(j);
					visit[j]=1;
				}
			}
		}
	}
}
int main(){
	readGraph();
	showGraph();
	char v;
	printf("Enter the starting vertex: \n");
	scanf("%c",&v);
	v=(int)v;
	v-=65;
	printf("DFS \n");
	dfs(v);
	return 0;
}*/


#include<stdio.h>
#include<limits.h>
#define MAX 20
int a[MAX][MAX];
int visit[MAX];
int key[MAX];
int n;
void readGraph(){
	FILE *fp;
	fp=fopen("exp.txt","r");
	if(fp==NULL){
		printf("ERROR");
		return;
	}
	fscanf(fp,"%d",&n);
	printf("The number of vertex is: %d",n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&a[i][j]);
		}
	}
	fclose(fp);
	return;
}
void showGraph(){
	printf("The adj matrix is: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
int minIndex(int a[]){
	int min= INT_MAX;
	int minindex=-1;
	for(int i=0;i<n;i++){
		if(a[i]<min && visit[i]==0){
			min=a[i];
			minindex=i;
		}
	}
	return minindex;
}
void dijktra(int s){
	for(int i=0;i<n;i++){
		visit[i]=0;
		key[i]=INT_MAX;
	}
	key[s]=0;
	for(int j=0;j<n;j++){
		int u=minIndex(key);
		if(u==-1)
			break;
		for(int v=0;v<n;v++){
			if(a[u][v]!=0 && visit[v]==0 && key[u]+a[u][v]<key[v]){
				key[v]=key[u]+a[u][v];
			}
		}
	}
	printf("\n");
}
int main(){
	readGraph();
	showGraph();
	char v;
	printf("Enter the starting vertex: \n");
	scanf("%c",&v);
	v=(int)v;
	v-=65;
	dijktra(v);
	printf("From source: %c\n",v+65);
	printf("vertex          cost\n");
	printf("______          _______\n");
	for(int i=0;i<n;i++){
		if(visit[i]==0)
			printf("%c           %d\n",i+65,key[i]);
		else
			printf("%c        no path from source",i+65);
	}
	return 0;
}

