#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main () {
    double p1_job1 = 0.5, x1_job1 = 3000;
    double p2_job1 = 0.99, x2_job1 = 2510;

    double p1_job2 = 0.5, x1_job2 = 2000;
    double p2_job2 = 0.01, x2_job2 = 1510;

    double m1 = p1_job1 * x1_job1 + p2_job1 * x2_job1;
    double m2 = p1_job2 * x1_job2 + p2_job2 * x2_job2;

    double v1 = pow(x1_job1 - m1, 2) * p1_job1 + pow(x2_job1 - m1, 2) * p2_job1;
    double risk1 = sqrt(v1);

    double v2 = pow(x1_job2 - m2, 2) * p1_job2 + pow(x2_job2 - m2, 2) * p2_job2;
    double risk2 = sqrt(v2);

    cout << fixed << setprecision(2);
    cout << "place of work 1: M1 = " << m1 << ", risk1 = " << risk1 << endl;
    cout << "place of work 2: M2 = " << m2 << ", risk2 = " << risk2 << endl;
    cout << "--------------------------------------------------" << endl;

    cout << "result: " << endl;
    if(m1 > m2) {
        cout << "prybutok vyhidnishe v m1 (m = " << m1 << ")" << endl;
    } else if(m1 < m2) {
        cout << "prybutok vyhidnishe v m2 (m = " << m2 << ")" << endl;
    } else cout << "v dvokh mistsyakh odnakovyy prybutok (m = " << m1 << ")" << endl;
    
    if (risk1 < risk2) {
        cout << "naimensh ryzykovane: place 1 (risk = " << risk1 << ")" << endl;
    } else if (risk2 < risk1) {
        cout << "naimensh ryzykovane: place 2 (risk = " << risk2 << ")" << endl;
    } else {
        cout << "ryzyk odnakovyy na obokh mistsyakh" << endl;
    }
    return 0;
}
