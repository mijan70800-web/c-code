#include <stdio.h>

char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void drawBoard() {
    printf("\n\n  --- Tic-Tac-Toe ---  \n\n");
    printf(" Player 1 (X)  -  Player 2 (O)\n\n");
    
    printf(" _____ ____________\n");
    printf("|  %c  |  %c  |  %c  | \n", board[1], board[2], board[3]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  | \n", board[4], board[5], board[6]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  | \n", board[7], board[8], board[9]);
    printf("|_____|_____|_____|\n");
    
}
int checkWin() {
    if (board[1] == board[2] && board[2] == board[3]) return 1;
    else if (board[4] == board[5] && board[5] == board[6]) return 1;
    else if (board[7] == board[8] && board[8] == board[9]) return 1;
    else if (board[1] == board[4] && board[4] == board[7]) return 1;
    else if (board[2] == board[5] && board[5] == board[8]) return 1;
    else if (board[3] == board[6] && board[6] == board[9]) return 1;
    else if (board[1] == board[5] && board[5] == board[9]) return 1;
    else if (board[3] == board[5] && board[5] == board[7]) return 1;
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' &&
             board[4] != '4' && board[5] != '5' && board[6] != '6' &&
             board[7] != '7' && board[8] != '8' && board[9] != '9') return 0;
    else return -1;
}

int main() {
    int player = 1, choice, i;
    char mark;

    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        
        if (choice >= 1 && choice <= 9 && board[choice] == (choice + '0')) {
            board[choice] = mark;
        } else {
            printf("Invalid move! Press enter to try again...");
            player--; 
            getchar();
            getchar(); 
        }

        i = checkWin();
        player++;
    } while (i == -1);

    drawBoard();

    if (i == 1)
        printf("==> Congratulations! Player %d Wins!\n", --player);
    else
        printf("==> Game Draw!\n");

    return 0;
}