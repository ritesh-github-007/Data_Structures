#include<stdio.h>
#include<stdlib.h>


struct node{

	int data;
	struct node *next;
};

struct node *root=NULL;




void enque(int in){

	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=in;
	temp->next=NULL;
	
	if(root==NULL){
	
		root=temp;
	}
	else{
	
		p=root;
		while(p->next!=NULL){
		
			p=p->next;
		}
		p->next=temp;
	}

}

int deque(){
	int out;
		
	struct node *temp;
	temp=root;
	root=root->next;
	out=temp->data;
	temp->next=NULL;
	free(temp);		

	return out;	
}

void peek(){

	struct node *temp;
	temp=root;
	printf("\n Front element of queue is %d ",root->data);
	
	while(temp->next!=NULL){
		
		temp=temp->next;
	}
	printf("\n Rear element of queue is %d ",temp->data);
}

void traverse(){
	
	struct node *temp;
	temp=root;
	printf("\n Queue elememts =  ");
	while(temp!=NULL){
	
		printf("%d\t",temp->data);
		temp=temp->next;
	}		
}

int main(){

	int choice,in,out;
	while(1){

		printf("\nMENU \n 1)ENQUE\n 2)DEQUE\n 3)PEEK\n 4)TRAVERSE\n 5)EXIT ");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		
		switch(choice){
		
			case 1:
				printf("\nEnter the no to be enqued");
				scanf("%d",&in);
				enque(in);
				break;
				
			case 2:
				out=deque();
				printf("%d dequed succesfully ",out);
				break;
				
			case 3:
				peek();
				break;
				
			case 4:
				traverse();
				break;
				
			case 5:
				exit(1);
				
			default:
				printf("\n Wrong choice- reEnter");
		}
		
	}
	
return 0;
} 



