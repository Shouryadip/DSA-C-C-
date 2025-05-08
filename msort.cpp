#include<stdio.h>
void print(int a[],int low,int high){
	for(int i=low;i<=high;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void merge(int a[],int low,int mid,int high){
	int b[50];
	int i=low,j=mid+1,k=low;
	while(i<=mid && j<=high){
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid){
		b[k++]=a[i++]; 
	}
	while(j<=high){
		b[k++]=a[j++];
	}
	for(int p=low;p<=high;p++)
		a[p]=b[p];
}
void msort(int a[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		printf("L array: ");
		print(a,low,mid);
		printf("R array: ");
		print(a,mid+1,high);
		msort(a,low,mid);
		msort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main(){
	int n;
	int arr[50];
	printf("Enter the number of array: \n");
	scanf("%d",&n);
	printf("Enter the elemts: \n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	print(arr,0,n-1);
	msort(arr,0,n-1);
	printf("After sorting: \n");
	print(arr,0,n-1);
	return 0;
}
