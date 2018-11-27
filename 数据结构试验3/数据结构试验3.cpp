//树形图创作者
#include "pch.h"
#include <iostream>
#include <stdlib.h>
struct TreeNode {
	struct TreeNode * LeftNode;
	int data;
	struct TreeNode * RightNode;
};
TreeNode * CreatTree(int Number, int value); // 建立树 
void AddNode(TreeNode **tree, int value);//添加节点
void DelNode(TreeNode * tree, int value);//删除节点 
void FidNode(TreeNode * tree, int value);//查找节点
void FidMax(TreeNode * tree); //查找最大 
void FidMin(TreeNode * tree); //查找最小 
void FirPut(TreeNode * tree); //先序遍历 
void SecPut(TreeNode * tree); //中序遍历 
void ThrPut(TreeNode * tree); //后序遍历
void LevPut(TreeNode * tree); //层序遍历 

int main()
{
	TreeNode * tree = NULL;
	AddNode(&tree, 1);
	AddNode(&tree, 2);
	AddNode(&tree, 3);

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
		if (value = (*tree)->data)
			printf("数据已经在树中\n");
	}

}
//添加节点
//netsh interface ip set DNS "本地连接" static 8.8.8.8