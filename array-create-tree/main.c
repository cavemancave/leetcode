//https://blog.csdn.net/Redmoon955331/article/details/75451763?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.add_param_isCf&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.add_param_isCf
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

 typedef struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 }treeNode;
 
treeNode* CreateNewNode(int data)
{
	treeNode* pnewNode=(treeNode*)malloc(sizeof(treeNode));
	if(pnewNode==NULL)
	{
		printf("memory is out\n");
		exit(EXIT_FAILURE);
	}
	pnewNode->val=data;
	pnewNode->left=NULL;
	pnewNode->right=NULL;
	return pnewNode;
}

treeNode* RCreatBinaryTreeByPeorderTraversal(int *arr, int size, int *index){
    treeNode* newNode = NULL;
    (*index)++;
    if(arr[*index] >=0 && *index < size){
        newNode = CreateNewNode(arr[*index]);
        newNode->left = RCreatBinaryTreeByPeorderTraversal(arr, size, index);
        newNode->right = RCreatBinaryTreeByPeorderTraversal(arr, size, index);
    }
    return newNode;
}

void preOrder(treeNode* root){
    if(root == NULL){return;}
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}
void destory(treeNode* root){
    if(root==NULL) return;
    if(root->left == NULL && root->right == NULL) {free(root); return ;}
    destory(root->left);
    destory(root->right);
}
int main(void){
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int index = -1;
    treeNode* root = RCreatBinaryTreeByPeorderTraversal(array, sizeof(array)/sizeof(int), &index);

    preOrder(root);
    destory(root);
    return 0;
}