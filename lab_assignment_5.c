#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node*next;
}node;

//returns number of nodes in the linkedList
int length(node*head){
    int length=0;
    node*cur=head;
    if (cur==NULL) return length;
    while(cur!=NULL){
        length +=1;
        cur=cur->next;
    }
    return length;
}

//passes the string in the linkedList
//if the linked list is head->|a|->|b|->|c|
//then toCString function will return "abc"
char*toCString(node*head){
    //check if the list is empty
    int len=length(head);
    char*res=malloc((len+1)*sizeof(char));
    node*cur=head;
    int i=0;
    if (len==0) return NULL;
    while (cur!=NULL){
        res[i]=cur->letter;
        cur=cur->next;
        i++;
    }
    res[len]='\0';
    return res;
}

//inserts character to the linkedList
//if the linked list is head->|a|->|b|->|c|
//then insertChar(&head, 'x') will update the linked list as follows:
//head->|a|->|b|->|c|->|x|
void insertChar(node**pHead, char c){
    node*cur=*pHead;
    if (cur==NULL) return;
    while(cur!=NULL) {
        if (cur->next!=NULL){
            node*next=cur->next;
            cur=cur->next;}
    }
    node*newNode=(node*)malloc(sizeof(node));
    cur->next=newNode;
    c=newNode->letter;
    newNode->next=NULL;
}

//deletes all nodes in the linkedList
void deleteList(node**pHead){
    node*cur=*pHead;
    while(cur!=NULL){
        //to not lose the next node
        node*next=cur->next;
        free(cur);
        //transfers the information to allow the while loop to work
        cur=next;
    }
}

int main(void){
    int i,strLen,numInputs;
    node*head=NULL;
    char*str;
    char c;
    FILE* inFile=fopen("input.txt","r");

    fscanf(inFile,"%d\n", &numInputs);

    while(numInputs-->0){
        fscanf(inFile,"%d\n", &strLen);
        for (i=0;i<strLen;i++){
            fscanf(inFile," %c", &c);
            insertChar(&head,c);
        }
        str=toCString(head);
        printf("String is: %s\n", str);

        free(str);
        deleteList(&head);
        if (head!=NULL){
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
    return 0;
}