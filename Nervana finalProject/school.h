#ifndef SCHOOL_H_INCLUDED
#define SCHOOL_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NULL ((Node *)0)
extern IDSERIES;

 typedef struct Node{
     char studentName[30];
     float studentGPA;
     char studentAddress[30] ;
     char studentPhoneNumber[30];
      int studentID;
      //pointers to nodes in alphabitical order
      struct Node* NextNamePtr;
      struct Node* PrevNamePtr;
      // pointers to nodes to arrange according to GPA
      struct Node* NextGPAPtr;
      struct Node* PrevGPAPtr;
 }Node;
 typedef struct MyList{
      //pointers to nodes in alphabitical order
       Node* HeadNamePtr;
       Node* TailNamePtr;
      // pointers to nodes to arrange according to GPA
      Node* HeadGPAPtr;
      Node* TailGPAPtr;

 }List;

 void FillNode(Node* node);
 void PrintNode(Node * node);
 void CreateList(List * myList);
bool isEmpty(List * myList);
 bool NewStudent(List *myList);
bool NameSort(Node* node ,List *myList);
bool GPASort(Node* node ,List *myList);
void StudentList(List * myList);
void RankStudent(List * myList);
void StudentScore(List *myList);
void RearrangeRank(Node* node ,List *myList);
void deleteStudent(int ID , List * myLIst);
Node* searchNode(int ID , List * myList);
void EditStudent(int ID , List * myList);

#endif // SCHOOL_H_INCLUDED
