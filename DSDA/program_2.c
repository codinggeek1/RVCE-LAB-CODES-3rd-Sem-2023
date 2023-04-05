#include<stdio.h>
#include<stdlib.h>
#define MAX 500

int front = -1;
int rear = -1;

struct request{
	int number,memorysize;
};

struct request req[100];

void qinsert(int n, int m){
	if(rear == MAX -1){
		printf("QUEUE IS FULL");
	}
	else{
		if(front == -1){
			front = 0;
		}
		rear++;
		req[rear].number = n;
		req[rear].memorysize = m;
	}
}

struct request delete(){
	if(front == -1 || front > rear){
		printf("QUEUE IS EMPTY");
		front = -1;
		rear = -1;
	}
	else{
		return req[front++];
	}
}

int main(){
	int numin, memin, memory = 3000, no_of_req;
	struct request temp;
	printf("Enter the no of requests : ");
	scanf("%d",&no_of_req);
	for(int i = 0; i < no_of_req; i++){
		numin = (1000 + rand())%9999;
		memin = (100 + rand())%999;
		qinsert(numin,memin);
	}
	while(front <= rear)
	{
		temp = delete();
		if( memory >= temp.memorysize ){
			memory -= temp.memorysize;
			printf("Request number %d successfully processed, Avl. Free Capacity = %d\n",temp.number,memory);
		}
		else{
			printf("Request number %d Cannot be processe due to shortage of memory, Avl Free Capacity = %d\n",temp.number,memory);
			break;
		}
	}
	return 0;
}