Expression Tree for converting postfix to infix and prefix
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node{
	char a;
	struct node *left,*right;
};

struct stack{
	struct node *top;
	struct stack *link;
};

struct node *new(char ch){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->a = ch;
	temp->left = temp->right = NULL;
	return temp;
}

void push(struct stack **s, struct node *newnode){
	struct stack *temp;
	temp = (struct stack*)malloc(sizeof(struct stack));
	temp->top = newnode;
	temp->link = *s;
	*s = temp;
}

struct node *pop(struct stack **s){
	if(*s == NULL)
		printf("Underflow");
	else{
		struct node *temp;
		temp = (*s)->top;
		*s = (*s)->link;
		return temp;
	}
}

struct node *Createexp(char postfix[]){
	struct node *t, *t1, *t2;
	struct stack *s = NULL;
	for(int i = 0; i<strlen(postfix); i++){
		t = new(postfix[i]);
		if(isalnum(postfix[i]))
			push(&s,t);
		else{
			t1 = pop(&s);
			t2 = pop(&s);
			t->right = t1;
			t->left = t2;
			push(&s,t);
		}
	}
	return pop(&s);
}

void infix(struct node *root){
	if(root){
		infix(root->left);
		printf("%c",root->a);
		infix(root->right);
	}
}

void prefix(struct node *root){
	if(root){
		printf("%c",root->a);
		prefix(root->left);
		prefix(root->right);
	}
}

void post(struct node *root){
	if(root){
		post(root->left);
		post(root->right);
		printf("%c",root->a);
	}
}

void main(){
	struct node *root;
	char b[100];
	printf("enter the postfix exp : ");
	scanf("%s",b);
	root = Createexp(b);
	printf("Infix is : ");
	infix(root);
	printf("\nprefix is : ");
	prefix(root);
	printf("\npostfix is : ");
	post(root);
}