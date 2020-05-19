#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "server.h"
void displayBug();
void ReadBugManager();

void ReadBugCustomer()
{
    FILE *fp = NULL;
    fp=fopen("myfile.txt","w+");                                // opening a file
    if(fp!=NULL)                                                // check if file is open
    {
        int NumberOfBugs;
        printf("How many bugs would you like to file?\n");
        scanf("%d",&NumberOfBugs);
        for(int i=0;i<NumberOfBugs;i++)
        {   int bugType,priority,hours,minutes;                     // declaring the variables
            char Name[40],description[200],nStr[500],hoursStr[25],minutesStr[25];
            char falsechar;
            srand(time(0));
            int n=rand();
            printf("\nThis is a new Bug\n");
            printf("\nPlease enter your name:\n");
            scanf("%c",&falsechar);
            gets(Name);                                             // name of the person filing the bug
            printf("\nPlease provide a one line description of the bug\n");
            gets(description);                                      // reading description of the bug
            printf("\nPlease select the type of the bug \n 1.Major \n 2.Minor \n 3.Cosmetic \n Please enter the number against desired type of bug: \n");
            scanf("%d",&bugType);                                   // reading type of bug
            printf("\nPlease provide the time at which the bug is filed (hours , minutes format):\n");
            scanf("%d %d",&hours,&minutes);                             // reading hours and minutes of the bug
            printf("\n");
            printf("\nPlease select the priority for the bug (a number)\n 1.Low \n 2.Medium \n 3.High \n Please enter the number against desired priority of bug: \n");
            scanf("%d",&priority);                                    // reading the priority of the bug
            printf("\n");
            printf("\nYour status of the bug is Not Assigned\n");

            fputs("Unique ID: ",fp);
            sprintf(nStr,"%d",n);
            fputs(nStr,fp);
            fprintf(fp, "\n");
            fputs("Name: ",fp);
            fputs(Name,fp);
            fprintf(fp, "\n");
            fputs("Bug Description: ",fp);                               // writing description of the bug
            fputs(description,fp);
            fprintf(fp, "\n");
            fputs("Time -  ",fp);
            sprintf(hoursStr,"%d",hours);
            fputs(hoursStr,fp);
            fputs(":",fp);
            sprintf(minutesStr,"%d",minutes);
            fputs(minutesStr,fp);
            fprintf(fp, "\n");
            fputs("Bug-Type: ",fp);
            if(bugType==1)
                {
                fputs("Major",fp);
                fprintf(fp, "\n");
                }
            else if(bugType==2)
                {
                fputs("Minor",fp);
                fprintf(fp, "\n");
                }
            else
                {
                fputs("Cosmetic",fp);
                fprintf(fp, "\n");
                }
            fputs("Priority: ",fp);
            if(priority==1)
                {
                fputs("Low",fp);
                fprintf(fp, "\n");
                }
            else if(priority==2)
                {
                fputs("Medium",fp);
                fprintf(fp, "\n");
                }
            else
                {
                fputs("High",fp);
                fprintf(fp, "\n");
                }
            fputs("Bug Status: Not Assigned ",fp);
            fprintf(fp, "\n");
            fprintf(fp, "\n");

        }
        fclose(fp);                                                                     // close the file
        fp=NULL;
        displayBug();

    }
    else
        {
            printf("Error opening file");
        }

}
void ReadBugManager()
{
    int i=0;
    char numStr[10];
    {
    printf("\n");
    FILE *fp;
    fp=fopen("myfile.txt","r");
    char ch[100];
    if(fp!=NULL)                        // check if file is open
    {
        while((fgets(ch,100,fp))!=NULL)
        {
           printf("%s",ch);
           i++;

        }
    fclose(fp);                         // close the file
    fp=NULL;
    }
    else
    {
        printf("Error opening file");
    }
    }
    FILE *fp = NULL;
    fp=fopen("myfile.txt","a");                                // opening a file
    if(fp!=NULL)                                                // check if file is open
    {
            int ChangeStatus;
            i=i/7;
            printf("\n You have %d bugs available for status change in the file  \n",i);
            for(int k=0;k<i;k++)
            {
                    printf("\n What would you like to change the status bug %d to: \n",k+1);
                    printf("\n 1. Assigned \n 2. Being Fixed \n 3. Fixed \n 4. Delivered\n");
                    printf("\n Please enter the number against desired status change: \n");
                    scanf("%d",&ChangeStatus);
                    fprintf(fp, "\n");
                    fputs("Changed the status of bug:  ",fp);
                    sprintf(numStr,"%d",k+1);
                    fputs(numStr,fp);
                    fputs(": ",fp);
                    if(ChangeStatus==1)
                        {
                        fputs("Assigned",fp);
                        fprintf(fp, "\n");
                        }
                    else if(ChangeStatus==2)
                        {
                        fputs("Being Fixed",fp);
                        fprintf(fp, "\n");
                        }
                    else if(ChangeStatus==3)
                        {
                        fputs("Fixed",fp);
                        fprintf(fp, "\n");
                        }
                    else
                    {
                       fputs("Delivered",fp);
                       fprintf(fp, "\n");
                    }


            }

        fclose(fp);                                                                     // close the file
        fp=NULL;
        displayBug();

    }
    else
        {
            printf("Error opening file");
        }

}

void displayBug()                   // to read the contents in the file
{
    printf("\n");
    FILE *fp;
    fp=fopen("myfile.txt","r");
    char ch[100];
    if(fp!=NULL)                        // check if file is open
    {
        while((fgets(ch,100,fp))!=NULL)
        {
           printf("%s",ch);

        }
    fclose(fp);   // close the file
    fp=NULL;
    }
    else
    {
        printf("Error opening file");
    }
}