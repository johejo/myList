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
    Node *incert = AllocNode();
    strncpy(incert->name, name, NAME_LEN);
    strncpy(incert->tel, tel, TEL_LEN);

    incert->next = list->head;
    list->head = incert;
    list->tail->next = NULL;
    (list->length)++;
}

void AppendNode(List *list, char *name, char *tel)
{

}

void DeleteNode(List *list)
{

}

void RemoveNode(List *list)
{


}

void ClearList(List *list)
{
    free(list);
}

void PrintList(List *list) {
    Node *current;
    current = list->head;
    int i;
    for(i = 0; i < (list->length); i++){
        printf("name:%s\ttel:%s\n", current->name, current->tel);
        current = current->next;
    }
}

/*---データの入力---*/
Node Read(char *message)
{
    Node	temp;

    printf("%sするデータを入力してください．\n",message);

    printf("名	  前:");	scanf("%s", temp.name);
    printf("電話番号:");	scanf("%s", temp.tel);

    return (temp);
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