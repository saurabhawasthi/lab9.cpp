# lab9.cpp
#include<iostream>
using namespace std;


class node{
     public:
     node *parent;
     node *left;
     node *right;
     int data;
    node(){
     parent=left=right=NULL;
     data=0;
    }
};

class Btree{
     public:
     node *root;

    Btree()
    {
    root=NULL;
    }

// to insert elements
 void insert(int x){
   node *temp=new node;
   temp->data=x;
   temp->parent=temp->left=temp->right=NULL;

   if(root==NULL)
   { root=temp;
   }
   else{ node *cur;
         cur=root;
        while(1){
            if(x<cur->data){

               if(cur->left==NULL){
                  temp->parent=cur;
                  cur->left=temp;
               break;
               }
              else{cur=cur->left;}
            }
           else {
                    if(cur->right==NULL)
                       {
                       temp->parent=cur;
                       cur->right=temp;
                                                                                                                                                                                                 1,10          Top
      break;}
                   else{cur=cur->right;}
                  }

        }
     }
 }

//to display the elements

 void display(node *temp){

      if(temp==NULL)
         return;
      display(temp->left);
      cout<<"\t"<<temp->data;
      display(temp->right);
}
/////////////////////////////////////count all nodes
int count(node *temp){
  int l,r;

   if (temp==NULL)
      { return 0;}
  else{ 
         while(temp->left !=NULL){
              l++;
              temp=temp->left;}
          cout<<"\nl= "<<l;
         temp=root;
         while(temp->right !=NULL){
              r++;
              temp=temp->right;}
         cout<<"\nr= "<<r;
         }

          return (l+r+1);
 }
//////////////////////////////////////////////////////////leaf count
int lcount(node *temp){
   if (temp==NULL)
     return 0;
   else if(temp->left==NULL && temp->right==NULL)
      return 1;
   else
                                                                                                                                                                                                 101,8         51%
return lcount(temp->left)+lcount(temp->right);

}
/////////////////////////////////////////////////////range search
void rsearch(node *temp,int max,int min){
  int n;
     if(temp==NULL)
         return;
      rsearch(temp->left,max,min);
      if(temp->data>=min && temp->data<=max)
        cout<<"\t"<<temp->data;
      rsearch(temp->right,max,min);
      n++;
     cout<<"\n NO. of nodes between "<<min<<" and  "<<max<<" = "<<n;
}
};

////////////////////////////////////////////main
int main(){
 Btree b;
 cout<<"\nMENU";
 cout<<"\n1.INSERT";
 cout<<"\n2.DISPLAY\n3.COUNT\n4.LEAF\n5.INTERNAL NODES\n6.RANGE SEARCH";
 cout<<"\nEXIT";

int ch,x,y,z,q;
do{
  cout<<"\nenter your choice (1-6): ";
  cin>>ch;
  switch(ch){
  case 1:cout<<"\nenter the data you want to enter :";
         cin>>x;
         b.insert(x);break;
  case 2:b.display(b.root);break;
  case 3:z =b.count(b.root);
         cout<<"\n no. of nodes = "<<z;break;
  case 4:y=b.lcount(b.root);
         cout<<"\n no. of leaf nodes= :"<<y;
  case 5:z=b.count(b.root);
         y=b.lcount(b.root);
         q=z-y;
         cout<<"\n no. of internal nodes = "<<q;break;
  case 6:cout<<"\n enter max value= ";cin>>x;
         cout<<"\n enter min value = ";cin>>y;
         b.rsearch(b.root,x,y);break;
  deafult:cout<<"\nwrong choice ";break;
  }
}while(ch!=7);
return 0;
}
