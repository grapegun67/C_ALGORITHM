#include <stdio.h>

#define	MAX_NUM		10
#define ROTATE		7

int main()
{
	int index = 0, ii = 0;
	int arr1[MAX_NUM] = { 10,9,8,7,6,5,4,3,2,1 };
	int arr2[MAX_NUM] = { 0, };

	printf("BEFORE ARRAY\n");
	for (ii = 0; ii < MAX_NUM; ii++)
		printf("[%d] ", arr1[ii]);
	printf("\n\n");

	/* Logic		*/	
	for (ii = 0; ii < ROTATE; ii++)
		arr2[(MAX_NUM - ROTATE + ii)] = arr1[ii];
	for (ii = ROTATE; ii < MAX_NUM; ii++)
		arr2[index++] = arr1[ii];

	printf("AFTER ARRAY\n");
	for (ii = 0; ii < MAX_NUM; ii++)
		printf("[%d] ", arr2[ii]);
	printf("\n");

	return (0);
}
