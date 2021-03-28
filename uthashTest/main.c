/*sudo apt install uthash-dev*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<uthash.h>


typedef struct {
    int key;
    char name[10];
    UT_hash_handle hh;
}hashNode;
hashNode *gHash = NULL;
void AddUser(int key, char *name){
    hashNode *s = NULL;
    HASH_FIND_INT(gHash, &key, s);
    if(s == NULL){
        hashNode *newNode = (hashNode*)malloc(sizeof(hashNode));
        newNode->key = key;
        strcpy(newNode->name, name);
        HASH_ADD_INT(gHash, key, newNode);
    }
}
void DeleteAll(){
    hashNode *s = NULL;
    hashNode *tmp = NULL;
    HASH_ITER(hh, gHash, s, tmp){
        HASH_DEL(gHash, s);
        free(s);
    }
}
void IterUser(){
    hashNode *s = NULL;
    hashNode *tmp = NULL;
    HASH_ITER(hh, gHash, s, tmp){
        printf("id:%d, name:%s\n", s->key, s->name);
    }
}
int main(void){
    hashNode *gHash = NULL;
    AddUser(123, "xgh");
    AddUser(234, "cxh");

    IterUser();
    DeleteAll();

    printf("hello world.\n");
    return 0;
}