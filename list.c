#include "defs.h"

/*---一つのノードを確保---*/
Node *AllocNode(void)
{
    return ((Node *)calloc(1, sizeof(Node)));
}

/*---線形リスト制御ブロックの初期化---*/
void InitList(List *list)
{
    list->head = list->tail = AllocNode();
    list->length = 0;
}

/*
 * 	以下の関数の定義をここに埋め込む
 * 		InsertNode	AppendNode
 * 		DeleteNode	RemoveNode
 * 		ClearList	PrintList
 */

void InsertNode(List *list, char *name, char *tel)
{
    Node *target = AllocNode();
    setInfo(target, name, tel);

    target->next = list->head;
    list->head = target;
    list->tail->next = NULL;
    increaseLength(list);
}

void AppendNode(List *list, char *name, char *tel)
{
    Node *target= AllocNode();
    setInfo(list->tail, name, tel);

    list->tail->next = target;
    list->tail = target;
    setNULLToNext(list->tail);
    increaseLength(list);
}

void DeleteNode(List *list)
{
    Node *target;
    target = list->head;
    list->head = target->next;
    setNULLToNext(list->tail);
    free(target);
    reduceLength(list);
}

void RemoveNode(List *list)
{
    Node *target, *beforeTail;
    beforeTail = searchBeforeTail(list);

    target = beforeTail->next;
    beforeTail->next = list->tail;
    setNULLToNext(list->tail);
    reduceLength(list);
    free(target);
}

void ClearList(List *list)
{
    while(list->head != NULL){
        DeleteNode(list);
    }
    InitList(list);
}

void PrintList(List *list) {
    Node *target;
    target = list->head;
    int i;
    for(i = 0; i < (list->length); i++){
        printf("name:%s\ttel:%s\n", target->name, target->tel);
        target = target->next;
    }
}

/*---データの入力---*/
Node Read(char *message)
{
    Node *temp = AllocNode();

    printf("%sするデータを入力してください．\n",message);

    printf("名	  前:");	scanf("%s", temp->name);
    printf("電話番号:");	scanf("%s", temp->tel);

    return (*temp);
}

/*---メニュー選択---*/
Menu SelectMenu(void)
{
    int	ch;

    do {
        puts("(1) 先頭にノードを挿入	(2) 末尾にノードを挿入");
        puts("(3) 先頭のノードを削除	(4) 末尾のノードを削除");
        puts("(5) 全てのノードを削除	(6) 全てのノードを表示");
        puts("(0) 終			  了");
        scanf("%d", &ch);
    } while (ch < Term ||  ch > Print);
    return ((Menu)ch);
}

void setInfo(Node *node, char *name, char *tel){
    setName(node, name);
    setTel(node, tel);
}

void setName(Node *node, char *name){
    strncpy(node->name, name, NAME_LEN);
}

void setTel(Node *node, char *tel){
    strncpy(node->tel, tel, TEL_LEN);
}

void setNULLToNext(Node *node){
    node->next = NULL;
}

void increaseLength(List *list){
    (list->length)++;
}

void reduceLength(List *list){
    (list->length)--;
}

Node *searchBeforeTail(List *list){
    int i;
    Node *beforeTail;
    beforeTail = list->head;
    for(i = 0; i < (list->length) - 1; i++) {
        beforeTail = beforeTail->next;
    }
    return beforeTail;
}

