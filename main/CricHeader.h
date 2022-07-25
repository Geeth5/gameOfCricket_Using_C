typedef struct node
{
    char *data;
    struct node *next;
} Node;

#define MAX_STR 30

typedef struct List
{
    struct node *first;
} List;

Node *Node_create();

void Node_destroy(Node *node);

List *List_create();

void List_destroy(List *list);

void List_append(List *list, char *str);

void List_print(List *list);

void linebatsmen(int a, char *player);

void showbatsmen();

void linebowler(int a, char *player);

void showbowler();

void lineKeeper(int a, char *player);

void showKeeper();

void lineAllRounders(int a, char *player);

void showAllRounders();

extern /*@observer@*/ char * assign_team_name(int team_number);

void delay(int number_of_seconds);

void loader(int delay_count);

int toss();

int batting(int isChasing, int target);

int bowling(int isDefending, int target);


