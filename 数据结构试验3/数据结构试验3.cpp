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
void DelNode(TreeNode **tree, int value);//删除节点 √
void PriNode(TreeNode * tree, int value);//打印树 √
TreeNode* FidMax(TreeNode * tree); //查找最大 √
TreeNode* FidMin(TreeNode * tree); //查找最小 √
TreeNode* CreatTree(TreeNode * tree); //创建树 ？？？
void FirPut(TreeNode * tree); //先序遍历  √
void SecPut(TreeNode * tree); //中序遍历 
void ThrPut(TreeNode * tree); //后序遍历
void LevPut(TreeNode * tree); //层序遍历

int main()
{
	TreeNode * tree = NULL;
	AddNode(&tree, 4);
	AddNode(&tree, 7);
	AddNode(&tree, 8);
	AddNode(&tree, 5);
	AddNode(&tree, 2);
	AddNode(&tree, 3);
	AddNode(&tree, 1);
	//AddNode(&tree, 6);
	AddNode(&tree, 9);
	DelNode(&tree, 8);
	PriNode(tree,0);
	ThrPut(tree);
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
		else
			Node = Node->RightNode;
	}
	if (Node == NULL)
		return NULL;
	else
	    return Node;
}//查找节点

void PriNode(TreeNode * tree,int value)
{
	while (tree != NULL)
	{
		PriNode(tree->RightNode, value + 4);
		for (int i = 0; i < value; i++)
		{
			printf(" ");
		}
		printf("%d\n", tree->data);

		PriNode(tree->LeftNode, value + 4);

		tree = NULL;
	}
} 

TreeNode* FidMax(TreeNode * tree)
{
	while (tree -> RightNode != NULL)
	{
		tree = tree->RightNode;
	}
	return tree;
} //查找最大 

TreeNode* FidMin(TreeNode * tree)
{
	while (tree->LeftNode != NULL)
	{
		tree = tree->LeftNode;
	}
	return tree;
}

void DelNode(TreeNode **tree, int value) 
{
	if (FidNode(*tree, value))
	{
		TreeNode * Node = *tree;
		TreeNode * PNode = NULL;
		TreeNode * SNode = NULL;
		TreeNode * PSNode = NULL;
		while (Node != NULL && Node->data != value)
		{
			PNode = Node;
			if (value < Node->data)
				Node = Node->LeftNode;
			else
				Node = Node->RightNode;
		}
		if (Node->LeftNode == NULL && Node->RightNode == NULL)//左右无叶节点
		{
			if (PNode->LeftNode == Node)
			{
				PNode->LeftNode = NULL;
			}
			else
			{
				PNode->RightNode = NULL;
			}
		}
		else if (Node->LeftNode != NULL && Node->RightNode != NULL)//左右有叶节点
		{
			PSNode = Node;
			SNode = Node->LeftNode;
			while (SNode->RightNode != NULL) //查找代替节点和其父节点
			{
				PSNode = SNode;
				SNode = SNode->RightNode;
			}
			if (PNode == NULL)
				*tree = SNode;
			else if (PNode->LeftNode == Node) //用代替结点替换删除结点
				PNode->LeftNode = SNode;
			else
				PNode->RightNode = SNode;

			if (PSNode->LeftNode == SNode)//让代替结点的父节点左/右指针指向代替结点的左/右指针
				PSNode->LeftNode = SNode->RightNode;
			else
				PSNode->RightNode = SNode->LeftNode;
			SNode->RightNode = Node->RightNode;//让代替结点左右指针指向删除结点左右指针
			SNode->LeftNode = Node->LeftNode;
		}
		else	//单边有叶节点
		{
			if (PNode->LeftNode == Node)
			{
				if (Node->LeftNode == NULL)
					PNode->LeftNode = Node->RightNode;
				else
					PNode->LeftNode = Node->LeftNode;
			}
			else
			{
				if (Node->RightNode == NULL)
					PNode->RightNode = Node->LeftNode;
				else
					PNode->RightNode = Node->RightNode;
			}
		}
		free(Node);
		return;
	}
	else
	{
		printf("要删除的节点不存在 ERROR : DelNode \n");
		return;
	}
}//删除节点 

void FirPut(TreeNode * tree)
{
	if (tree == NULL)
	{
		return;
	}
	printf("%d ", tree->data);
	FirPut(tree->LeftNode);
	FirPut(tree->RightNode);
}//先序遍历

void SecPut(TreeNode * tree) 
{
	if (tree == NULL)
	{
		return;
	}
	SecPut(tree->LeftNode);
	printf("%d ", tree->data);
	SecPut(tree->RightNode);
} //中序遍历 

void ThrPut(TreeNode * tree) 
{
	if (tree == NULL)
	{
		return;
	}
	ThrPut(tree->LeftNode);
	ThrPut(tree->RightNode);
	printf("%d ", tree->data);
} //后序遍历
//更改 +描述 上传 同步 +
//netsh interface ip set DNS "本地连接" static 8.8.8.8