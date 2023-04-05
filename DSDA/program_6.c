Dictionary Tree

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char word[20];
	struct node *left, *right;
};

void display(struct node *root){
	if(root){
		display(root->left);
		printf("%s\n",root->word);
		display(root->right);
	}
}

struct node *create(struct node *root, struct node *newnode){
	if(root == NULL)
		return newnode;
	int c = strcmp(newnode->word, root->word);
	if(c>0){
		root->right = create(root->right, newnode);
		return root;
	}
	else{
		root->left = create(root->left, newnode);
		return root;
	}
}
struct node *del(struct node *root, char w[]){
	if(root == NULL)
		return root;
	int c = strcmp(root->word,w);
	if(c>0){
		root->left = del(root->left,w);
		return root;
	}
	else if(c<0){
		root->right = del(root->right,w);
		return root;
	}
	else{
		if(root->left == NULL){
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		else{
			struct node *temp = root->right;
			while(temp->left){
				temp = temp->left;
			}
			strcpy(root->word,temp->word);
			root->right = del(root->right,root->word);
			return root;
		}
	}
}

void main(){
	char a[20];
	struct node *root = NULL;
	while(1){
		scanf("%s",a);
		if ( strcmp(a ,"end") == 0 )
			break;
		struct node *newnode = (struct node *)malloc(sizeof(struct node));
		strcpy(newnode->word,a);
		newnode->right = newnode->left = NULL;
		root = create(root, newnode);
	}
	printf("Words in Dictionary are :\n");
	display(root);
	char b[20];
	printf("enter the word to delete in the dictionary : ");
	scanf("%s",b);
	root =  del(root, b);
	printf("\nAfter deletion : ");
	display(root);
}
