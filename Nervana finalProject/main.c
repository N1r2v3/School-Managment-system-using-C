#include <stdio.h>
#include <stdlib.h>
#include "school.h"
 #define newStudent 0
 #define editStudent 1
#define Rank 2
#define studentList 3
#define DeleteStudent 4
#define UpdateScores 5
#define Exit 6

int main()
{
    List myList;
    CreateList(&myList);
    int action;
    int ID;
    while (1)
{ printf("\n insert \n 0-new student \n 1-edit student info \n 2- view rank \n 3-view list \n 4-delete student\n 5- update scores \n 6- exit ");
   scanf("%d",&action);
   fflush(stdin);

switch(action)
{
    case(newStudent):
        NewStudent(&myList);
        break;
    case(editStudent):

            printf("/nInsert Student's ID");
            scanf("%d",&ID);
            fflush(stdin);
           EditStudent(ID,&myList);
        break;
    case(Rank):
            printf("\n Rank :");
            RankStudent(&myList);

        break;
    case (studentList):
        StudentList(&myList);
        break;
    case(DeleteStudent):
            printf("insert the ID of student you want to delete");
            scanf("%d",&ID);
         deleteStudent(ID,&myList);
        break;
    case(UpdateScores):
        StudentScore(&myList);
        break;
    case(Exit):
        return ;
    default :
        printf("wrong choice");
}

printf("\n===========================================\n");

}

}
