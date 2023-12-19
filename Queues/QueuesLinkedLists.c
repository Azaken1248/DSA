#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *  next;
};

struct node * front = 0;
struct node * rear = 0;

void enqueue(int n){
	struct node * newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> data = n;       
	if(front == 0 && rear == 0){
		rear = newnode;
		front = newnode;
	}
	else{
		struct node * temp;
		temp = rear;
		rear -> next = newnode;
		rear = newnode;
	}
}
int dequeue(){
	int var = -1;
	if(front == 0 && rear == 0){
		printf("Underflow!\n");
	}
	else if(front == rear){
		var = front -> data;
		front = 0;
		rear = 0;
	}
	else{
		var = front -> data;
		
		struct node * temp;
		temp = front;
		front = front -> next;
		free(temp);
	}
	return var;
}
void display(){
	struct node * temp;
	temp = front;
	printf("[");
	while(temp != 0){
		if(temp->next != 0){
			printf("%d,",temp -> data);
			temp = temp -> next;
		}
		else{
			printf("%d]\n",temp -> data);
			temp = temp -> next;
		}
	}
}
int peek(){
	 if(front == 0 && rear == 0){
		 return -1;
	 }
	 else{
	 	 return  front -> data;
	 }
}

int main(){
	int choice;
	while(1){
		
		printf("==================================Queues===================================\n");
		printf("1. Enter Element\n2. Remove Element\n3. Display Queue\n4. Show Peek Element\n5. exit\n");
		printf("===========================================================================\n");
		printf("Enter Your Choice : ");
		scanf("%d",&choice);

		if(choice == 1){
			int element;
			printf("Value Of Element : ");
			scanf("%d",&element);
			enqueue(element);
		}
		else if(choice == 2){
			printf("Element Removed -> %d\n",dequeue());
		}
		else if(choice == 3){
			display();
		}
		else if(choice == 4){
		 	printf("Peek Element -> %d\n",peek());
                        
		}
		else if(choice == 5){
			printf("Exiting....\nDone\n");
			break;
		}
		else{
			printf("INVALID CHOICE!!\n\n");
		}
	}

	return 0;
}
