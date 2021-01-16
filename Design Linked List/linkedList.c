#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate();

// ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
// [[], [1], [3], [1, 2], [1], [1], [1]]

int main() {
    MyLinkedList *myLinkedList = myLinkedListCreate();
    myLinkedListAddAtHead(myLinkedList, 1);
    myLinkedListAddAtTail(myLinkedList, 3);
    myLinkedListAddAtIndex(myLinkedList, 1, 2);   // linked list becomes 1->2->3
    print(myLinkedList);
    printf("\n%d\n", myLinkedListGet(myLinkedList, 1));      // return 2
    myLinkedListDeleteAtIndex(myLinkedList, 1);  // now the linked list is 1->3
    print(myLinkedList);
    printf("\n%d\n", myLinkedListGet(myLinkedList, 1));     // return 3
    myLinkedListFree(myLinkedList);

    return 0;
}


/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
     MyLinkedList *head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->next = NULL;
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i=0;
    MyLinkedList *temp = obj->next;
    while(i<index &&temp) {
        i++;
        temp=temp->next;
    }
    if(temp) return temp->value;
    else return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  MyLinkedList *temp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    temp->value = val;
    temp->next = obj->next;
    obj->next = temp;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList * temp = obj;
  while(temp->next) {
      temp=temp->next;
  }
    MyLinkedList *temp1 = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    temp1->value = val;
    temp1->next = NULL;
    temp->next = temp1;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    int i = 1;
    MyLinkedList *iter = obj->next;

    while(i<index && iter) {
        i++;
        iter = iter->next;
    }
    MyLinkedList *temp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
        if(index==0) {
        temp->value = val;
        temp->next=obj->next;
        obj->next = temp;
    }
    else {
    temp->value = val;
    temp->next=iter->next;
    iter->next = temp;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  int i=0;
    index--;
    MyLinkedList * iter = obj->next;
    while(i<index && iter) {
        i++;
        iter=iter->next;
    }
    MyLinkedList *rm;
    if(index+1 == 0) {
        rm = obj->next;
        obj->next = obj->next->next;
        free(rm);
        return;
    }

    if(iter->next && iter->next->next !=NULL) {
    rm =iter->next;
    iter->next = iter->next->next;
    free(rm);
    }
    else if(iter->next && iter->next->next==NULL) {
    rm = iter->next;
    free(rm);
    iter->next = NULL;
    }

}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *rm;
    while(obj->next) {
        rm=obj->next;
        obj->next = obj->next->next;
        free(rm);
    }
}

/* Print all the elements in the linked list */
void print(MyLinkedList *head) {
    MyLinkedList *current_node = head;
   	while ( current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
}

