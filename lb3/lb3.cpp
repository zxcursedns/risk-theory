#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double U1(double x) {
    return 1.3 * x;
}

double U2(double x) {
    return 1.4 * sqrt(x);
}

int main() {
    double start_money = 50;
    double sure_win = start_money; 
    
    double x1_lost = 0;
    double x2_win = 200;
    double p = 0.5;

    double expected_win = p * x1_lost + p * x2_win;

    cout << "pochatrovi hroshi: " << start_money << " grn" << endl;
    cout << "spodivanyy vyhrash: " << expected_win << " grn" << endl;
    cout << "harantovanyy vyhrash: " << sure_win << " grn" << endl;

    cout << "student 1: U(x) = 1.3 * x" << endl;
    double u1_sure = U1(sure_win);
    double u1_lottery = p * U1(x1_lost) + p * U1(x2_win);
    
    cout << "korysnist zberezhennia hroshey: " << u1_sure << endl;
    cout << "spodivana korysnist lotereyi: " << u1_lottery << endl;
    
    if (u1_lottery > u1_sure) {
        cout << "vysnovok dlya student 1: obyraye stavku" << endl;
    } else {
        cout << "vysnovok dlya student 1: obyraye zberehty hroshi" << endl;
    } 

    cout << "student 2: U(x) = 1.4 * sqrt(x)" << endl;
    double u2_sure = U2(sure_win);
    double u2_lottery = p * U2(x1_lost) + p * U2(x2_win);
    
    cout << "korysnist zberezhennia hroshey: " << fixed << setprecision(2) << u2_sure << endl;
    cout << "spodivana korysnist lotereyi: " << u2_lottery << endl;
    
    if (u2_lottery > u2_sure) {
        cout << "vysnovok dlya student 2: obyraye stavku" << endl;
    } else {
        cout << "vysnovok dlya student 2: obyraye zberehty hroshi" << endl;
    }
    return 0;
}