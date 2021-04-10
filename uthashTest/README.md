[](https://troydhanson.github.io/uthash/userguide.html)

## 安装
下载uthash.h 放到源码同目录
或者linux安装到公共目录`sudo apt install uthash-dev`

## 使用
```c
//1. 包含头文件
#include "uthash.h"

//2. 申请数据结构，包含UT_hash_handle字段
typedef struct {
    int key;
    char name[10];
    UT_hash_handle hh;
}hashNode;

//3. 添加节点
//3.1 为了保证key不重复，要先查找是否已经插入了这个节点
//3.2 库函数不查找的原因是为了某些已经保证id不重复的场景的性能
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

//4. 如果不是使用全局变量，一定要传入指针的指针，因为uthash会改变指针的内容
/* bad */
void add_user(struct my_struct *users, int user_id, char *name) {
  ...
  HASH_ADD_INT(users, id, s);
}
/* good */
void add_user(struct my_struct **users, int user_id, char *name) { ...
  ...
  HASH_ADD_INT(*users, id, s);
}

//5. 查找，不能直接传入数值，要赋给一个变量，然后取变量的地址
int key = 5;
struct my_struct *s;
HASH_FIND_INT(users, &user_id, s); 
printf("value:%s", s->name);



```