#include "..\headfile\question5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// typedef struct
// {
//     bucket head;
//     bucket *lastBuck;
// } hashItem;

hashTable build_hash()
{
    hashTable x = malloc(sizeof(hashItem) * HASHSIZE);
    memset(x, 0, sizeof(hashItem) * HASHSIZE);
    return x;
}
//打印hashtable
void print_hash(hashTable hash)
{
    for (size_t i = 0; i < HASHSIZE; i++)
    {
        bucket *temp = hash[i].head;
        while (temp != NULL)
        {
            printf("当前值对%d:%c\n", temp->key, temp->value);
            temp=temp->next;
        }
    }
}
//检查是否有key
static bool has_key(hashTable hash, int key)
{
    int index = key % HASHSIZE;
    bucket *temp = hash[index].head;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            printf("已经有这个key\n");
            return true;
        }
        temp = temp->next;
    }
    printf("没有找到\n");
    return false;
}
//可以存 重复的键，本例加入键值对时没有检查之前是否存入了该键
void push_back_pair(hashTable hash, int key, char value)
{
    // 先检查 避免加入重复的键
    // if (has_key(hash,key))
    // {
    //     return;
    // }
    int index = key % HASHSIZE;
    bucket *temp = malloc(sizeof(bucket));
    temp->key = key;
    temp->value = value;
    temp->next = NULL;
    if (hash[index].head != NULL)
    {
        hash[index].lastBuck->next = temp; //接在末尾
    }
    else
    {
        hash[index].head = temp;
    }
    hash[index].lastBuck = temp; //变成末尾
}

//查找指定key的值
char get_value(hashTable hash, int key)
{
    int index = key % HASHSIZE;
    bucket *temp = hash[index].head;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    printf("没有找到\n");
    return 0;
}

//删除 键值对
void delete_pair(hashTable hash, int key)
{
    int index = key % HASHSIZE;
    bucket *temp = hash[index].head;

    if (temp->key == key)
    {
        printf("删除键值对%d:%c\n", temp->key, temp->value);
        free(temp);
        return;
    }
    bucket *after = NULL;
    while (temp->next != NULL)
    {
        // after = temp->next;
        if (temp->next->key == key)
        {
            after = temp->next;
            printf("删除键值对%d:%c\n", temp->key, temp->value);
            temp->next = temp->next->next;
            free(after);
            return;
        }
        temp = temp->next;
    }
    printf("没有找到\n");
}
