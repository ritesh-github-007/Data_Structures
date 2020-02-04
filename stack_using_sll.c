#include<stdio.h>
#include<stdlib.h>

struct node{

	int data;
	struct node *next;
};

struct node *top=NULL;


void push(int in){

	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=in;
	temp->next=NULL;
	
	if(top==NULL){
		
		top=temp;
	}
	else{
	
		temp->next=top;
		top=temp;
	}

}

int pop(){	
	int out;
	struct node *temp;
	
	if(top==NULL){
		
		printf("\n stack is empty");
	}
	else{
		temp=top;
		out=temp->data;
		top=top->next;
		temp->next=NULL;
		free(temp);
		return out;
	}
	

}

void traverse(){
	
	struct node *temp;
	temp=top;
	printf("\n stack elements =  ");
	while(temp!=NULL){
	
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	
	

}

void peek(){
	
	printf("\ntop element of stack is %d",top->data);	
}


int main(){
	
	int choice,in,out;
	
	while(1){
		
		printf("\nMENU");
		printf("\n 1) PUSH \n 2) POP \n 3) PEEK \n 4) TRAVERSE \n 5) EXIT");
		printf("\n Enter your choice =  ");
		scanf("%d",&choice);
	
	
		switch(choice){
		
			case 1:
				printf("\n Enter the no to be pushed");
				scanf("%d",&in);
				push(in);
				break;
				
			case 2:
				out=pop();
				printf("\n popped element is %d",out);
				break;
				
			case 3:
				peek();
				break;
				
			case 4:
				traverse();
				break;
				
			case 5:
				exit(1);
				
		
		}
	
	
	
	
	}


return 0;
}






