using namespace std;
#include "iostream"
#include "stdlib.h"
#include "ttt_model.h"

class ttt_view {
    private:
        ttt_model model;
        int players, difficulty, boardsize, winner = 0, quit = 0;
        void reset() {
            players = 0;
            difficulty = 0;
            boardsize = 0;
            quit = 0;
            winner = 0;
        }
        void initMenu(){
            system("clear");
            printf("Welcome to Tic-Tac-Toe! \n");
            printf("How many players? ( 1 or 2 ) \n");
            while(!(players == 1 || players == 2)) {
                cin >> players;
                if (cin.fail()) {
                    cin.clear();
                }
            }
            if (players == 1) {
                printf("What difficulty? ( 1-easy, 2-medium, 3-hard \n");
                while(!(difficulty <=3 && difficulty >= 1)) {
                    cin >> difficulty;
                    if (cin.fail()) {
                        cin.clear();
                    }
                }
            }
            printf("What size board to play with? 3-10 \n");
            while(!(boardsize <= 10 && boardsize >= 3)) {
                cin >> boardsize;
                if (cin.fail()) {
                    cin.clear();
                }
            }
            model.init(boardsize);
        }
        void formatBoard(char* boardstate) {
            int i,j;
            for(j = 0;j<boardsize;j++) {
                for(i = 0;i<boardsize;i++) {
                    if (i != 0) {
                        printf("| %c ", boardstate[j * boardsize + i]);
                    }
                    else {
                        printf(" %c ", boardstate[j * boardsize + i]);
                    }
                }
                if (j != boardsize - 1) {
                    printf("\n");
                    for (int k = 0;k<boardsize;k++){(k==0) ? printf("---") : printf("----");}
                    printf("\n");
                }
            }
            printf("\n");
        }
        void endgameMenu() {
            printf("Play Again? (y/n) \n"); 
                char ans;
                cin >> ans;
                if (ans == 'n') {
                    quit = 1;
                }
        }
        void gameLoop() {
            formatBoard(model.getBoardState());
            int ans1, ans2;
            int turn = 1;
            char player1 = 'X';
            char player2 = 'O';
            while(!(winner == 1 || winner == 2)) {
                while(true) {
                    printf("Input Player %s Move Row\n", (turn == 1) ? "One" : "Two"); 
                    cin >> ans1;
                    if(cin.fail() || ans1 >= boardsize) {
                        printf("Invalid Move\n");
                        cin.clear();
                        continue;
                    }
                    printf("Input Player %s Move Column\n", (turn == 1) ? "One" : "Two"); 
                    cin >> ans2;
                    if(cin.fail() || ans2 >= boardsize) {
                        printf("Invalid Move\n");
                        cin.clear();
                        continue;
                    }
                    break;
                }
                if(!model.processMove(ans1, ans2, boardsize,(turn == 1)?player1:player2)) {
                    printf("That spot is already taken! \n");
                    continue;
                }
                winner = model.winCheck('X', 'O', boardsize);
                formatBoard(model.getBoardState());
                turn = (turn  == 1) ? 2 : 1;
            }
            (winner == 1) ? printf("Player One Won!!!\n") : printf("Player Two Won!!!\n");
        }
    public:
        void start() {
            std::cout << "Init view \n";
            while(quit == 0) {
                reset();
                initMenu();
                gameLoop();
                endgameMenu();
            }
        }
};