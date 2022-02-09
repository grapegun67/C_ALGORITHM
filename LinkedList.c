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

void p_lastInsert(ListNode* head, int value)
{
	ListNode *head_tmp = head;
	ListNode *node_tmp = malloc(sizeof(ListNode));
	if (node_tmp == NULL)
	{
		printf("p_lastInsert() - malloc() ERROR\n");
		return;
	}

	node_tmp->value = value;
	node_tmp->next = NULL;

	while (head_tmp->next != NULL)
		head_tmp = head_tmp->next;

	head_tmp->next = node_tmp;
}

void p_printNode(ListNode* head)
{
	ListNode* head_tmp = head;

	while (head_tmp->next != NULL)
	{
		head_tmp = head_tmp->next;
		printf("[%d] ", head_tmp->value);
	}
}

int main()
{
	ListNode head;
	head.value = 0;
	head.next = NULL;

	p_firstInsert(&head, 1);
	p_lastInsert(&head, 3);
	p_firstInsert(&head, 2);
	p_printNode(&head);

	p_free(&head);
	return (0);
}
