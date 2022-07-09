#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Listdata {
    char name[30];
    int id;
} listData;


typedef struct Listnode {
    listData data;
    struct Listnode* link;
   
} listNode;


typedef struct LinkedList {
    listNode* head;
    int length;
} linkedList;

void cut_string(char *line, int *i, char *seg) {
    int j=0;
    while(line[*i] ==' ' || line[*i] == ',') (*i)++;
    
    while(line[*i] != ' ' && line[*i] != ',' && line[*i] != '\0') {
        seg[j]= line[*i]; (*i)++; j++;
    }
    seg[j]= '\0';
}

int digits_only(char* str) {
    int k;
    if(str[0]== '\0')
        return 0;
    for(k=0; str[k]!= '\0'; k++)
        if(!isdigit(str[k]))
            return 0;
    return 1;
}

void printList(linkedList* L) {
    listNode *node = NULL;
    node= L->head;
    while(node!=NULL){
        printf("%s %d\n",node->data.name,node->data.id);
        node=node->link;
    }

}


listNode* search(linkedList* L, int x) {
    listNode *node = NULL;
    node= L->head;
    while(node!=NULL){
        if(node->data.id==x){
            return node;
        }
        node=node->link;

}
    printf("값을 찾지 못했습니다.\n");
    return NULL;
}

int insert(linkedList* L, listNode* pre, listData item) {
    listNode *node = NULL;
    node= L->head;
    listNode *new = (listNode *)malloc(sizeof(listNode));
    new->data=item;
    while(node!=NULL){
        if(node->data.id==pre->data.id){
            new->link=node->link;
            node->link=new;
            printf("노드 가 삽입되었습니다.\n");
        }
        node=node->link;
    }
    return 1;
}

int delete(linkedList* L, int x) {
    listNode *search_=search(L, x);
    listNode *node = NULL;
    node= L->head;
    if(node->data.id==x) {
        L->head=node->link;
        free(node);
        return 0;
    }
    while(node->link!=NULL){
    if(node->link->data.id==x){
        search_=node->link;
        node->link=search_->link;
        free(search_);
        return 0;
        }
        node=node->link;
    }
    printf("값을 찾지 못했습니다.\n");
    return 0;
}

void reverse(linkedList* L) {
    listNode* node;
    listNode* temp;
    listNode* next;
    node=L->head;
    if(!node || node->link==NULL)
        return;

    temp= node;
    node= node->link;
    temp->link= NULL;

    while(node) {
        next= node->link;
        node->link=L->head;
        L->head= node;
        node = next;
    }
}



int getLength(linkedList *L) {
    listNode *node = NULL;
    node= L->head;
    int i=0;
    while(node!=NULL){
        i++;
        node=node->link;
        L->length=i;
    }
    return L->length;
}


void insertLast(linkedList* L, listData item) {
    listNode *new = (listNode *)malloc(sizeof(listNode));
    listNode *node=NULL;
    new->data=item;
    node= L->head;
    if(node==NULL){
        L->head=new;
        new->link= NULL;
    } else {
        while(node->link!=NULL){
            node= node->link;
        
        }
        
        node->link=new;
        new->link= NULL;
        
    }

}

int main() {
    listData temp;
    linkedList fst;
    
    char line[100], command[30] , numstr[30], numstr2[30], iname[30];
    char* ch_ptr;
    int i;
    int sno, sno2, success;
    listNode *nptr;
    listData input;
    FILE *fp;
    fp=fopen("students.txt","r");
    if(fp==NULL) {
        printf("x");
    }
    fst.head =NULL;
    
    while(!feof(fp)) {
        fscanf(fp,"%s %d",temp.name,&temp.id);
        
        insertLast(&fst,temp);
        
    }
    fclose(fp);
    
    while(1) {
        printf("명령문>");
        ch_ptr = gets(line);
        if(!ch_ptr)
            break;
        i=0;
        cut_string(line, &i, command);

        if(strcmp(command, "print")==0) {
            printList(&fst);
        } else if(strcmp(command, "search") == 0) {
            cut_string(line, &i, numstr);
            sno = atoi(numstr);
            nptr = search(&fst, sno);
            
            if(nptr==NULL){
                printf("없는 학번입니다.\n");
            } else {
                printf("찾기 성공!!\n이름:%s, 학번: %d\n",nptr->data.name, nptr->data.id);
            }
            
        } else if(strcmp(command, "insert")==0) {
            cut_string(line, &i, numstr);
            sno = atoi(numstr);
            nptr = search(&fst, sno);
            if(nptr==NULL) {
                printf("없는 학번입니다.\n");
            } else {
            printf("%s\n",numstr);
            cut_string(line,&i, numstr2);
            printf("%s\n",numstr2);
            if(!digits_only(numstr)) {
                printf("잘못된 명령문입니다.\n");

            }
                sno2= atoi(numstr2);
                cut_string(line, &i, iname);
                if(strlen(iname)==0){
                printf("학생 이름이 없어요\n");
                continue;
                }
            input.id= sno2; strcpy(input.name, iname);
            insert(&fst, nptr, input);
            printList(&fst);
            }
            
        }
        else if (strcmp(command, "delete")==0) {
                cut_string(line, &i, numstr);
                if(!digits_only(numstr)) {
                    printf("잘못된 명령문입니다.\n");
                    continue;;
                }
                sno= atoi(numstr);
                success= delete(&fst, sno);
                if(success)
                    printList(&fst);
            } else if( strcmp(command, "reverse")==0) {
                reverse(&fst);
                printList(&fst);
            } else if(strcmp(command, "getLength")==0) {
                int length = getLength(&fst);
                printf("%d\n",length);
            }
            else if(strcmp(command, "exit")==0) {
                listNode *fre;
                listNode *curr;
                curr=fst.head;
                while(curr!=NULL){
                    fre=curr;
                    curr = curr->link;
                    free(fre);
                }
                break;
            }
            else{
                printf("알수 없는 명령어입니다.\n");
            }
        }

//
//    printList(&fst);
//
//    listNode adr;
//    adr= *search(&fst, 2021265120);
//    printf("%p",&adr);
//
//    listData hong;
//    strcpy(hong.name,"honggildong");
//    hong.id= 202198765;
//    printf("\n%d",hong.id);
//    int inse = insert(&fst, &adr, hong);
//    printf("\n%d",inse);
//
//
//    printList(&fst);
//
//    int del= delete(&fst, 2021265120);
//    printf("%d %s\n",del, "삭제되었습니다.");
//    printList(&fst);
//
//
//    int length= getLength(&fst);
//    printf("%d\n",length);
//
//    printf("\n\n\n");
//    reverse(&fst);
//    printList(&fst);
//
   
   

    return 0;
}

/*
  작업수행순서 (1) 리스트 저장
 -
 프로그램을 실행하면 먼저 주어진 students.txt 파일 안의 모든 데이터(이름과 학번)를 linked list에 순서대로 저장한다. 프로그램 실행시 초기에 파일의 모든 내용을 리스트에 삽입하기 위해 마지막 노드로 데이터를 저장하는 insertLast( )를 작성하여 반복적으로 호출하여 사용하도록 한다.
 함수 정의: void insertLast(linkedList* L, listData item) (2) 테스트
 - 명령문을 입력 받아 이를 수행하는 작업을 반복하도록 한다.
 - 명령문 입력 시,scanf()를 사용하지 않도록 하며 대신에gets()로 한 줄을 읽어 온 후 먼저 명령을 파악하고 그에 따라 후속되는 arguments 를 알아내는 방법을 사용하도록 한다.
 
 */


/*
 - 명령문 종류 예시
 print
 설명: 리스트의 내용을 차례대로 출력한다.
 함수 정의: void printList(linkedList* L)
 
 search 202112345
 설명: 리스트에서 학번이 202112345인 노드를 찾아 학생의 이름을 출력하고 찾은 노드의 주소를 리턴한다. 탐색에 실패할 경우 탐색 실패 메시지를 출력하고 NULL을 리턴한다.
 함수 정의: listNode* search(linkedList* L, int x)
 
 insert 2021265120, 202198765, 홍길동
 설명: 리스트에서 search( ) 함수를 통해 학번이 202154321인 노드를 먼저 찾고, 해당 노드 뒤에 학번이 202198765, 이름이 “홍길동” 인 노드를 추가한 후 리스트의 전체 내용을 차례대로 출력한다. 삽입에 실패할 경우 삽입 실패 메시지를 출력한다.
 함수 정의: int insert(linkedList* L, listNode* pre, listData item)
 
 delete 202124680
 설명: 리스트에서 search( ) 함수를 통해 학번이 202124680인 노드를 먼저 찾고, 해당 노드 삭제한 후 리스트의 내용을 차례대로 출력한다. 삭제에 실패할 경우 삭제 실패 메시지를 출력한다.
 함수 정의: int delete(linkedList* L, int x)
 t
 reverse
 설명: 리스트의 노드 순서를 역순으로 바꾼 후 리스트의 내용을 차례대로 출력한다. 정렬이 아님을 주의한다.
 함수 정의: void reverse(linkedList* L)
 
 getLength
 설명: 리스트의 노드 개수를 출력한다.
 함수 정의: int getLength(linkedList* L)
 
 exit
 설명: 프로그램을 종료한다.
 */
/*
  제출
 - 프로그램 소스 코드(.c)와 보고서(.pdf) - 보고서 포함 내용
  모든명령에대해수행해본실행창을캡처한이미지
  과제수행중어려웠던점,난관을헤쳐가는과정등을보고서에간단하게기술
 */

