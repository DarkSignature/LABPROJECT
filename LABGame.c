#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
// Battle variables - Player stats
int fight = 1, defend = 0, kraft = 0, itemBag = 0;
int crit, eva, damage = 10; 
const int att = 10; // Can be changed to a structure for different classes

// Battle variables - Enemy stats - Can be changed to a structure to make different types of enemies
int enemyDamage = 0, enemyHeal = 10, enemyDefend = 0, enemyCharge = 0; // Healing decreases per usage for balance
const int enemyAtt = 10;

// Temporary variables for testing
int playerHP = 50;
int maxPlayerHP = 50;
int enemyHP = 50;
int maxEnemyHP = 50;
//srand(time(NULL));

// struct for character classes
struct classes{
	char name[10];
	char description[100];
	int playerHP;
	int maxPlayerHP;	
};

// Setup for class of choice
void classSetup(int classChoice){
	struct classes job;
	if(classChoice == 1){
		strcpy(job.name, "Warrior");
	}
	if(classChoice == 2){
		strcpy(job.name, "Mage");
	}
	if(classChoice == 1){
		strcpy(job.name, "Warrior");
	}
}

// struct for extracting text in txt files
struct script{
	char text[100];
};

// struct for items
struct item{
	char name[1000];
	char desc[1000];
	int owned;
};
struct item item[5];


void battleSetup(){
// Potion - index 0
strcpy(item[0].name, "Potion - Heals HP by 10 - One of the most drinked bev- Wait can you even call this a beverage?");
strcpy(item[0].desc, "One of the most drinked bev- Wait can you even call this a beverage?");
item[0].owned = 3;

// Character and Enemy Setup
playerHP = 50;
enemyHP = 50;
}

// Box Function
// textBox = For ingame dialogue and story...
char textBox(char word[]){ 
while(1){
	char nextTextbox;
	system("cls");
	printf("%c", 201);
	for(int q = 0; q < strlen(word)+3; q++){
			printf("%c", 205);	
	}
	printf("%c\n", 187);
	printf("%c %-*s  %c\n", 186, strlen(word), word, 186);
	printf("%c", 200);
	
	for(int q = 0; q < strlen(word)+3; q++){
			printf("%c", 205);	
		
	}
	printf("%c\n", 188);
	nextTextbox = getch();
        if (nextTextbox == ' ' || nextTextbox == 'x') {
        	return nextTextbox;
            break;
        }
}
}

//Box for healing output
char healBox(int healed){ 
while(1){
	char nextTextbox;
	system("cls");
	printf("%c", 201);
	for(int q = 0; q < 26; q++){
			printf("%c", 205);	
	}
	printf("%c\n", 187);
	printf("%c %+15s %2d HP!   %c\n", 186, "You healed for", healed, 186);
	printf("%c", 200);
	
	for(int q = 0; q < 26; q++){
			printf("%c", 205);	
		
	}
	printf("%c\n", 188);
	nextTextbox = getch();
        if (nextTextbox == ' ' || nextTextbox == 'x') {
        	return nextTextbox;
            break;
        }
}
}

char healBoxEnemy(int healed){ 
while(1){
	char nextTextbox;
	system("cls");
	printf("%c", 201);
	for(int q = 0; q < 32; q++){
			printf("%c", 205);	
	}
	printf("%c\n", 187);
	printf("%c %+21s %2d HP!   %c\n", 186, "The enemy healed for", healed, 186);
	printf("%c", 200);
	
	for(int q = 0; q < 32; q++){
			printf("%c", 205);	
		
	}
	printf("%c\n", 188);
	nextTextbox = getch();
        if (nextTextbox == ' ' || nextTextbox == 'x') {
        	return nextTextbox;
            break;
        }
}
}

// Damage output box for player
char damageBox(int damageDealt, int enemyHP){ 
while(1){
	char nextTextbox;
	system("cls");
	printf("%c", 201);
	for(int q = 0; q < 40; q++){
			printf("%c", 205);	
	}
	printf("%c\n", 187);
	printf("%c %+12s %2d damage to the enemy!   %c\n", 186, "You dealt", damageDealt, 186);
	printf("%c", 200);
	
	for(int q = 0; q < 40; q++){
			printf("%c", 205);	
		
	}
	printf("%c\n", 188);
	nextTextbox = getch();
        if (nextTextbox == ' ' || nextTextbox == 'x') {
        	return nextTextbox;
            break;
        }
}
}

char damageBoxEnemy(int damageDealt, int playerHP){ 
while(1){
	char nextTextbox;
	system("cls");
	printf("%c", 201);
	for(int q = 0; q < 40; q++){
			printf("%c", 205);	
	}
	printf("%c\n", 187);
	printf("%c %+17s %2d damage to you!    %c\n", 186, "The enemy dealt", damageDealt, 186);
	printf("%c", 200);
	
	for(int q = 0; q < 40; q++){
			printf("%c", 205);	
		
	}
	printf("%c\n", 188);
	nextTextbox = getch();
        if (nextTextbox == ' ' || nextTextbox == 'x') {
        	return nextTextbox;
            break;
        }
}
}

// Use potion function
void usePot(int *playerHP, int maxHP){
	textBox("You used a potion!");
	*playerHP += 10;
	int amountHealed = 10;
	if(*playerHP > maxHP){
		amountHealed = 10 - (*playerHP % maxHP);
		*playerHP -= (*playerHP % maxHP);
	}
	healBox(amountHealed);
	item[0].owned--;
}

// A different textbox function specifically for yes and no choices
void useItem(char word[]) {
    char nextTextbox;

//    textBox(word);

    do {
        nextTextbox = textBox(word); 

        if (nextTextbox == ' ') {
            usePot(&playerHP, maxPlayerHP);
            break;
        } else if (nextTextbox == 'x') {
            break;
        } else {
            continue;
        }
    } while (!(nextTextbox == ' ' || nextTextbox == 'x'));
}

// Opening Item Bag function --> For now just shows potion information
void openBag(){
	textBox(item[0].name);
	useItem("Use potion? SPACE to use, 'x' to EXIT");
	
//  Problem - getch() in textBox function is used the same time as this function's getch(), so one input inputs for both
}
	

// storyBox = Dialogue based on choices made...
void tutorial(){
	struct script tutorial[9];
	FILE* fr;
	int s = 0;
	fr = fopen("RPGtutorial.txt", "r");
	while (fscanf(fr, " %[^\n]", tutorial[s].text) == 1) {
    	s++;
    	if (s >= 9) {
            break; 
        }
	}
	fclose(fr);
	for(int s = 0; s < 9; s++){
		textBox(tutorial[s].text);
		}
	}
	
void battleBox(){
	system("cls");
	printf("%c", 201);
	for(int q = 0; q < 40; q++){
			printf("%c", 205);	
	}
	printf("%c\n", 187);

	printf("%c %+*s%12c\n", 186, 28, "Choose a COMMAND!", 186);

	if(fight == 1){
		printf("%c %+*s %c%16c\n", 186, 22, "ATTACK", 248, 186);
	}
	else{
		printf("%c %+*s%18c\n", 186, 22, "ATTACK", 186);
	}
	if(kraft == 1){
		printf("%c %+*s %c%17c\n", 186, 21, "CRAFT", 248, 186);
	}
	else{
		printf("%c %+*s%19c\n", 186, 21, "CRAFT", 186);
	}
	if(defend == 1){
		printf("%c %+*s %c%16c\n", 186, 22, "DEFEND", 248, 186);
	}
	else{
		printf("%c %+*s%18c\n", 186, 22, "DEFEND", 186);
	}
	if(itemBag == 1){
		printf("%c %+*s %c%18c\n", 186, 20, "ITEM", 248, 186);
	}
	else{
		printf("%c %+*s%20c\n", 186, 20, "ITEM", 186);
	}
	printf("%c%41c\n", 186, 186);
	printf("%c %s %2d  %22s %2d %c\n", 186, "Your HP:", playerHP, "Enemy's HP:", enemyHP, 186);
	for(int i = 0; i <= 40; i++){
		
	}
	printf("%c", 200);
	
	for(int q = 0; q < 40; q++){
			printf("%c", 205);	
		
	}
	printf("%c\n", 188);
	if(fight == 1){
		printf("Attack the enemy, dealing damage based on base attack. \n2x Damage on Critical\n");
	}
	else if(kraft == 1){
		printf("Attack the enemy with your special attack,\ndealing damage based on base attack + 50%% base attack. \n2x Damage on Critical\n");
	}
	else if(defend == 1){
		printf("Defend against the enemy's attack, decreasing their damage by half.\n");
	}
	else if(itemBag == 1){
		printf("Open your item bag, for now you only have potions...\nYou have %d potion(s) left\n", item[0].owned);
	}
}

// Enemy turn - do people use AI for this?
void enemyTurn(int* playerHP, int* enemyHP, int enemyMax, int defend){
	if(*enemyHP <= 0){
		return;
	}
	enemyDamage = 0;
	srand(time(NULL));
	int enemyCMD;
	
	int amountHealed = 0;
	enemyCMD = rand()%5; // 0 - 4, so 5 ways for enemies to act
	crit = rand()%20; // 0 - 19, > 17 is critical
	
	
	if(enemyCMD == 2 && *enemyHP < enemyMax){
		textBox("The enemy heals up...");
		*enemyHP += enemyHeal;
		amountHealed = enemyHeal;
		if(*enemyHP > enemyMax){
		amountHealed = enemyHeal - (*enemyHP % enemyMax);
		*enemyHP -= (*enemyHP % enemyMax);
	}
	enemyHeal -= 2;
	healBoxEnemy(amountHealed);
	item[0].owned--;
		
	}
	else if(enemyCMD == 2 && enemyCharge == 0){
		textBox("The enemy charges up...");
		enemyCharge = 1;
	}
	else if(enemyCMD == 0 || enemyCMD == 3 || enemyCMD == 4 || enemyCMD == 2){
		textBox("The enemy attacks you...");
			enemyDamage = enemyAtt;

		if(crit > 17){
			textBox("C R I T I C A L !!!");
				enemyDamage = (2 * enemyAtt);
		}
		if(defend == 1){
			enemyDamage /= 2;
		}
		
		if(enemyCharge == 1){ // Charge 2x damage
			enemyDamage *= 2;
			enemyCharge = 0;
		}
		
		damageBoxEnemy(enemyDamage, *playerHP);
		*playerHP -= enemyDamage;
		
}
	else if(enemyCMD == 1){
		textBox("The enemy gets ready for your next attack...");
		enemyDefend = 1;
	}
}

void battleInput(){
	int keyPressed;
	if(enemyHP <= 0 || playerHP <= 0){
		return;
	}
	do{
		keyPressed = getch();
		switch(keyPressed){
			case 'w':
				if(fight == 1){
					fight = 0;
					itemBag = 1;
				}
				else if(kraft == 1){
					kraft = 0;
					fight = 1;
				}
				else if(defend == 1){
					defend = 0;
					kraft = 1;
				}
				else if(itemBag == 1){
					itemBag = 0;
					defend = 1;
				}
				battleBox();
				break;
			case 's':
				if(fight == 1){
					fight = 0;
					kraft = 1;
				}
				else if(kraft == 1){
					kraft = 0;
					defend = 1;
				}
				else if(defend == 1){
					defend = 0;
					itemBag = 1;
				}
				else if(itemBag == 1){
					itemBag = 0;
					fight = 1;
				}
				battleBox();
				break;
			case ' ':
				if(fight == 1){
					damage = 0;
					srand(time(NULL));
					textBox("You attacked the enemy!");
					crit = rand()%20;
					if(crit > 17){
						textBox("C R I T I C A L !!!");
						damage += (2*att);
					}
					else{
						damage = att;
					}
					if(enemyDefend == 1){
						damage /= 2;
						enemyDefend = 0;
					}
					damageBox(damage, enemyHP);
					enemyHP -= damage;
					enemyTurn(&playerHP, &enemyHP, maxEnemyHP, defend);
				}
				else if(kraft == 1){
					damage = 0;
					srand(time(NULL));
					textBox("You used Crescent Slash on the enemy!");
					crit = rand()%10;
					if(crit > 5){
						textBox("C R I T I C A L !!!");
						damage += 2 * (0.5 * att + att);
					}
					else{
						damage = (0.5 * att) + att;
					}
					if(enemyDefend == 1){
						damage /= 2;
						enemyDefend = 0;
					}
					damageBox(damage, enemyHP);
					enemyHP -= damage;
					enemyTurn(&playerHP, &enemyHP, maxEnemyHP, defend);
				}
				else if(defend == 1){
					textBox("You get ready for the enemy's attack...");
					enemyTurn(&playerHP, &enemyHP, maxEnemyHP, defend);
				}
				else if(itemBag == 1 && item[0].owned > 0){
					openBag();
					enemyTurn(&playerHP, &enemyHP, maxEnemyHP, defend);
				}
				else if(itemBag == 1 && item[0].owned <= 0){
					textBox("You don't have any potions left!");
				}
				break;

		}
			
		}while(!(keyPressed == 'w' || keyPressed == 's' || keyPressed == ' '));
	

}

	
void battleSequence(){
	while(playerHP > 0 && enemyHP > 0){ //Could've made it while playerHP != 0 
	battleBox();
	battleInput();
	}	
	if(enemyHP <= 0){
		textBox("You win!");
	}
	else if(playerHP <= 0){
		textBox("You lost!");
	}
}

//Every function placed here!
void rpgBattleSim(){
	printf("\33[?25l");	
	tutorial();
	while(1){
		battleSetup();
		battleSequence();
		char reset = textBox("Restart? SPACE to restart, 'x' to EXIT...");
		if(reset == ' '){
			continue;
		}
		else if(reset == 'x'){
			break;
		}
	}
	return;
}


int fruitx = 0, fruity = 0;
int rows = 20, column = 40;
int gameover = 0;
int flag;
int wormx, wormy;
int score = 0;
int p = 0, z = 0;
int nameChoice, nameContinue;

struct player{
	char name[10];
	long int score;
};
struct player player[100];

void setup(){

	srand(time(NULL));
	wormx = column/2; 
	wormy = rows/2;
	
	
	do{
		fruitx = rand()%(column - 1);
	}while(fruitx == 0);
	do{
		fruity = rand()%(rows - 1);
	}while(fruity == 0);
}

void box(){
	// Declaring the column and rows
//	int rows = 30;
//	int column = 60;
	// Making the box
	// hiding cursor
	printf("\33[?25l");
	
	system("cls");
	
	printf("%c", 201);
	for (int i = 0; i < column; i++){
		printf("%c", 205);
	}
	printf("%c\n", 187);
	
	for(int j = 0; j < rows; j++){
		printf("%c", 186);
		
		for(int i = 0; i < column; i++){
			if(i == wormx && j == wormy){
				printf("%c", 254); //Snake
			}
			else if(i == fruitx && j == fruity){
				printf("%c", 248); //Fruit
			}
			else{
			printf(" ");
		}
		
		}
		printf("%c\n", 186);
	}
	
	printf("%c", 200);
	
	for(int i = 0; i < column; i++){
		printf("%c", 205);
	}
	printf("%c\n", 188);
	if(nameContinue > -1){
		printf("   %s's Score: %d\n", player[nameContinue].name, score);
		printf("   %s's Highscore: %d\n", player[nameContinue].name, player[nameContinue].score);
		printf("   Type 'x' to quit!\n");
		printf("   Type 'p' to pause!\n");
	}
	else{
		printf("   %s's Score: %d\n", player[p].name, score);
		printf("   Type 'x' to quit!\n");
		printf("   Type 'p' to pause!\n\n");
	}
}

void input(){
	
	if(kbhit()){
		switch(getch()){
			case 'w':
				flag = 1;
				break;
			case 'a': 
				flag = 2;
				break;
			case 's': 
				flag = 3;
				break;
			case 'd': 
				flag = 4;
				break;
			case 'p':
			printf("\n Game Paused! Type '1' to continue!\n");
			printf("\33[?25h");
			int yes;
			
			while(yes != 1){
				
				scanf("%d", &yes);
				
//				system("cls");
				if(yes != 1){
					printf("You need to input '1' to continue!\n");
				}
			}	
			printf("\33[?25l");
			break;
			case 'x':
				gameover = 1;
				break;
			default:
				break;
			
		}
	}
}

void logic(){
	sleep(0.01);
	switch(flag){
		case 1:
			wormy--;
			break;
		case 2:
			wormx--;
			break;
		case 3:
			wormy++;
			break;
		case 4:
			wormx++;
			break;
		case 5:
			wormx = wormx;
			wormy = wormy;
		default:
			break;
	}
	
	if(wormx < 0 || wormy < 0 || wormx > column || wormy > rows){
		gameover = 1;
	}
	
	if(wormx == fruitx && wormy == fruity){
		score += 10;
		
		do{
			fruitx = rand()%(column - 1);
		}while(fruitx == 0);
		do{
			fruity = rand()%(rows - 1);
		}while(fruity == 0);
	}
}

void resetInput(){
	flag = 5;
	logic();
}
void printScoreboard(){
	printf("        SCOREBOARD      \n");
	printf("%c", 201);
	for(int q = 0; q < 28; q++){
		if(q == 15){
			printf("%c", 203);
		}
		else{
			printf("%c", 205);	
		}
	}
	printf("%c\n", 187);
	printf("%c  Player       %c   Score    %c\n", 186, 186, 186);
	printf("%c", 204);
	for(int q = 0; q < 28; q++){
		if(q == 15){
			printf("%c", 206);
		}
		else{
			printf("%c", 205);	
		}
	}
	printf("%c\n", 185);
	
	for(int i = 0; i <= p; i++){
		printf("%c %-2d %-10s %c   %5ld    %c\n", 186, i+1, player[i].name, 186, player[i].score, 186);
	}
	printf("%c", 200);
	
	for(int q = 0; q < 28; q++){
		if(q == 15){
			printf("%c", 202);
		}
		else{
			printf("%c", 205);	
		}
	}
	printf("%c\n", 188);
}
void scoreboardSort(){
	char tempName[100] = "Temp";
	int tempScore;
	//Bubble sort
	for(int i = 0; i < p; i++){
		for(int j = i+1; j <= p; j++){
			if(player[i].score < player[j].score){
				strcpy(tempName, player[i].name);
				strcpy(player[i].name, player[j].name);
				strcpy(player[j].name, tempName);
				tempScore = player[i].score;
				player[i].score = player[j].score;
				player[j].score = tempScore;
			}
		}
	}
}
void scoreboard(){
	system("cls");
	p--;
	scoreboardSort();
	printScoreboard();
	printf("\n\nPress anything to continue...\n");
	getch();
	p++;
}
void soloPlay(){
 char name[10];
 	int v = 0;
 	do{
 		if(v > 0){
 			printf("Name needs to be less than 10 letters!\n");
		 }
		printf("Enter Name: ");
		getchar();
		scanf(" %[^\n]", name);
		v++;
	}while(strlen(name) > 10);
	
	nameChoice = 0; 
	nameContinue = -1;
	for(int v = 0; v <= p; v++){
		if(strcmp(player[v].name, name) == 0){
			printf("Current name already exist!\n[1] - New Name\n[2] - Continue\nName: %s\nHighscore: %d\n", player[v].name, player[v].score);
			scanf(" %d", &nameChoice);
			if(nameChoice == 1){
				return;
				break;	
			}
			else if(nameChoice == 2){
				nameContinue = v;
				break;
			}
		}
				
		}
	if(nameContinue == -1){
		strcpy(player[p].name, name);
	}
	setup();
	
	while(!gameover){
		box();
		input();
		logic();
		usleep(25000);
	}
	resetInput();
	if(nameContinue > -1){
		if(score > player[nameContinue].score){
			p--;
			printf("\n      New Highscore!!!\n");
			player[nameContinue].score = score;
			scoreboardSort();
			printScoreboard();
			printf("\n\nPress anything to continue...\n");
			getch();
			p++;
		}
		else{
			p--;
			printf("\n     Not a new highscore...\n");
			scoreboardSort();
			printScoreboard();
			printf("\n\nPress anything to continue...\n");
			getch();
			p++;
		}
	}
	else{
		player[p].score = score;
		scoreboardSort();
		printScoreboard();
		printf("\n\nPress anything to continue...\n");
		getch();
		p++;
	}
//	printf("\n%s = %d\n", player[p].name, player[p].score);
//	scoreboard();
//	scoreboardSort();
//	printScoreboard();
//	printf("\n\nPress anything to continue...\n");
//	getch();
//	p++;
	gameover = 0;
	score = 0;
	sleep(0.5);
}
void otherGames(){
	int mode;
	while(1){
		system("cls");
	printf("Enter Game!\n1. SimBattle Demo\n2.\n3.\n4.\n");
	scanf(" %d", &mode);
	switch(mode){
		case 1:
			rpgBattleSim();
			printf("\33[?25h");
			continue;
		case 2:
			printf("TBA\n");
			continue;
		case 3:
			printf("TBA\n");
			continue;
		case 4:
			return;
		default:
			printf("You didn't pick a game mode!");
			sleep(1);
			continue;
		}
	}
}




int main(){
	// Reading scoreboard from a txt file
	FILE* fr; 
	FILE* fw;
    fr = fopen("score.txt", "r");
	if(fr == NULL){
		printf("Can't Open File!"); getch(); exit(1);
	}

	while (fscanf(fr, "%s - %ld", player[p].name, &player[p].score) == 2) {
    	p++;
	}
	fclose(fr);
	
	int mode;
	
	// Constantly on the menu
	while(1){
		system("cls");
		char gameTitle[] = "Welcome to WORM!";
		printf("%74s\n\n", gameTitle);
		printf("%56c", 201);
		for(int a = 0; a < 20; a++){
			printf("%c", 205);
		}
		printf("%c\n", 187);
	printf("%56c%21c\n%56c  Enter Game Mode!  %c\n%56c%21c\n%56c  1. Solo Play      %c\n%56c  2. Other Games    %c\n%56c  3. Scoreboard     %c\n%56c  4. Exit Program   %c\n", 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186);
	printf("%56c                    %c\n", 186, 186);
	
	printf("%56c", 200);
	
	for(int b = 0; b < 20; b++){
		printf("%c", 205);
	}
	printf("%c\n", 188);
	
	// Choosing game modes
	printf("Enter Gamemode Here!\n", ' ');
//	printf("%57c", ' ');
	scanf(" %d", &mode);
	switch(mode){
		case 1:
			soloPlay();
			//show cursor after game
			printf("\33[?25h");
			continue;
		case 2:
			otherGames();
			continue;
		case 3:
			scoreboard();
			continue;
		case 4:
			fw = fopen("score.txt", "w");
			if(fw == NULL){
				printf("Can't Open File!"); getch(); exit(1);
			}
			while(p > z){
				fprintf(fw, "%s - %ld\n", player[z].name, player[z].score);
				z++;
			}
			fclose(fw);
			return 0;
		default:
			printf("You didn't pick a game mode!");
			sleep(1);
			continue;
		}
	}
}
