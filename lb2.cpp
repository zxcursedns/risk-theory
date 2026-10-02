#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    double p1_job1 = 0.5, x1_job1 = 3000;
    double p2_job1 = 0.5, x2_job1 = 2000;

    double p1_job2 = 0.99, x1_job2 = 2510;
    double p2_job2 = 0.01, x2_job2 = 1510;

    double m1 = p1_job1 * x1_job1 + p2_job1 * x2_job1;
    double m2 = p1_job2 * x1_job2 + p2_job2 * x2_job2;

    double v1 = pow(x1_job1 - m1, 2) * p1_job1 + pow(x2_job1 - m1, 2) * p2_job1;
    double risk1 = sqrt(v1);

    double v2 = pow(x1_job2 - m2, 2) * p1_job2 + pow(x2_job2 - m2, 2) * p2_job2;
    double risk2 = sqrt(v2);

    double cv1 = risk1 / m1;
    double cv2 = risk2 / m2;

    cout << fixed << setprecision(2);
    cout << "place of work 1:" << endl;
    cout << "  m1 = " << m1 << ", v1 = " << v1 << ", risk1 = " << risk1;
    cout << ", cv1 = " << setprecision(4) << cv1 << setprecision(2) << endl;

    cout << "place of work 2:" << endl;
    cout << "  m2 = " << m2 << ", v2 = " << v2 << ", risk2 = " << risk2;
    cout << ", cv2 = " << setprecision(4) << cv2 << setprecision(2) << endl;

    cout << "--------------------------------------------------" << endl;
    cout << "result: " << endl;

    if (m1 > m2) {
        cout << "prybutok vyhidnishe v place 1 (m = " << m1 << ")" << endl;
    } else if (m1 < m2) {
        cout << "prybutok vyhidnishe v place 2 (m = " << m2 << ")" << endl;
    } else {
        cout << "v dvokh mistsyakh odnakovyy prybutok (m = " << m1 << ")" << endl;
    }

    if (cv1 < cv2) {
        cout << "obraty place 1: naimenshyy ryzyk (cv = " << cv1 << ")" << endl;
    } else if (cv2 < cv1) {
        cout << "obraty place 2: naimenshyy ryzyk (cv = " << cv2 << ")" << endl;
    } else {
        cout << "ryzyk odnakovyy na obokh mistsyakh" << endl;
    }

    return 0;
}