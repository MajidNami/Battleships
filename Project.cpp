#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

//#define size 10
int size;
int winer;
int area_of_largest_ship;
int bot;

struct shipNode {
	int x;
	int y;
	int lenght;
	int VH ;
	struct  shipNode* next;
};
struct shipNode s[50];

struct Information_of_all_game_users {
	int user_number;
	char user_name [100];
	int user_socer;
	char user_password [100];
};
struct Information_of_all_game_users  allusers [200];

int Total_number_of_users;

struct user {
	int user_number;
	char user_name [100];
	int user_socer;
	char user_password [100];
	int New_score;
	
	struct shipNode *ships = NULL;
	
	int n6;
	int n5;
	int n4;
	int n3;
	int n2;
	int n1;
};
struct user player[2];

struct board {
	char board_Real [100][100];
	char board_Game [100][100];
};
struct board playerboard[2];
/*
char board1_Real [size][size];
char board1_Game [size][size];

char board2_Real [size][size];
char board2_Game [size][size];
*/


int Selected_coordinates [2]; //Selected_coordinates [0] is i and Selected_coordinates [1] is j

int Menu ();
void default_settings ();
void addShip(struct shipNode** head, int i,int j,int VH,int lenght) ;
void printShips(struct shipNode* node);
void deleteNode(struct shipNode** head, int i,int j);
void gameloop ();
void setting ();
void create_board (int);
void draw(int , char board[][100]);
void draw2(char board_1[][100],char board_2[][100]);
void manual (int Turn);
void print_users ();
void find_user (int a,int user_number);
void add_new_user (int);
void password (char *a);
int Authorized_selection (int Turn,int i , int j);
void Apply_change (int Turn , int i , int j);
void update_users_list ();
void read_users_list () ;
void saveToFile();
void loadFromFile();
int Ship_Destroy (int Turn,int i,int j,int length);
void Update_new_score (int Turn,int length);
void largestship();
void bot_manual_default(int Turn);
void addSteps();
void printSteps();


FILE *fp;

int Menu () {
	int Menu_selected;
		int exit=0;
	int frien_or_bot=1; //if want to play with friend --> (frien_or_bot=1)  and if want to play with bot --> (frien_or_bot=2)
	int newuser_or_availableuser; // if is new user --> (newuser_or_availabeuser=1) and if is availableuser --> (newuser_or_availabeuser=2)
	int Auto_or_Manual ; // if want Auto --> (Auto_or_Manual=1) and if want Manual --> (Auto_or_Manual=2)
	int usernumber;
	
	printf ("Please select :\n");
	printf ("1)Play with a Friend  \n2)Play with bot  \n3)Load game  \n4)Load last game  \n5)Setting  \n6)Score Board  \n7)Exit\n");
	scanf ("%d",&Menu_selected);
	
/*	while (exit==0) {
		printf ("Do you want to play with your friend or bot ? \n1)Play with Frien\n2)Play with bot\n");
		scanf ("%d",&frien_or_bot);*/
	while (Menu_selected!=7) {
		
		
	if (Menu_selected==1) {
//play with friend	
	bot=0;
	//	if (frien_or_bot==1) {
			//first player
			printf ("\nFirst player :\n\n");
			printf ("choose user :\n1)choose from available users\n2)new user\n");
			scanf ("%d",&newuser_or_availableuser);
			if (newuser_or_availableuser==1) {
			print_users ();
			printf ("Enter your username number\n");
			scanf ("%d",&usernumber);
			find_user (0,usernumber);
			create_board (0);
			//printf ("%s  %d  %s  %d\n",player[0].user_name,player[0].user_socer,player[0].user_password,player[0].user_number);
			}
			else if (newuser_or_availableuser==2){
			add_new_user (0);
			create_board (0);	
			}
			
			printf ("\n%s , please Choose how to pick your ships :\n1)Auto\n2)Manual\n",player[0].user_name);
			scanf ("%d",&Auto_or_Manual);
			if (Auto_or_Manual==1) {
				bot_manual_default(0);
			}
			else if (Auto_or_Manual==2) {
				manual (0);
			}
	//	}
			
			//second player
			printf ("\nSecond player :\n\n");
			printf ("choose user :\n1)choose from available users\n2)new user\n");
			scanf ("%d",&newuser_or_availableuser);
			if (newuser_or_availableuser==1) {
			print_users ();
			printf ("Enter your username number");
			scanf ("%d",&usernumber);
			find_user (1,usernumber);
			create_board (1);
			//printf ("%s  %d  %s  %d\n",player[1].user_name,player[1].user_socer,player[1].user_password,player[1].user_number);
			}
			else if (newuser_or_availableuser==2){
			add_new_user (1);
			create_board (1);	
			}
			
			printf ("\n%s , please Choose how to pick your ships :\n1)Auto\n2)Manual\n",player[1].user_name);
			scanf ("%d",&Auto_or_Manual);
			if (Auto_or_Manual==1) {
				bot_manual_default(1);
			}
			else if (Auto_or_Manual==2) {
				manual (1);
			}
			
			
		}
		
	if (Menu_selected==2) {
//play with bot		
		bot=1;
	//	else if (frien_or_bot==2) {
			//first player
			printf ("\nFirst player :\n\n");
			printf ("choose user :\n1)choose from available users\n2)new user\n");
			scanf ("%d",&newuser_or_availableuser);
			if (newuser_or_availableuser==1) {
			print_users ();
			printf ("Enter your username number\n");
			scanf ("%d",&usernumber);
			find_user (0,usernumber);
			create_board (0);
			//printf ("%s  %d  %s  %d\n",player[0].user_name,player[0].user_socer,player[0].user_password,player[0].user_number);
			}
			else if (newuser_or_availableuser==2){
			add_new_user (0);
			create_board (0);	
			}
			
			printf ("\n%s , please Choose how to pick your ships :\n1)Auto\n2)Manual\n",player[0].user_name);
			scanf ("%d",&Auto_or_Manual);
			if (Auto_or_Manual==1) {
				bot_manual_default(0);
			}
			else if (Auto_or_Manual==2) {
				manual (0);
			}
			
			//second player is bot
			find_user (1,1);
			create_board (1);
			bot_manual_default(1);
			//Auto (1);
	//	}
		
	}
	
	if (Menu_selected==3) {
	//	update_users_list ();
		gameloop();
	}
	
	if (Menu_selected==4) {
		loadFromFile();
	}
	
	if (Menu_selected==5) {
		setting ();
	}
	
	if (Menu_selected==6) {
		int total1=player[0].user_socer+player[0].New_score;
		int total2=player[1].user_socer+player[1].New_score;
		printf ("\n\n*************\n");
		printf ("player1 (%s)\nnew Score : %d\nTotal Score : %d\n",player[0].user_name,player[0].New_score,total1);
		printf ("*************\n");
		printf ("player2 (%s)\nnew Score : %d\nTotal Score : %d\n",player[1].user_name,player[1].New_score,total2);
		printf ("*************\n\n\n");
	}
	
	if (Menu_selected==7) {
		return 0;
	}
	
	printf ("\nPlease select :\n");
	printf ("1)Play with a Friend  \n2)Play with bot  \n3)Load game  \n4)Load last game  \n5)Setting  \n6)Score Board  \n7)Exit\n");
	scanf ("%d",&Menu_selected);	

		
}
		
//	}
	
}





void gameloop () {
	
	void largestship();



	int t=1;
	int save;
	int m=0,n=0;
//	draw2(playerboard[0].board_Game,playerboard[1].board_Game);
	draw2(playerboard[0].board_Game,playerboard[1].board_Game);
	printf ("\n\n");
//	manual (0);
//	manual (1);
	
	//manual ();
	
	int turn = 0;
	int Opponent;
	
	if (bot==0) {
	while (t) {
		
	printf ("Do you want to save the game here?\n1)Yes\n2)No\n");
	scanf("%d",&save);
	if (save==1) {
		saveToFile();
	}
	
	
	
	
	if ((turn % 2)==0)
	Opponent=1;
	if ((turn % 2)==1)
	Opponent=0;
	printf("player %d its your turn\n\n",(turn % 2) + 1);
	

	draw(Opponent, playerboard[Opponent].board_Game);
	char block[2];
	
    printf("\nchoose a block : ");
    scanf("%s", &block);
    Selected_coordinates [0]=block[1]-'A';
	Selected_coordinates [1]=block[0]-49;	
	//	printf ("\n\n%d   %d\n\n",Selected_coordinates [0] , Selected_coordinates[1] );	
	if (Authorized_selection ((turn%2),Selected_coordinates [0] , Selected_coordinates [1]) == 1) {
		
	
	Apply_change ((turn % 2),Selected_coordinates [0],Selected_coordinates [1]);
	turn++;	
	}
	else
	{
	printf("wrong move! try again.\n");
	}

	if (player[0].n1==0 && player[0].n2==0 && player[0].n3==0 && player[0].n4==0 && player[0].n5==0 && player[0].n6==0 ){
		t=0;
		winer = 1;
		player[0].user_socer=player[0].user_socer+player[0].New_score;
		player[0].New_score=0;
		
		player[1].user_socer=player[1].user_socer+player[1].New_score;
		player[1].New_score=0;
		
	//	update_users_list ();
	}
	
	if (player[1].n1==0 && player[1].n2==0 && player[1].n3==0 && player[1].n4==0 && player[1].n5==0 && player[1].n6==0 ){
		t=0;
		winer = 0;
		player[0].user_socer=player[0].user_socer+player[0].New_score;
		player[0].New_score=0;
		
		player[1].user_socer=player[1].user_socer+player[1].New_score;
		player[1].New_score=0;
		
	//	update_users_list ();
	}
	addSteps();
	system("cls");
	//draw(Opponent, playerboard[Opponent].board_Game);
	draw2(playerboard[0].board_Game, playerboard[1].board_Game);
//	system("cls");
	}

	}
	
	
	
	if (bot==1) {
	while (t) {
	
	if ((turn % 2)==0) {
	printf ("Do you want to save the game here?\n1)Yes\n2)No\n");
	scanf("%d",&save);
	if (save==1) {
		saveToFile();
	}
	}
	
	
	
	
	if ((turn % 2)==0)
	Opponent=1;
	if ((turn % 2)==1)
	Opponent=0;
	printf("player %d its your turn\n\n",(turn % 2) + 1);
	

	draw(Opponent, playerboard[Opponent].board_Game);
	char block[2];
	
	if ((turn % 2)==0) {
	
    printf("\nchoose a block : ");
    scanf("%s", &block);
    Selected_coordinates [0]=block[1]-'A';
	Selected_coordinates [1]=block[0]-49;	
	//	printf ("\n\n%d   %d\n\n",Selected_coordinates [0] , Selected_coordinates[1] );	
	if (Authorized_selection ((turn%2),Selected_coordinates [0] , Selected_coordinates [1]) == 1) {
		
	
	Apply_change ((turn % 2),Selected_coordinates [0],Selected_coordinates [1]);
	turn++;	
	}
	else
	{
	printf("wrong move! try again.\n");
	}
	}
	
	if ((turn % 2)==1) {
		for (m=0;m<size;m++){
			for (n=0;n<size;n++)
				if (Authorized_selection ((turn%2),m , n) == 1) {
		
				Apply_change ((turn % 2),m,n);
				turn++;	
				break;
				}
			break;
		}
	}

	if (player[0].n1==0 && player[0].n2==0 && player[0].n3==0 && player[0].n4==0 && player[0].n5==0 && player[0].n6==0 ){
		t=0;
		winer = 1;
		player[0].user_socer=player[0].user_socer+player[0].New_score;
		player[0].New_score=0;
		
		player[1].user_socer=player[1].user_socer+player[1].New_score;
		player[1].New_score=0;
		
	//	update_users_list ();
	}
	
	if (player[1].n1==0 && player[1].n2==0 && player[1].n3==0 && player[1].n4==0 && player[1].n5==0 && player[1].n6==0 ){
		t=0;
		winer = 0;
		player[0].user_socer=player[0].user_socer+player[0].New_score;
		player[0].New_score=0;
		
		player[1].user_socer=player[1].user_socer+player[1].New_score;
		player[1].New_score=0;
		
	//	update_users_list ();
	}
	addSteps();
	system("cls");
	//draw(Opponent, playerboard[Opponent].board_Game);
	draw2(playerboard[0].board_Game, playerboard[1].board_Game);
//	system("cls");
	}

	}
	

}




void addShip(struct shipNode** head, int i,int j,int VH,int lenght) 
{ 
    
    struct shipNode* new_node = (struct shipNode*) malloc(sizeof(struct shipNode)); 
    struct shipNode *last = *head; 
 
    new_node->x  = i; 
    new_node->y  = j; 
    new_node->VH = VH;
    new_node->lenght = lenght;

  
    new_node->next = NULL; 
  
    if (*head == NULL) 
    { 
       *head = new_node; 
       return; 
    }   

    while (last->next != NULL) 
        last = last->next; 

    last->next = new_node; 
    return;     
} 



void printShips(struct shipNode* node)
{
    while (node != NULL) {
        printf(" %d  %d  %d  %d  \n", node->x , node->y , node->lenght,node->VH);
        node = node->next;
    }
}


void deleteNode(struct shipNode** head, int i,int j)
{
     
    struct shipNode *temp = *head, *prev;
    if (temp != NULL && temp->x == i && temp->y == j) {
        *head = temp->next; 
        free(temp); 
        return;
    }
    while (temp != NULL && (temp->x != i  || temp->y != j)) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
        
    prev->next = temp->next;
    free(temp); 
}


void Update_new_score (int Turn,int length) {
	int t=0;
	t=5*(area_of_largest_ship)/length;
	player[Turn].New_score = player[Turn].New_score+t;
}



 
void loadFromFile()
{
	
	struct user player_temp[2];
	struct board board_temp[2];


	int count = 0;
	fp = fopen("saveBoard.bin", "r"); 
  	if (fp == NULL){
    	printf("Error: file out.bin cannot be opened\n");
		return;
  	}
 
 
  fread(&player_temp[0], sizeof(struct user), 1, fp);
  fread(&player_temp[1], sizeof(struct user), 1, fp);
  
  fread(&board_temp[0], sizeof(struct board), 1, fp);
  fread(&board_temp[1], sizeof(struct board), 1, fp);
  
  int i ;
  for(i=0;i<2;i++)
  {
	player[i] = player_temp[i];
	playerboard[i] = board_temp[i];
  }
  
 
   fclose(fp); 
 
	printf("\n\nplayer 1 : %s  \nNew_score = %d  \nuser_socer%d\n",player[0].user_name,player[0].New_score,player[0].user_socer/*,player[0].ships->y*/); 
	draw(0,playerboard[0].board_Game);
	
	printf("\n\nplayer 2 : %s  \nNew_score = %d  \nuser_socer%d\n",player[1].user_name,player[1].New_score,player[1].user_socer/*,player[0].ships->y*/); 
	draw(1,playerboard[1].board_Game);
  	gameloop ();
}


void saveToFile()
{

/*	
	player[0].user_number = 10;
	strcpy(player[0].user_name, "hala");
	player[0].user_socer = 15;
	strcpy(player[0].user_password ,"hmmm");
	player[0].New_score = 58;
	
	addShip(&player[0].ships,10,4,1,4);
	addShip(&player[0].ships,2,4,2,4);
	addShip(&player[0].ships,2,2,1,6);
	
	player[1].user_number = 4;
	strcpy(player[1].user_name, "hihi");
	player[1].user_socer = 5;
	strcpy(player[1].user_password ,"byebye");
	player[1].New_score = 60;
	
	addShip(&player[1].ships,1,1,1,4);
	addShip(&player[1].ships,2,1,2,3);
	addShip(&player[1].ships,2,1,1,1);
	
	*/
   
  fp = fopen("saveBoard.bin", "w"); 
  if (fp == NULL){
    printf("Error: file saveBoard.bin cannot be opened\n");
    return;
  }

  fwrite(&player[0], sizeof(struct user), 1, fp); 
  fwrite(&player[1], sizeof(struct user), 1, fp); 
  fwrite(&playerboard[0], sizeof(struct board), 1, fp);
  fwrite(&playerboard[1], sizeof(struct board), 1, fp);
 
  fclose(fp);
 
}



//FILE *fileAdd;
//FILE *file2;
int stepNumber = 0;

void addSteps()
{
	FILE *file2;
/*	if(stepNumber == 0)
	{
		file2 = fopen("steps.txt", "w"); 
	}
	else 
	{*/
		file2 = fopen("steps.txt", "a"); 
//	}
	  if (file2 == NULL){
	    printf("Error: file saveBoard.bin cannot be opened\n");
	    return;
	  }

	stepNumber++;
	int i,j,k;
	for(i=0;i<2;i++) {
	

		fprintf(file2,"%d\n%s %d %d \n",stepNumber,player[i].user_name,player[i].user_socer,player[i].New_score);
		for(j=0;j<100;j++)
		{
			for(k=0;k<100;k++)
				fprintf(file2,"%c ",playerboard[i].board_Game[j][k]);
			fprintf(file2,"\n");
		}
		
	}
	fprintf(file2,"\n");
 /* 	if(stepNumber == 0)
	{
		fclose(file2) ;
	}*/
  fclose(file2) ;
//  fclose(fileAdd);
}


void printSteps() {
	char str[999],c;
	
    FILE *fptr; 
    fptr = fopen("steps.txt", "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Read contents from file 
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr); 
    } 
  
    fclose(fptr); 
    //return 0;
}



void setting () {
	int x,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0;
	printf ("\n\n1)ships\n2)map size\n");
	scanf ("%d",&x);
	if (x==1) {
		printf ("Enter the number of your ships with the following lengths :\n");
		printf ("\nNumber of ships with length 1 : ");
		scanf ("%d",&n1);
		player[0].n1=n1;
		player[1].n1=n1;
		
		printf ("\nNumber of ships with length 2 : ");
		scanf ("%d",&n2);
		player[0].n2=n2;
		player[1].n2=n2;
		
		printf ("\nNumber of ships with length 3 : ");
		scanf ("%d",&n3);
		player[0].n3=n3;
		player[1].n3=n3;
		
		printf ("\nNumber of ships with length 4 : ");
		scanf ("%d",&n4);
		player[0].n4=n4;
		player[1].n4=n4;
		
		printf ("\nNumber of ships with length 5 : ");
		scanf ("%d",&n5);
		player[0].n5=n5;
		player[1].n5=n5;
		
		printf ("\nNumber of ships with length 6 : ");
		scanf ("%d",&n6);
		player[0].n6=n6;
		player[1].n6=n6;
	}
	
	if (x==2) {
		printf ("Enter the new map size :\n");
		scanf ("%d",&size);
	}
}


void create_board ( int a /*int ship_5 [] , int n5 , int ship_4 [] , int n4 , int ship_3 [] , int n3 , int ship_2 [] , n2 , int ship_1 [] , int n1*/ ) {

	    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            playerboard[a].board_Game [i][j] = 'O';
            playerboard[a].board_Real [i][j] = 'O';
           
        }
    }
   
   
   // draw();
    
}





void draw(int a,char board[][100])
{
    // row names display
    printf("   ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", i+1);
    }
    printf("\n");

    // board display
    for (int i = 0; i < size; i++)
    {
        // column names display
        printf(" %c ",i+65);
        for (int j = 0; j < size; j++)
        {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
    printf (" player %d (%s) board\n",a+1,player[a].user_name);
}




void draw2(char board_1[][100],char board_2[][100])
{
    // row names display
    printf ("\n");
    printf ("player 1 (%s) board",player[0].user_name);
    printf ("                       ");
     printf ("player 2 (%s) board",player[1].user_name);
     printf ("\n");
     
    printf("   ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", i+1);
    }
    //12 space
  //  for (int i=0;i <size ;i++)
  //  printf (" ");
    printf("             ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", i+1);
    }
    printf("\n");


    // board display
    for (int i = 0; i < size; i++)
    {
        // column names display
        printf(" %c ",i+65);
        for (int j = 0; j < size; j++)
        {
            printf(" %c ", board_1[i][j]);
        }
        
        //10 space
        printf ("          ");
        printf(" %c ",i+65);
        for (int j = 0; j < size; j++)
        {
            printf(" %c ", board_2[i][j]);
        }
        printf("\n");
    }
    printf ("\n\n\n");
}



void manual (int Turn) {
	
	printf ("\n*** Designing the position of player %d ships\n\n",Turn+1);
	int n[7];
	n[6]=player[Turn].n6;
	n[5]=player[Turn].n5;
	n[4]=player[Turn].n4;
	n[3]=player[Turn].n3;
	n[2]=player[Turn].n2;
	n[1]=player[Turn].n1;
	
	
	int a,b,i,j;
	int confirmation1=0;
	int confirmation2=0;
	int confirmation3=0;
	int vertical_or_horizontal=0;
	int length_of_ship ;
	char select [2];
	
	while (n[5]!=0 || n[3]!=0 || n[2]!=0 || n[1]!=0 ) {
	
	draw(Turn,playerboard[Turn].board_Real);
	
	while (confirmation3==0) {
	printf ("\nYou have the following ships:\n");
	printf ("1) Ship with a length of 5 :  %d numbers\n",n[5]);
	printf ("2) Ship with a length of 3 :  %d numbers\n",n[3]);
	printf ("3) Ship with a length of 2 :  %d numbers\n",n[2]);
	printf ("4) Ship with a length of 1 :  %d numbers\n",n[1]);
	printf ("\nEnter the length of the ship:\n");
	scanf ("%d",&length_of_ship);
	if (n[length_of_ship]>0){
		confirmation3=1;
	}
	else{
	printf ("sorry , The ship with your length %d is over",length_of_ship);
//	scanf ("%d",&length_of_ship);
	}
	}
	
	
	while (confirmation2==0) {
		select [0]='0';
		select [1]='0';
		confirmation1=0;
	printf ("\nMap the location of your The beginning of the ship : \n");
	
	 while (confirmation1==0) {
	 i=select [1]-'A';
	 j=select[0]-49;
	scanf ("%s",select);
	//if (select [0] <= 57 && 48 <= select [0] && select [1] <= 90  && 65 <= select [1])
	if (select [0] <= 57 && 48 <= select [0] && select [1] <= 90  && 65 <= select [1])
	confirmation1=1;
	else 
	printf ("Incorrect input \nRe-enter:");
	}
	//printf ("1)confirmation1=%d   confirmation2=%d   \n",confirmation1,confirmation2);
	
	 i=select [1]-'A';
	 j=select[0]-49;
	//printf ("i= %d\nj=%d\n",i,j);
	
	printf ("Is the ship vertical or horizontal ?\n");
	printf ("1) Vertical (inter 1)\n");
	printf ("2) Horizontal (inter 2)\n");
	scanf ("%d",&vertical_or_horizontal);
	
	if (vertical_or_horizontal==1 && size - (j)< length_of_ship) {
		printf ("error!!! The ship is taken off the map\n");
		confirmation1=0;
	//	continue;
		}
	
	if (vertical_or_horizontal==1 && size - (j) >= length_of_ship) {
		confirmation2=1;
		for (int k=(j) ; k<(j)+length_of_ship ; k++) {
				if (confirmation2==0) {
				printf ("error!!! There is interference with the position of other ships");
				continue;
				}
		
		    if (playerboard[Turn].board_Real [i][k]!='O') {
		    //printf ("o");
		    confirmation2=0;
		    confirmation1=0;
			}
		}
	}
	///////////////////////////////////////////////////
	if (vertical_or_horizontal==2 && (size - (i)) < length_of_ship) {
		printf ("error!!! The ship is taken off the map\n");
		confirmation1=0;
	//	continue;
		}
	
	if (vertical_or_horizontal==2 && size - (i) >= length_of_ship) {
		confirmation2=1;
		for (int k=(i) ; k<(i)+length_of_ship ; k++) {
		
		    if (playerboard[Turn].board_Real [i][k]!='O') {
		    //printf ("o");
		    confirmation2=0;
		    confirmation1=0;
			}
			
		}
		
		if (confirmation2==0) {
		printf ("error!!! There is interference with the position of other ships");
		continue;
		}
	}
	
	}
	
//	addShip( s[1], i,j,vertical_or_horizontal,length_of_ship) ;
	
	if (vertical_or_horizontal==1) {
		for (a=j;a<j+length_of_ship;a++){
			
			playerboard[Turn].board_Real [i][a] =length_of_ship+48;
			
			if (i-1>=0) {
			playerboard[Turn].board_Real [i-1][a] ='W';
			
			if (j-1>=0)
			playerboard[Turn].board_Real [i-1][j-1] ='W';
			if (j+length_of_ship<size)
			playerboard[Turn].board_Real [i-1][j+length_of_ship] ='W';
			}
			
			if (i+1<=size) {
			playerboard[Turn].board_Real [i+1][a] ='W';
			
			if (j-1>=0)
			playerboard[Turn].board_Real [i+1][j-1] ='W';
			if (j+length_of_ship<size)
			playerboard[Turn].board_Real [i+1][j+length_of_ship] ='W';
			}
			
			if (j-1>=0)
			playerboard[Turn].board_Real [i][j-1] ='W';
			
			if (j+length_of_ship<size)
			playerboard[Turn].board_Real [i][j+length_of_ship] ='W';
			
			
		}
	}
	
	if (vertical_or_horizontal==2) {
		for (b=i;b<i+length_of_ship;b++){
			
			playerboard[Turn].board_Real [b][j] =length_of_ship+48;
			
			if (j-1>=0) {
			playerboard[Turn].board_Real [b][j-1] ='W';
			
			if (i-1>=0)
			playerboard[Turn].board_Real [i-1][j-1] ='W';
			if (i+length_of_ship<=size)
			playerboard[Turn].board_Real [i+length_of_ship][j-1] ='W';
			}
			
			if (j+1<=size) {
			playerboard[Turn].board_Real [b][j+1] ='W';
			
			if (i-1>=0)
			playerboard[Turn].board_Real [i-1][j+1] ='W';
			if (i+length_of_ship<=size)
			playerboard[Turn].board_Real [i+length_of_ship][j+1] ='W';
			}
			
			if (i-1>=0)
			playerboard[Turn].board_Real [i-1][j] ='W';
			
			if (i+length_of_ship<=size)
			playerboard[Turn].board_Real [i+length_of_ship][j] ='W';
		}
	}
	
	
	n[length_of_ship]--;
	
	 confirmation1=0;
	 confirmation2=0;
	 confirmation3=0;
	
	}
	
	printf ("Player %d (%s) ships were arranged correctly\n\n",Turn+1,player[Turn].user_name);
	draw(Turn,playerboard[Turn].board_Real);
	int ch;
	printf ("Enter 1 to continue");
	scanf ("%d",&ch);
	system("cls");
}

int Authorized_selection (int Turn , int i , int j) {
	int Opponent;
	if (Turn==0)
	Opponent=1;
	if (Turn==1)
	Opponent=0;
	if (playerboard[Opponent].board_Game[i][j]=='O')
	return 1;
	else
	return 0;
}

void Apply_change (int Turn , int i , int j) {
	
	int t=0;
	int i2=i;
	int j2=j;
	int Opponent;
	if (Turn==0)
	Opponent=1;
	if (Turn==1)
	Opponent=0;
	
	if (playerboard[Opponent].board_Real[i][j]=='W')
	playerboard[Opponent].board_Game[i][j]='W';
	
	if (playerboard[Opponent].board_Real[i][j]=='O')
	playerboard[Opponent].board_Game[i][j]='W';
	
	
	if (playerboard[Opponent].board_Real[i][j]=='1') {
	playerboard[Opponent].board_Game[i][j]='E';
	player[Turn].New_score ++;
	t=Ship_Destroy (Turn,i,j,1);
	if (t==1) {
		player[Opponent].n1 --;
		Update_new_score (Turn,1);
		
		playerboard[Opponent].board_Game[i][j]='C';
		
	i2=i;
	j2=j;
	i2++;
	while (i2<size && playerboard[Opponent].board_Real[i2][j2]=='1') {
		playerboard[Opponent].board_Game[i2][j2]='C';
	}
	
	i2=i;
	j2=j;
	i2--;
	while (0<=i2 && playerboard[Opponent].board_Real[i2][j2]=='1' ) {
		playerboard[Opponent].board_Game[i2][j2]='C';
	}
	
	i2=i;
	j2=j;
	j2++;
	while (j2<size && playerboard[Opponent].board_Real[i2][j2]=='1') {
		playerboard[Opponent].board_Game[i2][j2]='C';
	}
	
	i2=i;
	j2=j;
	j2--;
	while (0<=j2 && playerboard[Opponent].board_Real[i2][j2]=='1') {
		playerboard[Opponent].board_Game[i2][j2]='C';
	}
	
	
	}
	t=0;
	}
	
	if (playerboard[Opponent].board_Real[i][j]=='2') {
	playerboard[Opponent].board_Game[i][j]='E';
	player[Turn].New_score ++;
	t=Ship_Destroy (Turn,i,j,2);
	if (t==1) {
		player[Opponent].n2 --;
		Update_new_score (Turn,2);
		
				playerboard[Opponent].board_Game[i][j]='C';
		
	i2=i;
	j2=j;
	i2++;
	while (i2<size && playerboard[Opponent].board_Real[i2][j2]=='2') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		i2++;
	}
	
	i2=i;
	j2=j;
	i2--;
	while (0<=i2 && playerboard[Opponent].board_Real[i2][j2]=='2' ) {
		playerboard[Opponent].board_Game[i2][j2]='C';
		i2--;
	}
	
	i2=i;
	j2=j;
	j2++;
	while (j2<size && playerboard[Opponent].board_Real[i2][j2]=='2') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		j2++;
	}
	
	i2=i;
	j2=j;
	j2--;
	while (0<=j2 && playerboard[Opponent].board_Real[i2][j2]=='2') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		j2--;
	}
	}
	
	
	t=0;
	}
	
	if (playerboard[Opponent].board_Real[i][j]=='3') {
	playerboard[Opponent].board_Game[i][j]='E';
	player[Turn].New_score ++;
	t=Ship_Destroy (Turn,i,j,3);
	if (t==1) {
		player[Opponent].n3 --;
		Update_new_score (Turn,3);
		
				playerboard[Opponent].board_Game[i][j]='C';
		
	i2=i;
	j2=j;
	i2++;
	while (i2<size && playerboard[Opponent].board_Real[i2][j2]=='3') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		i2++;
	}
	
	i2=i;
	j2=j;
	i2--;
	while (0<=i2 && playerboard[Opponent].board_Real[i2][j2]=='3' ) {
		playerboard[Opponent].board_Game[i2][j2]='C';
		i2--;
	}
	
	i2=i;
	j2=j;
	j2++;
	while (j2<size && playerboard[Opponent].board_Real[i2][j2]=='3') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		j2++;
	}
	
	i2=i;
	j2=j;
	j2--;
	while (0<=j2 && playerboard[Opponent].board_Real[i2][j2]=='3') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		j2--;
	}
		
	}
	t=0;
	}
	
	if (playerboard[Opponent].board_Real[i][j]=='4') {
	playerboard[Opponent].board_Game[i][j]='E';
	player[Turn].New_score ++;
	t=Ship_Destroy (Turn,i,j,4);
	if (t==1) {
		player[Opponent].n4 --;
		Update_new_score (Turn,4);
		
				playerboard[Opponent].board_Game[i][j]='C';
		
	i2=i;
	j2=j;
	i2++;
	while (i2<size && playerboard[Opponent].board_Real[i2][j2]=='4') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		i2++;
	}
	
	i2=i;
	j2=j;
	i2--;
	while (0<=i2 && playerboard[Opponent].board_Real[i2][j2]=='4' ) {
		playerboard[Opponent].board_Game[i2][j2]='C';
		i2--;
	}
	
	i2=i;
	j2=j;
	j2++;
	while (j2<size && playerboard[Opponent].board_Real[i2][j2]=='4') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		j2++;
	}
	
	i2=i;
	j2=j;
	j2--;
	while (0<=j2 && playerboard[Opponent].board_Real[i2][j2]=='4') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		j2--;
	}
		
	}
	t=0;
	}
	
	if (playerboard[Opponent].board_Real[i][j]=='5') {
	playerboard[Opponent].board_Game[i][j]='E';
	player[Turn].New_score ++;
	t=Ship_Destroy (Turn,i,j,5);
	if (t==1) {
		player[Opponent].n5 --;
		Update_new_score (Turn,5);
		
				playerboard[Opponent].board_Game[i][j]='C';
		
	i2=i;
	j2=j;
	i2++;
	while (i2<size && playerboard[Opponent].board_Real[i2][j2]=='5') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		i2++;
	}
	
	i2=i;
	j2=j;
	i2--;
	while (0<=i2 && playerboard[Opponent].board_Real[i2][j2]=='5' ) {
		playerboard[Opponent].board_Game[i2][j2]='C';
		i--;
	}
	
	i2=i;
	j2=j;
	j2++;
	while (j2<size && playerboard[Opponent].board_Real[i2][j2]=='5') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		j2++;
	}
	
	i2=i;
	j2=j;
	j2--;
	while (0<=j2 && playerboard[Opponent].board_Real[i2][j2]=='5') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		j2--;
	}
		
	}
	t=0;
	}
	
	if (playerboard[Opponent].board_Real[i][j]=='6') {
	playerboard[Opponent].board_Game[i][j]='E';
	player[Turn].New_score ++;
	t=Ship_Destroy (Turn,i,j,6);
	if (t==1) {
		player[Opponent].n6 --;
		Update_new_score (Turn,6);
		
				playerboard[Opponent].board_Game[i][j]='C';
		
	i2=i;
	j2=j;
	i2++;
	while (i2<size && playerboard[Opponent].board_Real[i2][j2]=='6') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		i2++;
	}
	
	i2=i;
	j2=j;
	i2--;
	while (0<=i2 && playerboard[Opponent].board_Real[i2][j2]=='6' ) {
		playerboard[Opponent].board_Game[i2][j2]='C';
		i2--;
	}
	
	i2=i;
	j2=j;
	j2++;
	while (j2<size && playerboard[Opponent].board_Real[i2][j2]=='6') {
		playerboard[Opponent].board_Game[i2][j2]='C';
	}
	j2++;
	
	i2=i;
	j2=j;
	j2--;
	while (0<=j2 && playerboard[Opponent].board_Real[i2][j2]=='6') {
		playerboard[Opponent].board_Game[i2][j2]='C';
		j2--;
	}
		
	}
	t=0;
	}
		
}

int Ship_Destroy (int Turn,int i,int j,int length) {
	
	int t=1;
	int i2=i;
	int j2=j;
	char ch;
	ch = length;
	int Opponent;
	if (Turn==0)
	Opponent=1;
	if (Turn==1)
	Opponent=0;
	
	
	i2=i;
	j2=j;
	i2++;
	while (i2<size && playerboard[Opponent].board_Real[i2][j2]==length+48) {
		if (playerboard[Opponent].board_Game[i2][j2]=='O') {
		t=0;
		break;
		}
	i2++;
	}
	if (t==0)
	return 0;
	
	
	i2=i;
	j2=j;
	i2--;
	while (0<=i2 && playerboard[Opponent].board_Real[i2][j2]==length+48 ) {
		if (playerboard[Opponent].board_Game[i2][j2]=='O') {
		t=0;
		break;
		}
	i2--;
	}
	if (t==0)
	return 0;
	
	
	i2=i;
	j2=j;
	j2++;
	while (j2<size && playerboard[Opponent].board_Real[i2][j2]==length+48) {
		if (playerboard[Opponent].board_Game[i2][j2]=='O') {
		t=0;
		break;
		}
	j2++;
	}
	if (t==0)
	return 0;
	
	
	i2=i;
	j2=j;
	j2--;
	while (0<=j2 && playerboard[Opponent].board_Real[i2][j2]==length+48) {
		if (playerboard[Opponent].board_Game[i2][j2]=='O') {
		t=0;
		break;
		}
	j2++;
	}
	if (t==0)
	return 0;
	
	if (t==1) {
	//	deleteNode(struct shipNode** head,i, j);
	}
	return 1;
	
}




void print_users () {
		char x[100];
		char x2[100];
		int x3;
		char x4 [100];
		char ch;
		int number;
		int i;
		FILE *p = fopen ("user.csv","r");
		fscanf (p,"%s",x);
		//printf ("%s\n",x);
		printf ("%15s%15s%15s\n","number","user name","socer");
		while (feof(p)==0) {
		
		fscanf (p,"%d",&number);
		printf ("%15d",number);
		
	fscanf (p,"%c",&ch);
	fscanf (p,"%c",&ch);
	for (i=0;ch!=',';i++){
		x2[i]=ch;
		fscanf (p,"%c",&ch);
	}
	x2[i]='\0';
	
	printf ("%15s",x2);
	
	fscanf (p,"%d",&x3);
	printf ("%15d",x3);
	
	fscanf (p,"%c",&ch);
	fscanf (p,"%s",&x4);
	//printf ("%15s",x4);
	printf ("\n");
	//fscanf (p,"%c",&ch);
	}
	fclose(p);
	//printf ("\n\n\n%15d\n\n\n",number);	
}



void find_user (int a,int user_number) {
	
	
		char x[100];
		char x2[100];
		int x3;
		char x4 [100];
		char ch;
		int number;
		int i;
	
	FILE *p = fopen ("user.csv","r");
	
	fscanf (p,"%s",x);
	
	while (feof(p)==0) {
		
		fscanf (p,"%d",&number);
		
		
	fscanf (p,"%c",&ch);
	fscanf (p,"%c",&ch);
	for (i=0;ch!=',';i++){
		x2[i]=ch;
		fscanf (p,"%c",&ch);
	}
	x2[i]='\0';
	
	fscanf (p,"%d",&x3);
	
	fscanf (p,"%c",&ch);
	fscanf (p,"%s",&x4);
	
	if (user_number==number) {
		strcpy(player[a].user_name,x2);
		player[a].user_socer=x3;
		strcpy(player[a].user_password,x4);
		player[a].user_number=user_number;
	}
	
	}
	fclose (p);
//	printf ("11%s  %s  %s",player[a].user_name,player[a].user_socer,player[a].user_password);	
}


void add_new_user (int a) {
	
		char new_user_name [100];
		char password1 [100];
		char x[100];
		char x2[100];
		int x3;
		char x4 [100];
		char ch;
		int number;
		int i;
	FILE *p = fopen ("user.csv","r+");
	
	while (feof(p)==0) {
		
		fscanf (p,"%d",&number);
		
		
	fscanf (p,"%c",&ch);
	fscanf (p,"%c",&ch);
	for (i=0;ch!=',';i++){
		x2[i]=ch;
		fscanf (p,"%c",&ch);
	}
	x2[i]='\0';
	
	fscanf (p,"%d",&x3);
	
	fscanf (p,"%c",&ch);
	fscanf (p,"%s",&x4);
	
	}
	number++;
	Total_number_of_users=number;
	fprintf(p,"%d,",Total_number_of_users);
	printf ("\nplease enter your user name : \n");
	//gets (new_user_name);
	scanf ("%s",new_user_name);
	
	fprintf(p,"%s,",new_user_name);
	
	fprintf(p,"%d,",0);
	
	password (password1);
	//printf ("%s",password1);
	fprintf(p,"%s\n",password1);
	fclose (p);
	
	player[a].user_number=number;
	strcpy(player[a].user_name,new_user_name);
	player[a].user_socer=0;
	strcpy(player[a].user_password,password1);
	
	printf ("Thank you %s it was successful\n\n",new_user_name);
}


void password (char *a) {
	int i=0;
	char ch;
	printf ("Please inter your password  4 letters\n");
	printf ("\nletter 1 : ");
	scanf (" %c",&ch);
	*(a+i)=ch;
	i++;
	
	printf ("\nletter 2 : ");
	scanf (" %c",&ch);
	*(a+i)=ch;
	i++;
	
	printf ("\nletter 3 : ");
	scanf (" %c",&ch);
	*(a+i)=ch;
	i++;
	
	printf ("\nletter 4 : ");
	scanf (" %c",&ch);
	*(a+i)=ch;
	i++;

}	


void bot_manual_default(int Turn) {
	playerboard[Turn].board_Real[0][0]='W';
	playerboard[Turn].board_Real[0][1]='W';
	playerboard[Turn].board_Real[0][2]='W';
	playerboard[Turn].board_Real[0][3]='W';
	playerboard[Turn].board_Real[0][4]='W';
	playerboard[Turn].board_Real[0][5]='W';
	playerboard[Turn].board_Real[0][6]='W';
	playerboard[Turn].board_Real[0][7]='W';
	playerboard[Turn].board_Real[0][8]='W';
	
	playerboard[Turn].board_Real[1][0]='W';
	playerboard[Turn].board_Real[1][1]='5';
	playerboard[Turn].board_Real[1][2]='W';
	playerboard[Turn].board_Real[1][3]='1';
	playerboard[Turn].board_Real[1][4]='W';
	playerboard[Turn].board_Real[1][5]='3';
	playerboard[Turn].board_Real[1][6]='3';
	playerboard[Turn].board_Real[1][7]='3';
	playerboard[Turn].board_Real[1][8]='W';
	
	playerboard[Turn].board_Real[2][0]='W';
	playerboard[Turn].board_Real[2][1]='5';
	playerboard[Turn].board_Real[2][2]='W';
	playerboard[Turn].board_Real[2][3]='W';
	playerboard[Turn].board_Real[2][4]='W';
	playerboard[Turn].board_Real[2][5]='W';
	playerboard[Turn].board_Real[2][6]='W';
	playerboard[Turn].board_Real[2][7]='W';
	playerboard[Turn].board_Real[2][8]='W';
	
	playerboard[Turn].board_Real[3][0]='W';
	playerboard[Turn].board_Real[3][1]='5';
	playerboard[Turn].board_Real[3][2]='W';
	playerboard[Turn].board_Real[3][3]='2';
	playerboard[Turn].board_Real[3][4]='W';
	playerboard[Turn].board_Real[3][5]='W';
	playerboard[Turn].board_Real[3][6]='W';
	playerboard[Turn].board_Real[3][7]='1';
	playerboard[Turn].board_Real[3][8]='W';
	
	playerboard[Turn].board_Real[4][0]='W';
	playerboard[Turn].board_Real[4][1]='5';
	playerboard[Turn].board_Real[4][2]='W';
	playerboard[Turn].board_Real[4][3]='2';
	playerboard[Turn].board_Real[4][4]='W';
	playerboard[Turn].board_Real[4][5]='3';
	playerboard[Turn].board_Real[4][6]='W';
	playerboard[Turn].board_Real[4][7]='W';
	playerboard[Turn].board_Real[4][8]='W';
	
	playerboard[Turn].board_Real[5][0]='W';
	playerboard[Turn].board_Real[5][1]='5';
	playerboard[Turn].board_Real[5][2]='W';
	playerboard[Turn].board_Real[5][3]='W';
	playerboard[Turn].board_Real[5][4]='W';
	playerboard[Turn].board_Real[5][5]='3';
	playerboard[Turn].board_Real[5][6]='W';
	playerboard[Turn].board_Real[5][7]='1';
	playerboard[Turn].board_Real[5][8]='W';
	
	playerboard[Turn].board_Real[6][0]='W';
	playerboard[Turn].board_Real[6][1]='W';
	playerboard[Turn].board_Real[6][2]='W';
	playerboard[Turn].board_Real[6][3]='W';
	playerboard[Turn].board_Real[6][4]='W';
	playerboard[Turn].board_Real[6][5]='3';
	playerboard[Turn].board_Real[6][6]='W';
	playerboard[Turn].board_Real[6][7]='W';
	playerboard[Turn].board_Real[6][8]='W';
	
	playerboard[Turn].board_Real[7][0]='W';
	playerboard[Turn].board_Real[7][1]='2';
	playerboard[Turn].board_Real[7][2]='2';
	playerboard[Turn].board_Real[7][3]='W';
	playerboard[Turn].board_Real[7][4]='W';
	playerboard[Turn].board_Real[7][5]='W';
	playerboard[Turn].board_Real[7][6]='W';
	playerboard[Turn].board_Real[7][7]='2';
	playerboard[Turn].board_Real[7][8]='W';
	
	playerboard[Turn].board_Real[8][0]='W';
	playerboard[Turn].board_Real[8][1]='W';
	playerboard[Turn].board_Real[8][2]='W';
	playerboard[Turn].board_Real[8][3]='W';
	playerboard[Turn].board_Real[8][4]='1';
	playerboard[Turn].board_Real[8][5]='W';
	playerboard[Turn].board_Real[8][6]='W';
	playerboard[Turn].board_Real[8][7]='2';
	playerboard[Turn].board_Real[8][8]='W';
	
	
}

void largestship(){
			area_of_largest_ship=1;
	if (player[0].n2!=0)
	area_of_largest_ship=2;
	
	if (player[0].n3!=0)
	area_of_largest_ship=3;
	
	if (player[0].n3!=0)
	area_of_largest_ship=3;
	
		if (player[0].n4!=0)
	area_of_largest_ship=4;
	
		if (player[0].n4!=0)
	area_of_largest_ship=4;
	
	if (player[0].n5!=0)
	area_of_largest_ship=5;
	
	if (player[0].n6!=0)
	area_of_largest_ship=6;
	
}


void default_settings (){
/*	size =10;
	
	 player[0].n1=4;
	 player[0].n2=3;
	 player[0].n3=2;
	 player[0].n4=0;
	 player[0].n5=1;
	 player[0].n6=0;
	 
	 player[1].n1=4;
	 player[1].n2=3;
	 player[1].n3=2;
	 player[1].n4=0;
	 player[1].n5=1;
	 player[1].n6=0;*/
	 
	 //test
	 	size =9;
	
	 player[0].n1=0;
	 player[0].n2=0;
	 player[0].n3=1;
	 player[0].n4=0;
	 player[0].n5=0;
	 player[0].n6=0;
	 
	 player[1].n1=0;
	 player[1].n2=0;
	 player[1].n3=1;
	 player[1].n4=0;
	 player[1].n5=0;
	 player[1].n6=0;
}

void read_users_list () {
		char x[100];
		char x2[100];
		int x3;
		char x4 [100];
		char ch;
		int number;
		int i;
		FILE *p = fopen ("user.csv","r");
		fscanf (p,"%s",x);
		
		while (feof(p)==0) {
		
		fscanf (p,"%d",&number);
		allusers[number].user_number=number;
		
	fscanf (p,"%c",&ch);
	fscanf (p,"%c",&ch);
	for (i=0;ch!=',';i++){
		x2[i]=ch;
		fscanf (p,"%c",&ch);
	}
	x2[i]='\0';
	
	strcpy(allusers[number].user_name,x2);
	
	fscanf (p,"%d",&x3);
	allusers[number].user_socer=x3;
	
	fscanf (p,"%c",&ch);
	fscanf (p,"%s",&x4);
	strcpy(allusers[number].user_password,x4);
	
	//fscanf (p,"%c",&ch);
	}
	Total_number_of_users=number;
	fclose(p);
	//printf ("\n\n\n%15d\n\n\n",number);
}


void update_users_list (){
	int n1,n2,s1=0,s2=0,i;
	n1=player[0].user_number;
	n2=player[1].user_number;
	s1=player[0].user_socer+player[0].New_score;
	s1=player[1].user_socer+player[1].New_score;
	for (i=0;i<100;i++) {
		if ((allusers[i].user_number)==n1){
			allusers[i].user_socer=s1;
		//	break;
		}
	}
	
	for (i=0;i<100;i++) {
		if ((allusers[i].user_number)==n2){
			allusers[i].user_socer=s2;
		//	break;
		}
	}
	//printf ("\n\nok\n\n");
	
	FILE *p = fopen ("user.csv","w");
	fprintf (p,"%s,","number");
	fprintf (p,"%s,","user_name");
	fprintf (p,"%s,","score");
	fprintf (p,"%s,","password");
	for (i=0;i<Total_number_of_users+1;i++){
		fprintf (p,"%d,",allusers[i].user_number);
		fprintf (p,"%s,",allusers[i].user_name);
		fprintf (p,"%d,",allusers[i].user_socer);
		fprintf (p,"%s,",allusers[i].user_password);
		fprintf (p,"\n");
	//	printf ("\n\nok\n\n");
	}
//	printf ("\n\nok\n\n");
	
	
	fclose (p);
}



int main () {
	
	int t,t1;
	bot=0;
	printf ("Hello, welcome to the game (^.^) \n\n");
	default_settings ();
	t=Menu();
printf ("\nDo you want to print playback?\n");
scanf ("%d",&t1);
	if (t1==1){
	printSteps();	
	}
	
	printf ("End");
	
}
