#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20
#define TEL_LEN 16

/*---メニュー---*/
typedef enum {
    Term, Insert, Append, Delete, Remove, Clear, Print
} Menu;

/*---ノード---*/
typedef struct __node {
    char	name[NAME_LEN];	//名前
    char	tel[TEL_LEN];	//電話番号
    struct __node	*next;	//次の会員を指すポインタ
} Node;

/*---線形リスト制御ブロック---*/
typedef struct {
    Node *head;		//先頭ノードを指すポインタ
    Node *tail;		//末尾ノードを指すポインタ
    int length;
} List;

Node *AllocNode(void);

void InitList(List *list);
void InsertNode(List *list, char *name, char *tel);
void AppendNode(List *list, char *name, char *tel);
void DeleteNode(List *list);
void RemoveNode(List *list);
void ClearList(List *list);
void PrintList(List *list);

Node Read(char *message);

Menu SelectMenu(void);