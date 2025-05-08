#include<stdio.h>
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void print(int a[],int low,int high){
	for(int i=low;i<=high;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int partition(int a[],int low,int high){
	int pivot=a[high];
	int i=low-1;
	for(int j=low;j<=high;j++){
		if(a[j]<pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[high],&a[i+1]);
	return i+1;
}
void qsort(int a[],int low,int high){
	if(low<high){
	int p=partition(a,low,high);
	qsort(a,low,p-1);
	qsort(a,p+1,high);
	}
}
int main(){
	int n;
	int arr[50];
	printf("Enter the number of array: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
	}
	print(arr,0,n-1);
	qsort(arr,0,n-1);
	printf("After sorting: \n");
	print(arr,0,n-1);
	return 0;
}
