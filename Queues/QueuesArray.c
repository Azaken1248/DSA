#include <stdio.h>

#define N 100

int front = -1;
int rear = -1;

int Queue[N];

void enqueue(int data)
{
    if (rear == N)
    {
        printf("Queue Overflow!\n");
    }
    else if (front == -1 && rear == -1)
    {
        front += 1;
        rear += 1;

        Queue[rear] = data;
    }
    else
    {
        rear += 1;
        Queue[rear] = data;
    }
}
int dequeue()
{
    int item;
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow!\n");
    }
    else if (front == rear)
    {
        item = Queue[front];
        front = -1;
        rear = -1;
    }
    else
    {
        item = Queue[front];
        front += 1;
    }
    return item;
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("No Elements In Queue!\n");
    }
    else
    {
        printf("Peek Element : %d\n", Queue[front]);
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue : []\n");
    }
    else
    {
        printf("Queue  : [");
        for (int i = front; i <= rear; i++)
        {
            if (i != rear)
            {
                printf("%d,", Queue[i]);
            }
            else
            {
                printf("%d]\n", Queue[i]);
            }
        }
    }
}
int main()
{
    int choice;
    do
    {
        printf("Queue Options:-\n");
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n\nEnter Your Choice : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            printf("Enter Data To Enqueue : ");
            scanf("%d", &data);

            enqueue(data);
        }
        else if (choice == 2)
        {
            printf("Dequeued Item : %d\n", dequeue());
        }
        else if (choice == 3)
        {
            peek();
        }
        else if (choice == 4)
        {
            display();
        }
        else
        {
            if (choice != -1)
            {
                printf("INVALID CHOICE!!\n");
            }
        }

    } while (choice != -1);
}
=======
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int n){
	if(rear == N-1){
		printf("Overflow!\n");
	}
	else if(front == -1 && rear == -1){
		rear += 1;
		front += 1;

		queue[rear] = n;
	}
	else{
		rear += 1;

		queue[rear] = n;
	}
}
int dequeue(){
	int var = -1;
	if(front == -1 && rear == -1){
		printf("Underflow!\n");
	}
	else if(front == rear){
		var = queue[front];
		front = -1;
		rear = -1;
	}
	else{
		var = queue[front];
		front += 1;
	}
	return var;
}
void display(){
	printf("[");
	for(int i = front; i <= rear; i++){
		if(i != rear){
			printf("%d, ",queue[i]);
		}
		else{
			printf("%d]\n",queue[i]);
		}
	}
}
int peek(){
	 if(front == -1 && rear == -1){
		 return -1;
	 }
	 else{
	 	 return  queue[front];
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

