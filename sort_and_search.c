#include<stdio.h>
#include<stdlib.h>
# define max 100

int arr[max],i,j,n;


void bubble_sort(){

	for(i=0;i<n-1;i++){
	
		for(j=0;j<n-1-i;j++){
			
			if(arr[j]>arr[j+1]){
				
				int temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	printf("sorted elements = ");
		
	for(i=0;i<n;i++){
		
		printf("\t%d",arr[i]);
	} 
}

void selection_sort(){
	int min,temp;
	
	for(i=0;i<n-1;i++){
	
		min=i;
		for(j=i+1;j<n;j++){
		
			if(arr[j]<arr[min]){
			
				min=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;	
	}
	
	printf("sorted elements = ");
		
	for(i=0;i<n;i++){
		
		printf("\t%d",arr[i]);
	} 
}

void insertion_sort(){
	int key;
	
	for(i=1;i<n;i++){
	
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
		
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;	
	}
	
	printf("sorted elements = ");
		
	for(i=0;i<n;i++){
		
		printf("\t%d",arr[i]);
	} 
	
	
}



void linear_search(int ele){
	int found=0;
	for(i=0;i<n;i++){
	
		if(arr[i]==ele){
		
			found=1;
			printf("%d found on location %d ",ele,i+1);
			break;
		}
	}
	
	if(found==0){
	
		printf("%d element not found",ele);
	}
}

void binary_search(int ele){

	int low,high,mid,found;
	low=0;
	high=n-1;
	found=0;
	
	while(low<=high){
	
		mid=(low+high)/2;
		if(ele<arr[mid]){
		
			high=mid-1;
		}
		else if(ele>arr[mid]){
		
			low=mid+1;
		}
		else{
			printf("%d found on location %d",ele,mid+1);
			found=1;
			break;	
		} 
	
	
	}
	
	if(found==0){
	
		printf("ELEMENT NOT FOUND");
	}

}



int main(){
	
	int choice;
	int l,h,ele;
	l=0;
	h=n;
	
	printf("Enter no of elements to insert");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
	
		printf("Enter %d element",i+1);
		scanf("%d",&arr[i]);
		
	} 
	printf("Entered elements = ");
	
	for(i=0;i<n;i++){
	
		printf("\t%d",arr[i]);
	} 
	
	while(1){
	
		printf("\n  CHOICE MENU \n 1) BUBBLE SORT \n 2) SELECTION SORT \n 3) INSERTION SORT \n 4) EXIT ");
		printf("\n 5) LINEAR SEARCH \n 6) BINARY SEARCH \n Enter your choice");
		scanf("%d",&choice);
		
		switch(choice){
		
			case 1:
				bubble_sort();
				break;
				
			case 2:
				selection_sort();
				break;
			
			case 3:
				insertion_sort();
				break;
			
			
			case 4:
				exit(1);
				
			case 5:
				printf("\nEnter the element to search");
				scanf("%d",&ele);
				linear_search(ele);
				break;
				
			case 6:
				printf("\nEnter the element to search");
				scanf("%d",&ele);
				binary_search(ele);
				break;
				
			
			default:
				printf("Invalid choice, Re-Enter");
			
		}
		
		
	}
	
	
return 0;
}




