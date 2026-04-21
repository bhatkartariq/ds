
/*NAME: TARIQ KHALIL BHATKAR
UIN: 251P032
ROLL NO: 31*/ Z
#include <stdio.h>
#define size 10
int arr[size];

void insertion();
void deletion();
void display();
int main()
{
	int choice,element,index;

	while(1)
	{
		printf("------MENU------ \n");
		printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit ");
		printf("\nEnter your choice:-");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			printf("Enter position:-");
			scanf("%d",&index);
			printf("Element to be inserted:-");
			scanf("%d",&element);
			insertion(index,element);
			break;
		case 2:
			printf("Enter position:-");
			scanf("%d",&index);
			deletion(index);
			break;
		case 3:
			display();
			break;
		case 4:
		    printf("program end");
			return 0;
		default:
			printf("Invalid choice !!!\n");
		}
	}

}
void insertion(int index,int element)
{
	if(index<0 || index>10)
	{
		printf("Invalid position !!! \n");
	}
	else {
		index=index-1;
		arr[index]=element;
	}
}
void deletion(int index)
{
	if(index<0 || index>10)
	{
		printf("Invalid position !!!\n");
	}
	else {
		index=index-1;
		arr[index]=0;
	}
	return;
}
void display()
{
	int i;
	printf("Array=");
	printf("[");
	for(i=0; i<10; i++)
	{
		printf("%d,",arr[i]);
	}
	printf("]\n");
	return;
}
