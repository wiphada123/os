#include <stdio.h>
 
#define MAX 50
 
void add_item();
void remove_item();
void display();
int buffer_array[MAX];
int rear = - 1;
int front = - 1;
main()
{
    int choice;
    while (1)
    {
        printf(" ======================= CIRCULAR BUFFER =======================\n");
	    printf(" =        Please choose from the following options:            =\n");    
        printf(" =                       1.Add Item                            = \n");
        printf(" =                       2.Remove Item                         =\n");
        printf(" =                       3.Display all elements of buffer       =\n");
        printf(" =                       4.Quit                                =\n");
        printf(" ===============================================================\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            add_item();
            break;
            case 2:
            remove_item();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } /* End of switch */
    } /* End of while */
} /* End of main() */
 
void add_item()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Buffer Overflow \n");
    else
    {
        if (front == - 1)
        /*If buffer is initially empty */
        front = 0;
        printf("Add Item the element in buffer : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        buffer_array[rear] = add_item;
    }
} /* End of insert() */
 
void remove_item()
{
    if (front == - 1 || front > rear)
    {
        printf("Buffer Underflow \n");
        return ;
    }
    else
    {
        printf("Remove Item from buffer is : %d\n", buffer_array[front]);
        front = front + 1;
    }
} /* End of delete() */
 
void display()
{
    int i;
    if (front == - 1)
        printf("Buffer is empty \n");
    else
    {
        printf("Buffer is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", buffer_array[i]);
        printf("\n");
    }
} /* End of display() */