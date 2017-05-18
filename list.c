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
    setNULLToNext(list->tail);
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

void SearchList(List *list, char *name){
    Node *target;
    target = list->head;
    int i, n = 0;
    char c;
    for(i = 0; i < (list->length); i++){
        if (!strncmp(target->name, name, NAME_LEN)) {
            printf("HIT name : %s\n\n", name);
        }
        target = target->next;
    }
}

/*---データの入力---*/
Node Read(char *message)
{
    Node *temp = AllocNode();
    int n;

    printf("%sするデータを入力してください．\n",message);

    printf("名	  前:");	n = scanf("%s", temp->name);
    if (n == EOF) {
        fprintf(stderr, "Input Error.\n");
        exit(1);
    }
    printf("電話番号:");	n = scanf("%s", temp->tel);
    if (n == EOF) {
        fprintf(stderr, "Input Error.\n");
        exit(1);
    }

    return (*temp);
}

/*---メニュー選択---*/
Menu SelectMenu(void)
{
    int	ch, n;

    do {
        puts("(1) 先頭にノードを挿入	(2) 末尾にノードを挿入");
        puts("(3) 先頭のノードを削除	(4) 末尾のノードを削除");
        puts("(5) 全てのノードを削除	(6) 全てのノードを表示");
        puts("(7) 検索");
        puts("(0) 終			  了");
        n = scanf("%d", &ch);
        if (n == EOF) {
            fprintf(stderr, "Input Error.\n");
            exit(1);
        }
    } while (ch < Term || ch > Search);
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