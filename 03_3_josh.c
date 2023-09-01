/* Joshua Bara
    IT - 03 */
 // DISPLAYING RECORDS OF  5 STUDENTS USING ARRAY OF STRUCTURE IN ASCENDING ORDER OF ROLL LIST
 
#include<stdio.h>
 struct students
 {
     char name[20];
     int roll_no;
     float percentage;
 } s[5], temp;
 void main()
 {

     printf("Enter Name,Roll_no,Percentage: \n");
     for (int i = 0; i < 5; i++)
     {
        scanf("%s %d %f", s[i].name, &s[i].roll_no, &s[i].percentage);
         printf("\n");
     }

     for (int i = 0; i < 5; i++)
    {
         for (int j = 0; j < 4; j++)
         {

             if(s[j].roll_no > s[j + 1].roll_no){
             temp = s[j];
             s[j] = s[j + 1];
             s[j + 1] = temp;
             }
         }
     }

     printf("Name\t\t Roll_no\t\t Percentage\n");
     printf("------------------------------\n");
     for (int i = 0; i < 5; i++)
     {
         printf("%s\t\t %d\t\t %f\n ", s[i].name, s[i].roll_no, s[i].percentage);
   }
 }

