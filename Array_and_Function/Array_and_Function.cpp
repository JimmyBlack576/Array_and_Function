#include <iostream>
#include <cmath>
using namespace std;
//Функция расчёта дней и проверки високосных лет
long nDays(long y, long m, long d);
//Функция расчёта среднего арифметического 
void average(int* arr, int s);
//Функция подсчёта отрицательных, положительных и нулевых элементов массива
void value_count(int* arr3);



int main()
{
    int arr3[10] = { -1,3,-5,0,4,7,4,-4,0,9 };
    int* ptr = arr3;
    int arr[10] = { 12,3,21,4,2,514,35,32,12,75 };
    //Task 1___________________________________________
    long y, m, d;
    cout << "Enter the start date (dd:mm:yy): \n";
    cin >> d >> m >> y;
    long nd1 = nDays(y, m, d);
    cout << "Enter the final date (dd:mm:yy): \n";
    cin >> d >> m >> y;
    long nd2 = nDays(y, m, d);

    cout <<"Amount of days: "<< nd2 - nd1<<endl<<endl;
    system("pause");
    //_________________________________________________
    //Task 2
    average(arr, 0);
    system("pause");
    //_________________________________________________
    //Task 3
    value_count(arr3);
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
    cout << "Average: " << s / 10 << endl<<endl;
}

void value_count(int* arr3) {
    int cp = 0, cn = 0, cnull = 0;
    for (int i = 0; i < 10; i++) {
        if (*(arr3 + i) < 0) cn++;
        else if (*(arr3 + i) == 0) cnull++;
        else if (*(arr3 + i) > 0) cp++;
    }
    cout << "Negative- " << cn << endl;
    cout << "Positive- " << cp << endl;
    cout << "Null- " << cnull << endl;
}