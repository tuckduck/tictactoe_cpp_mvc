using namespace std;
#include "iostream"
#include "A_v2m.h"
class ttt_view {
    private:
        A_v2m* _v2m;
        void initMenu(){

        }
    public:
        ttt_view(A_v2m v2m) {
            _v2m = v2m;
        }
        void start() {
            std::cout << "Init view \n";
            _v2m.playerMove();
        }
};