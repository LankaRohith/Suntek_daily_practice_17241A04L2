#include<stdio.h>
#include<conio.h>

struct node{
int data;
struct node *next;
};

struct node *first=NULL,*new,*last,*temp,*d;
char cnfm;
int ch,i,n;

void create()
{
do
{
new=(struct node *)malloc( sizeof(struct node));
new->next=NULL;
printf("\n Enter Data : ");
scanf ("%d",&new->data);

if(first==NULL)
{
first=new;
last=new;
}
else
{
last->next=new;
last=new;
}
printf("\n Do u want another Y|N ");
fflush(stdin);
scanf ("%c",&cnfm);
}
while(cnfm!='n');
}

void list()
{
temp=first;
if(temp==NULL)
{
printf("\n List is Empty");
}
else
{
while(temp!=NULL)
{
sleep(1);
printf("\n %d",temp->data);
temp=temp->next;
}
}
}

void find()
{
int sno,found=0;
temp=first;

if(first==NULL)
{
printf("\n List is Empty ");
}
else
{
printf("\n Enter SNO :");
scanf ("%d",&sno);

while(temp!=NULL)
{
if(temp->data==sno)
{
sleep(1);
printf("\n Found ");
printf("\n Data is : %d",temp->data);
found=1;
break;
}
temp=temp->next;
}
if(found==0)
printf("\n REC NOT Found ");

}
}

void modify()
{
int mrno,found=0,ndata;
temp=first;

if(temp==NULL)
{
printf("\n List is Empty ");
}
else
{
printf("\n enter MRNO ");
scanf ("%d",&mrno);

while(temp!=NULL)
{
if(temp->data==mrno)
{
found=1;
printf("\n Rec is Found ");
sleep(1);
printf("\n Enter New DATA ");
scanf ("%d",&ndata);
temp->data=ndata;
sleep(1);
printf("\n REC REC UPDATED...!");
break;
}
temp=temp->next;
}
if(found==0)
printf("\n REC NOT FOUND");
}
}

void insert()
{
int pos;
new=(struct node *)malloc(sizeof(struct node));
new->next=NULL;
printf("\n Enter Data ");
scanf ("%d",&new->data);

INSERT:
sleep(1);
clrscr();
printf("\n Insert Operations ");
printf("\n -----------------");
printf("\n 1. First \n 2. Last");
printf("\n 3. POS ");
printf("\n -----------------");
printf("\n Enter u r choice ");
scanf ("%d",&ch);

switch(ch)
{
case 1:
new->next=first;
first=new;
break;
case 2:
last->next=new;
last=new;
break;
case 3:
printf("\n Enter POS ");
scanf ("%d",&pos);

i=1;
temp=first;

while(i<pos)
{
temp=temp->next;
i++;
}

new->next=temp->next;
temp->next=new;
break;

default:
printf("\n Invalid Choice ");
goto INSERT;
}
sleep(1);
printf("\n REC is INSERTED ");
}

void delete()
{
DELETE:
sleep(1);
clrscr();
printf("\n DELETE OPERATIONS ");
printf("\n -------------------");
printf("\n 1. First \n 2. Last ");
printf("\n 3. POS ");
printf("\n -------------------");
printf("\n Enter u r choice ");
scanf ("%d",&ch);

switch(ch)
{
case 1:
d=first;
first=first->next;
free(d);
break;
case 2:
for(temp=first;temp->next->next!=NULL;temp=temp->next);
d=temp->next;
temp->next=NULL;
last=temp;
free(d);
break;
case 3:

default:
printf("\n Invalid Choice");
goto DELETE;
}

sleep(1);
printf("\n REC is Deleted ...!");

}

int count()
{
int cnt=0;

temp=first;

if(first==NULL)
{
printf("\n List is Empty");
}
else
{
while(temp!=NULL)
{
cnt++;
temp=temp->next;
}
}
return cnt;
}

void main()
{
do
{
clrscr();
printf("\n Linked List Operations");
printf("\n ----------------------");
printf("\n 1. Crate \n 2. List ");
printf("\n 3. Insert \n 4. Delete ");
printf("\n 5. Find \n 6. Modify ");
printf("\n 7. count \n 8. Exit ");
printf("\n -----------------------");
printf("\n Enter U R Choice :");
scanf ("%d",&ch);

switch(ch)
{
case 1:
create();
break;
case 2:
list();
break;
case 3:
insert();
break;
case 4:
delete();
break;
case 5:
find();
break;
case 6:
modify();
break;
case 7:
n=count();
printf("\n No.of.Nodes :%d",n);
break;
case 8:
exit();
default:
printf("\n Invalid Choice");
}

getch();
}
while(1);
}
