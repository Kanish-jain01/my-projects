#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "server.h"

void main()
{
    int UserType;
    printf("Welcome!!\n");
    printf("Instructions\n");
    printf("\n 1. You are requested to enter the number against the type when options are given for, user-type, priority of bug, type of bug\n");
    printf("\n 2. The name and the description of the bug must be a string \n");
    printf("\n 3. While inputting the time write the hour in the first line and the minutes in the next line \n");
    printf("\n 4. For status change please enter capital Y for yes and capital N for no (if you are a manager) \n");
    printf("\n 5. Your status is automatically set to Not Assigned (for customer)\n");
    printf("\n 6. When the manager is using then he must change the status of all the bugs\n");
    printf("\n 7. It is mandatory to run the program as a customer for the first time to populate the file with details \n");
    printf("\nAre you a \n 1. Customer \n 2. Manager");
    printf("\n Please enter 1 for customer and 2 for manager\n ");
    scanf("%d",&UserType);
    printf("\n***********************************************\n\n");
    if(UserType==1)
    {
     ReadBugCustomer();
                                                        // calling the function to read the details of the bug
    }
   else
   {
     ReadBugManager();
   }
}
