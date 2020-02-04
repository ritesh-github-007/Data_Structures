#include<stdio.h>
#include<stdlib.h>
#define capacity 5

int front=-1;
int rear=-1;
int queue[capacity];

int isEmpty(){

	if(front==-1 && rear==-1){
	
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(){

	if((rear+1)%capacity==front){
	
		return 1;
	}
	else{
	
		return 0;
	}

}

void enque(int in){

	if(isFull()){
	
		printf("\n queue is full");
	}
	else{
	
		if(front==-1){
		
			front=0;
		}
		rear=(rear+1)%capacity;
		queue[rear]=in;
		printf("\n %d enqued succesfully",in);
		
	}
}

int deque(){
	int out;
	if(isEmpty()){
		
		printf("\n Queue is Empty");
	}
	else{
		out=queue[front];
		front=(front+1)%capacity;
		return out;
	}	

}

void peek(){

	printf("\n Front element of queue is %d ",queue[front]);
	printf("\n Rear element of queue is %d ",queue[rear]);
}

void traverse(){
	
	if(isEmpty()){
		
		printf("\n queue is empty");
	}
	else{
	
		int index=front;
		printf("\n Queue elements =  ");
		while(index!=rear){
		
			printf("%d\t",queue[index]);
			index=(index+1)%capacity;
		}
		printf("%d",queue[index]);
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



