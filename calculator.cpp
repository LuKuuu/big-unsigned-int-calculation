#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MaxSize 50
typedef struct node
{
    int data;
    struct node *next;
} NodeType;



void CreateLink(NodeType *&h,char a[ ],int n){
    NodeType *p,*r;
    int i=0;
    h=(NodeType *)malloc(sizeof(NodeType));
    r=h;
    while(i<n){
        p=(NodeType *)malloc(sizeof(NodeType));
        p->data=a[n-i-1]-'0';
         r->next=p;r=p;
        i++;
    }
    r->next=NULL;
}



void DestroyLink(NodeType *&h){
    NodeType *pre=h,*p=pre->next;
    while(p!=NULL){
        free(pre);
        pre=p;
        p=p->next;
    }
    free(pre);
}


void DispLink(NodeType *h){
    NodeType *p=h->next;
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}

void Reverse(NodeType *&h)
{NodeType *p=h->next,*q;
h->next=NULL;
while(p!=NULL)
{q=p->next;
p->next=h->next;h->next=p;
p=q;
}
}



void Add(NodeType *h1,NodeType *h2,NodeType *&h){
    NodeType *p1=h1->next,*p2=h2->next,*p,*r;
    int carry=0;
    h=(NodeType*)malloc(sizeof(NodeType));
    r=h;
    while(p1!=NULL&&p2!=NULL){
        p=(NodeType *)malloc(sizeof(NodeType));
        p->data=(p1->data+p2->data+carry)%10;
        r->next=p;
        r=p;
        carry=(p1->data+p2->data+carry)/10;
        p1=p1->next;
        p2=p2->next;
    }	
if(p1==NULL)p1=p2;
while (p1!=NULL)
{p=(NodeType *)malloc(sizeof(NodeType));
p->data=(p1->data+carry)%10;
r->next=p;r=p;
carry=(p1->data+carry)/10;
p1=p1->next;
}
if(carry>0)
{p=(NodeType *)malloc(sizeof(NodeType));
p->data=carry;
r->next=p;r=p; 
}
r->next=NULL;
}

NodeType* multiply(NodeType *h1,NodeType *h2){
    NodeType *tempValue, *tempHead, *tempLink, *r;
    

    int a=0;
    int remain=0;

    for(NodeType *p2=h2->next;p2!=NULL;p2=p2->next){


        tempHead=(NodeType*)malloc(sizeof(NodeType));
        tempLink=tempHead;
        tempValue=tempLink->next;
    
        for(int i=0; i<a; i++){
            tempValue=(NodeType*)malloc(sizeof(NodeType));
            tempValue->data=0;
            tempLink->next=tempValue;
            tempLink=tempValue;

            
        }

        for(NodeType *p1=h1->next;p1!=NULL;p1=p1->next){
            tempValue=(NodeType*)malloc(sizeof(NodeType));
            tempValue->data=(p2->data*p1->data+remain)%10;
            remain=(p2->data*p1->data+remain)/10;
            tempLink->next=tempValue;
            tempLink=tempValue;

     
        }


        if(remain!=0){
            tempValue=(NodeType*)malloc(sizeof(NodeType));
            tempValue->data=remain;
            remain=0;
            tempLink->next=tempValue;
            tempLink=tempValue;

        }
    

        a++;
        Add(tempHead, r, r);
        DestroyLink(tempHead);
    
    }
    
    return r;
}





int Mid(NodeType *h)
{NodeType *slow=h,*quick=h;
while (quick!=NULL&&quick->next!=NULL)
{slow=slow->next;
quick=quick->next->next;
}
return slow->data;
}



int main(){
    NodeType *h1,*h2, *r1, *r2;

        
    char s[MaxSize],t[MaxSize];
    printf("please input two numbers\n");
    printf("please input the first number ");scanf("%s",s); 
    printf("please input the second number ");scanf("%s",t);
    CreateLink(h1,s,strlen(s));
    CreateLink(h2,t,strlen(t));
    
    r2=multiply(h1,h2);
    Reverse(r2);
    Add(h1,h2,r1);
    Reverse(r1);

    for(;;){
        
        int command=0;

        printf("inut (1) to do addition, input (2) to do multiply ");scanf("%d",&command);
        if(command==1){
            printf("the result is ");
            DispLink(r1);

        }else if(command==2){
         

            printf("the result is ");
            DispLink(r2);

        }else{
            printf("error command!\n");
            return 1;
        }

        printf("press (1) to exit, press (2) to do another calculation ");scanf("%d",&command);
        if(command==1){
            DestroyLink(h1);
            DestroyLink(h2);
            DestroyLink(r1);
            DestroyLink(r2);

            return 0;
        }
        
    }


}