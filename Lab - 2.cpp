#include<bits/stdc++.h>

using namespace std;

struct node 
{
	int data;
	struct node *link;
};

struct node *insertFront(struct node *head, int data)                               //Insert From Front
{
	struct node *temp = (struct node*)malloc(sizeof(struct node*));
	temp->data = data;
	temp->link = NULL;
	//cout<<"1";
	if(head == NULL)
	{
		return temp;
		//cout<<"2";
	}
	
	temp->link = head;
	head->link = (struct node*)((uintptr_t)head->link ^ (uintptr_t)temp);
	head = temp;
	return head;
}

struct node* insertEnd(struct node *head, int data)										//Insert from Rear
{
	struct node *temp = (struct node*)malloc(sizeof(struct node*));
	temp->data = data;
	temp->link = NULL;
	if(head == NULL)
	return temp;
	struct node *prev = NULL, *curr = head, *next;
	while(curr->link!=prev)
	{
		next = (struct node*)((uintptr_t)curr->link ^ (uintptr_t)prev);
		prev = curr;
		curr = next;
	}	
	curr->link = (struct node*)((uintptr_t)curr->link ^ (uintptr_t)temp);
	temp->link=curr;
	return head;
}

struct node *deleteFront(struct node *head)												//Delete from front
{
	if(head==NULL)
	return head;
	struct node *curr = head, *next, *nextToNext;
	next = head->link;
	nextToNext = (struct node*)((uintptr_t)next->link ^ (uintptr_t)head);
	next->link = nextToNext;
	free(head);
	head = next;
	return head;
}

struct node *deleteRear(struct node *head)                                             //Delete from Rear
{
	if(head==NULL)
	return head;
	struct node *prev = NULL, *curr = head, *next, *prevToPrev;
	while(curr->link!=prev)
	{
		next = (struct node*)((uintptr_t)curr->link ^ (uintptr_t)prev);
		prev = curr;
		curr = next;
	}	
	prevToPrev = (struct node*)((uintptr_t)curr ^ (uintptr_t)prev->link);
	prev->link = prevToPrev;
	free(curr);
	return head;
}

void print(struct node *head)
{
	struct node *prev = NULL, *curr = head, *next;
	if(head==NULL)
	return;
	while(curr!=NULL)
	{
		cout<<curr->data<<" - > ";
		next = (struct node*)((uintptr_t)curr->link ^ (uintptr_t)prev);
		prev = curr;
		curr = next;
	}
	cout<<endl;
}

int main()
{
	struct node *head = NULL;
	cout<<"Inserting 1 from front"<<endl;
	head = insertFront(head,1);
	//cout<<"front";
	print(head);
	cout<<"Inserting 2 from front"<<endl;
	head = insertFront(head,2);
	print(head);
	cout<<"Inserting 3 from front"<<endl;
	head = insertFront(head,3);
	print(head);
	cout<<"Inserting 4 from front"<<endl;
	head = insertFront(head,4);
	print(head);
	cout<<"Inserting 5 from front"<<endl;
	head = insertFront(head,5);
	print(head);
	cout<<"Inserting 6 from front"<<endl;
	head = insertFront(head,6);
	print(head);
	cout<<"Inserting 7 from front"<<endl;
	head = insertFront(head,7);
	print(head);
	cout<<"Inserting 8 from front"<<endl;
	head = insertFront(head,8);
	//cout<<"front";
	print(head);
	cout<<"Inserting 9 from rear"<<endl;
	head = insertEnd(head,9);
	print(head);
	cout<<"Inserting 10 from rear"<<endl;
	head = insertEnd(head,10);
	print(head);
	cout<<"Inserting 11 from rear"<<endl;
	head = insertEnd(head,11);
	print(head);
	cout<<"Inserting 12 from rear"<<endl;
	head = insertEnd(head,12);
	print(head);
	cout<<"Inserting 13 from rear"<<endl;
	head = insertEnd(head,13);
	print(head);
	
	cout<<"Deleting from front"<<endl;
	head = deleteFront(head);
	print(head);
	cout<<"Deleting from front"<<endl;
	head = deleteFront(head);
	print(head);
	cout<<"Deleting from Rear"<<endl;
	head = deleteRear(head);
	print(head);
	cout<<"Deleting from Rear"<<endl;
	head = deleteRear(head);
	print(head);
}
