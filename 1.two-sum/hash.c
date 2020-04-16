/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */

#include<stdbool.h>
#include<stdlib.h>

typedef int Value;
typedef int Key;

typedef struct NodeStruct {
    Value value;
    Key key;
    struct NodeStruct * next;

} Node;

typedef struct HashmapStruct {
    Node ** list;
    int size;
} Hashmap;

void initHashmap(Hashmap * hashmap, int size)
{
    hashmap->list = malloc(sizeof(Hashmap) * size);
    hashmap->size = size;
}

bool addNode(Key key,Value value, Hashmap* hashmap)
{
    int index =(key > 0 ? key : -key) % hashmap->size;
    Node * head = hashmap->list[index];

    while(head)
    {
        if(head->value == value)
        {
            return false;
        }
        head = head->next;
    }

    head = malloc(sizeof(Hashmap));
    head->value = value;
    head->key = key;
    head->next = hashmap->list[index];
    hashmap->list[index] = head;

    return true;
}

bool freeHashmap(Hashmap * hashmap)
{
    for(int i = 0; i < hashmap->size;i++)
    {
        Node * head = hashmap->list[i];
        while(head->next)
        {
            Node * next = head->next;
            free(head);
            head = next;
        }
    }
    free(hashmap->list);
    hashmap->list = NULL;
    hashmap->size = 0;
    return true;
}

Value * searchKey(Key key, Hashmap * hashmap)
{
    int index = key % hashmap->size;
    Node * head = hashmap->list[index];

    while(head->key != key)
    {
        if(!head)
        {
            return NULL;
        }
        head = head->next;
    }

    return &head->value;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    if(numsSize < 2)
    {
        *returnSize = 0;
        return NULL;
    }
    int * result = malloc(sizeof(int) * 2);
    Hashmap hashmap;
    initHashmap(&hashmap, numsSize);

    for(int i = 0;i < numsSize;i++)
    {
        if(i != 0)
        {
            Value * value = searchKey(target - nums[i], &hashmap);
            if(value)
            {
                result[0] = *value;
                result[1] = i;
                *returnSize = 2;
                return result;
            }
        }
        addNode(nums[i], i, &hashmap);
    }
    *returnSize = 0;
    return NULL;
}
