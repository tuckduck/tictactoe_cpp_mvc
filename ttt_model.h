using namespace std;
#include "iostream"
#include "algorithm"
class ttt_model {
    private:
            char* board;
    public:
        void start() {
            std::cout << "Init model \n";
        }
        void init(int boardsize) {
            board = new char[boardsize * boardsize];
            printf(board);
            for(int i = 0;i<boardsize*boardsize;i++){board[i] = ' ';}
            //printf("%c", board[0]);
        }
        char* getBoardState() {
            return board;
        } 
        int winCheck(char player1, char player2, int boardsize) {
            int i, j, count1, count2, count3, count4;
            for (j=0;j<boardsize;j++) {
                count1 = 0;
                count2 = 0;
                count3 = 0;
                count4 = 0;
                for (i=0;i<boardsize;i++) {
                    if (board[j * boardsize + i] == player1) {count1++;}
                    if (board[j * boardsize + i] == player2) {count2++;}
                    if (board[i * boardsize + j] == player1) {count3++;}
                    if (board[i * boardsize + j] == player2) {count4++;}
                }
                if (count1 == boardsize || count3 == boardsize) {return 1;}
                if (count2 == boardsize || count4 == boardsize) {return 2;}
            }
            return 0;

        }
        bool processMove(int row, int column, int boardsize, char player) {
            if (board[row * boardsize + column] != ' ') {
                return false;
            }
            board[row * boardsize + column] = player;
            return true;
        }
};