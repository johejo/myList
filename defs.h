#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---メニュー---*/
typedef enum {
    Term, Insert, Append, Delete, Remove, Clear, Print
} Menu;

/*---ノード---*/
typedef struct __node {
    char	name[20];	//名前
    char	tel[16];	//電話番号
    struct __node	*next;	//次の会員を指すポインタ
} Node;

/*---線形リスト制御ブロック---*/
typedef struct {
    Node *head;		//先頭ノードを指すポインタ
    Node *tail;		//末尾ノードを指すポインタ
} List;