#include<stdio.h> 
#include<limits.h> 
#define MAX 20 
int p[MAX]; 
int s[MAX][MAX]; 
int m[MAX][MAX]; 
int n;  
void matrix_mult(){ 
    for(int i=1;i<n;i++){ 
        m[i][i]=0; 
    } 
    for(int len=2;len<=n;len++){ 
        for(int i=1;i<=n-len+1;i++){ 
            int j=i+len-1; 
            m[i][j]=INT_MAX; 
            for(int k=i;k<j;k++){ 
                int c=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; 
                if(c<m[i][j]){ 
                    m[i][j]=c; 
                    s[i][j]=k; 
                } 
            } 
        } 
    } 
} 
 
void matrix_display(int i, int j){ 
    if(i==j) 
        printf("A%d",i); 
    else{
    	 printf("("); 
        matrix_display(i,s[i][j]); 
        matrix_display(s[i][j]+1,j); 
        printf(")"); 
    } 
} 
 
int main(){ 
    printf("Enter the number of matrix: "); 
    scanf("%d",&n); 
    printf("Enter the array p: "); 
    for(int i=0;i<=n;i++){ 
        scanf("%d",&p[i]); 
    } 
    matrix_mult(); 
    printf("\nThe m matrix is: \n"); 
    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=n;j++){ 
            printf("%3d  ",m[i][j]); 
        }printf("\n"); 
    } 
    printf("\nThe s matrix is: \n"); 
    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=n;j++){ 
            printf("%3d  ",s[i][j]); 
        }printf("\n"); 
    } 
    matrix_display(1,n); 
    printf("\nNo. of scaler multiplication is %d.\n",m[1][n]); 
    return 0; 
} 
