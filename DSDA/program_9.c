*By Recursive*

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2*i + 1; 
    int right = 2*i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    int startIdx = (n / 2) - 1;
 
    for (int i = startIdx; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
}

 
void printArray(int arr[], int n) { 
   for (int i=0; i<n; ++i) 
       printf("%d ",arr[i]); 
   printf("\n"); 
} 


int main() { 
   int arr[] = {4,10,3,5,1,88,94,36,57,1,2,8,72}; 

   int n = sizeof(arr)/sizeof(arr[0]); 

   printf("Input array is \n"); 
   printArray(arr,n); 

   buildHeap(arr,n); 

   printf("Output array is \n"); 
   printArray(arr,n); 

   return 0; 
}

Another Method

# include<stdio.h>

int arr[100],n=0;

void heap(int num, int loc){
	int par;
	while(loc>0){
		par = (loc-1)/2;
		if(num < arr[par]){
			arr[loc] = num;
			return;
		}
		arr[loc] = arr[par];
		loc = par;
	}
	arr[0] = num;
}

void display(){
	int i;
	if(n == 0){
		printf("No Elements present in Heap");
	}
	for(i = 0; i<n; i++){
		printf("%d  ",arr[i]);
	}
}

void main(){
	int i;
	printf("Enter the elements ");
	while(1){
		scanf("%d",&i);
		if(i==-1)
			break;
		
		heap(i,n++);
	}
	printf("Display\n");
	display();
}

