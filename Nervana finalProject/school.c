#include "school.h"
int IDSERIES=0;
void FillNode(Node* node){
   // scanning student's data from user
    // name
    printf("\n Please enter student's name :");
    fgets(node->studentName, 30, stdin);

    //gpa
    printf("\n Please enter student's GPA :");
    scanf(" %f",&(node->studentGPA));

    // checking GPA range after scanning it
    while(0>(node->studentGPA) || (node->studentGPA)>4)
    {
        printf(" \n Error, GPa range is 0<GPA<4, please re-enter Student's GPA :");
         scanf(" %f",&(node->studentGPA));
    }
    fflush(stdin);
    //address
   printf(" \n Please enter student's address :");
    fgets(node->studentAddress, 30, stdin);
    //phone number
    printf("\n Please enter student's phone number :");
    fgets(node->studentPhoneNumber, 30, stdin);
    // national ID
   node->studentID= ++ IDSERIES;
    printf(" \n Students ID is : %d ", node->studentID);


    }
void PrintNode(Node * node)
   {
    // to print data of the struct
    printf("\n Student %d data:  ",node->studentID);
    printf(" \n \t   ID: %d",node->studentID);
    printf(" \n \t  Name: %s",node->studentName);
    printf(" \n \t  GPA: %f",node->studentGPA);
    printf(" \n \t  Address: %s",node->studentAddress);
    printf(" \n \t  Phone Number: %s",node->studentPhoneNumber);
    printf("\n -------------------\n");

}

void CreateList(List * myList)
{
    //intializing pointers
  myList->HeadNamePtr = NULL;
  myList->TailNamePtr = NULL;
  myList->HeadGPAPtr = NULL;
  myList->TailGPAPtr = NULL;


}
bool isEmpty(List * myList){
    // return true if head is null
    return ((myList->HeadGPAPtr)==NULL);
}
 bool NewStudent(List *myList){

     // step 1 reserve memory in heap for  new node
     Node* node = (Node*) malloc(sizeof(Node));
     // step 2 check if the memory is reserved or not
     if (node==NULL)
        {

            printf(" cannot store data no memory left in heap ");
            return false;
        }

            //step 3 node already created so fill data
            FillNode(node);
            // 3.1 intialize node pointers
            node->NextNamePtr=NULL;
            node->PrevNamePtr=NULL;
            node->NextGPAPtr=NULL;
            node->PrevGPAPtr=NULL;\
            //step 4 check if it is the first node in the list
            if (isEmpty(myList))
                 { //set all list pointers to node pointer
                      myList->HeadNamePtr = node;
                      myList->TailNamePtr = node;
                      myList->HeadGPAPtr = node;
                      myList->TailGPAPtr = node;

                      return true;
                 }
             //list already contains data

                    // sort according to name
            NameSort(node,myList);
            // sort according to GPA
             GPASort(node,myList) ;
             return true;


 }
 bool NameSort(Node* node , List* myList)
 {

        Node * searchPtr=myList->HeadNamePtr;
                    signed char compare;
                    compare =stricmp(node->studentName,searchPtr->studentName);
                    if (compare==-1)
                    {
                        searchPtr->PrevNamePtr=node;
                        node->NextNamePtr=searchPtr;
                        myList->HeadNamePtr=node;
                        return true;

                    }
                    while(searchPtr->NextNamePtr!=NULL)// while it is not the last node
                    {
                       signed char compare =stricmp(node->studentName,searchPtr->studentName);
                        if(compare!=1) //search > node then the node will be the previous
                        {
                           node->PrevNamePtr= searchPtr->PrevNamePtr; // node prev = seach prev
                          searchPtr->PrevNamePtr= node;   // seach prev = node
                          node->NextNamePtr= searchPtr; // node next = search ptr
                          node->PrevNamePtr->NextNamePtr = node;
                            //inside the node prev add the next of it to node
                          return true;

                        }
                       searchPtr= searchPtr->NextNamePtr;
                    }
                // search for specific node
                   if (searchPtr->NextNamePtr==NULL)
                   {// if search is the tail .. compare tail with search and update search
                       if((stricmp(node->studentName,searchPtr->studentName)==1)){
                            // if the GPA is higher than tail make it the tail
                       searchPtr->NextNamePtr= node;
                       node->PrevNamePtr=searchPtr;
                       // update mylist tail
                       myList->TailNamePtr=node;
                       node->NextNamePtr=NULL;
                       return true;}
                      else{
                            // tail is higher than search then insert it before tail
                        myList->TailNamePtr->PrevNamePtr->NextNamePtr=node;
                        node->PrevNamePtr=myList->TailNamePtr->PrevNamePtr;
                        node->NextNamePtr=searchPtr;
                        myList->TailNamePtr=node;
                      }
                   }
                   return false;
 }

 bool GPASort(Node* node , List* myList)
 {
     Node* searchPtr = myList->HeadGPAPtr;
     if ((searchPtr->studentGPA)>= (node->studentGPA))
     {
          searchPtr->PrevGPAPtr=node;
          node->NextGPAPtr=searchPtr;
          myList->HeadGPAPtr=node;
          node->PrevGPAPtr=NULL;
          return true;
     }

                    while(searchPtr->NextGPAPtr!=NULL)// while it is not the last node
                    {

                        if((node->studentGPA)<=(searchPtr->studentGPA)) //search > node then the node will be the previous
                        {
                           node->PrevGPAPtr= searchPtr->PrevGPAPtr; // node prev = seach prev
                          searchPtr->PrevGPAPtr= node;   // seach prev = node
                          node->NextGPAPtr= searchPtr; // node next = search ptr
                          node->PrevGPAPtr->NextGPAPtr = node;  //inside the node prev add the next of it to node
                          return true;
                        }
                        searchPtr=searchPtr->NextGPAPtr;
                    }
                // search for specific node
                   if (searchPtr->NextGPAPtr==NULL)
                   {// if search is the tail .. compare tail with search and update search
                       if((node->studentGPA)>(searchPtr->studentGPA)){
                            // if the GPA is higher than tail make it the tail
                       searchPtr->NextGPAPtr= node;
                       node->PrevGPAPtr=searchPtr;
                       // update mylist tail
                       myList->TailGPAPtr=node;
                       node->NextGPAPtr=NULL;
                       return true;}
                      else{
                            // tail is higher than search then insert it before tail
                        myList->TailGPAPtr->PrevGPAPtr->NextGPAPtr=node;
                        node->PrevGPAPtr=myList->TailGPAPtr->PrevGPAPtr;
                        node->NextGPAPtr=searchPtr;
                        myList->TailGPAPtr=node;
                      }
                   }



 }

void StudentList(List * myList)
{if(myList->HeadNamePtr == NULL)//list is empty
    {
        printf("List is empty\n");
        return;
    }
    Node * pointer ;
for(pointer = myList->HeadNamePtr;pointer!=NULL;pointer=pointer->NextNamePtr)
    {
        PrintNode(pointer);
    }
}
void RankStudent(List * myList)
{
     if(myList->HeadGPAPtr == NULL)//list is empty
    {
        printf("List is empty\n");
        return;
    }
    Node * pointer = myList->HeadGPAPtr;
   for(pointer = myList->HeadGPAPtr;pointer!=NULL;pointer=pointer->NextGPAPtr){


        PrintNode(pointer);
    }

}
void StudentScore(List *myList)
{
    if(myList->HeadNamePtr == NULL)//list is empty
    {
        printf("no students in this list \n");
        return;
    }
      Node * pointer ;
      float oldGPA;
for(pointer = myList->HeadNamePtr;pointer!=NULL;pointer=pointer->NextNamePtr)
    {
        oldGPA= pointer->studentGPA;
        printf("\n please enter the grade of %s ", pointer->studentName);
        scanf("%f",&(pointer->studentGPA));

    while(0>(pointer->studentGPA) || (pointer->studentGPA)>4)
        {
            printf(" \n Error, GPa range is 0<GPA<4, please re-enter Student's GPA :");
             scanf(" %f",&(pointer->studentGPA));
        }
     fflush(stdin);
         // if the student is in the same rank as the previous don't change it's place
        if( (pointer->studentGPA==oldGPA)){continue;}
         // rearrange student according to GPA
          RearrangeRank(pointer, myList );
    }


}
void RearrangeRank(Node* node ,List *myList)
{ //join the next and the previous nodes with each other
    // if it is the head
    if (node->PrevGPAPtr==NULL)
    {
       myList->HeadGPAPtr= node->NextGPAPtr;
        node->NextGPAPtr->PrevGPAPtr= NULL;
        node->NextGPAPtr= NULL;
        node->PrevGPAPtr= NULL;
        GPASort(node,myList);
        return;
    }
    // if it is the tail
    if(node->NextGPAPtr==NULL)
    {
      myList->TailGPAPtr= node->PrevGPAPtr;
        node->PrevGPAPtr->NextGPAPtr= NULL;
         node->NextGPAPtr= NULL;
        node->PrevGPAPtr= NULL;
        GPASort(node,myList);
        return;
    }
    // middle
    Node* temp =node->NextGPAPtr;
    Node* temp2 =node->PrevGPAPtr;
  node->PrevGPAPtr->NextGPAPtr=temp;
  node->NextGPAPtr->PrevGPAPtr=temp2;
  node->NextGPAPtr=NULL;
  node->PrevGPAPtr=NULL;
  // resort the node according to GPA
  GPASort(node,myList);

}


void deleteStudent(int ID , List * myList)
{ // search is the student is found
    if(myList->HeadGPAPtr==NULL)
    {
       printf("list is empty");
         return;
    }

   Node * temp = searchNode(ID,myList);
   if (temp ==NULL){
        printf("student not found");
         return;
   }
   // if the student is the head
   if(myList->HeadGPAPtr==myList->TailGPAPtr)
   {
       free(temp);
       myList->HeadGPAPtr=NULL;
      myList->TailGPAPtr=NULL;

      printf("deleted");
      return;
   }
    if (temp->PrevGPAPtr==NULL)
    {
       myList->HeadGPAPtr= temp->NextGPAPtr;

        temp->NextGPAPtr->PrevGPAPtr= NULL;

        free(temp);
        printf("deleted");
         return;
    }
    // if student is tail
    if(temp->NextGPAPtr==NULL)
    {
      myList->TailGPAPtr= temp->PrevGPAPtr;
        temp->PrevGPAPtr->NextGPAPtr= NULL;
       free(temp);
        printf("deleted");
        return;
    }
  // middle


    temp->PrevGPAPtr->NextGPAPtr=temp->NextGPAPtr;
    temp->NextGPAPtr->PrevGPAPtr=temp->PrevGPAPtr;
   free(temp);
   printf("deleted");
}
Node* searchNode(int ID , List * myList)
{
     Node * searchPtr=myList->HeadGPAPtr;
     while(searchPtr!=NULL)// while it is not the last node
     {
       if (searchPtr->studentID==ID)
       {

           return searchPtr;
       }
         searchPtr= searchPtr->NextGPAPtr;
     }

printf("not found");
return NULL;

}

void EditStudent(int ID , List * myList)
{

    Node * node = searchNode(ID,myList);
    if (node==NULL)
    {
        printf("student not found");
        return;
    }

 printf("insert 1 to edit GPA ,2 to address,3 to edit phone: ");
 int choice=3;
 fflush(stdin);
 scanf("%d",&choice);
 fflush(stdin);
 switch(choice)
 {
 case 1:
      printf("\n Please enter student's GPA :");

    scanf(" %f",&(node->studentGPA));
    while(0>(node->studentGPA) || (node->studentGPA)>4)
    {
        printf(" \n Error, GPa range is 0<GPA<4, please re-enter Student's GPA :");
         scanf(" %f",&(node->studentGPA));

    }
    printf("\n updated successfully\n");
    PrintNode(node);
    break;
 case 2 :
     printf(" \n Please enter student's address :");
    fgets(node->studentAddress, 30, stdin);
    printf("\n updated successfully\n");
    PrintNode(node);
    break;
 case 3:
     printf("\n Please enter student's phone number :");
    fgets(node->studentPhoneNumber, 30, stdin);
    printf("\n updated successfully\n");
    PrintNode(node);
    break;
 default:
    printf("wrong choice ");
 }

}


