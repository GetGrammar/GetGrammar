
#include "Grammar_logic_lib.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

string find_word(int *mas,int size, string words[], int mod)
{
    ifstream in;
    if (mod == 0)
        in.open("dictionaries/rus.txt");
    else
        in.open("dictionaries/eng.txt");
    string a;
    int k = 0,i = 0;
    while(k < mas[size - 1] + 2){
        getline(in,a);
        if(k == mas[i]){
            words[i] = a;
            i++;
        }
        k++;
    }
    in.close();
    return a;
}

string find_word(int num,int mod){
    string a;
    ifstream in;
    if (mod == 0)
        in.open("dictionaries/rem_rus.txt");
    else
        in.open("dictionaries/rem_eng.txt");
    for(int i = 0; i <= num; ++i) getline(in,a);
    in.close();
    return a;
}

bool find_word(string check_rus){
    ifstream fin;
    string a;
    fin.open("dictionaries/rem_rus");
    while(getline(fin, a)){
        if(a == check_rus) return false;
    }
    return true;
}

void rem(string rem_rus,string rem_eng){
    if(find_word(rem_rus)){
        ofstream eng,rus;
        rus.open("dictionaries/rem_rus.txt", std::ios::app);
        rus << rem_rus << endl;
        rus.close();
        eng.open("dictionaries/rem_eng.txt", std::ios::app);
        eng << rem_eng << endl;
        eng.close();
    }
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


void sort(int* arr,int size){
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void get_rem_mass(int a[], int n, int size,int current)
{
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        while (true) {
            a[i] = rand() % n;
            while(true){
                if(is_repeat(a,i + 1,current)) break;
                a[i] = rand() % n;
            }
            if (is_repeat(a, i + 1))
                break;
        }
    }
    sort(a,size);
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
    sort(a,size);
}


void get_mass(int a[], int n, int size_a, int b[], int size_b)
{
    //cout << n << endl;
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
    sort(b,size_b);
}
void get_correct_words_for_first_mode(
        int mas[], string correct_rus[], string correct_eng[], int size,int n)
{

    get_mass(mas, n, size);
    find_word(mas,size,correct_rus,0);
    find_word(mas,size,correct_eng,1);
}

char* str_to_char(string s){
    char* chrstr = new char[s.length() + 1];
    strcpy(chrstr,s.c_str());
    return chrstr;
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
        int size_mas_inc,
        int n)
{
    srand(time(0));

    get_mass(mas, n, size_mas, mas_inc, size_mas_inc);
    find_word(mas_inc,size_mas_inc,incorrect,1);
}
