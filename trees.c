#include <stdio.h>
#include <stdlib.h>

typedef struct tnode *Treeptr;

struct tnode {
  int data;
  Treeptr left;
  Treeptr right;  
};

Treeptr addtree(Treeptr tree,int data){
  if (tree == NULL){
    Treeptr newnode = malloc(sizeof(struct tnode));
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    tree = newnode;
  }
  else if (data < tree -> data)
     tree -> left = addtree(tree -> left,data);
    else if (data > tree -> data)
     tree -> right = addtree(tree -> right,data);
  return tree;  
}

void printtree(Treeptr tree){
    if(tree == NULL)
      return;
    printtree(tree ->left);
    printf("%d\n",tree -> data );
    printtree(tree -> right);
}

void freetree(Treeptr tree){
    if(tree != NULL){
        freetree(tree -> left);
        freetree(tree -> right);
        free(tree);
    }
}

int main (){

  int d;

   Treeptr tree = NULL;
   
   while (scanf("%d",&d) == 1)
   tree = addtree(tree,d);

  printtree(tree);

 return 0;
}

  

    