#include<stdio.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void selectionSort(int arr[],int n){
	int i,j,minIndex;
	
	for(i=0;i<n-1;i++){
		minIndex =i;
		for(j=i+1;j<n;j++){
			if(arr[j],arr[minIndex]){
				minIndex=j;
			}
		}
		swap(&arr[minIndex],&arr[i]);
	}
}
int main(){
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter %d elemets: \n",n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	selectionSort(arr,n);
	
	printf("Sorted array::\n");
	for(int i=0;i<n;i++){
		printf("%d ",&arr[i]);
	}
	return 0;
}
