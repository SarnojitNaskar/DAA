#include<stdio.h>
int main(){
	int a[20], i, n, lb, ub, mid, item;
	printf("Enter the size of the array : ");
	scanf("%d", &n);
	printf("Enter the elements of the array : \n");
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	printf("Elements in array : ");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\nEnter an element for search : ");
	scanf("%d", &item);
	lb=0;
	ub=n-1;
	while(lb<=ub){
		mid=(lb+ub)/2;
		{
			if(a[mid]==item){
				printf("%d at location %d", item, mid+1);
				break;
			}
			else if(a[mid]>item){
				ub=mid-1;
			}
			else{
				ub=mid+1;
			}
		}
	}
	return 0;
}
