#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
  int exp;
  int coeff;
  struct node *next;
}node;
node *phead=NULL,*qhead=NULL,*pptr,*qptr,*shead=NULL,*sptr,*fhead,*fptr;
void add();
void mul();
void enter(node* x);

void main()
{
  int ch,choice;
  printf("\nEnter 1st polynomial details:\n");
  enter(phead);
  printf("Enter 2nd polynomial details:\n");
  enter(qhead);
  do
    {
      printf("\nMENU\n1)ADD\n2)MULTIPY\nChoose your option:\n");
      scanf("%d",&ch);
      switch(ch)
	{
	case 1:add();
	  sptr=shead;
	  while(sptr!=NULL)
	    {
	      printf("(%dx^%d)+",sptr->coeff,sptr->exp);
	      if(sptr->next==NULL)
		printf("(%dx^%d)",sptr->coeff,sptr->exp);
	      sptr=sptr->next;
	    }
	  break;
	case 2:mul();
	  fptr=fhead;
	  while(fptr!=NULL)
	    {
	      printf("(%dx^%d)+",fptr->coeff,fptr->exp);
	      if(sptr->next==NULL)
		printf("(%dx^%d)",fptr->coeff,fptr->exp);
	      fptr=fptr->next;
	    }
	  break;
	default:printf("error");
	}
      printf("\nDo you want to continue(1/0):");
      scanf("%d",&choice);
    }
  while(choice);
}

void enter(node*x)
{
  int deg;
  node*temp,*newnode;
  newnode=(node*)malloc(sizeof(phead));
  printf("\nEnter degree:\n");
  scanf("%d",&deg);
  for(int i=deg;i>=1;i--)
    {
      newnode->exp=i;
      printf("Enter coefficient of degree %d:",i);
      scanf("%d",&newnode->coeff);
      if(x==NULL)
	{
	  x=newnode;
	  newnode->next=NULL;
	}
      else
	temp=x;
      while(temp!=NULL)
	temp=temp->next;
      temp->next=newnode;
      newnode->next=NULL;
    }
}

void add()
{
  node *newnode;
  newnode=(node*)malloc(sizeof(phead));
  sptr=shead;
  pptr=phead;
  qptr=qhead;
  while(pptr!=NULL||qptr!=NULL)
    {
      if(qptr->exp>pptr->exp)
	{
	  newnode=qptr;
	  sptr->next=newnode;
	  newnode->next=NULL;
	}
      if(qptr->exp<pptr->exp)
	{
	  newnode=pptr;
	  sptr->next=newnode;
	  newnode->next=NULL;
	}
      if(qptr->exp==pptr->exp)
   	{
	  newnode->coeff=pptr->coeff+qptr->coeff;
	  sptr->next=newnode;
	  newnode->next=NULL;
	}
      pptr=pptr->next;
      qptr=qptr->next;
      sptr=sptr->next;
    }
}

void mul()
{
  node*zhead,*zptr,*k,*khead,*kptr;
  zptr=zhead;
  pptr=phead;
  kptr=khead;
  while(pptr!=NULL)
    {
      qptr=qhead;
      while(qptr!=NULL)
	{
	  zptr->exp=qptr->exp+pptr->exp;
	  zptr->coeff=qptr->coeff*pptr->coeff;
	  qptr=qptr->next;
	  zptr=zptr->next;
	}
      pptr=pptr->next;
      zptr=zptr->next;
    }
  zptr->next=NULL;
  zptr=zhead;
  while(zhead!=NULL)
    {
      k=zhead->next;
      while(k!=NULL)
	{
	  if(zptr->exp==k->exp)
	    kptr->coeff=zptr->coeff+k->coeff;
	  k=k->next;
	}
      zptr=zptr->next;
      kptr=kptr->next;
    }
  kptr->next=NULL;
  kptr=khead;
  while (kptr!=NULL)
    {
      zptr=kptr->next;
      node*temp=kptr;
      while(zptr!=NULL)
	{
	  if(zptr->exp<kptr->exp)
	    {
	      temp->exp=zptr->exp;
	      temp->coeff=zptr->coeff;
	      temp->next=zptr->next;
	    }
	  zptr=zptr->next;
	}
      fhead=fptr;
      fptr=temp;
      fptr=fptr->next;
      kptr=kptr->next;
    }
}
	  
	  
  
      
      
	    
      
  
  
    
 
   
	  
