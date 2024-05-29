#include<stdio.h>

int partition(int a[], int p, int r){
	int x, i, j, temp;
	x=a[p];
	i=p-1;
	j=r+1;
	while(1){
		do{
			i++;
		}while(a[i]<x);
		do{
			j--;
		}while(a[j]>x);
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}else{
			return(j);
		}
	}
}

void quicksort(int a[], int p, int r){
	int q;
	if(p<r){
		q=partition(a, p, r);
		quicksort(a, p, q);
		quicksort(a, q+1, r);
	}
}

int main(){
        int a[20], i, n;
        printf("Enter the size of the array : ");
        scanf("%d", &n);
        printf("Enter the elements of the array : \n");
        for(i=0;i<n;i++){
                scanf("%d", &a[i]);
        }
        printf("Before Sorting : ");
        for(i=0;i<n;i++){
                printf("%d ",a[i]);
        }
        quicksort(a, 0, n-1);
        printf("\nAfter Sorting : ");
        for(i=0;i<n;i++){
                printf("%d ",a[i]);
        }
        printf("\n");
        return 0;
}

