#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node* next;
}ListNode;

void p_firstInsert(ListNode* head, int data)
{
	ListNode *newNode = malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("malloc() ERROR!\n");
		return;
	}

	newNode->value = data;
	newNode->next = head->next;
	head->next = newNode;
}

void p_free(ListNode* node)
{
	if (node->next == NULL)
		return;
	else 
		p_free(node->next);

	free(node->next);
}

int main()
{
	ListNode head;
	head.value = 0;
	head.next = NULL;

	p_firstInsert(&head, 5);

	p_free(&head);
	return (0);
}
