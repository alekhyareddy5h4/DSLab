#include <stdio.h>
#define MAX 5  

int st[MAX], top = -1;

// Function declarations
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main()
{
    int val, option;

    do
    {
        printf("\n***** MAIN MENU *****");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("\nEnter the number to be pushed on stack: ");
                scanf("%d", &val);
                push(st, val);
                break;

            case 2:
                val = pop(st);
                if (val != -1)
                    printf("\nThe value deleted from stack is: %d", val);
                break;

            case 3:
                val = peek(st);
                if (val != -1)
                    printf("\nThe value stored at top of stack is: %d", val);
                break;

            case 4:
                display(st);
                break;

            case 5:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid option! Please try again.");
        }

    } while (option != 5);

    return 0;
}

// Push operation
void push(int st[], int val)
{
    if (top == MAX - 1)
    {
        printf("\nSTACK OVERFLOW");
    }
    else
    {
        top++;
        st[top] = val;
    }
}

// Pop operation
int pop(int st[])
{
    int val;
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;
    }
}

// Peek operation
int peek(int st[])
{
    if (top == -1)
    {
        printf("\nSTACK IS EMPTY");
        return -1;
    }
    else
    {
        return st[top];
    }
}

// Display operation
void display(int st[])
{
    int i;
    if (top == -1)
    {
        printf("\nSTACK IS EMPTY");
    }
    else
    {
        printf("\nStack elements are:");
        for (i = top; i >= 0; i--)
        {
            printf("\n%d", st[i]);
        }
    }
}

