#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a1[5] = {15, 13, 12, 13, 17};
    double a2[5] = {16, 20, 12, 20, 12};
    int n = 5;

    double sum1 = 0;
    double sum2 = 0;
    for(int i = 0; i < n; i++) {
        sum1 += a1[i];
        sum2 += a2[i];
    }
    
    double m1 = sum1 / n;
    double m2 = sum2 / n;

    double disp1 = 0;
    double disp2 = 0;
    double cov = 0;
    for(int i = 0; i < n; i++) {
        disp1 += pow(a1[i] - m1, 2);
        disp2 += pow(a2[i] - m2, 2);
        cov += (a1[i] - m1) * (a2[i] - m2);
    }
    disp1 /= n;
    disp2 /= n;
    cov /= n;

    double risk1 = sqrt(disp1);
    double risk2 = sqrt(disp2);
    double r = cov / (risk1 * risk2);

    // a
    double x1_a = (disp2 - r * risk1 * risk2) / (disp1 + disp2 - 2 * r * risk1 * risk2);
    double x2_a = 1 - x1_a;
    double m_a = x1_a * m1 + x2_a * m2;
    double risk_a = sqrt(pow(x1_a, 2) * disp1 + pow(x2_a, 2) * disp2 + 2 * x1_a * x2_a * cov);

    cout << "a) " << endl;
    cout << "x1 = " << x1_a << endl;
    cout << "x2 = " << x2_a << endl;
    cout << "mp = " << m_a << "%" << endl;
    cout << "risk = " << risk_a << "%" << endl << endl;

    // b
    double rf1 = 0;
    double x1_b1 = ((m1 - rf1) * disp2 - (m2 - rf1) * cov) / ((m1 - rf1) * disp2 + (m2 - rf1) * disp1 - (m1 + m2 - 2 * rf1) * cov);
    double x2_b1 = 1 - x1_b1;
    double m_b1 = x1_b1 * m1 + x2_b1 * m2;
    double risk_b1 = sqrt(pow(x1_b1, 2) * disp1 + pow(x2_b1, 2) * disp2 + 2 * x1_b1 * x2_b1 * cov);

    double rf2 = 10;
    double x1_b2 = ((m1 - rf2) * disp2 - (m2 - rf2) * cov) / ((m1 - rf2) * disp2 + (m2 - rf2) * disp1 - (m1 + m2 - 2 * rf2) * cov);
    double x2_b2 = 1 - x1_b2;
    double m_b2 = x1_b2 * m1 + x2_b2 * m2;
    double risk_b2 = sqrt(pow(x1_b2, 2) * disp1 + pow(x2_b2, 2) * disp2 + 2 * x1_b2 * x2_b2 * cov);

    cout << "b) " << endl;
    cout << "rf = 0%: x1 = " << x1_b1 << ", x2 = " << x2_b1 << endl;
    cout << "rf = 10%: x1 = " << x1_b2 << ", x2 = " << x2_b2 << endl << endl;

    // v
    double m_v = 15.25;
    double x1_v = (m_v - m2) / (m1 - m2);
    double x2_v = 1 - x1_v;
    double risk_v = sqrt(pow(x1_v, 2) * disp1 + pow(x2_v, 2) * disp2 + 2 * x1_v * x2_v * cov);

    cout << "v) " << endl;
    cout << "x1 = " << x1_v << endl;
    cout << "x2 = " << x2_v << endl;
    cout << "risk = " << risk_v << "%" << endl << endl;

    // g
    double m_g = 3.5;
    double x1_g = (m_g - m2) / (m1 - m2);
    double x2_g = 1 - x1_g;
    double risk_g = sqrt(pow(x1_g, 2) * disp1 + pow(x2_g, 2) * disp2 + 2 * x1_g * x2_g * cov);

    cout << "g) " << endl;
    cout << "x1 = " << x1_g << endl;
    cout << "x2 = " << x2_g << endl;
    cout << "risk = " << risk_g << "%" << endl << endl;

    // d
    cout << "d) " << endl;
    cout << "a: mp = " << m_a << "%, risk = " << risk_a << "%" << endl;
    cout << "b (rf = 0): mp = " << m_b1 << "%, risk = " << risk_b1 << "%" << endl;
    cout << "b (rf = 10): mp = " << m_b2 << "%, risk = " << risk_b2 << "%" << endl;
    cout << "v: mp = " << m_v << "%, risk = " << risk_v << "%" << endl;
    cout << "g: mp = " << m_g << "%, risk = " << risk_g << "%" << endl;

    return 0;
}