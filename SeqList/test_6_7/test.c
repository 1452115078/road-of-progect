#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

void TESTSeqList1()
{
    SL s;
    SLInit(&s);
    SLPushback(&s, 1);
    SLPushback(&s, 2);
    SLPushback(&s, 3);
    SLPushback(&s, 4);
    SLPrint(&s);

    SLPopback(&s);
    SLPopback(&s);
    SLPopback(&s);
    SLPopback(&s);
    SLPopback(&s);
    //SLPopback(&s);
    //SLPopback(&s);
    SLPrint(&s);

    SLDestory(&s);
}
void TESTSeqList2()
{
    SL s;
    SLInit(&s);
    SLPushfront(&s, 1);
    SLPushfront(&s, 2);
    SLPushfront(&s, 3);
    SLPushfront(&s, 4);
    SLPushfront(&s, 5);
    SLPrint(&s);

    SLPopfront(&s);
    SLPopfront(&s);
    SLPopfront(&s);
    SLPopfront(&s);
    SLPopfront(&s);
    SLPopfront(&s);
    SLPrint(&s);

    SLDestory(&s);
}
void TESTSeqList3()
{
    SL s;
    SLInit(&s);
    SLPushback(&s, 1);
    SLPushback(&s, 2);
    SLPushback(&s, 3);
    SLPushback(&s, 4);
    SLInsert(&s, 1, 5);
    SLPrint(&s);

    SLErase(&s, 1);
    SLPrint(&s);
    SLErase(&s, 1);
    SLPrint(&s);
    SLErase(&s, 1);
    SLPrint(&s); 
    SLErase(&s, 1);
    SLPrint(&s);
    SLErase(&s, 0);
    SLPrint(&s);
    SLDestory(&s);
}
int main()
{
    TESTSeqList3();
    return 0;
}