#include <stdio.h>
#define MAX 4

int queue[MAX];
int front = -1, rear = -1;

int isFull()
{
    return ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front);
}

int isEmpty()
{
    return (front == -1);
}

void insert()
{
    int num;
    printf("\nEnter the number to be inserted in the queue: ");
    scanf("%d", &num);

    if (isFull())
    {
        printf("\nOVERFLOW\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = num;
}

int delete_element()
{
    int val;

    if (isEmpty())
    {
        printf("\nUNDERFLOW\n");
        return -1;
    }

    val = queue[front];

    if (front == rear)  // Only one element
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    return val;
}

int peek()
{
    if (isEmpty())
    {
        printf("\nQUEUE IS EMPTY\n");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }

    printf("\nQueue elements are: ");

    i = front;
    while (1)
    {
        printf("\t%d", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int option, val;

    do
    {
        printf("\n***** MAIN MENU *****");
        printf("\n1. Insert an element");
        printf("\n2. Delete an element");
        printf("\n3. Peek");
        printf("\n4. Display the queue");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                insert();
                break;

            case 2:
                val = delete_element();
                if (val != -1)
                    printf("\nThe number deleted is: %d\n", val);
                break;

            case 3:
                val = peek();
                if (val != -1)
                    printf("\nThe first value in queue is: %d\n", val);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid option. Try again.\n");
        }
    } while (option != 5);

    return 0;
}

