#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node* prev;
	struct node* next;
}ListNode;

void p_p_free(ListNode* head)
{
  /* "head->next = NULL" 를 처리하기 위해서 p_free() 세부 기능으로 분리해놓은 함수 */
	if (head->next == NULL)
		return;
	else
		p_p_free(head->next);

	free(head->next);
}

void p_free(ListNode* head)
{
	p_p_free(head);
	head->next = NULL;
}

void p_printNode(ListNode* head)
{
	head = head->next;
	while (head != NULL)
	{
		printf("[%d] ", head->val);
		head = head->next;
	}
}

void p_firstInsert(ListNode* head, int val)
{
	/* 첫 번째 노드의 prev필드에는 head주소를 넣기로 정의	*/
	ListNode* tmp = malloc(sizeof(ListNode));
	if (tmp == NULL)
	{
		printf("p_firstInsert() - malloc() error!\n");
		return;
	}

	tmp->val = val;
	tmp->prev = head;
	tmp->next = head->next;

	head->next = tmp;
}

void p_sortInsert(ListNode* head, int val)
{
	/* 오름차순 정렬 기준	*/
	ListNode* tmp, *tmptmp;
	ListNode* val_node;

	if (head->next == NULL)
		p_firstInsert(head, val);
	else
	{
		tmp = head;
		val_node = malloc(sizeof(ListNode));
		if (val_node == NULL)
		{
			printf("p_sortInsert() - malloc() error!\n");
			return;
		}

		while (tmp->next != NULL)
		{
			tmptmp = tmp->next;
			if (val < tmptmp->val)
				break;
			else
				tmp = tmp->next;
		}

		val_node->val = val;
		val_node->prev = tmp;
		val_node->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = val_node;

		/* 아래 작업은 반드시 위 작업 후에 진행해야함 */
		tmp->next = val_node;
	}
}

void p_deleteFirst(ListNode* head)
{
	ListNode* tmp;

	/* 데이터가 없는 경우	*/
	if (head->next == NULL)
	{
		printf("No Data!!\n");
		return;
	}
	/* 데이터가 한 개 있는 경우 */
	else if (head->next->next == NULL)
		p_free(head);
	/* 나머지 경우	*/
	else
	{
		tmp = head->next->next;
		free(head->next);
		head->next = tmp;
	}
}

void p_reverseCopy(ListNode* srchead, ListNode *dsthead)
{
	ListNode* tmp;
	ListNode* stand_node = srchead->next;

	while (stand_node->next != NULL)
		stand_node = stand_node->next;

	dsthead->val = 0;
	dsthead->prev = NULL;
	dsthead->next = malloc(sizeof(ListNode));

	while (stand_node != srchead)
	{
		tmp = dsthead->next;

		tmp->val = stand_node->val;
		tmp->prev = dsthead;
		tmp->next = malloc(sizeof(ListNode));

		stand_node = stand_node->prev;
		dsthead = dsthead->next;
	}

	tmp->next = NULL;
}

int main()
{
	int rc, num;
	ListNode head, head1;
	head.val = 0;
	head.prev = NULL;
	head.next = NULL;

	while (1)
	{
		printf("숫자입력하세요(-1은 처음노드 삭제): ");
		rc = scanf("%d", &num);

		if (num == -1)
		{
			p_reverseCopy(&head, &head1);
			p_printNode(&head);
			printf("\n");
			p_printNode(&head1);
			p_free(&head1);
		}
		else
		{
			p_sortInsert(&head, num);
			p_printNode(&head);
		}
		
		printf("\n\n");
	}

	p_free(&head);
	
	return (0);
}
