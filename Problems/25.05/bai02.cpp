#include<stdio.h>
#include<String.h>

struct NhanVien
{
	char msnv[10];
	char hoVaTen[50];
	int luong;
};

typedef struct NhanVien NhanVien;

struct Node
{
	NhanVien data;
	struct Node *ptrNext;
};

typedef struct Node Node;

struct LinkedList
{
	Node *head;	
};

typedef struct LinkedList LinkedList ;

LinkedList addAnElement(NhanVien value,LinkedList list);
LinkedList deleteAnElement(char msnv[],LinkedList list);
void printList(LinkedList list);
LinkedList updateData(LinkedList list,char msnv[10],int value);
int compareString(char str1[], char str2[]);
Node* maxLuong(LinkedList list);
int sumLuong(LinkedList list);

int main()
{
	LinkedList list;
	list.head=NULL;
	int n,i=0,luong;
	char msnv[10];
	
	printf("Nhap so nhan vien n=");
	scanf("%d",&n);
	fflush(stdin);
	for(i=0;i<n;i++)
	{
		NhanVien newNhanVien;
		printf("Nhap msnv:");
		gets(newNhanVien.msnv);
		printf("Nhap ten nhan vien:");
		gets(newNhanVien.hoVaTen);
		printf("Nhap luong:");
		scanf("%d",&newNhanVien.luong);
		fflush(stdin);
		list=addAnElement(newNhanVien,list);
	}
	
	printList(list);
	
	printf("Nhap nhan vien can xoa MSNV=");
	gets(msnv);
	list=deleteAnElement(msnv,list);
	printf("Nhap nhan vien can cap nhat MSNV=");
	gets(msnv);
	printf("Nhap luong:");
	scanf("%d",&luong);
	updateData(list,msnv,luong);
	printf("Nhan vien luong cao nhat:\n");
	printf("%10s%30s%10d\n",maxLuong(list)->data.msnv,maxLuong(list)->data.hoVaTen,maxLuong(list)->data.luong);
	printList(list);
	printf("Tong luong:%d",sumLuong(list));
	
	return 0;
}

LinkedList addAnElement(NhanVien value,LinkedList list)
{
	//Add an element in front of list
	Node *newNode=(Node *) malloc(sizeof(Node));
	newNode->data= value;
	newNode->ptrNext=NULL;
	
	if(list.head==NULL)//Empty list
	{
		list.head=newNode;
		list.head->ptrNext=NULL;
	}
	else
	{
		newNode->ptrNext=list.head;
		list.head=newNode;
	}
	return list;
}

LinkedList deleteAnElement(char msnv[],LinkedList list)
{
	
	Node *curNode=list.head;
	if(curNode->ptrNext==NULL&&compareString(curNode->data.msnv,msnv)==1)
	{
		list.head=NULL;
	}
	else
	{
		while(compareString(curNode->ptrNext->data.msnv,msnv)!=1)
		{
			curNode=curNode->ptrNext;
		}
		curNode->ptrNext=curNode->ptrNext->ptrNext;
	}
	
	return list;
}

void printList(LinkedList list)
{
	Node *curNode=list.head;
	printf("%10s%30s%10s\n","MSNV","Ho Va Ten","Luong");
	while(curNode!=NULL)
	{
		printf("%10s%30s%10d\n",curNode->data.msnv,curNode->data.hoVaTen,curNode->data.luong);
		curNode=curNode->ptrNext;
	}
		
}

int compareString(char str1[], char str2[])
{
	
	int i;
	
	for(i=0;i<strlen(str1);i++)
	{
		if(str1[i]!=str2[i])
		{
			return 0;
		}
		
	}
	return 1;
	
}

LinkedList updateData(LinkedList list,char msnv[],int value)
{
	Node *curNode=list.head;
	while(compareString(curNode->data.msnv,msnv)!=1)
	{
		curNode=curNode->ptrNext;
	}
	curNode->data.luong=value;
	return list;
}

Node* maxLuong(LinkedList list)
{
	Node *curNode=list.head,*max=list.head;
	
	
	while(curNode!=NULL)
	{
		if(max->data.luong<curNode->data.luong)
		{
			max=curNode;
		}
		curNode=curNode->ptrNext;
	}
	return max;
}

int sumLuong(LinkedList list)
{
	Node *curNode=list.head;
	int tong=0;
	
	while(curNode!=NULL)
	{
		tong+=curNode->data.luong;
		curNode=curNode->ptrNext;
	}
	return tong;
	
	
}






