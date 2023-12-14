/**
Problem Statement:
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. 
Write C++ program using stack to check whether given expression is well parenthesized or not.
**/
#include <iostream>
using namespace std;
#define size 10

class stackexp
{
    int top;
    char stk[size];
public:
    stackexp()
    {
     top=-1;
    }
    void push(char);
    char pop();
    int isfull();
    int isempty();
};

void stackexp::push(char x)
{
    top=top+1;
    stk[top]=x;
}

char stackexp::pop()
{
    char s;
    s=stk[top];
    top=top-1;
    return s;
}

int stackexp::isfull()
{
    if(top==size)
        return 1;
    else
        return 0;
}

int stackexp::isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int main()
{
    stackexp s1;
    char exp[20],ch;
    int i=0;
    cout << "\n\t!!Well Formness of Parenthesis..!!!!" << endl; // prints !!!Hello World!!!
    cout<<"\nEnter the expression to check whether it is in well form or not :  ";
    cin>>exp;
    if((exp[0]==')')||(exp[0]==']')||(exp[0]=='}'))
    {
        cout<<"\n Invalid Expression.....\n";
        return 0;
    }
    else
    {
        while(exp[i]!='\0')
        {
            ch=exp[i];
            switch(ch)
            {
            case '(':s1.push(ch);break;
            case '[':s1.push(ch);break;
            case '{':s1.push(ch);break;
            case ')':s1.pop();break;
            case ']':s1.pop();break;
            case '}':s1.pop();break;
            }
            i=i+1;
        }
    }
    if(s1.isempty())
    {
        cout<<"\nExpression is well parenthesis...\n";
    }
    else
    {
        cout<<"\nSorry !!! Invalid Expression or not in well parenthesized....\n";
    }
    return 0;
}

/******************* output   *****************************************************

  !!Well Formness of Parenthesis..!!!!

Enter the expression to check whether it is in well form or not :  (m<(n[8]+0))

Expression is well parenthesis...


!!Well Formness of Parenthesis..!!!!

Enter the expression to check whether it is in well form or not :  )(m+n)*(a-b)

 Invalid Expression.....



     !!Well Formness of Parenthesis..!!!!

Enter the expression to check whether it is in well form or not :  (m+b(n[8)/2+3)

Sorry !!! Invalid Expression or not in well parenthesized....


*********************************************************************************/


















































/*#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define bool int

/* structure of a stack node */
struct sNode
{
   char data;
   struct sNode *next;
};

/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data);

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref);

/* Returns 1 if character1 and character2 are matching left
   and right Parenthesis */
bool isMatchingPair(char character1, char character2)
{
   if (character1 == '(' && character2 == ')')
     return 1;
   else if (character1 == '{' && character2 == '}')
     return 1;
   else if (character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;
}

/*Return 1 if expression has balanced Parenthesis */
bool areParenthesisBalanced(char exp[])
{
   int i = 0;

   /* Declare an empty character stack */
   struct sNode *stack = NULL;

   /* Traverse the given expression to check matching parenthesis */
   while (exp[i])
   {
      /*If the exp[i] is a starting parenthesis then push it*/
      if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        push(&stack, exp[i]);

      /* If exp[i] is a ending parenthesis then pop from stack and
          check if the popped parenthesis is a matching pair*/
      if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
      {

          /*If we see an ending parenthesis without a pair then return false*/
         if (stack == NULL)
           return 0;

         /* Pop the top element from stack, if it is not a pair
            parenthesis of character then there is a mismatch.
            This happens for expressions like {(}) */
         else if ( !isMatchingPair(pop(&stack), exp[i]) )
           return 0;
      }
      i++;
   }

   /* If there is something left in expression then there is a starting
      parenthesis without a closing parenthesis */
   if (stack == NULL)
     return 1; /*balanced*/
   else
     return 0;  /*not balanced*/
}

/* UTILITY FUNCTIONS */
/*driver program to test above functions*/
int main()
{
  char exp[100] ;
  cout<<"enter:";
  cin>>exp;
  if (areParenthesisBalanced(exp))
    printf("\n Balanced ");
  else
    printf("\n Not Balanced ");
  return 0;
}

/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data)
{
  /* allocate node */
  struct sNode* new_node =
            (struct sNode*) malloc(sizeof(struct sNode));

  if (new_node == NULL)
  {
     printf("Stack overflow \n");
     getchar();
     exit(0);
  }

  /* put in the data  */
  new_node->data  = new_data;

  /* link the old list off the new node */
  new_node->next = (*top_ref);

  /* move the head to point to the new node */
  (*top_ref)    = new_node;
}

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
  char res;
  struct sNode *top;

  /*If stack is empty then error */
  if (*top_ref == NULL)
  {
     printf("Stack overflow \n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->data;
     *top_ref = top->next;
     free(top);
     return res;
  }
}
*/
