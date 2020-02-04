

#include<stdio.h>
#include<stdlib.h>

#define capacity 5
int stack[capacity];
int top=-1;

int isFull(){

	if(top==capacity-1){
		
		return 1;
	}
	else{
	
		return 0;
	}
	
}

int isEmpty(){

	if(top==-1){
		
		return 1;
	}
	else{
	
		return 0;
	}
	
}

void push(int in){

	if(isFull()){
	
		printf("\n stack is full");
	}
	else{
		top++;
		stack[top]=in;
		printf("\n %d pushed succesfully",in);
	}
}

int pop(){	
	int out;
	
	if(isEmpty()){
	
		printf("\n stack is Empty");	
	}
	else{
		out=stack[top];
		top--;
		return out;
	}

}

void traverse(){
	
	int i;
	printf("\n stack elements =  ");
	for(i=0;i<=top;i++){
	
		printf("%d \t ",stack[i]);
	}

}

void peek(){
	
	printf("\ntop element of stack is %d",stack[top]);	
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






