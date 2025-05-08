/*#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int *x;
int count=0;
bool place(int k,int i){
	for(int j=0;j<k;j++){
		if(x[j]==i || abs(x[j]-i)==abs(j-k))
		return false;
	}
	return true;
}
void Nqueen(int k,int n){
	for(int i=0;i<n;i++){
		if(place(k,i)){
			x[k]=i;
			if(k==n-1){
				count++;
				for(int j=0;j<n;j++)
					printf("%d",x[j]+1);
				printf("\n");
			}
			else
				Nqueen(k+1,n);
		}
	}
}
int main(){
	int n;
	printf("Enter the row or coloumn size of the chase board: ");
	scanf("%d",&n);
	x=(int *)calloc(n, sizeof(int));
	Nqueen(0,n);
	printf("Total possibile solution: %d\n",count);
	free(x);
	return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int *x;
int count=0;
bool place(int k,int i){
	for(int j=0;j<k;j++){
		if(x[j]==i || abs(x[j]-i)==abs(j-k))
		return false;
	}
	return true;
}
void Nqueen(int k,int n){
	for(int i=0;i<n;i++){
		if(place(k,i)){
			x[k]=i;
			if(k==n-1){
				count++;
				for(int j=0;j<n;j++)
					printf("%d",x[j]+1);
				printf("\n");
			}
			else
				Nqueen(k+1,n);
		}
	}
}
int main(){
	int n;
	printf("enter the size: ");
	scanf("%d",&n);
	x=(int *)calloc(n, sizeof(int));
	Nqueen(0,n);
	printf("Total numbers of solution: %d\n",count);
	free(x);
	return 0;
}

