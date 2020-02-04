#include<stdio.h>
#include<stdlib.h>

struct node{

	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;

void insert(int in){

	struct node *temp;
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=in;
	temp->left=NULL;
	temp->right=NULL;
	
	if(root==NULL){
	
		root=temp;
	}
	else{
		
		struct node *parent,*curr;
		curr=root;
		while(curr!=NULL){
			parent=curr;		
			if(curr->data > temp->data){
		
				curr=curr->left;
			}
			else{
			
				curr=curr->right;
			}
		}
		if(temp->data > parent->data){
		
			parent->right=temp;
		}	
		else{
		
			parent->left=temp;
		}
}
}


int length(struct node* t){
	if(t == NULL)
		return 0;
	
	int len_right, len_left;
	len_left= length(t->left);
	len_right = length(t->right);
	return (len_left+len_right+1);
}
	


void delete(int del){
	
	struct node *curr,*parent,*temp;
	curr=root;
	
	while(curr->data!=del){
		
		parent=curr;
		if(curr->data < del){
	
			curr=curr->right;
		}
		else{
			
			curr=curr->left;
		}
		
	}
	
	if(curr->left==NULL && curr->right==NULL){
	
		if(curr==parent->left){
			
			parent->left=NULL;
			free(curr);
		}
		else{
		
			parent->right=NULL;
			free(curr);
		}
	}
	else if(curr->left!=NULL && curr->right==NULL){
	
		if(curr==parent->left){
			
			parent->left=curr->left;
			free(curr);
		}
		else{
		
			parent->right=curr->left;
			free(curr);
		}
	
	}
	else if(curr->left==NULL && curr->right!=NULL){
	
		if(curr==parent->left){
			
			parent->left=curr->right;
			free(curr);
		}
		else{
		
			parent->right=curr->right;
			free(curr);
		}
	
	}
	else{
		temp=curr->right;
		
		if(temp->left==NULL && temp->right==NULL){
		
			if(curr==parent->right){
			
				parent->right=temp;
				temp->left=curr->left;
				free(curr);
			}
			else{
			
				parent->left=temp;
				temp->left=curr->left;
				free(curr);
			}
		}
		else if(temp->left!=NULL){
			
			struct node *p;
			while(temp->left!=NULL){
				p=temp;
				temp=temp->left;
			}
			
			if(curr==parent->right){
			
				parent->right=temp;
				p->left=NULL;
				temp->right=curr->right;
				temp->left=curr->left;
				free(curr);
			}
			else{
			
				parent->left=temp;
				p->left=NULL;
				temp->right=curr->right;
				temp->left=curr->left;
				free(curr);
			}
			
		}
		else if(temp->right!=NULL){
		
			if(curr==parent->right){
			
				parent->right=temp;
				temp->left=curr->left;
				free(curr);
			}
			else{
			
				parent->left=temp;
				temp->left=curr->left;
				free(curr);
			}
		}
		else{
			
			struct node *p;
			while(temp->left!=NULL){
				p=temp;
				temp=temp->left;
			}
			
			if(curr==parent->right){
			
				parent->right=temp;
				p->left=NULL;
				temp->right=curr->right;
				temp->left=curr->left;
				free(curr);
			}
			else{
			
				parent->left=temp;
				p->left=NULL;
				temp->right=curr->right;
				temp->left=curr->left;
				free(curr);
			}
			
		}
}
}

void inorder(struct node *t){

	if(t->left!=NULL){
	
		inorder(t->left);
	}
	printf("%d\t",t->data);
	if(t->right!=NULL){
	
		inorder(t->right);
	}
}
	
void preorder(struct node *t){
	
	printf("%d\t",t->data);
	if(t->left!=NULL){
	
		preorder(t->left);
	}
	
	if(t->right!=NULL){
	
		preorder(t->right);
	}
}

void postorder(struct node *t){

	if(t->left!=NULL){
	
		postorder(t->left);
	}
	
	if(t->right!=NULL){
	
		postorder(t->right);
	}
	printf("%d\t",t->data);
}



int main(){
	
	int choice;
	int in,del,len;
	
	while(1){
	
		printf("\n  CHOICE MENU SINGLE LINKED LIST \n 1) INSERT INTO BST \n 2)DELETE FROM BST  \n 3) INORDER TRAVERASAL \n 4) PREORDER TRAVERSAL ");
		printf("\n 5) POSTORDER TRAVERSAL \n 7) EXIT  \n 6) FIND NO OF NODES");
		printf("\n Enter your choice");
		scanf("%d",&choice);
		
		switch(choice){
		
			case 1:
				printf("\n Enter the element to INSERT INTO BST");
				scanf("%d",&in);
				insert(in);
				break;
				
			case 2:
				printf("\n Enter the element to DELETE");
				scanf("%d",&del);
				delete(del);
				break;
				
			case 3:
				printf("\n INORDER TRAVERSAL \n");
				inorder(root);
				break;
				
			case 4:
				printf("\n PREORDER TRAVERSAL \n");
				preorder(root);
				break;

			case 5:
				printf(" POSTORDER TRAVERSAL\n");
				postorder(root);
				break;
			
			case 6:
				printf("The number of nodes = %d\n",length(root));
				break;
			
			case 7:
				exit(1);
				
				
			default:
				printf("Invalid choice, Re-Enter");
			
		}
		
		
	}
	
	
return 0;
}




