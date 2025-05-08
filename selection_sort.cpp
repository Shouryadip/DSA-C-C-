#include<stdio.h>
void selection_sort(int arr[],int n){
	int i,j,minIndex,temp;
	for(i=0;i<n-1;i++){
		minIndex=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[minIndex]){
				minIndex=j;
			}
		}
		temp=arr[minIndex];
		arr[minIndex]=arr[i];
		arr[i]=temp;
	}
}
int main(){
	int arr[100],n,i;
	printf("Enter no of elemets: ");
	scanf("%d",&n);
	printf("Enter %d elemets:",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,n);
	printf("Sorted array:\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return 0;
}
