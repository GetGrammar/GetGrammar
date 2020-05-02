#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

void find_dictionary_name(char*& name, int number, int lang)
{
    if (lang == 0) {
        switch (number) {
        case 1:
            name = "rus_1.txt";
            break;
        case 2:
            name = "rus_2.txt";
            break;
        case 3:
            name = "rus_3.txt";
            break;
        case 4:
            name = "rus_4.txt";
            break;
        case 5:
            name = "rus_5.txt";
            break;
        case 6:
            name = "rus_6.txt";
            break;
        case 7:
            name = "rus_7.txt";
            break;
        }
    }
    if (lang == 1) {
        switch (number) {
        case 1:
            name = "eng_1.txt";
            break;
        case 2:
            name = "eng_2.txt";
            break;
        case 3:
            name = "eng_3.txt";
            break;
        case 4:
            name = "eng_4.txt";
            break;
        case 5:
            name = "eng_5.txt";
            break;
        case 6:
            name = "eng_6.txt";
            break;
        case 7:
            name = "eng_7.txt";
            break;
        }
    }
}

