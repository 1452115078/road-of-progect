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
    SLPrint(&s);

    SLDestory(&s);

}

int main()
{
    TESTSeqList1();
    return 0;
}