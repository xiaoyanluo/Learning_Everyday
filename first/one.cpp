#include <iostream>

Status ListInsert(Sqlist *L,int i,ElemType *e)
{
  int k;
  if(L->length==MAXSIZE)
    return ERROR;
  if(i<1 || i>L-length+1)
    return ERROR;
  if(i<=L->length)
  {
    for(int k=L->length-1; k>=i-1;k--)
      L->data[k+1] = L->data[k];
  }
  L->data[i-1]=e;//第i个数的位置是在 【i-1】
  L->length++;
  return OK;
}
//删除L的第i个数据元素，并用e返回其值，L的长度减1
Status ListDelete(Sqlist *L, int i,ElemType *e)
{
  int k;
  if(L->length==0)
    return ERROR;
  if(i<1 || i>L-length+1)
    return ERROR;
  *e = L-data[i-1];
  if(i<L->length)//如果删除位置不是最后一个元素
  {
    for(k=i;k<L->length;i++)
    {
      L->data[i-1] = L->data[i];
    }
  }
  L->length--;
  return OK;
}

