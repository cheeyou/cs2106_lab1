/*************************************
* Lab 1 Exercise 2
* Name: Chee You
* Student No: A0188719J
* Lab Group: 01
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"

// add in your implementation below to the respective functions
// feel free to add any headers you deem fit (although you do not need to)

// inserts a new node with data value at index (counting from the front
// starting at 0)
void insert_node_from_head_at(list *lst, int index, int data)
{	
	// Initialising node part
	// Need to allocate enough space to store the address of prev and next pointers.
	node *newNodePtr, *prevHead, *current;
	int i;
	newNodePtr = (node*)malloc(1 * sizeof(node));
	newNodePtr->data = data;
	newNodePtr->prev = NULL;
	newNodePtr->next = NULL;
	
	// Adding to list part (take note that index is btwn 0 and length of list)
	// Check if list is empty (Use dereferencing)
	if (lst->head == NULL && lst->tail == NULL) 
	{
		lst->head = newNodePtr;
		lst->tail = newNodePtr;	
	}
	// It should be the head
	else if (index == 0) 
	{
		prevHead = lst->head;
		newNodePtr->next = prevHead;
		prevHead->prev = newNodePtr;
		lst->head = newNodePtr;
	}	
	else 
	{
		// current is the node that would be in front of the new node
		current = lst->head;
		for (i = 1; i < index; i++)
		{
			current = current->next;
		}

		if (current->next == NULL)
		{
			newNodePtr->prev = current;
			current->next = newNodePtr;
			lst->tail = newNodePtr;
		}
		else
		{
			newNodePtr->prev = current;
			newNodePtr->next = current->next;
			current->next->prev = newNodePtr;
			current->next = newNodePtr;
		}
	}
}
void insert_node_from_tail_at(list *lst, int index, int data)
{	
	// Initialising node part
	// Need to allocate enough space to store the address of prev and next pointers.
	node *newNodePtr, *prevTail, *current;
	int i;
	newNodePtr = (node*)malloc(1 * sizeof(node));
	newNodePtr->data = data;
	newNodePtr->prev = NULL;
	newNodePtr->next = NULL;
	
	// Adding to list part (take note that index is btwn 0 and length of list)
	// Check if list is empty (Use dereferencing)
	if (lst->head == NULL && lst->tail == NULL) 
	{
		lst->head = newNodePtr;
		lst->tail = newNodePtr;	
	}
	// It should be the tail
	else if (index == 0) 
	{
		prevTail = lst->tail;
		newNodePtr->prev = prevTail;
		prevTail->next = newNodePtr;
		lst->tail = newNodePtr;
	}	
	else 
	{
		// current is the node that would be at the back of the new node
		current = lst->tail;
		for (i = 1; i < index; i++)
		{
			current = current->prev;
		}

		if (current->prev == NULL)
		{
			newNodePtr->next = current;
			current->prev = newNodePtr;
			lst->head = newNodePtr;
		}
		else
		{
			newNodePtr->next = current;
			newNodePtr->prev = current->prev;
			current->prev->next = newNodePtr;
			current->prev = newNodePtr;
		}
	}
}
void delete_node_from_head_at(list *lst, int index)
{
	node *toDelete;	
	int i;
	toDelete = lst->head;
	for (i = 0; i < index; i++)
	{
		toDelete = toDelete->next;
	}
	if (toDelete == lst->head && toDelete == lst->tail)
	{
		lst->head = NULL;
		lst->tail = NULL;
	}
	else if (toDelete == lst->head)
	{
		lst->head = toDelete->next;
		toDelete->next->prev = NULL;
	}
	else if (toDelete == lst->tail)
	{
		lst->tail = toDelete->prev;
		toDelete->prev->next = NULL;
	}
	else
	{
		toDelete->prev->next = toDelete->next;
		toDelete->next->prev = toDelete->prev;
	}
	free(toDelete);
}
void delete_node_from_tail_at(list *lst, int index)
{
	node *toDelete;	
	int i;
	toDelete = lst->tail;
	for (i = 0; i < index; i++)
	{
		toDelete = toDelete->prev;
	}
	if (toDelete == lst->head && toDelete == lst->tail)
	{
		lst->head = NULL;
		lst->tail = NULL;
	}
	else if (toDelete == lst->head)
	{
		lst->head = toDelete->next;
		toDelete->next->prev = NULL;
	}
	else if (toDelete == lst->tail)
	{
		lst->tail = toDelete->prev;
		toDelete->prev->next = NULL;
	}
	else
	{
		toDelete->prev->next = toDelete->next;
		toDelete->next->prev = toDelete->prev;
	}
	free(toDelete);
}

// resets list to an empty state (no nodes) and frees any allocated memory in the process
void reset_list(list *lst)
{       
	node *toDelete, *current;
	current = lst->head;

	if (lst->head == NULL && lst->tail == NULL)
	{
	}
	else {
		lst->head = NULL;
		while (current != NULL)
		{
			toDelete = current;
			current = current->next;
			free(toDelete);
		}
		lst->tail = NULL;
	}
}

void map(list *lst, int (*func)(int))
{
	node *current;
	int input, output;
	if (lst->head == NULL && lst->tail == NULL)
	{
	}
	else
	{
		current = lst->head;
		while (current != NULL)
		{
			input = current->data;
			output = (*func)(input);
			current->data = output;
			current = current->next;
		}
	}
}

long sum_list(list *lst)
{
	long sum = 0;
	node *current;
	if (lst->head == NULL && lst->tail == NULL)
	{
	}
	else
	{
		current = lst->head;
		while (current != NULL)
		{
			sum += (long)(current->data);
			current = current->next;
		}
	}
	return sum;
}
