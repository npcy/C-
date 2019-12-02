//C语言多项式相加。。..

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int coef;//系数 
	int expn;//指数 
	struct Node *next;
}LNode;                              
struct elem
{
	int coef;
	int expn;
}List[100],change;            
LNode* create(int n)           
{
	LNode *head;                                    
	LNode *s,*L;              //*s表示新创建的空表，*L表示当前的链表，用来连接两空表
	L=s=NULL;
	head=(LNode *)malloc(sizeof(LNode));
	head->next=0;                 //定义空链表 
	L=(LNode *)malloc(sizeof(LNode));
	n--;                                            
	L->coef=List[1].coef;          //复制
	L->expn=List[1].expn;
	head->next=L;
	int i=2;             
	while(n)
	{
		s=(LNode *)malloc(sizeof(LNode));
		L->next=s;
		s->coef=List[i].coef;
		s->expn=List[i].expn;
		L=s;
		n--;
		i++;
	}
	L->next=0;
	return head;
}
LNode* add(LNode *p1,LNode *p2)   //将多项式p1与p2相加，结果存在第三个链表中（第三个链表由该函数创建）
{  
 
	p1=p1->next;              
	p2=p2->next;
	LNode *head;              
	LNode *L,*s;
	head=(LNode *)malloc(sizeof(LNode));
	head->next=NULL;
	L=head;
	while(p1&&p2)            //遍历两表，根据情况判断表的长短是否相同，是否缺项多项，建立一个新的链表来存取内容 
	{
		if(p1->expn > p2->expn)
		{
			s=(LNode *)malloc(sizeof(LNode));
			L->next=s;
			s->coef=p2->coef;
			s->expn=p2->expn;
			L=s;
			p2=p2->next;
		}
		if(p1->expn < p2->expn)
		{
			s=(LNode *)malloc(sizeof(LNode));
			L->next=s;
			s->coef=p1->coef;
			s->expn=p1->expn;
			L=s;
			p1=p1->next;
		}
		if(p1->expn == p2->expn)
		{
			s=(LNode *)malloc(sizeof(LNode));
			L->next=s;
			s->coef=p1->coef + p2->coef;
			s->expn=p1->expn;
			L=s;
			p1=p1->next;
			p2=p2->next;
		}
	}
	while(p1)
	{
		    s=(LNode *)malloc(sizeof(LNode));
			L->next=s;
			s->coef=p1->coef;
			s->expn=p1->expn;
			L=s;
			p1=p1->next;
	}
	while(p2)
	{
		    s=(LNode *)malloc(sizeof(LNode));
			L->next=s;
			s->coef=p2->coef;
			s->expn=p2->expn;
			L=s;
			p2=p2->next;
	}
	L->next=NULL;
	return head;
}
void print(LNode *p1)     
{
	p1=p1->next;
	while(p1)
	{
		printf("%d %d\n",p1->coef,p1->expn);
		p1=p1->next;
	}
}
int main()
{
	int z=2;
	LNode *head2[2];     //head2[]为两多项式的头结点
	int n;
	while(z)                                        
	{
	printf("Please enter the number of items\n");
	scanf("%d",&n);
	printf("Please enter ench items\n");
	int i=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&List[i].coef,&List[i].expn);
	}
	i=1;
	int j=1;
	for(i;i<n;i++)                                     
	for(j=i+1;j<=n;j++)
	{
		if(List[j].expn<List[i].expn)    //将输入的指数按升序排列 ，排序算法 
		{
			change.coef=List[i].coef;
			change.expn=List[i].expn;
			List[i].coef=List[j].coef;
			List[i].expn=List[j].expn;
			List[j].coef=change.coef;
			List[j].expn=change.expn;
		}
	}
    head2[z]=create(n); 
	z--;
	}
	LNode *pp;
	pp=add(head2[1],head2[2]);
	printf("result is:\n");
	print(pp);
	system("pause");
	return 0;
} 
