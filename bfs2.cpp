#include<stdio.h> 
#define MAX 20 
 
int arr[MAX][MAX]; 
int n; 
int visit[MAX]; 
 
int Q[MAX]; 
int front=-1; 
int rear=-1; 
 
int isEmpty(){ 
    if(rear==front) 
        return 1; 
    return 0; 
} 
 
void insert(int item){ 
    rear=rear+1; 
    Q[rear]=item; 
} 
 
int del(){ 
    front=front+1; 
    return Q[front]; 
} 
 
void readGraph(){ 
    FILE* fp; 
    fp=fopen("exp.txt","r"); 
    if(fp==NULL){ 
        printf("File open failed.\n"); 
        return; 
    } 
    fscanf(fp,"%d",&n); 
    printf("Number of vertices...%d\n",n); 
    int i,j; 
    for(i=0;i<n;i++){ 
        for(j=0;j<n;j++){ 
            fscanf(fp,"%d",&arr[i][j]); 
        } 
    } 
    fclose(fp); 
    return; 
} 
 
void showGraph(){ 
    int i,j; 
    printf("The Adjacency Matrix is: \n"); 
    for(i=0;i<n;i++){ 
        for(j=0;j<n;j++){ 
            printf("%d  ",arr[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
void bfs(int v){ 
    int u; 
    for(u=0;u<n;u++) 
        visit[u]=0; 
    insert(v); 
    visit[v]=1; 

 
    while(isEmpty()==0){ 
        u=del(); 
        printf("%c -> ", u+65); 
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
    printf("\nEnter start vertex--> "); 
    scanf("%c",&v); 
    v=(int) v; 
    v-=65; 
    printf("BFS: "); 
    bfs(v); 
    return 0; 
}
