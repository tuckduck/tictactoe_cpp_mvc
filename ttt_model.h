using namespace std;
#include "iostream"
class ttt_model {
    private:
            int board_dim;
    public:
        void start() {
            std::cout << "Init model \n";
        }
        void processMove() {
            std::cout << "Processing move \n";
        }
};