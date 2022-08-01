#include <iostream>
#include <cmath>
using namespace std;
//Функция расчёта дней и проверки високосных лет
long nDays(long y, long m, long d);
//Функция расчёта среднего арифметического 
void average(int* arr, int s);
//Функция перевода 2 сс в десятичнную
int convert(long long n);


int main()
{
    int arr[10] = { 12,3,21,4,2,514,35,32,12,75 };
    //Task 1___________________________________________
    long y, m, d;
    cout << "Enter the start date (dd:mm:yy): \n";
    cin >> d >> m >> y;
    long nd1 = nDays(y, m, d);
    cout << "Enter the final date (dd:mm:yy): \n";
    cin >> d >> m >> y;
    long nd2 = nDays(y, m, d);

    cout <<"Amount of days: "<< nd2 - nd1<<endl;
    //_________________________________________________
    //Task 2
    average(arr, 0);
    //_________________________________________________
    //Task 3
    long long n;
    cout << "Enter a binary number: ";
    cin >> n;
    cout << n << " in binary = " << convert(n) << " in decimal";
    return 0;
}

long nDays(long y, long m, long d) {
    if (m <= 2) m += 12, y -= 1;
    return (y * 146097) / 400 + (m * 153 + 8) / 5 + d;
}

void average(int* arr, int s) {
    for (int i = 0; i < 10; i++) {
        s += arr[i];
    }
    cout << "Average: " << s / 10 << endl;
}

int convert(long long n) {
    int dec = 0, i = 0, temp;
    while (n != 0) {
        temp = n % 10;
        n /= 10;
        dec += temp * pow(2, i);
        ++i;
    }
    return dec;
}