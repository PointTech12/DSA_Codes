/* JOSHUA BARA
    IT - 03 */


/*ARRAY IMPLEMENTATI0N OF DOUBLE ENDED QUEUE*/


#include<stdio.h>
int f=-1, r=-1;
int n=5, x, choice;
int arr[5];
void makeEmpty(int arr[])
{
    //making Queue empty
    f=r=-1;
}
void enQueueRear(int x, int arr[])
{
    if((r==n-1)&&(f==0)||(f==r+1))
    {
        //Queue Overflow
        printf("Queue is full");
        return;
    }
    if(f==-1)
    {
        //entering first value
        f++;
    }
    r = (r+1)%n;
    arr[r]= x;
}
void enQueueFront(int x, int arr[])
{
    if((r==n-1)&&(f==0)||(f==r+1))
    {
        //Queue Overflow
        printf("Queue is full");
        return;
    }
    if(f==-1)
    {
        //entering first value
        enQueueRear(x, arr);
        return;
    }
    if(f==0){
    	//entering element in end as cannot enter before
    	f=n-1;
    	arr[f]=x;
    	return;
    }
    f--;
    arr[f]=x;
}
void deQueueFront(int arr[])
{
    if(f==-1)
    {
        //Queue Underflow
        printf("Queue is empty");
        return;
    }
    if(f==r)
    {
        //single element to pop
        f=-1;r=-1;
        return;
    }
    f=(f+1)%n;
}
void deQueueRear(int arr[])
{
    if(f==-1)
    {
        //Queue Underflow
        printf("Queue is empty");
        return;
    }
    if(f==r)
    {
        //single element to pop
        f=-1;r=-1;
        return;
    }
    if(r==0){
    	r=n-1;
    }
    else{
    	r--;
    }
}
void display(int arr[])
{
    if(f==-1)
    {
        //no element to print
        printf("Queue is empty");
        return;
    }
	for(int i=f; i!=r; i=(i+1)%n){
		printf("%d\n", arr[i]);
	}
	printf("%d", arr[r]);
}
void main()
{

    /*calling the everlasting choices*/
    while(choice!=6)
    {
        /*description of menu bar*/
        printf("\n\n\n\n-----These are the menu panel-----");
        printf("\n1. Enter element in Queue from front end");
        printf("\n2. Enter element in Queue from rear end");
        printf("\n3. Delete from Queue from front end");
        printf("\n4. Delete from Queue from rear end");
        printf("\n5. Traverse");
        printf("\n6. Exit");
        printf("\nenter the option no.: ");
        scanf("%d", &choice);

        /*switch on entered choice*/
        switch(choice)
        {
            /*case-wise calling functions*/
            case 1: 
            printf("enter the number you want to push: ");
            scanf("%d", &x);
            enQueueFront(x, arr);
                break;
            case 2: 
            printf("enter the number you want to push: ");
            scanf("%d", &x);
            enQueueRear(x, arr);
                break;
            case 3: deQueueFront(arr);
                break;
            case 4: deQueueRear(arr);
                break;
            case 5: display(arr);
                break;
            case 6:
                break;
            default:
                printf("incorrect choice");
        }
    }/*end of while*/

    /*code execution completed*/
    printf("You got exit\n\n");
}