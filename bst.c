#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct bint
{
int data,flag;
struct bint *left,*right;
}node;
node * create(node *r,int d)
{
if(r == NULL)
 {
 r = (node *)malloc(sizeof(node));
 r->data = d;
 r->left = r->right = NULL;
 }
else
 {
 if(r->data <= d)
 r->right = create(r->right,d);

else
r->left = create(r->left,d);
}
return r; }
void inorder(node *r) {
if(r != NULL)
{
 inorder(r->left);
printf("%d\t",r->data);
inorder(r->right);
}}
void non_in(node *r) {
int top=0;
node *s[20],*pt=r;
s[0]=NULL;
while(pt != NULL)
{
 s[++top] = pt;
 pt = pt->left;

}
pt = s[top--];
while(pt != NULL)

{
 printf("%d\t",pt->data);
 if(pt->right != NULL)

{
 pt = pt->right;
 while(pt != NULL)

{
 s[++top] = pt;
 pt = pt->left;

}

}
 pt = s[top--];
}}
void preorder(node *r) {
if(r != NULL)

{
 printf("%d\t",r->data);
preorder(r->left);
 preorder(r->right);

}}
void non_pre(node *r) {
int top=0;
node *s[20],*pt=r;
s[0]=NULL;
while(pt != NULL)

{
 printf("%d\t",pt->data);
 if(pt->right != NULL)
 s[++top] = pt->right;
 if(pt->left != NULL)
 pt = pt->left;
 else
 pt = s[top--];
}}
void postorder(node *r) {
if(r != NULL)

{
 postorder(r->left);
 postorder(r->right);
 printf("%d\t",r->data);

}
}
void non_post(node *root) {
node *stack[100]
;
int top=
-1;
node *temp=root;
while(temp!=NULL)

{
 while(temp!= NULL)

{
 top++;
 stack[top] = temp;
 temp = temp->left;

}
 label: temp =stack[top];
 top--
;
 if(temp->flag==1)

{
 printf("%d\t",temp->data);
 break;
}
 else
 {
 temp->flag=1;
 top++;
 stack[top] = temp;
 temp=temp->right;
 }
 }
 if(top>=0)
 goto label;
}
int main()
{
int d;
char ch = 'Y';
node *head = NULL;
int n,i=0;
printf("enter no.of nodes:");
scanf("%d",&n);
for(int i=0;i<n;i++){
printf("\n Enter the item to insert");
scanf("%d",&d);
head = create(head,d);
}
printf("\ninorder recursive\n");
inorder(head);
printf("\ninorder non recursive\n");
non_in(head);
printf("\n\n");
printf("\npostorder rrecursive\n");
postorder(head);
printf("\npostorder non recursive\n");
non_post(head);
printf("\n\n");
printf("\npreorder recursive\n");
preorder(head);
printf("\npreorder non recursive\n");
non_pre(head);
}
