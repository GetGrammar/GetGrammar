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
}

void correct_init(string a[10], string b[10], string c[30])
{
    int dict_number = rand() % 7 + 1;
    for (int i = 0; i < 10; ++i) {
        get_correct_words_for_first_mode(a[i], b[i], dict_number, i);
    }
    int incorrect_dict_number = dict_number;
    while (dict_number = incorrect_dict_number)
        incorrect_dict_number = rand() % 7 + 1;
}

int main()
{
    srand(time(0));
    string rus_correct[10];
    string eng_correct[10];
    string incorrect[30];
    correct_init(rus_correct, eng_correct, incorrect);
    for (int i = 0; i < 10; ++i) {
        cout << rus_correct[i] << " " << eng_correct[i] << endl;
    }
}
