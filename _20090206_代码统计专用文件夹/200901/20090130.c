#include <stdio.h>
#define NULL 0
    struct JD
    { int data;
      struct JD *next;
    };
    int find(int number,struct JD *h)
    { while(h->data)
       { if(h->data!=number)
           { h=h->next;
         continue;
           }
         else
           return 0;
       }
      return 1;
    }
    struct JD * make()
    { struct JD *h=NULL,*p=NULL;
      int number,tf;
      h=(struct JD *)malloc(sizeof(struct JD));
      scanf("%d",&h->data);
      p=h;
      while(p->data)
        { p->next=(struct JD *)malloc(sizeof(struct JD));
          p=p->next;
          p->data=0;
          scanf("%d",&number);
          tf=find(number,h);
          if(tf)
        p->data=number;
          else
        continue;
        }
      return h;
    }
   
    void print(struct JD *h)
    { while(h->data)
       { printf("%d ",h->data);
         h=h->next;
       }
    }
   
    struct JD * change(struct JD *la,struct JD *lb)
    { struct JD *h,*p,*s,*q;
      int number,tf;
      p=lb;
      while(p->data)
        { number=p->data;
          tf=find(number,la);
          p=p->next;
          if(tf)
        { s=(struct JD *)malloc(sizeof(struct JD));
          s->data=number;
          s->next=la;
          la=s;
        }
          else
        continue;
        }
      return la;
    }
   
    void del(struct JD *h)
    { struct JD *p=h->next;
      while(h->data)
       { free(h);
         h=p;
         p=p->next;
       }
      free(h);
    }

    void main()
    { struct JD *la,*lb;
      printf("\n\nGive the number to LA :\n\n");
      la=make();
      printf("\nLA is:   ");
      print(la);
      printf("\n\nGive the number to LB :\n\n");
      lb=make();
      printf("\nLB is:   ");
      print(lb);
      la=change(la,lb);
      printf("\n\n\nThe new LA=LA||LB is:   ");
      print(la);
      del(la);
      del(lb);
      printf("\n\n\nPass any key to exit...!\n");
      getch();
    } 
