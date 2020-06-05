#ifndef GRAMMAR_LOGIC_LIB_H
#define GRAMMAR_LOGIC_LIB_H

#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

string find_word(int *mas,int size, string words[], int mode);
bool is_repeat(int* mas, int n);
bool is_repeat(int* mas, int n, int current);
void sort(int* arr,int size);
void get_mass(int a[], int n, int size);
bool find_word(string check_rus);
void rem(string rem_rus,string rem_eng);
void get_mass(int a[], int n, int size_a, int b[], int size_b);
void get_correct_words_for_first_mode(
        int mas[], string correct_rus[], string correct_eng[], int size,int n);
void get_incorrect_words_for_first_mode(
        int mas[],
        int mas_inc[],
        string incorrect[],
        int size_mas,
        int size_mas_inc,
        int n);
char* str_to_char(string s);
string find_word(int num,int mod);
void get_rem_mass(int a[], int n, int size,int current);

#endif // GRAMMAR_LOGIC_LIB_H
