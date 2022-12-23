#include<stdio.h>
#include<stdlib.h>


struct LinkedListNode 
{
	int posX;
	int posY;
	char ch;
	struct LinkedListNode *next;
};

struct LinkedListNode *head;

void insert(int inValueX, int inValueY, char sign)
{
	struct LinkedListNode *newNode;
	newNode = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));

	
		if(head==NULL)
		{
			newNode->posX = inValueX;
			newNode->posY = inValueY;
			newNode->ch = sign;
			newNode->next = NULL;
			head = newNode;
		}
		else
		{
			newNode->posX = inValueX;
			newNode->posY = inValueY;
			newNode->ch = sign;
			newNode->next = head;
			head = newNode;
		}
}



int *removeFirst()
{
	int x;
	int y;
	char c;
	static int arr[3];

	struct LinkedListNode *delNode;
	if(head==NULL)
	{
		return NULL;
	}
	else
	{
		x = head->posX;
		y = head->posY;
		c = head->ch;

		arr[0] = x;
		arr[1] = y;
		arr[2] = c;

		delNode = head;
		head = head->next;
		free(delNode);
	}
	return arr;
	
}


void display()
{
	struct LinkedListNode *curr;
	curr=head;
	if(curr==NULL)
	{
		printf("\nStack is empty ");
		printf("\n");
	}
	else
	{
		while(curr!=NULL)
		{
			printf("\n%d %d %c", curr->posX, curr->posY, curr->ch);
			printf("\n");
			curr = curr->next;
		}
	}
}

/*int main(){


	insert(100, 200, '>');
	insert(300, 400, '<');
	insert(500, 600, '^');
	insert(700, 800, '<');
	insert(900, 1000, '>');
	insert(1100, 1200, '<');


 
		1100 1200 <
		900 1000 >
		700 800 <
		500 600 ^
		300 400 <
		100 200 >
	


	printf("\n----------------------------");
	int *ptr = removeFirst();


	printf("\n%d %d %c", ptr[0], ptr[1], ptr[2]);
	printf("\n----------------------------");

	ptr = removeFirst();
	printf("\n%d %d %c", ptr[0], ptr[1], ptr[2]);
	printf("\n----------------------------");

		ptr = removeFirst();
	printf("\n%d %d %c", ptr[0], ptr[1], ptr[2]);
	printf("\n----------------------------");



	ptr = removeFirst();
	int arr1[3];
	arr1[0] = ptr[0];
	arr1[1] = ptr[1];
	arr1[2] = ptr[2];

	printf("\n %d %d %c", arr1[0], arr1[1], arr1[2]);




	//display();
	return 0;
}*/


















