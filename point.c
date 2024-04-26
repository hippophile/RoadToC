#include <stdio.h>
#include <stdlib.h>

//ασκηση 1 Y

// struct point {
//     double x;
//     double y;
// };

// struct point middle(struct point *a, struct point *b){
//     struct point m;
//     m.x = ((a->x) + (b->x)) / 2.0;
//     m.y = ((a->y) + (b->y)) / 2.0;
//     return m;
// }

// int main(void){

//   double m;

//     //struct pont a, b = {10,20};
//     struct point a, b, c;
//     a.x = 1.0;
//     a.y = 0.0;
//     b.x = 0.0;
//     b.y = 1.0;


// c = middle(&a,&b);

// printf("%f %f\n",c.x,c.y);

// return 0;
// }

//ασκηση 2 X

// struct person {
//   char *fname;
//   char *lname;
//   char *mname;
// };

// struct person *father(char *fname, char *lname, char *mname){
// struct person *newp;
// newp = malloc(sizeof(struct person));
// newp ->fname = f;
// newp ->lname = l;
// newp ->mname = m;
// return newp;
// }

// int main(int argc, char **argv){

//  int fname = atoi(argv[1]);
//   int lname = atoi(argv[2]);
//   int mname = atoi(argv[3]);

// char l, m, f;

// struct person *father(char *fname, char *lname, char *mname);



//   return 0;
// }

//ασκηση 3 Y

typedef struct listdata *Listptr;

struct listdata{
  int data;
  Listptr next;
};

void insert_at_start(int data, Listptr *list){
  Listptr newdata = malloc(sizeof(struct listdata));
  newdata -> data = data;
  newdata -> next = *list;
  *list = newdata;
}

float average(Listptr ptr){

}

int main(void) {
  Listptr list = NULL, temp;
  int d, c;
  int s = 0;

  while(scanf("%d",&d) == 1){
    insert_at_start(d, &list);
  }

  temp = list;
  
  while(temp != NULL){
    printf("%d\n",temp -> data);
    c++;
    s+= temp -> data;
    temp = temp -> next;
  }

  while (list != NULL){
    temp = list;
    list = list -> next;
    free(temp);
  }
  printf("the average is = %d",s/c);

  return 0;
}
