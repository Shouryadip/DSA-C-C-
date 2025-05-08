#include<stdio.h>
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
int part(int arr[],int low,int high){
	int big=arr[high];
	int i=(low-1);
	for(int j=low;j<=high;j++){
		if(arr[j]<big){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}
void quick_sort(int arr[],int low,int high){
	if(low<high){
		int p=part(arr,low,high);
		quick_sort(arr,low,p-1);
		quick_sort(arr,p+1,high);
	}
}
int main(){
	int arr[100],n,i;
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	printf("Enter %d elements: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	quick_sort(arr,0,n-1);
	printf("Sorted array: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
