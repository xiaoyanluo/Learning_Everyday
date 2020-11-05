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
    for(k=i;k<L->length;k++)
    {
      L->data[k-1] = L->data[k];
    }
  }
  L->length--;
  return OK;
}
//以上线性表的顺序结构在 存数据、读数据时的复杂度为O(1). 而插入或删除时为O(n)。

//线性表的单链表存储结构
type struct Node
{
  ElemType data;
  struct Node *next;
  
} Node;
typedef struct Node *ListList;
p->next的值是一个指针
p->next->data表示下一个结点的数据域内的数据

Status GetElem(LinkList L, int i, ElemType *e)
{
  int j;
  LinkList p;
  p=L->next;//p指向L的第一个结点(L->next 表示第一个结点哦)
  j=1;//计数器
  while(p->next && j<i)//p不是NULL，且j还没到i的时候，循环继续
  {
    p = p->next;
    ++j;
  }
  if(!p || j>i)
    return ERROR;
  *e = p->data;
  return OK;
}
//

//插入数据
Status ListInsert(LinkList *l,int i, ElemType e){
  int j;
  LinkList p,s;
  p = *L;
  j = 1;
  while(p && j<i){
    p = p->next;
    ++j;
  }//寻找第i个结点
  s = (LinkList)malloc(sizeof(Node));//生成新结点,在内存找到一块空地存放新结点。
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}

//头插法
void CreatListHead(LinkList *L, int n){
  LinkList p;
  int i;
  *L = (Linklist)malloc(Sizeof(Node));
  (*L)->next = NULL;//建立一个带头结点的单链表
   for( i=0;i<n;i++){
    p=(Linklist)malloc(sizeof(Node));//生成新结点
     p->data = rand()%100+1;
     p->next = (*L)->next;
     (*L)->next = p;//插入到表头
   }
}


//双向链表
typedef struct DulNode{
  ElemType data;
  struct DulNode *prior;//前驱指针
struct DulNode *next;//后驱指针
}DulNode,*DuLinkList;

