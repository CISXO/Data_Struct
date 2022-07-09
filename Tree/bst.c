
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 6

typedef int itemStock;
typedef struct {
    char itemCode[MAX_CODE_LENGTH];
    itemStock stock;
} item;

typedef struct treeNode {
    item key;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

treeNode* root= NULL;

//노드의 생성
treeNode *getBinaryNode(void)
{
    treeNode *newNode = calloc(1, sizeof(treeNode));
 
    newNode->key.stock = 0;      // 초기화 0
    newNode->left = NULL;   // 초기값 NULL
    newNode->right = NULL;  // 초기값 NULL
 
    
    return newNode;
}
//노드에 값 너어줌
void setBinNode(treeNode *node, item key , treeNode *left_child, treeNode *right_child)
{
    node->key = key;
    node->left = left_child;
    node->right = right_child;
}

int count;

treeNode *addNode(treeNode *node, item key) {
    if (node == NULL){
        node = getBinaryNode();
        setBinNode(node, key, NULL, NULL);
    } else if (strcmp(node->key.itemCode,key.itemCode)==0){
        printf("존재하는 상품 코드입니다.\n");
        node->key.stock += key.stock;
        printf("상품코드 %s의 재고는 %d개 입니다.\n",node->key.itemCode,node->key.stock);
    } else if (strcmp(node->key.itemCode,key.itemCode)>0){

        node->left = addNode(node->left, key);
    } else {
        node->right = addNode(node->right, key);

    }
    return node;
}

void showTree(const treeNode *node)
{
    
    if(node != NULL){   //중위순회노드
        showTree(node->left);
        printf("관리번호: %s, 재고: %d, \n", node->key.itemCode, node->key.stock);
        showTree(node->right);
    }
}

treeNode *searchTree (treeNode *node, item key) {
    if(node == NULL){
        printf("없는 관리번호입니다.\n");
        return NULL;
    }
    if (strcmp(node->key.itemCode,key.itemCode)==0){
        printf("\n 상품코드 %s의 재고는 %d개 입니다.\n",node->key.itemCode, node->key.stock);
        return node;
    } else if (strcmp(node->key.itemCode,key.itemCode)>0){
       return searchTree(node->left, key);
    } else {
       return searchTree(node->right, key);
        
    }
}


//하위 노드중 가장 작은 값을 찾아 준다.
treeNode *minValueNode(treeNode * node)
{
    treeNode *cur = node;
 
    while(cur && cur->left != NULL ){
        cur = cur->left;
    }
    return cur;
}
treeNode *MaxValueNode(treeNode *node) {
    treeNode *cur = node;
    while(cur && cur->right != NULL ){
        cur = cur->right;
    }
    return cur;
}

// 특정 노드 삭제 일반 포인터로

treeNode *deleteNode(treeNode *root, item ke, int sto)
{
    int s=0;
    // root가 NULL 일 경우. 트리가 비어있을 경우.
    if (root == NULL){
        return root;
    }
    // key 가 노드의 키값보다 작거나 큰 경우[하위트리에 이동]
    
    if (strcmp(root->key.itemCode,ke.itemCode)>0){
        root->left = deleteNode(root->left, ke, sto);
    } else if (strcmp(root->key.itemCode,ke.itemCode)<0){
        root->right = deleteNode(root->right, ke, sto);
    }
    // 키가 노드의 키값과 같은 경우[삭제]
    else {
       
        // 노드의 자녀가 한개일 경우(왼쪽 아니면 오른쪽)
        // 노드 자녀가 없는 경우도 if문에서 삭제된다.
        s=root->key.stock;
        root->key.stock-=sto;
      if(root->key.stock<=0){
          if(root->key.stock<0) {
              printf("재고가 모두 소진되어 %d개만 출고합니다.\n",s);
          }
        if(root->left == NULL){
            treeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            treeNode *temp = root->left;
            free(root);
            return temp;
        }
        // 노드의 자녀가 두개일 경우(왼쪽 오른쪽 둘다)
        // 오른쪽 서브트리에서 가장 작은 수를 선택한다. 또는 왼쪽 서브트리에서 가장 큰 수를 선택한다.
        //노드가 오른쪽을
//       treeNode *temp = minValueNode(root->right);  //삭제할 값 오른쪽 서브트리에서
          treeNode *temp = MaxValueNode(root->left);
        root->key = temp->key;
//        root->right = deleteNode(root->right, temp->key, sto);
          root->left = deleteNode(root->left, temp->key, sto);
       
        }
    }
    
    return root;
}
 

// 노드의 메모리 해제

void deleteTree(treeNode *node)
{
   if(node != NULL){
       deleteTree(node->left);
       deleteTree(node->right);
       free(node);
   }
}


int main() {
    treeNode *root = NULL;
    treeNode *search = NULL;
    item jo;
    int sto, swch;
    
    while(1) {
        printf("*==== S E L E C T  M E N U ====*\n        1 :  재고확인\n");
        printf("        2 :   입고\n");
        printf("        3 :   출고\n");
        printf("        4 :   검색\n");
        printf("        5 :   종료\n\n");
        printf("*==============================*\n");
        scanf("%d",&swch);

    switch(swch) {
        case 1:
            printf("[전체 재고 출력]\n");
            showTree(root);

            break;
        case 2:
            printf("[입고] 관리번호를 입력하세요. : ");
            scanf("%s",jo.itemCode);
            printf("[입고] 입고 수량을 입력하세요 : ");
            scanf("%d",&jo.stock);
            root= addNode(root,jo);
            break;
        case 3:
            printf("[출고] 관리번호를 입력하세요 :");
            scanf("%s",jo.itemCode);
            search = searchTree(root, jo);
            if(search==NULL) {
            } else {
            printf("[출고] 출고 수량을 입력하세요 :");
            scanf("%d",&sto);
           root= deleteNode(root, jo, sto);
            }
        
            break;
        case 4:
            printf("[재고 수량 검색] 관리번호를 입력하세요 :");
            scanf("%s",jo.itemCode);
            search = searchTree(root, jo);
            break;
        case 5:
            deleteTree(root);
            break;
    }
        if(swch==5) {
            break;
        }
        
        
    }
    return 0;
}


//    //입고
//    for(int i=0; i< 2; i++) {
//        printf("[입고] 관리번호를 입력하세요. : ");
//        scanf("%s",jo.itemCode);
//        printf("[입고] 입고 수량을 입력하세요 : ");
//        scanf("%d",&jo.stock);
//        root= addNode(root,jo);
//    }

    //재고확인
//    printf("[전체 재고 출력]\n");
//    showTree(root);
    
  
    
    //재고 검색
//    printf("[재고 수량 검색] 관리번호를 입력하세요 :");
//    scanf("%s",jo.itemCode);
//    search = searchTree(root, jo);
//    printf("\n 상품코드 %s의 재고는 %d개 입니다.",search->key.itemCode, search->key.stock);
//
    //출고
//    printf("[출고] 관리번호를 입력하세요 :");
//    scanf("%s",jo.itemCode);
//    search = searchTree(root, jo);
//    deleteNode(root, jo);
//    printf("상품코드 %s의 재고는 %d개 입니다.",search->key.itemCode, search->key.stock);
//
//    return 0;
//}

