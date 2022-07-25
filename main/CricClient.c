#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "CricHeader.h"

#define MAX_STR 30

int main()
{
	int toss_result; //stores result of coin toss
	int firstInnings_score = 0; //score at the end of first innings is stored
    int result; //indicates the status of the game
    int user_team;   //Stores the number corresponding to the team chosen by the user
    int comp_team;   //Stores the number corresponding to the team picked by the computer
    char user_team_name[4];  //Stores the team name corresponding to the "user_team" as picked by the user
    char comp_team_name[4];  //Stores the team name corresponding to the "comp_team" as picked by the computer
    srand((unsigned) time(0));
    (void) system("clear"); //clear screen on cmd
    printf("\n----------# IPL 2021 #----------");
    printf("\n        Choose your team :");
    printf("\n        1. CSK      2. DC");
    printf("\n        3. KKR      4. MI");
    printf("\n        5. PBKS     6. RCB");
    printf("\n        7. RR       8. SRH");
    printf("\n--------------------------------");
    printf("\nEnter your option : ");
    (void) scanf("%d",&user_team);
     do
    {
        comp_team = (rand() % (8 - 1 + 1)) + 1; 
    } while (comp_team == user_team); //Picking a random number other than the one chosen by the user
    strcpy(user_team_name, assign_team_name(user_team));
    strcpy(comp_team_name, assign_team_name(comp_team));
    printf("--------------------------------\n");
    printf("\nYour team     : %s", user_team_name);
    printf("\nOpponent team : %s", comp_team_name);
    printf("\n\n--------------------------------\n");
    loader(5);
    (void) system("clear");
    
    List *l = List_create();
    int cb,cbo,cw,ca, a,i=0,j;
    loop:
    printf("How many Batsmen do you want in your team?\n(Preferable range 4-5)\n");
    (void) scanf("%d", &cb);
    printf("How many Bowlers do you want in your team?\n(Preferable range 3-5)\n");
    (void) scanf("%d", &cbo);
    printf("How many Wicket Keepers do you want in your team?\n(Preferable range 1-2)\n");
    (void) scanf("%d", &cw);
    printf("How many All-Rounders do you want in your team?\n(Preferable range 3-4)\n");
    (void) scanf("%d", &ca);
    int total = cb + cbo + cw + ca;
    if(total < 11)
    {
        printf("Not enough players, pick again");
        goto loop;
    }
    else if (total > 11)
    {
        printf("Too many players, pick again");
        goto loop;
    }
    char ch[11][30];
    showbatsmen();
    printf("\n****Choose your %d Batsmen****\n",cb);
    for (i = 0; i < cb; i++)
    {
        printf("\nChosen a number: ");
        (void) scanf("%d", &a);
        printf("Chosen player ");
        linebatsmen(a, ch[i]);
        printf("%s", ch[i]);
    }
    showKeeper();
    printf("\n****Choose your %d Wicket Keeper****\n",cw);
    for (j=0; j < cw; j++,i++)
    {
        printf("\nChosen a number: ");
        (void) scanf("%d", &a);
        printf("Chosen player ");
        lineKeeper(a, ch[i]);
        printf("%s", ch[i]);
    }
    showAllRounders();
    printf("\n****Choose your %d All-Rounders****\n",ca);
    for (j=0; j < ca; j++,i++)
    {
        printf("\nChosen a number: ");
        (void) scanf("%d", &a);
        printf("Chosen player ");
        lineAllRounders(a, ch[i]);
        printf("%s", ch[i]);
    }
    showbowler();
    printf("\n****Choose your %d Bowlers****\n",cbo);
    for (j=0; j < cbo; j++,i++)
    {
        printf("\nChosen a number: ");
        (void) scanf("%d", &a);
        printf("Chosen player ");
        linebowler(a, ch[i]);
        printf("%s", ch[i]);
    }
    printf("\n\n****** PLAYERS LIST ******\n");
    for (int i = 0; i < total; i++)
    {
        List_append(l, ch[i]);
       
    }
    List_print(l);
    
    
    toss_result = toss(); //calling the toss function which returns game mode number as per decision taken by user or opponent
    switch(toss_result)
    {
        //user bats first and then defends the total
        case 1:
        case 4: printf("\n-----1ST INNINGS-----");
                printf("\nYou are batting first !\n");
                firstInnings_score = batting(0,0);
                printf("\n-----END OF 1ST INNINGS-----");
                printf("\n%s = %d",user_team_name, firstInnings_score);
                printf("\n----------------------------");
                loader(5);
                printf("\n-----2ND INNINGS-----");
                result = bowling(1,firstInnings_score);
                printf("\n-----END OF 2ND INNINGS-----");
                if(result == -1)
                {
                    printf("\nRESULT : You LOST !");
                    printf("\n%s beats %s",comp_team_name, user_team_name);
                }
                if(result == -2)
                {
                    printf("\nRESULT : You WIN !");
                    printf("\n%s beats %s !", user_team_name, comp_team_name);
                }
                break;
        //user bowls first and chases the target
        case 2:
        case 3: printf("\n-----1ST INNINGS-----");
                printf("\nYou are bowling first !\n");
                firstInnings_score = bowling(0,0);
                printf("\n-----END OF 1ST INNINGS-----");
                printf("\n%s = %d",comp_team_name, firstInnings_score);
                printf("\n----------------------------");
                loader(5);
                printf("\n-----2ND INNINGS-----");
                result = batting(1,firstInnings_score);
                printf("\n-----END OF 2ND INNINGS-----");
                if(result == -1)
                {
                    printf("\nRESULT : You WIN !");
                    printf("\n%s beats %s !", user_team_name, comp_team_name);
                }
                if(result == -2)
                {
                    printf("\nRESULT : You LOST !");
                    printf("\n%s beats %s",comp_team_name, user_team_name);
                }
                break;
        default: break;             
                
    }
    
}
