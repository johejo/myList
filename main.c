#include "defs.h"

/*---メイン---*/
int main(void)
{
    Menu menu;
    List list;

    InitList(&list);

    do {
        Node  x;
        switch (menu = SelectMenu()){
            case Insert: x = Read("先頭に挿入");
                InsertNode(&list, x.name, x.tel); break;
            case Append: x = Read("末尾に挿入");
                AppendNode(&list, x.name, x.tel); break;
            case Delete: DeleteNode(&list);				   break;
            case Remove: RemoveNode(&list);				   break;
            case Clear : ClearList(&list);				   break;
            case Print : PrintList(&list);				   break;
        }
    }while (menu != Term);

    ClearList(&list);

    return (0);
}