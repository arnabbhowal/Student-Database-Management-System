#include<iostream>
#include<conio.h>
#include<string>
#include<windows.h>
#include<fstream>
#include<sstream>
#include<dos.h>
#include<cctype>
using namespace std;
bool check = true;
void login();
void passwd();
void user();
void mainmenu();
struct node
{
     char name[20];
     int rollNo;
     int m1;
     int m2;
     int m3;
     node *next;
}*head,* lastptr;

void add()    //Adds record of student//
{
     node *p;
     p=new node;
     cout<<"Enter name of student:"<<endl;
     gets(p->name);
     fflush(stdin);
     cout<<"Enter Roll Number of student:"<<endl;
     cin>>p->rollNo;
     fflush(stdin);
     cout<<"Enter sub1 marks of student:"<<endl;
     cin>>p->m1;
     fflush(stdin);
     cout<<"Enter sub2 marks of student:"<<endl;
     cin>>p->m2;
     fflush(stdin);
     cout<<"Enter sub3 marks of student:"<<endl;
     cin>>p->m3;
     fflush(stdin);
     p->next=NULL;

     if(check)
     {
          head = p;
          lastptr = p;
          check = false;
     }
     else
     {
          lastptr->next=p;
          lastptr=p;
     }
     cout<<endl<<"Recored Entered";
     getch();
}
void modify()   //modifies record of student//
{
     int flag=0;
     node *ptr;
     node *prev=NULL;
     node *current=NULL;
     int roll_no;
     cout<<"Enter Roll Number to search:"<<endl;
     cin>>roll_no;
     prev=head;
     current=head;
     while(current!=NULL)
     {
         if(current->rollNo==roll_no)
         {
             flag=1;
             break;
         }
         prev=current;
         current=current->next;
     }
     if(flag==1)
     {
         ptr=new node;
         fflush(stdin);
         cout<<"Enter name of student:"<<endl;
         gets(ptr->name);
         fflush(stdin);
         cout<<"Enter Roll Number of student:"<<endl;
         cin>>ptr->rollNo;
         fflush(stdin);
         cout<<"Enter sub1 marks of student:"<<endl;
         cin>>ptr->m1;
         fflush(stdin);
         cout<<"Enter sub2 marks of student:"<<endl;
         cin>>ptr->m2;
         fflush(stdin);
         cout<<"Enter sub3 marks of student:"<<endl;
         cin>>ptr->m3;
         fflush(stdin);
         prev->next=ptr;
         ptr->next=current->next;
         current->next=NULL;
         delete current;
         cout<<endl<<"Recored Modified";
     }
     else if(flag==0)
     {
        printf("Record not available!!");
     }
      getch();
}
void search()   //searches record of student//
{
     int flag=0;
     node *prev=NULL;
     node *current=NULL;
     int roll_no;
     cout<<"Enter Roll Number to search:"<<endl;
     cin>>roll_no;
     prev=head;
     current=head;
     while(current!=NULL)
     {
          if(current->rollNo==roll_no)
          {
              flag=1;
              break;
          }
          prev=current;
          current=current->next;
     }
     if(flag==1)
     {
         cout<<"\nName: ";
         puts(current->name);
         cout<<"\nRoll No:";
         cout<<current->rollNo;
         cout<<"\nSub1 Marks:";
         cout<<current->m1;
         cout<<"\nSub2 Marks:";
         cout<<current->m2;
         cout<<"\nSub2 Marks:";
         cout<<current->m2;
     }
     else if(flag==0)
     {
         cout<<"Record not available!!";
     }
      getch();
}
void del()    //deletes record of a student//
{
     int flag=0;
     node *ptr=NULL;
     node *prev=NULL;
     node *current=NULL;
     int roll_no;
     cout<<"Enter Roll Number to Delete:"<<endl;
     cin>>roll_no;
     prev=head;
     current=head;
     while(current!=NULL)
     {
          if(current->rollNo==roll_no)
         {
              flag=1;
              break;
         }
         prev=current;
         current=current->next;
     }
     if(flag==1)
     {
         prev->next = current->next;
         current->next=NULL;
         delete current;
         cout<<endl<<"Record Deleted";
     }
     else if(flag==0)
     {
         printf("Record not available!!");
     }
     getch();
}
void disp()
{
     int flag=0;
     node *prev=NULL;
     node *current=NULL;
     prev=head;
     current=head;
     if(head==NULL)
     {
         flag=1;
     }
     if(flag==0)
     {
         while(current!=NULL)
         {
             cout<<"\nName: ";
             puts(current->name);
             cout<<"\nRoll No:";
             cout<<current->rollNo;
             cout<<"\nSub1 Marks:";
             cout<<current->m1;
             cout<<"\nSub2 Marks:";
             cout<<current->m2;
             cout<<"\nSub3 Marks:";
             cout<<current->m3;
             cout<<"\n--------------------------------------";
             prev=current;
             current=current->next;
         }
     }
     else if(flag==1)
     {
         cout<<"Record not available!!";
     }
      getch();
}
void login()
{
    char x;
    system("cls");
    cout<<"\n\t\tWELCOME TO STUDENT MANAGEMENT SYSTEM";
    passwd();
}
void passwd()
{
    cout<<"\n\nEnter the Password:";
    char pwd[6],p[6]="abcde";
    int i=0;
    while(i<5)
        {
            pwd[i]=getch();
            cout<<"*";
            i++;
        }
    if(strcmp(pwd,p)==0)
        mainmenu();
    else
    {
        cout<<"\n\n\tWrong password!!!";
        getch();
        login();
    }
    getch();
}

void mainmenu()
{
     char x;
     system("cls");
     cout<<"\t\t\t\t ********************************* \t\t\t"<<endl;
     cout<<"\t\t\t\t ****STUDENT MANAGEMENT SYSTEM**** \t\t\t"<<endl;
     cout<<"\t\t\t\t ********************************* \t\t\t"<<endl;
     cout<<"\n\nPress Any Key To Continue . . . ."<<endl;

     getch();
     do
     {
          system("cls");
          cout<<"\t\t\t\t ********************************* \t\t\t"<<endl;
          cout<<"\t\t\t\t ****STUDENT MANAGEMENT SYSTEM**** \t\t\t"<<endl;
          cout<<"\t\t\t\t ********************************* \t\t\t"<<endl;
          cout<<"\n\t\t\t\t   1: Add New record"<<endl;
          cout<<"\n\t\t\t\t   2: Search a record"<<endl;
          cout<<"\n\t\t\t\t   3: Modify a record"<<endl;
          cout<<"\n\t\t\t\t   4: Delete a record"<<endl;
          cout<<"\n\t\t\t\t   5: Display record"<<endl;
          cout<<"\n\t\t\t\t   6: Exit"<<endl;
          cout<<"\n\t\t\t\tEnter your choice:";
          x=getch();
          if(x=='1')
          {
               system("cls");
               add();
          }
          else if(x=='2')
          {
               system("cls");
               search();
          }
          else if(x=='3')
          {
               system("cls");
               modify();
          }
          else if(x=='4')
          {
               system("cls");
               del();
          }
          else if(x=='5')
          {
               system("cls");
               cout<<"\n\n\t\t\tSTUDENTS' RECORD\n";
               disp();
          }
          else if(x=='6')
          {
              exit(-1);
          }
          else
          {
          }
     }while(x != 27);
     getch();
}
int main()
{
    login();
    getch();
}
