#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>



// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode tree;

typedef struct SListNode{
    void* data;
    struct SListNode* next;
}MyListNode;

typedef struct SList{
    int len;
    MyListNode* head;
    MyListNode* tail;
}MyList;

MyListNode* MakeNode(void *data)
{
    MyListNode* node = (MyListNode*)calloc(1, sizeof(MyListNode));
    if(node == NULL){printf("Calloc error in MakeNode."); return NULL;}
    node->data = data;
    return node;
}

void AddNode(MyList* list, MyListNode* node)
{
    if(list->head == NULL){
        list->head = node;
        list->tail = node;
        return;
    }
    list->tail->next = node;
}

void FreeNode(MyListNode* node)
{
    if(node->next == NULL){
        free(node);
        return;
    }
    FreeNode(node->next);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

}

void main(void)
{



}