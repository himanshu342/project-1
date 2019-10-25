#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define MAX 100
char arr[MAX];
void push(char item);
char pop();
int precedence(char p);
void inftopfx( char source[], char target[]);


int top=-1;


/*------------------------------------------*/

int main()
{
int n;
char infix[100],postfix[100];
cout<<"Enter Infix Expression :\n";
gets(infix);
n=strlen(infix);
infix[n]=')';
infix[n+1]='\0';

inftopfx(infix,postfix);
cout<<"Corresponding Postfix Expression is :\n";
puts(postfix);
}

/*------------------------------------------*/

void push(char item)
{
if(top==MAX-1)
{
cout<<"OVERFLOW\n";
}
else
{
top=top+1;
arr[top]=item;
}
}

/*------------------------------------------*/

char pop()
{
char val;
val=arr[top];
top=top-1;

return val;
}

/*------------------------------------------*/

int precedence(char ch)
{
if(ch=='^')
{
return 3;
}
else if(ch=='*'||ch=='/')
{
return 2;
}
else if(ch=='+'||ch=='-')
{
return 1;
}
else
{
return 0;
}
}

/*------------------------------------------*/

void inftopfx(char source[], char target[])
{
int i=0,j=0,k=0;
char h[100];
push('(');

while(source[i]!='\0')
{
if(source[i]=='(')
{
push(source[i]);
i++;
}
else if(source[i]==')')
{
while(arr[top]!='(')
{
target[j++]=pop();
}
h[k++]=pop();
i++;
}
else if(source[i]>='a'&&source[i]<='z' || source[i]>='A'&&source[i]<='Z' )
{
target[j++]=source[i++];
}
else if(source[i]=='+' || source[i]=='-' || source[i]=='*' || source[i]=='/' || source[i]=='^' ||source[i]=='%' )
{
int g,h;
g=precedence(source[i]);
h=precedence(arr[top]);
if(g>h)
{
push(source[i++]);
}
else if(arr[top]=='(')
{
push(source[i++]);
}
else if(g<=h)
{
target[j++]=pop();
h=precedence(arr[top]);

push(source[i++]);
}
}
}
target[j]='\0';

}

/*------------------------------------------*/



