#include "iostream"

#include "ttt_view.h"
#include "ttt_model.h"
#include "A_v2m.h"

using namespace std;
class ttt_controller {
    private:
        ttt_model model;
        ttt_view view;
    public:
        void start() {
            std::cout << "Init Controller \n";
            model.start();
            view.start();
        }
};