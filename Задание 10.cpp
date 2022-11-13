#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

__int64 vvod()
{
    long double Num = 0;
    
    cout << "Введите число" << endl; cin >> Num;
    
    if (__int64(Num) != Num) {
        
        do { cout << "\n" << "Упс, что-то неверно, попробуте снова.\n\nВведите число" << endl; cin >> Num; } while (__int64(Num) != Num);
    
    }
    
    return __int64(Num);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    __int64 Number = 0;
    vector <int> MassOfDel; /*создание динамичесго массива*/
    int NotCycle = 0;
    
    Number = vvod();

    int n = int(sqrt(Number));
    
    while (Number != 1)
    {
        int Del;
        for (Del = 2; Del < int(sqrt(Number)); Del++)       /*ищем первый делитель числа*/
        {
            if (Number % Del == 0)                                  
            {
                MassOfDel.push_back(Del);                              /*добавляем в массив этот делитель*/ 
                
                __int64 RevDel = Number / Del;                        /*находим обратный делитель числа*/                 

                while (RevDel / Del == RevDel / (Del*0.1))         
                {
                    RevDel /= Del;                          /*делим до той поры, пока обратный делитель, пока он делиться на делитель числа*/
                }
  
                Number = RevDel;        /*число, которое не делиться на простой делитель, основым числом и для него мы уже ищем делители,
                                        тем самым сокращем кол-во чисел для перебора*/
                break;
            }
        }

        if (Del == int(sqrt(Number)) ) /*антицикл, т.е если число уже не делиться, а до 1 все равно нужно добрать, чтобы
                                        выйти из цикла*/
        {
            NotCycle += 1;

            if (NotCycle > 4)
            {
                MassOfDel.push_back(Number); /*добавляем в массив число, для которого нет делителей*/

                Number = 1;
            }
        }
        
        else NotCycle = 0;
   
    }

    sort(MassOfDel.begin(), MassOfDel.end()); //сортировка массива для красоты :)
    
    
    auto iter = MassOfDel.begin();
    __int64 Sum = 1;
    cout << "\n" << "Множители данного числа :" << endl;
    while (iter != MassOfDel.end())
    {
        cout << *iter << endl;     /*вывод массива с помощью итератора*/
        Sum *= *iter;
        iter++;
    }
    cout <<"\n"<<"Проверка : " << Sum;
}

