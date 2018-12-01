//树形图创作者
#include "pch.h"
#include <iostream>
#include <stdlib.h>
struct TreeNode {
	struct TreeNode * LeftNode;
	int data;
	struct TreeNode * RightNode;
};
struct Queue
{
	TreeNode * data;
	struct Queue * Next;
};
TreeNode* FidNode(TreeNode * tree, int value); //查找节点 √
void AddNode(TreeNode **tree, int value);//添加节点 √
void DelNode(TreeNode * tree, int value);//删除节点
void PriNode(TreeNode * tree);//打印树
void FidMax(TreeNode * tree); //查找最大 
void FidMin(TreeNode * tree); //查找最小 
void FirPut(TreeNode * tree); //先序遍历 
void SecPut(TreeNode * tree); //中序遍历 
void ThrPut(TreeNode * tree); //后序遍历
void LevPut(TreeNode * tree); //层序遍历
void inQueue(Queue **end, TreeNode *value);
TreeNode* outQueue(Queue **head);

int main()
{
	TreeNode * tree = NULL;
	AddNode(&tree, 5);
	AddNode(&tree, 6);
	AddNode(&tree, 2);
	AddNode(&tree, 3);
	PriNode(tree);
}

void AddNode(TreeNode ** tree, int value)
{
	if (*tree == NULL)
	{
		*tree = (TreeNode*)malloc(sizeof(TreeNode));
		if (*tree != NULL)
		{
			(*tree)->LeftNode = NULL;
			(*tree)->data = value;
			(*tree)->RightNode = NULL;
		}
		else
		{
			printf("Error AddNode Malloc Fail\n");
		}
	}
	else
	{
		if (value < (*tree)->data)
			AddNode(&((*tree)->LeftNode), value);
		if (value > (*tree)->data)
			AddNode(&((*tree)->RightNode), value);
	}
}//添加节点

TreeNode* FidNode(TreeNode * tree, int value)
{
	TreeNode * Node = tree;
	while ( Node != NULL && Node->data != value)
	{
		if (value < Node->data)
			Node = Node->LeftNode;
		if (value > Node->data)
			Node = Node->RightNode;
	}
	if (Node == NULL)
	{
		printf("不存在值为%d的节点", value);
		return NULL;
	}
	else
	    return Node;
}//查找节点

void PriNode(TreeNode * tree)
{
	int value = 0;
	
	Queue *head,*end;
	head = (Queue *)malloc(sizeof(Queue));
	head->data = NULL; 
	head->Next = NULL;
	end = head;
	for (value = 0; tree != NULL; tree = tree->LeftNode, value++);
	inQueue(&head,tree);

	for (int i = value; i >= 0; i--)
	{
		for (int n = 0; n < 2 * i + 1; n++)
			printf("\t");
		TreeNode * Temp = outQueue(&head);
		printf("%d\t\t", Temp->data);
		if (Temp->LeftNode == NULL)
			inQueue(&end, NULL);
		else
			inQueue(&end, Temp->LeftNode);
		if (Temp->RightNode == NULL)
			inQueue(&end, NULL);
		else
			inQueue(&end, Temp->LeftNode);
	}
} 

void inQueue(Queue ** end, TreeNode *value)
{
	Queue * Temp;
	Temp = (Queue *)malloc(sizeof(Queue));
	Temp->data = value;
	Temp->Next = NULL;
	(*end)->Next = Temp;
	(*end) = (*end)->Next;

}
TreeNode* outQueue(Queue **head)
{
	Queue * Temp = *head;
	TreeNode * Node = (*head)->data;
	(*head) = (*head)->Next;
	free(Temp);
	return Node;
}

void DelNode(TreeNode **tree, int value) 
{
	if (FidNode(*tree, value))
	{

	}
	//左右无叶节点
	//单边有叶节点
	//左右有叶节点
}//删除节点 
//更改 +描述 上传 同步 +
//netsh interface ip set DNS "本地连接" static 8.8.8.8