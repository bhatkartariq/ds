#include <stdio.h>
#define SIZE 10
int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();
int isFull();
int isEmpty();

int main()
{
    int choice;

    while(1)
    {
        printf("\n------ MENU ------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program ended.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void enqueue()
{
    int element;
    if(isFull())
    {
        printf("Queue is full! Cannot enqueue.\n");
    }
    else
    {
        printf("Enter element to enqueue: ");
        scanf("%d", &element);
        if(front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("Element %d enqueued successfully.\n", element);
    }
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is empty! Cannot dequeue.\n");
    }
    else
    {
        int element = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        printf("Element %d dequeued successfully.\n", element);
    }
}

void display()
{
    if(isEmpty())
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        for(int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int isFull()
{
    return rear == SIZE - 1;
}

int isEmpty()
{
    return front == -1;
}
