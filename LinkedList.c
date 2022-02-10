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
	if (head->next == NULL)
		printf("NO DATA WITH p_printNode()\n");

	while (head_tmp->next != NULL)
	{
		head_tmp = head_tmp->next;
		printf("[%d] ", head_tmp->value);
	}
}

void p_sortInsert(ListNode* head, int value)
{
	/* 계속해서 p_sortInsert()를 사용했을 때만 정렬된 연결리스트 유지 가능	*/
	ListNode* tmp_node = head;
	ListNode* target_node = malloc(sizeof(ListNode));
	if (target_node == NULL)
	{
		printf("target_node malloc() - error\n");
		return;
	}

	target_node->value = value;
	target_node->next = NULL;

	while (tmp_node->next != NULL)
	{
		if (target_node->value < tmp_node->next->value)
			break;
		else
			tmp_node = tmp_node->next;
	}

	target_node->next = tmp_node->next;
	tmp_node->next = target_node;
}

void p_searchNode(ListNode* head, int value)
{
	/* 모든 노드를 O(n) 시간복잡도 검색	*/
	int cnt = 1, flag = 1;

	while (head->next != NULL)
	{
		if (head->next->value == value)
		{
			printf("[%d]값은 [%d]번 째 리스트에 존재\n", value, cnt);
			flag = 0;
		}

		cnt++;
		head = head->next;
	}

	if (flag == 1)
		printf("NO THAT DATA!\n");
}

void p_deleteNode(ListNode* head, int value)
{
	int flag = 1;
	ListNode* tmp_node;

	while (head->next != NULL)
	{
		if (head->next->value == value)
		{
			tmp_node = head->next->next;
			free(head->next);
			head->next = tmp_node;

			flag = 0;
			printf("삭제 완료\n");
		}
		else
			head = head->next;
	}

	if (flag == 1)
		printf("NO THAT DATA!\n");
}

void p_eraseList(ListNode* head)
{
	/* p_free() 이후에 head의 next필드가 NULL로 초기화되지않는 문제를 해결하기 위해서 따로 p_eraseList() 함수를 제작함	*/
	p_free(head);
	head->next = NULL;
}

void p_deepCopy(ListNode* srcHead, ListNode* dstHead)
{
	srcHead = srcHead->next;

	while (srcHead != NULL)
	{
		dstHead->next = malloc(sizeof(ListNode));

		dstHead->next->value = srcHead->value;
		dstHead->next->next = NULL;

		dstHead = dstHead->next;
		srcHead = srcHead->next;
	}
}

int main()
{
	/* free() 넣어야함*/
	int num = 0;
	ListNode head;
	ListNode copy_head;

	head.value = 0;
	head.next = NULL;
	copy_head.value = 0;
	copy_head.next = NULL;

	while (1)
	{
		printf("입력하세요(-1이면 종료): ");
		scanf("%d", &num);
		
		if (num == -1)
			break;
		else
		{
			p_sortInsert(&head, num);
			p_printNode(&head);
			printf("\n");
		}
	}

	printf("\n");
	p_printNode(&copy_head);
	printf("복사진행...\n");
	p_deepCopy(&head, &copy_head);
	p_printNode(&copy_head);
	printf("\n");

	p_free(&head);
	p_free(&copy_head);
	
	return (0);
}
