#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct grade
{
    int score;
    struct grade *next;

} NODE;

struct grade *create();  //创建链表

void insert(NODE *head, NODE *pnew, int i); //插入链表

void pdelete(NODE *head, int i); //删除链表

void display(NODE *head);   //输出链表

void Pfree(NODE *head);   //销毁链表

int main()
{
    printf("Hello world!\n");
    printf("Start coding today, 2017.07.16\n");

    NODE *head, *pnew;


    /* 链表操作  */
    /* 建立一个学生成绩的线性链表，对其实现插入，删除，输出，最后销毁。*/
    head = create();

    if (NULL == head)
    {
        return 0;
    }

    printf("输出创建的链表\r\n");

    display(head);

    pnew = (NODE *)malloc(sizeof(NODE));

    if (NULL == pnew)
    {
        printf("创建链表失败！\r\n");
        return 0;
    }     

    pnew->score = 88;

    insert(head, pnew, 3);

    printf("插入后的链表：\r\n");

    display(head);

    pdelete(head, 3);  //删除节点

    printf("删除后的链表：\r\n");

    display(head);

    Pfree(head);

    return 0;
    
}

NODE *create()
{
    NODE *head, *tail, *pnew;

    int score;

    head = (NODE *)malloc(sizeof(NODE));   //创建头节点

    if (NULL == head) //创建失败返回
    {
        printf("创建失败！\r\n");
        
        return NULL;
    }

    head->next = NULL; //头节点指针域置NULL

    tail = head;  //开始时尾指针指向头节点

    printf("输入学生成绩：\r\n");

    while (1)  //创建链表
    {
        scanf("%d", &score);

        if (score < 0) break; //成绩为负是推出循环

        pnew = (NODE *)malloc(sizeof(NODE)); //创建新节点

        if (NULL == pnew) 
        {
            printf("创建新节点失败\r\n");
            return NULL;
        }
        pnew->score = score;  //新节点数据域存放新的数据
        tail->next = pnew; //新节点插入到表尾
        tail = pnew;   //尾指针指向当前的尾节点
    }
    return head;  //返回创建链表的头指针
}

void insert(NODE *head, NODE *pnew, int i)
{
    NODE *p;
    int j;
    
    p = head;
    for(j = 0; j < i && p != NULL; j++)
    {
        p = p->next;
    }

    if (NULL == p)
    {
        printf("插入的节点不存在！\r\n");
        return;
    }

    pnew->next = p->next;
    p->next = pnew;

}

void pdelete(NODE *head, int i)
{
    NODE *p, *q;
    int j;

    if (0 == i) return;

    p = head;

    for(j = 1; j < i && p->next != NULL; j++)
    p = p->next;

    if (NULL == p->next)  //表明链表中的节点不存在
    {
        printf("链表中的节点不存在\r\n");  //
        return;
    }
    
    q = p->next;   //q指向待删除的节点

    p->next = q->next; //删除节点i， 也可写成p->next = p->next->next;

    free(q);  //释放节点i的内存单元
}

void display(NODE *head)
{
    NODE *p;

    for(p = head->next; p != NULL; p = p->next)
    printf("%d ", p->score);
    printf("\n");
}

void Pfree(NODE *head)
{
    NODE *p, *q;

    p = head;

    while(NULL != p->next)
    {
        q = p->next;
        p->next = q->next;
        free(q);
    }
    
    free(head); //最后删除头节点
}
