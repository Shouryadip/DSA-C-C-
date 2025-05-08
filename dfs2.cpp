#include<stdio.h>
#define MAX 20
int arr[MAX][MAX];
int visit[MAX];
int n;

int s[MAX];
int top=-1;

int isEmpty(){
	if(top==-1)
		return 1;
	return 0;
}
int insert(int item){
	s[top++]=item;
}
int del(){
	return s[top--];
}
void readGraph(){
	FILE *fp;
	fp=fopen("abc.txt","r");
	if(fp==NULL){
		printf("ERROR file not opened\n");
		return;
	}
	fscanf(fp,"%d",&n);
	printf("The number of vertex: %d\n",n);
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
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
void dfs(int v){
	for(int u=0;u<n;u++)
		visit[u]=0;
	insert(v);
	visit[v]=1;
	while(isEmpty()==0){
		u=del();
		printf("%c ->", u+65);
		for(int j=0;j<n;j++){
			if(arr[u][j]==1){
				if(visit[j]==0){
					insert(j);
					visit[j]=1;
				}
			}
		}
	}
	printf("DONE\n");
}
int main(){
	readGraph();
	showGraph();
	char v;
	printf("\nEnter start vertex-> ");
	scanf("%c",&v);
	v=(int)v;
	v-=65;
	printf("DFS: \n");
	dfs(v);
	return 0;
}
