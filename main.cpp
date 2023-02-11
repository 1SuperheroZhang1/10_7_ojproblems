#include <stdio.h>
#include <stdlib.h>
/*
 * Description
    输入3 4 5 6 7 9999一串整数,9999代表结束,通过尾插法新建链表,查找第二个位置的值并输出
    在2个位置插入99，输出为  3 99  4  5  6  7
    删除第4个位置的值，打印输出为  3 99  4  6  7。
输出函数如下：
void PrintList(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
    }
    printf("\n");
}
Input
    输入是3 4 5 6 7 9999
Output
    输出是
    4
    3 99  4  5  6  7
    3 99  4  6  7
 * */

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

//尾插法新建链表
LinkList list_tail_insert(LinkList &L){
    L=(LinkList) malloc(sizeof(LNode));//为头结点申请空间
    ElemType x;
    scanf("%d",&x);
    LinkList s,r=L;
    while(x!=9999){
        s=(LinkList) malloc(sizeof(LNode));//为新结点申请空间
        s->data=x;
        r->next=s;//让尾部结点指向新结点
        r=s;//指向新的表尾结点
        scanf("%d",&x);
    }
    r->next=NULL;//尾结点的next指针赋值为NULL
    return L;
}
//按位置查找值
LinkList search_by_location(LinkList L,int i){
  LinkList p=L->next;//让p指向第一个结点
  int j=1;
  if(i==0){
      return L;//i=0返回的就是头结点
  }
  if(i<1){
      return NULL;//i是负值就返回空
  }
  while(p&&j<i){
      p=p->next;//让p指向下一个结点
      j++;
  }
  return p;
}
//在第i个位置插入新结点
bool insert_node(LinkList L,int i,ElemType e){
    LinkList p= search_by_location(L,i-1);
    if(p==NULL){
        return false;
    }
    LinkList s=(LinkList)malloc(sizeof(LNode));//为新结点申请空间
    s->data=e;//将要插入的值放入对应空间
    s->next=p->next;//插入步骤
    p->next=s;
    return true;
}
//删除第i个位置的结点
bool list_delete(LinkList L,int i){
    LinkList p= search_by_location(L,i-1);//查找删除位置的前驱节点
    if(p==NULL){
        return false;
    }
    LinkList s=p->next;
    if(s==NULL){
        return false;//要删除的位置不存在
    }
    p->next=s->next;//断链
    free(s);//释放对应结点的空间
    s=NULL;//为了避免野指针
    return true;
}
//打印链表
void PrintList(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
    }
    printf("\n");
}
int main() {
    LinkList L;//链表头，是结构体指针类型
    LinkList search;//用来存储拿到的某一个节点
    list_tail_insert(L);//输入数据为3 4 5 6 7 9999，使用尾插法新建链表
    search=search_by_location(L,2);
    if(search!=NULL){
        printf("%d\n",search->data);
    }
    insert_node(L,2,99);//新结点插入第i个位置
    PrintList(L);//链表打印
    list_delete(L,4);//删除第4个结点
    PrintList(L);//链表打印
    return 0;
}
