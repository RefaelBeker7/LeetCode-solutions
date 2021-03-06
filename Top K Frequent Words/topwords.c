#include <stdio.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// if strlen < 6 key will be unic
int string_key(char *s)
{
    int len = strlen(s);
    int key = 7;
    if (len > 5) len = 5; // the key will not be uniq
    for (int i = 0; i < len; i++)
        key = key*31 + s[i];

    return(key);       
}


struct DataItem {
    char* s;   
    int   key;
    int   count;
    struct DataItem* next;
};

struct DataItem **init(int size)
{
    struct DataItem** hash=malloc(sizeof(struct DataItem*)*size);
    for (int i=0; i<size; i++)
        hash[i]= 0;
    return hash;
};

int hashCode(int key,int size) {
    return key % size;
}

void insert(char* s, struct DataItem** hashArray,int size)
{
    int key = string_key(s);
   //get the hash 
   int hashIndex = hashCode(key,size);

   struct DataItem** item = &hashArray[hashIndex];
   //move in array until an empty 
   while((*item) != NULL)
   {
       if ((*item)->key == key &&
           !strcmp(s,(*item)->s))
       {
           (*item)->count++;
           return;
       }
       
       item = &(*item)->next;
   }
   (*item) = (struct DataItem*) malloc(sizeof(struct DataItem));
   (*item)->s    = s;  
   (*item)->key  = key;
   (*item)->count  = 1;
   (*item)->next = 0;
}

struct Result
{
    char* s;
    int count;
};
int cmpfunc(const void* a_, const void* b_)
{ 
    struct Result* a = (struct Result*)a_;
    struct Result* b = (struct Result*)b_;
    if (a->count == b->count)
    {
        int i = 0;
        while (a->s[i] && b->s[i] && a->s[i]== b->s[i]) i++;
        return (a->s[i] - b->s[i]);
    }
   return (((struct Result*)b)->count - ((struct Result*)a)->count);
}
struct Result* destroy(struct DataItem** hashArray,int size,int* count)
{
    struct Result* result= malloc(sizeof(struct Result)*size);
    memset(result,0,sizeof(struct Result)*size);
    for(int i = 0; i<size; i++)
    {
	
        if(hashArray[i] != NULL)
        {
            struct DataItem* item = hashArray[i];
            while (item)
            {                
                result[*count].s = item->s;
                result[*count].count = item->count;
                (*count)++;
                
                struct DataItem* temp = item;
                item = item->next;
                free(temp);
            }
        }
    }
    free(hashArray);
    return result;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    if (!wordsSize)
    {
        *returnSize = 0;
        return 0;
    }

    int size = wordsSize;
            
    struct DataItem** hashArray = init(wordsSize);
    for(int i = 0; i<wordsSize; i++)
        insert(words[i],hashArray,size);


    int count = 0;
    struct Result* result = destroy(hashArray,size,&count);
    qsort(result,count,sizeof(struct Result),cmpfunc);
    int i;
    if (k<count) count = k;
    char **list = malloc(sizeof(char*)*count);
    for(i=0; i<count; i++)
    {
        int len = strlen(result[i].s)+1;
        list[i]=  malloc(sizeof(char)*len);
        strcpy(list[i],result[i].s);
    }
    free(result);
     *returnSize = count;
    return list;
}