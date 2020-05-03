#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void find_dictionary_name(char*& name, int number, int lang)
{
    if (lang == 0) {
        switch (number) {
        case 1:
            name = "dictionaries/rus_1.txt";
            break;
        case 2:
            name = "dictionaries/rus_2.txt";
            break;
        case 3:
            name = "dictionaries/rus_3.txt";
            break;
        case 4:
            name = "dictionaries/rus_4.txt";
            break;
        case 5:
            name = "dictionaries/rus_5.txt";
            break;
        case 6:
            name = "dictionaries/rus_6.txt";
            break;
        case 7:
            name = "dictionaries/rus_7.txt";
            break;
        }
    }
    if (lang == 1) {
        switch (number) {
        case 1:
            name = "dictionaries/eng_1.txt";
            break;
        case 2:
            name = "dictionaries/eng_2.txt";
            break;
        case 3:
            name = "dictionaries/eng_3.txt";
            break;
        case 4:
            name = "dictionaries/eng_4.txt";
            break;
        case 5:
            name = "dictionaries/eng_5.txt";
            break;
        case 6:
            name = "dictionaries/eng_6.txt";
            break;
        case 7:
            name = "dictionaries/eng_7.txt";
            break;
        }
    }
}

void get_correct_words_for_first_mode(
        string& rus_correct, string& eng_correct, int dict_number, int sector)
{
    srand(time(0));
    int num_rand;
    char* name_rus;
    char* name_eng;
    find_dictionary_name(name_rus, dict_number, 0);
    find_dictionary_name(name_eng, dict_number, 1);
    ifstream rus, eng;
    string a, rus_correct_1, eng_correct_1;
    rus.open(name_rus);
    eng.open(name_eng);
    if (sector == 9)
        num_rand = 630 + rand() % 66;
    else
        num_rand = 70 * sector + rand() % 70;
    for (int i = 0; i < num_rand; ++i) {
        getline(rus, a);
        getline(eng, a);
    }
    getline(rus, rus_correct_1);
    getline(eng, eng_correct_1);
    rus_correct = rus_correct_1;
    eng_correct = eng_correct_1;
    eng.close();
    rus.close();
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

void get_incorrect_words(string& in1, string& in2, string& in3, int dict_number)
{
    int rand_num_1 = rand() % 600;
    int rand_num_2 = rand() % rand_num_1;
    int rand_num_3 = rand_num_1 + rand() % (696 - rand_num_1);
    char* name_eng;
    string a;
    ifstream eng;
    find_dictionary_name(name_eng, dict_number, 1);
    eng.open(name_eng);
    for (int i = 0; i < rand_num_3; ++i) {
        if (i == rand_num_1 || i == rand_num_2) {
            if (i == rand_num_1) {
                getline(eng, a);
                in1 = a;
            } else {
                getline(eng, a);
                in2 = a;
            }
        } else
            getline(eng, a);
    }
    getline(eng, a);
    in3 = a;
    eng.close();
}

void correct_init(string a[10], string b[10], string c[30])
{
    srand(time(0));
    int dict_number = rand() % 7 + 1;
    for (int i = 0; i < 10; ++i) {
        get_correct_words_for_first_mode(a[i], b[i], dict_number, i);
    }
    int incorrect_dict_number = dict_number;
    while (dict_number == incorrect_dict_number)
        incorrect_dict_number = rand() % 7 + 1;
    for (int i = 0; i < 10; ++i)
        get_incorrect_words(
                c[3 * i], c[3 * i + 1], c[3 * i + 2], incorrect_dict_number);
}
