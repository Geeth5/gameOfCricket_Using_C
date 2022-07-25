#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include<bsd/string.h>
#include<string.h>
#include<assert.h>
//#include<sys/errno.h>
#include "CricHeader.h"

#define MAX_STR 30

//Creates A Node
Node *Node_create()
{
    Node *node = malloc(sizeof(Node));
    if (node != NULL)
    {
        node->data = "";
        node->next = NULL;
    }
    return node;
}

//Destroys a Node
void Node_destroy(Node *node)
{
    if (node != NULL)
        free(node);
}

//Creates a List
List *List_create()
{
    List *list = malloc(sizeof(List));
    if (list != NULL)
    {
        Node *node = Node_create();
        list->first = node;
    }
    return list;
}

void List_destroy(List *list)
{
    if (list != NULL)
    {
        Node *node = list->first;
        Node *next;
        while (node != NULL)
        {
            next = node->next;
            free(node);
            node = next;
        }

        free(list);
    }
}

void List_append(List *list, char *str)
{
    assert(list != NULL);
    assert(str != NULL);

    Node *node = list->first;
    while (node->next != NULL)
    {
        node = node->next;
    }

    node->data = str;
    node->next = Node_create();
}

void List_print(List *list)
{
    assert(list != NULL);

    Node *node = list->first;
    while (node->next != NULL)
    {
        printf("%s", node->data);
        node = node->next;
        /*if (node->next != NULL)
        {
            printf("");
        }*/
    }
}

void linebatsmen(int a, char *player)
{
    int no = 1, i = 0;
    char ch,str[MAX_STR];
    FILE *fp;
    fp = fopen("batsmen.txt", "r");
    if (fp == NULL)
        printf("Error Occurred while Opening the File!");
    else
    {
        ch = fgetc(fp);
        while (ch != EOF)
        {
            if (no == a)
            {
                str[i] = ch;
                i++;
            }
            if (ch == '\n')
            {
                no++;
            }
            ch = fgetc(fp);
        }
    }
    str[i] = '\0';
    strlcpy(player, str, MAX_STR);
    (void) fclose(fp);
}

void showbatsmen()
{
    char ch;
    int no = 1;
    FILE *fp;
    fp = fopen("batsmen.txt", "r");
    if (fp == NULL)
        printf("Error Occurred while Opening the File!");
    else
    {
        printf("\nFile's Content is:\n\n");
        ch = fgetc(fp);
        printf("%d ", no);
        while (ch != EOF)
        {
            if (ch == '\n')
            {
                printf("\n");
                no++;
                printf("%d ", no);
            }
            else
                printf("%c", ch);
            ch = fgetc(fp);
        }
    }
    (void) fclose(fp);
}

void linebowler(int a, char *player)
{
    int no = 1, i = 0;
    char ch, str[MAX_STR];
    FILE *fp;
    fp = fopen("bowlers.txt", "r");
    if (fp == NULL)
        printf("Error Occurred while Opening the File!");
    else
    {
        ch = fgetc(fp);
        while (ch != EOF)
        {
            if (no == a)
            {
                str[i] = ch;
                i++;
            }
            if (ch == '\n')
            {
                no++;
            }
            ch = fgetc(fp);
        }
    }
    str[i] = '\0';
    strlcpy(player, str, MAX_STR);
    (void) fclose(fp);
}

void showbowler()
{
    char ch;
    int no = 1;
    FILE *fp;
    fp = fopen("bowlers.txt", "r");
    if (fp == NULL)
        printf("Error Occurred while Opening the File!");
    else
    {
        ch = fgetc(fp);
        printf("%d ", no);
        while (ch != EOF)
        {
            if (ch == '\n')
            {
                printf("\n");
                no++;
                printf("%d ", no);
            }
            else
                printf("%c", ch);
            ch = fgetc(fp);
        }
    }
    (void) fclose(fp);
}

void lineKeeper(int a, char *player)
{
    int no = 1, i = 0;
    char ch, str[MAX_STR];
    FILE *fp;
    fp = fopen("keepers.txt", "r");
    if (fp == NULL)
        printf("Error Occurred while Opening the File!");
    else
    {
        ch = fgetc(fp);
        while (ch != EOF)
        {
            if (no == a)
            {
                str[i] = ch;
                i++;
            }
            if (ch == '\n')
            {
                no++;
            }
            ch = fgetc(fp);
        }
    }
    str[i] = '\0';
    strlcpy(player, str, MAX_STR);
    (void) fclose(fp);
}

void showKeeper()
{
    char ch;
    int no = 1;
    FILE *fp;
    fp = fopen("keepers.txt", "r");
    if (fp == NULL)
        printf("Error Occurred while Opening the File!");
    else
    {
        ch = fgetc(fp);
        printf("%d ", no);
        while (ch != EOF)
        {
            if (ch == '\n')
            {
                printf("\n");
                no++;
                printf("%d ", no);
            }
            else
                printf("%c", ch);
            ch = fgetc(fp);
        }
    }
    (void) fclose(fp);
}

void lineAllRounders(int a, char *player)
{
    int no = 1, i = 0;
    char ch, str[MAX_STR];
    FILE *fp;
    fp = fopen("allRounders.txt", "r");
    if (fp == NULL)
        printf("Error Occurred while Opening the File!");
    else
    {
        ch = fgetc(fp);
        while (ch != EOF)
        {
            if (no == a)
            {
                str[i] = ch;
                i++;
            }
            if (ch == '\n')
            {
                no++;
            }
            ch = fgetc(fp);
        }
    }
    str[i] = '\0';
    strlcpy(player, str, MAX_STR);
    (void) fclose(fp);
}

void showAllRounders()
{
    char ch;
    int no = 1;
    FILE *fp;
    fp = fopen("allRounders.txt", "r");
    if (fp == NULL)
        printf("Error Occurred while Opening the File!");
    else
    {
        ch = fgetc(fp);
        printf("%d ", no);
        while (ch != EOF)
        {
            if (ch == '\n')
            {
                printf("\n");
                no++;
                printf("%d ", no);
            }
            else
                printf("%c", ch);
            ch = fgetc(fp);
        }
    }
    (void)fclose(fp);
}

//In this program, "opponent" in the comments refers to the computer

extern /*@observer@*/ char * assign_team_name(int team_number)
{
    switch(team_number)
    {
        case 1: return("CSK");
                //break;
        case 2: return("DC"); 
                //break;
        case 3: return("KKR"); 
                //break;
        case 4: return("MI"); 
                //break;
        case 5: return("PBKS");
                //break;
        case 6: return("RCB");
                //break;
        case 7: return("RR");
                //break;
        case 8: return("SRH");
                //break;
        default: return("NONE");
    }
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;  // Converting time into milli_seconds
    clock_t start_time = clock();  // Storing start time
    while (clock() < start_time + milli_seconds);  // looping till required time is not achieved
        
}

void loader(int delay_count)
{
    printf("\n          ");
    for(int i  = 0 ; i < delay_count ; ++i)
    {
        printf(". ");
        delay(1);
    }
}

int toss()
{
    int coin; //Result of coin toss
    int call; //User call of heads or tails 
    int user_decision; //User wants to bat first or bowl
    int comp_decision; //Comp wants to bat first or bowl
    printf("\n----------# IPL 2021 #----------");
    printf("\n              TOSS");
    printf("\n--------------------------------");
    printf("\n           Make a call ");
    printf("\n         Heads or Tails !");
    printf("\n\n(Press 0 for heads and 1 for tails)");
    printf("\n\n         Your call : ");
    (void) scanf("%d",&call);
    printf("\n\n");
    coin = rand() % 2;
    if(call == 0 || call == 1)
    {
        if(coin == call) //User wins the toss
        {
            if(call == 1)
            {
                printf("\nYou called it right ! Its TAILS !");
            }
            else
            {
                printf("\nHeads was the call...and HEADS it is !");
            }
            //Since the user won the toss, user gets to pick bat or field
            printf("\nWhat would you like to do first?");
            printf("\n(Press 0 to Bat and 1 to Field)");
            printf("\nEnter option : ");
            (void) scanf("%d",&user_decision);
            if(user_decision == 0)
            {
                return 1;
                //Enter game mode 1
                // *User will bat first*
                //Call batting function first and return the score
                //Pass the target as parameter to bowling function
            }
            else
            {
                return 2;
                //Enter game mode 2
                // *User will bowl first*
                //Call bowling function first and get target
                //Pass target to batting function to be chased
            }
        }
        else //User loses the toss
        {
            if(coin == 1)
            {
                printf("\nOh no ! Its HEADS !");
            }
            else
            {
                printf("\nOh no ! Its TAILS !");
            }
            comp_decision = rand() % 2;
            if(comp_decision == 0)
            {
                printf("\nThe opponent has decided to BAT first !");
                return 3;
                //Enter game mode 3
                //Computer will bat first
                //similar to game mode 2
            }
            else
            {
                printf("\nThe opponent has decided to FIELD first");
                return 4;
                //Enter game mode 4
                //Computer will bowl first
                //similar to game mode 1
            }
        }
    }
    else //User enters a number other than 0 or 1
    {
        printf("\nInvalid call !");
    }
}

int batting(int isChasing, int target)
{
    int number_of_wickets = 0; //keeps track of number of wickets
    int comp_ball; //stores the number picked by the opponent
    int total = 0; //innings score of user team
    int number_of_balls = 0; //number of bowls bowled in the innings
    int display_target = 0; //flag to indicate whether the target has to be displayed
    int userBat; //stores the value entered by the user
	int game_value; //stores result of game
    int this_over[6];
    int ball_number;
    char wicket = 'W';
    while(number_of_wickets != 10 && number_of_balls != 60)
    {
        ball_number = number_of_balls % 6;
        comp_ball = (rand() % (6 - 1 + 1)) + 1; //opponent picks a random number between 1 and 6 both include
        if(isChasing == 1) //this flag is to indicate whether the team currently batting is chasing a total
        {
            if(total <= target) //if current score is less than the target
            {
                display_target = 1; //display target on scoreboard
            }
            else
            {
                printf("\nYou WIN ! Target chased !"); //the curent score becomes greater than the target
				game_value = -1;
                return -1; //Game over and target chased
            }
        }
        if(display_target == 1) //if the flag is set to display the target
        {
        	printf("\n2nd Innings : ");
            printf("\nTAREGT : %d", target);
            printf("\n%d runs required from %d balls",target-total,60-number_of_balls);
        }
        printf("\nSCORE : %d / %d", total, number_of_wickets);
        printf("\nOVERS : %d.%d", number_of_balls / 6, number_of_balls%6);
        printf("\nPick a number from 1 to 6 :");
        do //this loop accepts user's number
        {
            scanf("%d",&userBat); //input of user number
            if(userBat > 6 || userBat < 0) //if the number entered by the user is greater than 6 or less than 0
            {
                printf("Invalid input ! PENALTY !");
                printf("\nPick a number from 1 to 6 :");
                total = total - 5; //5 runs are subtracted from total as a result of invalid input
            }
        } while (userBat > 6 || userBat < 0); //continue to accept a input until it lies between 1 and 6
        printf("Your number : %d",userBat);
		printf("\nOpponents number : %d",comp_ball);
		if(userBat != comp_ball) //if the number picked by the user is not the same as the number picked by the opponent
		{
			if(userBat == 4)
			{
				printf("\nExquisite timing on that shot ! FOUR RUNS !"); //commentary
			}
			if(userBat == 6)
			{
				printf("\nPowerfully struck ! SIX RUNS !"); //commentary
			}
			total = total + userBat;
            this_over[ball_number] = userBat;
		}
		else //if number entered by user is the same as opponent
		{
			printf("Thats OUT !! What a ball !"); //commentary
			number_of_wickets += 1;
            this_over[ball_number] = wicket;
            //strcpy(this_over[ball_number],"W");
		}
        printf("\nThis over : ");
        for(int i = 0 ; i <= ball_number ; ++i)
        {
            if(this_over[i] == 87)
            {
                printf("W ");
            }
            else
            {
                printf("%d ",this_over[i]);
            }
        }
		number_of_balls += 1;
        printf("\n\n");
    }
    if(isChasing == 0) //if batting was the first innings of the game, then return the score 
    {
        
        return total;
    }
	if(total < target) //final check 
	{
    	printf("\nHard luck ! You LOST !");
    	return -2; //Game over and team lost
	}
}

int bowling(int isDefending, int target)
{
    int total = 0; //keeps track of total runs scored
    int userBall; //number picked by the user
    int compBat; //number picked by the opponent
    int number_of_balls = 0; //number of balls bowled in the innings
    int display_target = 0; //flag to indicatw whether to display target on scoreboard
    int number_of_wickets = 0; //keep track of number of wickets
    int this_over[6];
    int ball_number;
    char wicket = 'W';
    while(number_of_wickets != 10 && number_of_balls != 60)
    {
        ball_number = number_of_balls % 6;
        compBat = (rand() % (6 - 1 + 1)) + 1; //opponent picks a random number between 1 and 6
        if(isDefending == 1) //if user is defending target
        {
            if(total <= target) //if total is less than the target
            {
                printf("\n2nd Innings : ");
                display_target = 1; //set flag to 1 to display target in score board
            }
            if(total > target) //if runs scored is greater than target
            {
                printf("\nYou lost !");
                return -1;
            }
            if(number_of_wickets == 10 || number_of_balls == 60) //if target wasnt chased within 60 balls or all out before target was chased
            {
                printf("\nYou WON !");
                return -2;
            }
        }
        printf(" \nSCORE : %d / %d", total, number_of_wickets);
        printf("\nOVERS : %d.%d", number_of_balls / 6, number_of_balls%6);
        if(display_target == 1) //if the flag is equal to 1
        {
            printf("\nTARGET : %d",target);
            printf("\n%d runs required from %d balls",target,60-number_of_balls);
        }
        printf("\nPick a number from 1 to 6 : "); 
        do //user has to pick a number between 1 and 6
        {
            scanf("%d",&userBall); //take user input
            if(userBall > 6) //if the user inputs a number greater than 6
            {
                printf("\nNo ball !");
                printf("\nPick a number from 1 to 6 : ");
                total = total - 1;
            }
        } while (compBat > 6 || compBat < 0); //loop runs until user inputs a valid number
        printf("Your number : %d",userBall);
        printf("\nOpponents number : %d",compBat);
        if(userBall != compBat) //if number entered by the user is not the same as the opponent
        {
            if(compBat == 4)
			{
				printf("\nExquisite timing on that shot ! FOUR RUNS !"); //commentary
			}
			if(compBat == 6)
			{
				printf("\nPowerfully struck ! SIX RUNS !"); //commentary
			}
			total = total + compBat;
            this_over[ball_number] = compBat;
        }
        else //number entered by the user and the opponent is the same
        {
            printf("\nWhat a ball ! Knocked the timber over !");
            number_of_wickets += 1;
            this_over[ball_number] = wicket;
        }
        printf("\nThis over : ");
        for(int i = 0 ; i <= ball_number ; ++i)
        {
            if(this_over[i] == 87)
            {
                printf("W ");
            }
            else
            {
                printf("%d ",this_over[i]);
            }
        }
        number_of_balls += 1;
        printf("\n\n");
    }
    if(isDefending == 0) //if this is the first innings of bowling, then just return total score
    {
        return total;
    }
}


