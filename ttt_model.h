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
        void processMove() {
            std::cout << "Processing move \n";
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
};