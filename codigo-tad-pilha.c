//Implementing Stack as a linked list
typedef struct stack_item
{
  stack_object content;
  struct stack_item *next;
} stack_item;

typedef stack_item *stack;

stack *create_stack(void)
{
  stack *s;
  s = (stack *) malloc(sizeof(stack));
  if(s==NULL)
    {
      printf("OUT OF MEMORY!\n");
      exit(1);
    }

  *s = NULL;
  return s;
}

boolean stack_is_empty(stack *s)
{
  return( (*s==NULL) ? TRUE : FALSE );
}

stack_object *top_of_stack(stack *s)
{
  if(stack_is_empty(s)==TRUE)
    {
      printf("TRIED TO FIND THE TOP OF AN EMPTY STACK!\n");
      exit(1);
    }

  return &((*s)->content);
}

void push_on_stack(stack *s, stack_object *object)
{
  stack_item *new_item;
  new_item = (stack_item *) malloc(sizeof(stack_item));
  if(new_item==NULL)
    {
      printf("OUT OF MEMORY!\n");
      exit(1);
    }

  new_item->content=*object;
  new_item->next=*s;
  *s=new_item;
}

void pop_stack(stack *s)
{
  stack_item *memo;
  
  if(stack_is_empty(s)==TRUE)
    {
      printf("TRIED TO POP AN EMPTY STACK!\n");
      exit(1);
    }

  memo=*s;
  *s=memo->next;
  free(memo);
}
