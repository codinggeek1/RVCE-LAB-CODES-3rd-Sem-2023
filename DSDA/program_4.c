Simple text Editor
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char line[80];
    struct node *llink, *rlink;
} *first;

struct node *insert(struct node *l) {
    struct node *temp;
    temp = first;
    if (temp == NULL) {
        first = l;
    } else {
        while (temp->rlink != NULL)
            temp = temp->rlink;
        temp->rlink = l;
        l->llink = temp;
    }
    return first;
}

struct node *newinsert(struct node *nl, int p) {
    if (p == 1) {
        nl->rlink = first;
        first->llink = nl;
        first = nl;
    } else {
        struct node *temp;
        temp = first;
        for (int i = 1; i < p - 1 && temp != NULL; i++)
            temp = temp->rlink;
        if (temp == NULL) {
            printf("Invalid position\n");
        } else {
            nl->rlink = temp->rlink;
            if (temp->rlink != NULL) {
                temp->rlink->llink = nl;
            }
            temp->rlink = nl;
            nl->llink = temp;
        }
    }
    return first;
}

void display(struct node *d) {
    if (d == NULL) {
        printf("List is empty\n");
        return;
    }
    while (d != NULL) {
        printf("%s\n", d->line);
        d = d->rlink;
    }
}

struct node *delete (struct node *d, int p) {
    if (d == NULL) {
        printf("List is empty\n");
        return NULL;
    } else if (p == 1) {
        struct node *temp = d;
        d = d->rlink;
        if (d != NULL) {
            d->llink = NULL;
        }
        free(temp);
    } else {
        struct node *temp = d;
        for (int i = 1; i < p && temp != NULL; i++) {
            temp = temp->rlink;
        }
        if (temp == NULL) {
            printf("Invalid position\n");
        } else {
            temp->llink->rlink = temp->rlink;
            if (temp->rlink != NULL) {
                temp->rlink->llink = temp->llink;
            }
            free(temp);
        }
    }
    return d;
}

int main() {
    first = NULL;
    int n = 5, i = 1;
    char lines[80];
    while (n != 0) {
        printf("Enter line %d: ", i++);
        scanf(" %[^\n]", lines);
        struct node *newnode;
        newnode = (struct node *) malloc(sizeof(struct node));
        strcpy(newnode->line, lines);
        newnode->llink = NULL;
        newnode->rlink = NULL;
        first = insert(newnode);
        n--;
    }
    printf("Inserted lines are:\n");
    display(first);
    printf("Enter the position to insert: ");
    int position;
    char nline[80];
    scanf("%d", &position);
    printf("Enter the line to be inserted: ");
    scanf(" %[^\n]", nline);
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    strcpy(newnode->line, nline);
    newnode->llink = NULL;
    newnode->rlink = NULL;
    first = newinsert(newnode, position);
    printf("Lines after inserting:\n");
    display(first);
    printf("Enter the position to delete the line: ");
    scanf("%d", &position);
    first = delete(first, position);
    printf("After deletion:\n");
    display(first);
    return 0;
}