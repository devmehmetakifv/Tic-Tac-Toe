#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_CAP 99

/*Initialize board */
char board[9] = {'-','-','-','-','-','-','-','-','-'};

/*Initialize functions */
int firstPlayerWinCheck(void);
int secondPlayerWinCheck(void);
int firstPlayerMove(int pos);
int secondPlayerMove(int pos);
int drawCheck(void);
void displayCurrentBoard();
void displayEmptyBoard();

/* Initialize variables */
int isGameRunning = 1;
char firstPlayer[MAX_CAP];
char secondPlayer[MAX_CAP];
int firstPlayerInp;
int secondPlayerInp;
int isfirstPlayerWin;
int issecondPlayerWin;
int isGameDraw;

int main(){
printf("|----------------------------------------------------------------------------------------------------|\n");
    printf("| Hello! Welcome To Tic-Tac-Toe!                                                                     |\n");
    printf("| This program developed by Mehmet Akif VARDAR. Can only be used for educational purposes only.      |\n");
    printf("| For more information, please check https://github.com/devmehmetakifv/                              |\n");
    printf("|----------------------------------------------------------------------------------------------------|\n");
    sleep(5);

    printf("Please enter 1st Player(X) name: ");
    scanf("%s",&firstPlayer);
    printf("Please enter 2nd Player(O) name: ");
    scanf("%s",&secondPlayer);
    printf("Great, allow me a few seconds to set things up for you...\n");
    sleep(2);
    printf("Alright, here we go... Cleaning up your screen for a fresh start.\n");
    sleep(2);
    getchar();
    system("cls");
    displayEmptyBoard();
    while(isGameRunning == 1){
        displayCurrentBoard();
        printf("=> %s, please enter a number in the board where you want to place your X: ",firstPlayer);
        scanf("%d",&firstPlayerInp);
        if(firstPlayerInp < 0 || firstPlayerInp > 8){
            printf("You entered wrong number! Game is suspended!");
            break;
        }
        firstPlayerMove(firstPlayerInp);
        int firstPlayerWin = firstPlayerWinCheck();
        int isDraw = drawCheck();
        if(firstPlayerWin == 1 && isDraw == 0){
            isfirstPlayerWin = 1;
            issecondPlayerWin = 0;
            isGameRunning = 0;
            getchar();
            system("cls");
        }
        else if(firstPlayerWin == 0 && isDraw == 0){
            displayCurrentBoard();
            printf("=> %s, please enter a number in the board where you want to place your O: ",secondPlayer);
            scanf("%d",&secondPlayerInp);
            if(secondPlayerInp < 0 || secondPlayerInp > 8){
            printf("You entered wrong number! Game is suspended!");
            break;
        }
            secondPlayerMove(secondPlayerInp);
            int secondPlayerWin = secondPlayerWinCheck();
            isDraw = drawCheck();
            if(secondPlayerWin == 1 && isDraw == 0){
                issecondPlayerWin = 1;
                isfirstPlayerWin = 0;
                isGameRunning = 0;
                getchar();
                system("cls");
            }
        }
        else if(secondPlayerWinCheck() == 0 && firstPlayerWin == 0 && isDraw == 1){
            isGameDraw = 1;
            issecondPlayerWin = 0;
            isfirstPlayerWin = 0;
            isGameRunning = 0;
            getchar();
            system("cls");
        }


    }
    if(issecondPlayerWin == 1 && isfirstPlayerWin == 0 && isGameDraw == 0){
        displayCurrentBoard();
        printf("Congratulations %s !, you won!",secondPlayer);
        system("pause");
    }
    else if(isfirstPlayerWin == 1 && issecondPlayerWin == 0 && isGameDraw == 0){
        displayCurrentBoard();
        printf("Congratulations %s !, you won!",firstPlayer);
        system("pause");
    }
    else if(issecondPlayerWin == 0 && isfirstPlayerWin == 0 && isGameDraw == 1){
        displayCurrentBoard();
        printf("It's a draw! Play again!");
        system("pause");
    }
    return 0;
}

void displayCurrentBoard(){
    printf("Current board:\n\n");
    printf("         |         |     \n");
    printf("  %c      |  %c      |  %c \n", board[0], board[1], board[2]);

    printf("_________|_________|______\n");
    printf("         |         |     \n");

    printf("  %c      |  %c      |  %c \n", board[3], board[4], board[5]);

    printf("_________|_________|______\n");
    printf("         |         |     \n");

    printf("  %c      |  %c      |  %c \n", board[6], board[7], board[8]);

    printf("         |         |     \n\n");
}
void displayEmptyBoard(){
    printf("****************************************\n");
    printf("*  Tic-Tac-Toe by Mehmet Akif VARDAR.  *\n");
    printf("*  https://github.com/devmehmetakifv/  *\n");
    printf("****************************************\n\n");

    printf("         |         |     \n");
    printf("  0      |  1      |  2 \n");

    printf("_________|_________|______\n");
    printf("         |         |     \n");

    printf("  3      |  4      |  5 \n");

    printf("_________|_________|______\n");
    printf("         |         |     \n");

    printf("  6      |  7      |  8 \n");

    printf("         |         |     \n\n");
    printf("These are the numbers you will enter when you want to place your letter to one of these positions.\n");
    printf("--------------------------------------------------------------------------------------------------\n\n");
}

int firstPlayerMove(int pos){
    if(board[pos] == '-'){
        board[pos] = 'X';
    }
    else if(board[pos] == 'X' || board[pos] == 'O'){
        printf("That spot was taken!\n");
    }
}
int secondPlayerMove(int pos){
    if(board[pos] == '-'){
        board[pos] = 'O';
    }
    else if(board[pos] == 'X' || board[pos] == 'O'){
        printf("That spot was taken!\n");
    }
}
int firstPlayerWinCheck(){
    if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X'){
        return 1;
    }
    if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X'){
        return 1;
    }
    if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X'){
        return 1;
    }
    if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X'){
        return 1;
    }
    if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X'){
        return 1;
    }
    if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X'){
        return 1;
    }
    if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X'){
        return 1;
    }
    if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X'){
        return 1;
    }
    else{
        return 0;
    }
}
int secondPlayerWinCheck(){
    if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O'){
        return 1;
    }
    if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O'){
        return 1;
    }
    if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O'){
        return 1;
    }
    if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O'){
        return 1;
    }
    if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O'){
        return 1;
    }
    if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O'){
        return 1;
    }
    if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O'){
        return 1;
    }
    if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O'){
        return 1;
    }
    else{
        return 0;
    }
}
int drawCheck(){
    if(board[0] != '-' && board[1] != '-' && board[2] != '-' && board[3] != '-' && board[4] != '-' && board[5] != '-' && board[6] != '-' && board[7] != '-' && board[8] != '-'){
        return 1;
    }
    else{
        return 0;
    }

}
