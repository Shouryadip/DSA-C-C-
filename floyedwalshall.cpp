#include<stdio.h>
#include<limits.h>
#define MAX 20
#define INF 9999
int arr[MAX][MAX];
int key[MAX][MAX];
int n;
void readGraph(){
	FILE *fp;
	fp=fopen("abc.txt","r");
	if(fp==NULL){
		printf("ERROR\n");
		return;
	}
	fscanf(fp,"%d",&n);
	printf("The number of vertex is: %d",n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp "%d ",&arr[i][j]);
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
int min(int a,int b){
	return (a<b)?a:b;
}
void flyodwarshall(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==0 && i!=j)
				key[i][j]=INF;
			else
				key[i][j]=arr[i][j];
		}
	}
	printf("\n first step: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(key[i][j]=INF)
				printf("INF ");
			else
				printf("%3d ",key[i][j]);
		}
		printf("\n");
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(key[i][j]>key[i][k]+key[k][j])
					key[i][j]=key[i][k]+key[k][j];
			}
		}
		printf("\n THE next step: \n");
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(key[i][j]=INF)
					printf("INF ");
				else
					printf("%3d ",key[i][j]);
			}
			printf("\n");
		}
	}
}
int main(){
	readGraph();
	showGraph();
	flyodwarshall();
	printf("path      cost\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%c-->%c    %d",i+65,j+65,key[i][j]);
		}
	}
	return 0;
}
