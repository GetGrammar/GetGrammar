#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

string find_word(int num, int mode)
{
    ifstream in;
    if (mode == 0)
        in.open("dictionaries/rus.txt");
    else
        in.open("dictionaries/eng.txt");
    string a;
    for (int i = 0; i <= num; ++i) {
        getline(in, a);
    }
    in.close();
    return a;
}

bool is_repeat(int* mas, int n)
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (mas[i] == mas[j])
                return false;
        }
    }
    return true;
}

bool is_repeat(int* mas, int n, int current)
{
    for (int i = 0; i < n; ++i) {
        if (mas[i] == current)
            return false;
    }
    return true;
}

void get_mass(int a[], int n, int size)
{
    srand(time(0));
    a[0] = rand() % n;
    for (int i = 1; i < size; ++i) {
        while (true) {
            a[i] = rand() % n;
            if (is_repeat(a, i + 1))
                break;
        }
    }
}

void get_mass(int a[], int n, int size_a, int b[], int size_b)
{
    srand(time(0));
    while (true) {
        b[0] = rand() % n;
        if (is_repeat(a, size_a, b[0]))
            break;
    }
    for (int i = 1; i < size_b; ++i) {
        while (true) {
            b[i] = rand() % n;
            if (is_repeat(a, size_a, b[i]) && is_repeat(b, i + 1))
                break;
        }
    }
}
void get_correct_words_for_first_mode(
        int mas[], string correct_rus[], string correct_eng[], int size)
{
    ifstream in;
    in.open("dictionaries/rus.txt");
    string a;
    int n = 0;
    while (getline(in, a)) {
        n++;
    }
    in.close();
    get_mass(mas, n, size);
    for (int i = 0; i < size; ++i) {
        correct_rus[i] = find_word(mas[i], 0);
        correct_eng[i] = find_word(mas[i], 1);
    }
}

void get_words_for_second_mode(
        string& correct_eng,
        string& correct_rus,
        string& incorrect_1,
        string& incorrect_2,
        string& incorrect_3,
        int lenght)
{
    int num_rand_correct = rand() % lenght;
    int num1 = rand() % (lenght - 2) + 2, num2 = num1 - 1, num3 = num1 - 2;
    while (num1 == num_rand_correct && num2 == num_rand_correct
           && num3 == num_rand_correct) {
        num1 = rand() % (lenght - 2) + 2;
        num2 = num1 - 1;
        num3 = num1 - 2;
    }
    cout << num_rand_correct << " " << num1 << " " << num2 << " " << num3
         << endl;
    ifstream rus, eng;
    string a;
    rus.open("dictionaries/rem_rus.txt");
    eng.open("dictionaries/rem_eng.txt");
    int k = 0;
    for (int i = 0; i < lenght; i++) {
        if (i == num_rand_correct || i == num1 || i == num2 || i == num3) {
            if (i == num_rand_correct) {
                getline(rus, a);
                correct_rus = a;
                getline(eng, a);
                correct_eng = a;
            }
            if (i == num1) {
                getline(eng, a);
                incorrect_1 = a;
                getline(rus, a);
            }
            if (i == num2) {
                getline(eng, a);
                incorrect_2 = a;
                getline(rus, a);
            }
            if (i == num3) {
                getline(eng, a);
                incorrect_3 = a;
                getline(rus, a);
            }
            k++;
        } else {
            getline(eng, a);
            getline(rus, a);
        }
    }
}

void get_incorrect_words_for_first_mode(
        int mas[],
        int mas_inc[],
        string incorrect[],
        int size_mas,
        int size_mas_inc)
{
    ifstream in;
    in.open("eng_1.txt");
    string a;
    int n;
    while (getline(in, a)) {
        n++;
    }
    in.close();
    get_mass(mas, n, size_mas, mas_inc, size_mas_inc);
    for (int i = 0; i < size_mas_inc; ++i) {
        incorrect[i] = find_word(mas_inc[i], 1);
    }
}
