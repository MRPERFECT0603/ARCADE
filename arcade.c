/* SEMESTER PROECT SDF-1          TOPIC-ARCADE                      DATED-10 JAN 2022
       TEAM MEMBER- VIVEK SHAURYA(B61381)
                    HARSHIT VIJAY(B64322)
                    ANMOL VERMA(B62507) 
        
        DESCRIPTION- A PROGRAM CONTATING DIFFERENT GAMES JUST LIKE A GAMING CONSOLE WHERE 
                    USER CAN INTERACT WITH THE COMPUTER AND PLAY. */



#include<stdio.h>               // HEADER FILES
#include<stdlib.h>
#include<time.h>
#include<string.h>
#ifdef _WIN32                                       //Checking OS
    #define OS 0
    #include<windows.h>
#endif

#ifdef __APPLE__
    #define OS 1
    #include<unistd.h>
#endif
struct userdetails          
{                               // STRUCTURE DEFINITION
    char user[20];
    int token;
}detail;                        //STRUCTURE VARIABLE
int guess_the_number(int a);
int guess_the_colour(int a);
int coin_toss(int a);  
int tictactoe(int a);
void disp_grid();
int win_check(char);   
void player_m(char);
void comp_m(char);
int neutral_check();
int mindreader(int a);                              //ALL THE FUNCTIONS PROTOTYPES
void trick1(void);
void trick2(void);
void trick3(void);
void trick4(void);
void trick5(void);
void trick6(void);
void trick7(void);
void trick8(void);

char grid[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; //DEFINED FOR TIC-TAC-TOE

int main()                                              //MAIN FILE. 
{
    FILE *pfile = NULL;
    char *filename="ARCADE.txt";                        //OPENING EXTERNAL TEXT FILE
    pfile = fopen(filename,"a");
    if(pfile == NULL)
    {
        printf("FAILED TO OPEN THE FILE.\n");           //CHECKING ERROR IN FILE
    }
    int game,v;
    for(int i=0;i<20;i++)
    {
        printf("-*-*-");
    }
    printf("\n\t\t\t\t\tARCADE\n\t\t\t\tWELCOME MY FRIEND\n\t\t\tCHOOSE WHICH GAME YOU WANNA PLAY.\n");
    printf("\nENTER EVERYTHING IN CAPS.\nMINIMUM TOKEN REQUIRED:- 100\n\n\nENTER USER ID:\n");
    scanf("%s",detail.user);
    fprintf(pfile, "%s\t", detail.user);
    printf("ENTER THE TOKEN COUNT:\n");                 //TAKING USER DETAILS AND PPRINTING IN THE FILE
    scanf("%d",&detail.token);
    fprintf(pfile, "%d\t", detail.token); 
    label:if(detail.token<100)
    {
        printf("INSUFFICIENT TOKEN,PLEASE RECHARGE.\n");
        printf("THE REMAINING TOKEN:%d",detail.token);          //CHECKING FOR INSUFFICIENT TOKEN
        fprintf(pfile, "%d\n", detail.token);
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            printf("-*-*-");
        }
        printf("\n\nWHICH GAME YOU WANT TO PLAY:\n1.GUESS THE NUMBER.\n2.GUESS THE COLOUR.\n3.TOSS THE COIN\n4.TIC-TAC-TOE\n5.MINDREADER\n");
        scanf("%d",&game);
        switch(game)
        {
            case 1:
                    detail.token = guess_the_number(detail.token);
            break;
            case 2:
                    detail.token = guess_the_colour(detail.token);
            break;
            case 3:
                    detail.token = coin_toss(detail.token);
            break;
            case 4:                                                             //CALLING OF DIFFERENT GAME FUNNCTION
                    detail.token = tictactoe(detail.token);
            break;
            case 5:
                    detail.token = mindreader(detail.token);
            break;

        }
        printf("ENTER '1' TO CONTINUE WITH OTHER GAME 0R ENTER ANYTHING TO STOP.\n");
        scanf("%d",&v);
        if(v==1)
        {
            goto label;                                             //LOOP TO AGAIN PLAY ANOTHER GAME
        }
        else
        {
            printf("THE REMAINING TOKEN:%d",detail.token);          //FINALLY PRINTIING THE REMAINING TOKEN
            fprintf(pfile, "%d\n", detail.token); 
        }
    }
    fclose(pfile);                                      //CLOSING THE FILE
    return 0;
}
int guess_the_number(int a)
{
    int option;
    int upper=0,lower=0,randnum=0,guess=0;
    label: printf("CHOOSE THE LEVEL:\n");                           
    printf("1.EASY\t2.INTERMEDIATE\t3.HARD\n");             //CHOSSING THE LEVEL
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        printf("OHHO!!! YOU WANT TO GO SO EASILY\nOK NOW I AM CHOOSING A NUMBER BETWEEN (1-20)\nGUESS IT!!! ");
        upper=20,lower=1;
        srand(time(0));                                                 //FUNCTION TO CHOOSE RANDOM NUMBER
        randnum = (rand() % (upper - lower + 1)) + lower;
        printf("HOPE YOU THINK OF IT\nYOU WILL GET 5 TRIES.\nALL THE BEST.\n");
        for(int i=5;i>=1;i--)
        {
            printf("GUESS THE NUMBER:\n");
            scanf("%d",&guess);
            if(guess==randnum)
            {
                printf("YOU GUESSED IT CORRECTLY.HERE IS YOUR REWARD.\n");
                break;
            }
            else if(guess>randnum)                                          //CHECKING THE GUESS
            {
                printf("NICE TRY,BUT YOU ARE TOO BIGGER THAN  ME.\n");
            }
            else if(guess<randnum)
            {
                printf("NICE TRY,BUT YOU ARE TOO LESSER THAN ME.\n");   
            }
        }
        if(guess==randnum)
        {
            a+=20;
        }                                                               //TOKEN SYSTEM
        else
        {
            a=a-100;
        }
        if(guess!=randnum)
        printf("YOU LOST ALL YOUR TRIES,THE NUMBER WAS %d,BETTER LUCK NEXT TIME.\n",randnum);
        break;
        case 2:
        printf("OHHO!!! YOU WANT TO BE INTERMEDIATE\nOK NOW I AM CHOOSING A NUMBER BETWEEN (1-50)\nGUESS IT!!! ");
        upper=50,lower=1;
        srand(time(0));
        randnum = (rand() % (upper - lower + 1)) + lower;
        printf("HOPE YOU THINK OF IT\nYOU WILL GET 5 TRIES.\nALL THE BEST.\n");
        for(int i=5;i>=1;i--)
        {
            printf("GUESS THE NUMBER:\n");
            scanf("%d",&guess);
            if(guess==randnum)
            {
                printf("YOU GUESSED IT CORRECTLY.HERE IS YOUR REWARD.\n");
                break;
            }
            else if(guess>randnum)
            {
                printf("NICE TRY,BUT YOU ARE TOO BIGGER THAN  ME.\n");
            }
            else if(guess<randnum)
            {
                printf("NICE TRY,BUT YOU ARE TOO LESSER THAN ME.\n");   
            }
        }
        if(guess==randnum)
        {
            a+=50;
        }
        else                                        //TOKEN SYSTEM
        {
            a=a-100;
        }
        if(guess!=randnum)
        printf("YOU LOST ALL YOUR TRIES,THE NUMBER WAS %d,BETTER LUCK NEXT TIME.\n",randnum);
        break;
        case 3:
        printf("OHHO!!! YOU WANT TO GO GOD MODE.\nOK NOW I AM CHOOSING A NUMBER BETWEEN (1-100)\nGUESS IT!!! ");
        upper=100,lower=1;
        srand(time(0));
        randnum = (rand() % (upper - lower + 1)) + lower;
        printf("HOPE YOU THINK OF IT\nYOU WILL GET 3 TRIES.\nALL THE BEST.\n");
        for(int i=3;i>=1;i--)
        {
            printf("GUESS THE NUMBER:\n");
            scanf("%d",&guess);
            if(guess==randnum)
            {
                printf("YOU GUESSED IT CORRECTLY.HERE IS YOUR REWARD.\n");
                break;
            }
            else if(guess>randnum)
            {
                printf("NICE TRY,BUT YOU ARE TOO BIGGER THAN  ME.\n");
            }
            else if(guess<randnum)
            {
                printf("NICE TRY,BUT YOU ARE TOO LESSER THAN ME.\n");   
            }
        }
        if(guess==randnum)
        {
            a+=100;
        }
        else
        {                                       //TOKEN SYSTEM
            a=a-100;
        }
        if(guess!=randnum)
        printf("YOU LOST ALL YOUR TRIES,THE NUMBER WAS %d,BETTER LUCK NEXT TIME.\n",randnum);
        break;
        default:
        printf("WRONG OPTION CHOOSED.\n");
        goto label;                                     //LOOP TO GO BACK TO CHOOSE FUNCTION
        break;
    }
    return a;
}
int guess_the_colour(int a)
{
    int option;
    int upper=0,lower=0,randnum=0,result;
    char colour[100],guess[100];
    label: printf("CHOOSE THE LEVEL:\n");
    printf("1.EASY\t2.HARD\n");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        printf("OKAY GOOD\nI AM THINKING OF A COLOUR\nIT CAN BE (YELLOW,GREEN,RED)\nCAN YOU GUESS WHAT IT IS:\n");
        upper=3,lower=1;
        srand(time(0));
        randnum = (rand() % (upper - lower + 1)) + lower;
        printf("TELL ME,TELL ME, WHAT COLOUR I AM THINKING.\n");
        scanf("%s",guess);
        if(randnum==1)
        {
            char colour[100]="YELLOW";
            result = strcmp(colour,guess);
            if(result==0)
            {
                printf("WOW YOU READ MY MIND.\nOH GOD YOU ARE TOO GOOD IN THIS.\nHERE IS YOUR REWARD.\n");
            }
            else
            {
                printf("NICE TRY\nTHE COLOUR WAS %s.\nBUT BETTER LUCK NEXT TIME.\n",colour);
            }
        }
        else if(randnum==2)
        {
            char colour[100] = "GREEN";
            result = strcmp(colour,guess);
            if(result==0)
            {
                printf("WOW YOU READ MY MIND.\nOH GOD YOU ARE TOO GOOD IN THIS.\nHERE IS YOUR REWARD.\n");
            }
            else
            {
                printf("NICE TRY\nTHE COLOUR WAS %s.\nBUT BETTER LUCK NEXT TIME.\n",colour);
            }
        }
        else if(randnum==3)
        {
            char colour[100]="RED";
            result = strcmp(colour,guess);
            if(result==0)
            {
                printf("WOW YOU READ MY MIND.\nOH GOD YOU ARE TOO GOOD IN THIS.\nHERE IS YOUR REWARD.\n");
            }
            else
            {
                printf("NICE TRY\nTHE COLOUR WAS %s.\nBUT BETTER LUCK NEXT TIME.\n",colour);
            }
        }
        if(result==0)
        {
            a+=20;
        }                                           //TOKEN SYSTEM
        else
        {
            a=a-100;
        }
        break;
        case 2:
        printf("OKAY GOOD\nI AM THINKING OF A COLOUR\nIT CAN BE (YELLOW,GREEN,RED,BLUE,BLACK)\nCAN YOU GUESS WHAT IT IS:\n");
        upper=5,lower=1;
        srand(time(0));
        randnum = (rand() % (upper - lower + 1)) + lower;
        printf("TELL ME, TELL ME, WHAT COLOUR I AM THINKING.\n");
        scanf("%s",guess);
        if(randnum==1)
        {
            char colour[100]="YELLOW";
            result = strcmp(colour,guess);
            if(result==0)
            {
                printf("WOW YOU READ MY MIND.\nOH GOD YOU ARE TOO GOOD IN THIS.\nHERE IS YOUR REWARD.\n");
            }
            else
            {
                printf("NICE TRY\nTHE COLOUR WAS %s.\nBUT BETTER LUCK NEXT TIME.\n",colour);
            }
        }
        else if(randnum==2)
        {
            char colour[100] = "GREEN";
            result = strcmp(colour,guess);
            if(result==0)
            {
                printf("WOW YOU READ MY MIND.\nOH GOD YOU ARE TOO GOOD IN THIS.\nHERE IS YOUR REWARD.\n");
            }
            else
            {
                printf("NICE TRY\nTHE COLOUR WAS %s.\nBUT BETTER LUCK NEXT TIME.\n",colour);
            }
        }
        else if(randnum==3)
        {
            char colour[100]="RED";
            result = strcmp(colour,guess);
            if(result==0)
            {
                printf("WOW YOU READ MY MIND.\nOH GOD YOU ARE TOO GOOD IN THIS.\nHERE IS YOUR REWARD.\n");
            }
            else
            {
                printf("NICE TRY\nTHE COLOUR WAS %s.\nBUT BETTER LUCK NEXT TIME.\n",colour);
            }
        }
        else if(randnum==4)
        {
            char colour[100]="BLUE";
            result = strcmp(colour,guess);
            if(result==0)
            {
                printf("WOW YOU READ MY MIND.\nOH GOD YOU ARE TOO GOOD IN THIS.\nHERE IS YOUR REWARD.\n");
            }
            else
            {
                printf("NICE TRY\nTHE COLOUR WAS %s.\nBUT BETTER LUCK NEXT TIME.\n",colour);
            }
        }
        else if(randnum==5)
        {
            char colour[100]="BLACK";
            result = strcmp(colour,guess);
            if(result==0)
            {
                printf("WOW YOU READ MY MIND.\nOH GOD YOU ARE TOO GOOD IN THIS.\nHERE IS YOUR REWARD.\n");
            }
            else
            {
                printf("NICE TRY\nTHE COLOUR WAS %s.\nBUT BETTER LUCK NEXT TIME.\n",colour);
            }
        }
        if(result==0)
        {
            a+=50;
        }
        else                                //TOKEN SYSTEM
        {
            a=a-100;
        }
        break;
        default:
        printf("WRONG OPTION CHOOSED.\n");              //LOOP TO GO BACK TO CHOOSING LEVEL
        goto label;
        break;
    }
    return a;
}
int coin_toss(int a)
{
    getchar();
    int upper=2,lower=1,randnum;
    char *p,computer[10],*c;
    c = computer;
    p = (char*)malloc(6*sizeof(char));                          //DYNAMIC MEMORY ALLOCATION
    srand(time(0));
    randnum = (rand() % (upper - lower + 1)) + lower;
    printf("ENTER THE SIDE YOU THINK:\n");
    gets(p);
    switch (randnum) 
    {
    case 1:
        c = ("HEADS!!!!");       
        break;
    case 2:
        c = ("TAILS!!!!");  
        break;
    }    
    if(strncmp(p,c,4)==0)
    {
        printf("YEAH!!! WE THINK SIMILAR, ARE WE BROTHERS?\n");
    }
    else
    {
        printf("NO WORRIES, BETTER LUCK NEXT TIME.\n");
    }
    a=a-100;                                                //TOKEN SYSTEM
    return a;
}
int tictactoe(int a)
{
    getchar();
    char p_sym,c_sym;
    int run_st=1,count_v=0,move=0,tie=0,winner=0;   //winner=> 0:COMPUTER & 1:PLAYER
    printf("Welcome To Tic-Tac-Toe\n");
    printf("Pick Your Symbol:");
    scanf("%c",&p_sym);
    if (p_sym=='X'){c_sym = 'O';}
    else{c_sym = 'X';}
    // disp_grid();
    while (run_st==1)
    {   
        tie = neutral_check();
        if (tie == 1)
        {
            printf("Its a TIE\n");
            break;
        }
        else
        {
            if (OS==1){system("clear");}
            else{system("cls");}        
            disp_grid();
            if ((count_v%2)==0)
            {
                printf("YOUR Turn ...\n");
                player_m(p_sym);
                run_st=win_check(p_sym);
                winner=1;
                move++;
                count_v++;
                continue;
            }
            else if ((count_v%2)==1)
            {
                printf("COMPUTER's Turn ...\n");
                sleep(1);
                comp_m(c_sym);
                run_st=win_check(c_sym);
                winner=0;
                count_v++;
                continue;
            }
            else
            {
                printf("ERROR!! Encounter....\n.....ABORTING.....\n");
                break;
            }
        }        
    }
    if (tie!=1)
    {
        if (OS==1){system("clear");}
        else{system("cls");}   
        disp_grid();
        printf("...We have a WINNER!...\n");
        if (winner==1)
        {
            printf("\tPLAYER Wins the GAME\n");
            printf("\nMoves required to win the game = %d\n",move);
        }
        else
        {
            printf("\tCOMPUTER Wins the GAME\n");
            printf("Better Luck Next Time\n");
        }
    }
    if(winner==1)
    {
        a+=100;
    }
    return a;
}
int neutral_check()
{
    int x=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (grid[i][j] == ' ')
            {
                x=1;
                return 0;
            }
        }
    }
    return 1;
}
void player_m(char p_sym)
{
    int p_xmove,p_ymove;
    player_move:
        printf("Choose X-Coordinate:");
        scanf("%d",&p_xmove);
        printf("Choose Y-Coordinate:");
        scanf("%d",&p_ymove);
        if (grid[p_xmove][p_ymove]!=' '){
            printf("INVALID LOCATION\n");
            goto player_move;}
        else{grid[p_xmove][p_ymove] = p_sym;}
}
void comp_m(char c_sym)
{
    int x_loc,y_loc;
    srand(time(0));
    generate:
        x_loc = (rand()%3);
        y_loc = (rand()%3);
    if (grid[x_loc][y_loc]!=' '){goto generate;}
    else{grid[x_loc][y_loc] =c_sym;}
}
int win_check(char sym)
{
    if ((grid[0][0] == sym) && (grid[0][1] == sym) && (grid[0][2] == sym)){return 0;}
    else if ((grid[1][0] == sym) && (grid[1][1] == sym) && (grid[1][2] == sym)){return 0;}
    else if ((grid[2][0] == sym) && (grid[2][1] == sym) && (grid[2][2] == sym)){return 0;}
    else if ((grid[0][0] == sym) && (grid[1][0] == sym) && (grid[2][0] == sym)){return 0;}
    else if ((grid[0][1] == sym) && (grid[1][1] == sym) && (grid[2][1] == sym)){return 0;}
    else if ((grid[0][2] == sym) && (grid[1][2] == sym) && (grid[2][2] == sym)){return 0;}
    else if ((grid[0][0] == sym) && (grid[1][1] == sym) && (grid[2][2] == sym)){return 0;}
    else if ((grid[0][2] == sym) && (grid[1][1] == sym) && (grid[2][0] == sym)){return 0;}
    else {return 1;}
}
void disp_grid()
{
    printf("\t\t|\t\t|\t\t\n");
    printf("\t%c\t|\t%c\t|\t%c\t\n",grid[0][0],grid[0][1],grid[0][2]);
    printf("________________|_______________|________________\n");
    printf("\t\t|\t\t|\t\t\n");
    printf("\t%c\t|\t%c\t|\t%c\t\n",grid[1][0],grid[1][1],grid[1][2]);
    printf("________________|_______________|________________\n");
    printf("\t\t|\t\t|\t\t\n");
    printf("\t%c\t|\t%c\t|\t%c\t\n",grid[2][0],grid[2][1],grid[2][2]);
    printf("\t\t|\t\t|\t\t\n");
}
int mindreader(int a)
{
    int upper=8,lower=1,randnum;
    srand(time(0));
    randnum = (rand() % (upper - lower + 1)) + lower;
    switch (randnum)
    {
        case 1:
        trick1();
        break;
        case 2:
        trick2();
        break;
        case 3:
        trick3();
        break;
        case 4:
        trick4();
        break;
        case 5:                                     //CALLING DIFFERENT TRICK FUNCTIONS
        trick5();
        break;
        case 6:
        trick6();
        break;
        case 7:
        trick7();
        break;
        case 8:
        trick8();
        break;
    }
    a=a-200;                                        //TOKEN SYSTEM
    return a;
}
void trick1(void)
{
    getchar();
    printf("HELLO FRIEND, I AM GOING TO READ YOUR MIND\nLETS SEE HOW MUCH YOU CAN CONTROL IT.\n");
    printf("PICK A NUMBER BETWEEN 1 AND 10\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW ADD 2 IN YOUR NUMBER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW MULTIPLY IT WITH 2.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW SUBTRACT 2 FROM IT.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW DIVIDE IT BY 2.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("FINALLY SUBTRACT THE NUMBER YOU CHOOSED FROM IT.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("I BET YOU YOU GET 1 AS THE ANSWER.\n");
}
void trick2(void)
{
    getchar();
    printf("HELLO FRIEND, I AM GOING TO READ YOUR MIND\nLETS SEE HOW MUCH YOU CAN CONTROL IT.\n");
    printf("PICK A NUMBER BETWEEN 1 AND 8\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW MULTIPLY YOUR NUMBER BY 2.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW MULTIPLY IT WITH 5.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW SUBTRACT 5 FROM IT.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("FINALLY ADD 7 TO IT\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("THE FIRST DIGIT IS THE NUMBER YOU CHOOSE AND THE SECOND DIGIT IS  2.\n");
}
void trick3(void)
{
    getchar();
    printf("HELLO FRIEND, I AM GOING TO READ YOUR MIND\nLETS SEE HOW MUCH YOU CAN CONTROL IT.\n");
    printf("THINK OF ANY NUMBER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW DOUBLE THE NUMBER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW ADD 9 WITH THE RESULT.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW SUBTRACT 3 FROM IT.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW DIVIDE IT BY 2.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("FINALLY SUBTRACT THE NUMBER YOU CHOOSED FROM IT.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("I BET YOU YOU GET 3 AS THE ANSWER.\n");
}
void trick4(void)
{
    getchar();
    printf("HELLO FRIEND, I AM GOING TO READ YOUR MIND\nLETS SEE HOW MUCH YOU CAN CONTROL IT.\n");
    printf("THINK OF ANY NUMBER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW ADD THE NEXT HIGHER NUMBER INTO IT.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW ADD 9 WITH THE RESULT.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW DIVIDE IT BY 2.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("FINALLY SUBTRACT THE NUMBER YOU CHOOSED FROM IT.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("I BET YOU YOU GET 5 AS THE ANSWER.\n");
}
void trick5(void)
{
    getchar();
    printf("HELLO FRIEND, I AM GOING TO READ YOUR MIND\nLETS SEE HOW MUCH YOU CAN CONTROL IT.\n");
    printf("THINK OF ANY NUMBER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW ADD 5 INTO THE NUMBER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW MULTIPLY BY 3.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW SUBTRACT 15 FROM IT.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW DIVIDE IT BY YOUR ORIGINAL NUMBER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("FINALLY ADD 7 TO THE RESULT.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("I BET YOU YOU GET 10 AS THE ANSWER.\n");
}
void trick6(void)
{
    getchar();
    printf("HELLO FRIEND, I AM GOING TO READ YOUR MIND\nLETS SEE HOW MUCH YOU CAN CONTROL IT.\n");
    printf("PICK A NUMBER BETWEEN 20 AND 100\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW ADD YOUR DIGITS TOGETHER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW SUBTRACT THE TOTAL FROM YOUR ORIGINAL NUMBER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("FINALLY ADD THE DIGITS OF THE NEW NUMBER TOGETHER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("I BET YOU YOU GET 9 AS THE ANSWER.\n");
}
void trick7(void)
{
    getchar();
    printf("HELLO FRIEND, I AM GOING TO READ YOUR MIND\nLETS SEE HOW MUCH YOU CAN CONTROL IT.\n");
    printf("THINK OF A THREE DIGIT NUMBER(WITH EACH DIGIT DIFFERENT)\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW REVERSE THE DIGITS.(YOU HAVE TWO NUMBERS NOW.)\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW SUBTRACT THE SMALLER NUMBER FROM THE LARGER NUMBER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("FINALLY ADD THE DIGITS OF THE NEW NUMBER TOGETHER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("I BET YOU YOU GET 18 AS THE ANSWER.\n");
}
void trick8(void)
{
    getchar();
    printf("HELLO FRIEND, I AM GOING TO READ YOUR MIND\nLETS SEE HOW MUCH YOU CAN CONTROL IT.\n");
    printf("THINK OF A THREE DIGIT NUMBER(WITH EACH DIGIT DIFFERENT)\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW REVERSE THE DIGITS.(YOU HAVE TWO NUMBERS NOW.)\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("NOW SUBTRACT THE SMALLER NUMBER FROM THE LARGER NUMBER.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("REVERSE THE DIGITS OF THE DIFFERENCE AND ADD IT TO THE DIFFERENCE.\n");
    printf("Hit any key to continue....... ");
    getchar();
    printf("I BET YOU YOU GET 1089 AS THE ANSWER.\n");
}

    