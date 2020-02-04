#include<stdio.h>
#include<stdlib.h>


struct node{

	int data;
	struct node *next;
};

struct node *root=NULL;

void append(int in){

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

int insertAtBegin(int in){

	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=in;
	temp->next=NULL;
	
	if(root==NULL){
	
		root=temp;
	}
	else{
	
		temp->next=root;
		root=temp;
		
	}

}

void insertAtLocation(int in,int loc){

	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=in;
	temp->next=NULL;
	
	if(loc==1){
	
		temp->next=root;
		root=temp;
	}
	else{
		int i=1;
		struct node *p;
		p=root;
		while(i<loc-1){
		
			p=p->next;
			i++;
		
		}
		temp->next=p->next;
		p->next=temp;
	
	}
	
	
}
 
int delete(int del){

	struct node *temp,*p,*q;
	int out;
	temp=root;
	p=q=root;
	q=q->next;
	int count=0;
	while(temp){
	
		if(temp->data==del){
		
			out=temp->data;
			break;
		}
		temp=temp->next;
		q=q->next;
		count++;
	}
	int i=1;
	while(i<count){
	
		p=p->next;
		i++;
	}
	p->next=q;
	temp->next=NULL;
	free(temp);

return out;	
} 



void traverse(){
	
	struct node *temp;
	temp=root;
	printf("\n linked list Elements =  ");
	while(temp!=NULL){
	
		printf("%d\t",temp->data);
		temp=temp->next;
	}		
}

void reverse(){

	struct node *curr,*prev,*q;
	prev=NULL;
	curr=root;
	q=NULL;
	while(curr!=NULL){
		q=curr->next;
		curr->next=prev;
		prev=curr;
		curr=q;
	}
	
	root=prev;
	
	
}

int main(){

	int choice,in1,in2,in3,loc,del,out;
	while(1){

		printf("\nMENU \n 1)APPEND\n 2)INSERT AT BEGIN\n 3)INSERT AT LOCATION\n 4)DELETE\n 5)TRAVERSE\n 6)REVERSE LINKED LIST\n 7)EXIT ");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		
		switch(choice){
		
			case 1:
				printf("\nEnter the no to be appended");
				scanf("%d",&in1);
				append(in1);
				break;
				
			case 2:
				printf("\nEnter the no to be inserted");
				scanf("%d",&in2);
				insertAtBegin(in2);
				break;
				
			case 3:
				printf("\nEnter the no to be inserted and location");
				scanf("%d%d",&in3,&loc);
				insertAtLocation(in3,loc);
				break;
				
			case 4:
				printf("\nEnter the no to be deleted");
				scanf("%d",&del);
				delete(del);
				break;
				
			case 5:
				traverse();
				break;
				
			case 6:
				reverse();
				break;
				
			case 7:
				exit(1);
				
			default:
				printf("\n Wrong choice- reEnter");
		}
		
	}
	
return 0;
} 






