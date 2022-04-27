/*Viết chương trình tạo lập và thao tác trên danh sách các số thực (danh sách liên kết),
sao cho danh sách luôn được sắp theo chiều tăng

•Tạo danh sách

•In danh sách

•Tìm phần tử có giá trị lớn nhất/nhỏ nhất*/


#include<stdio.h>
#include<stdlib.h>

//khoi tao listNode
struct listNode {
	float data;
	struct listNode* nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode* ListNodePtr;

//khai bao nguyen ham
void them(ListNodePtr* sPtr, float value);
char xoa(ListNodePtr* sPtr, float value);
void printList(ListNodePtr currentPtr);


int main() {
	ListNodePtr startPtr = NULL;
	ListNodePtr curPtr = NULL;

	float item;
	float max;
	float min;

	printf("Enter a character: ");
	scanf_s("%f", &item);
	them(&startPtr, item);
	them(&startPtr, 2);
	printList(startPtr);

	max = startPtr->data;
	min = startPtr->data;
	curPtr = startPtr->nextPtr;
	while (curPtr != NULL) {
		if (curPtr->data > max)
			max = curPtr->data;
		if (curPtr->data < min)
			min = curPtr->data;
		curPtr = curPtr->nextPtr;
	}
	printf("min = %.2f, max = %.2f\n", min, max);

}

void them(ListNodePtr* sPtr, float value) {
	ListNodePtr newPtr;
	ListNodePtr prePtr;
	ListNodePtr curPtr;

	newPtr = (ListNodePtr)malloc(sizeof(ListNode));

	if (newPtr != NULL) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		prePtr = NULL;
		curPtr = *sPtr;

		while (curPtr != NULL && value > curPtr->data) {
			prePtr = curPtr;
			curPtr = curPtr->nextPtr;
		}

		if (prePtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else {
			prePtr->nextPtr = newPtr;
			newPtr->nextPtr = curPtr;
		}
	}
	else {
		printf("%c khong the them. Bo nho khong kha dung!!!\n", value);
	}
}

char xoa(ListNodePtr* sPtr, float value) {
	ListNodePtr prePtr;
	ListNodePtr curPtr;
	ListNodePtr tempPtr;

	if (value == (*sPtr)->data) {
		tempPtr = *sPtr;
		*sPtr = (*sPtr)->nextPtr;
		free(tempPtr);
		return value;
	}
	else {
		prePtr = *sPtr;
		curPtr = (*sPtr)->nextPtr;

		while (curPtr != NULL && curPtr->data != value) {
			prePtr = curPtr;
			curPtr = curPtr->nextPtr;
		}

		if (curPtr != NULL) {
			tempPtr = curPtr;
			prePtr->nextPtr = curPtr->nextPtr;
			free(tempPtr);
			return value;
		}
	}
	return '\0';
}

void printList(ListNodePtr currentPtr)
{
	/* if list is empty */
	if (currentPtr == NULL) {
		printf("List is empty.\n\n");

	} /* end if */
	else {
		printf("The list is:\n");

		/* while not the end of the list */
		while (currentPtr != NULL) {
			printf("%.2f --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;

		} /* end while */

		printf("NULL\n\n");

	} /* end else */

} /* end function printList */