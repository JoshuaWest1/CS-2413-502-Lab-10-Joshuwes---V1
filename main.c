/*
Joshua West
4/17/2021
LAB 10 QA
*/




#include <stdio.h>
#define size 10
int hash[size]={0};
int In_Num = 1;

//PROTOTYPE STATEMENTS
void insert();
void search();
void display();


int main()
{
  int NUM, is = 1;; 
  printf("How Many Values Are You Inputing Into The Table? ");
    scanf("%d", &NUM);

  for(int i = 0; i < NUM; i++){insert();}//function call to insert a value

   while(is != 0){
   printf("\n\nEnter '1' to Search For A Value\nEnter '0' to End Program\n");
   scanf("%d", &is); //Menu for Search 

if(is != 0){
    search();//function call to find a value
    display();//display the Hash Table
    }//END of IF
   }//END of WHILE


   printf("\nTHE PROGRAM HAS ENDED\n");
}//END OF MAIN




//FUNCTION TO INSERT VALUE INTO TABLE
void insert()
{
 int Val,INDEX,i,Hash_Key;


 printf("\nEnter value #%d into the hash table: ", In_Num);
 scanf("%d",&Val);
 In_Num++;


 Hash_Key=Val%size;//calcuates the hash key from the key(value) modulo divided by the size(10) 


    for(i=0;i<size;i++)//while i is less that 10
    {
        
        INDEX=(Hash_Key+i*i)%size;//the INDEX is the remainder of hashkey+i^2 from 10
    
        if(hash[INDEX] == 0)
        {
            hash[INDEX]=Val;//if no value is taken, insert into place

            break;//
        }
    }
    if(i == size)
     printf("\nNot Enough Space In Hash Table to Insert Value\n");
}//END OF INSERT







//FUNCTION TO FIND VALUE IN TABLE
void search()
{

 int Val,i,INDEX,Hash_Key;
 printf("\nEnter A Value You Would Like To Find: ");
 scanf("%d",&Val);

 Hash_Key=Val%size;
  for(i=0;i<size; i++)
  {
    
    INDEX=(Hash_Key+i*i)%size;//Calculate Index The same as Above

    if(hash[INDEX]==Val)//IF the value in hash index is the same as the value then it has been found

    {
      printf("The Value %d Is Found In Index #%d",Val, INDEX);//output location of value

      break;
    }
  }
  if(i == size)//if the value is never found
    printf("The Value %d Is Not Found In Any Index ",Val);
}//END OF SEARCH








//FUNCTION TO DISPLAY TABLE
void display()
{
  int i;

  printf("\n\nThe Hash Table Is:\n");

  for(i=0;i<size; i++){printf("\nIndex %d  :  %d",i,hash[i]);}//outputs the value in the Table

}//END OF DISPLAY