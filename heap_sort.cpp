#include<stdio.h>
void heap(int arr[],int n,int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[largest])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(largest!=i){
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		heap(arr,n,largest);
	}
}
void heap_sort(int arr[],int n){
	for(int i=n/2-1;i>=0;i--)
		heap(arr,n,i);
	for(int i=n-1;i>0;i--){
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		heap(arr,i,0);
	}
}
int main(){
	int arr[100],n,i;
	printf("Enter the no of element: ");
	scanf("%d",&n);
	printf("Enter %d elements: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	heap_sort(arr,n);
	printf("Sorted array: \n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
