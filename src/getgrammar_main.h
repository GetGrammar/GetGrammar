#ifndef GETGRAMMAR_MAIN_H
#define GETGRAMMAR_MAIN_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QString>
#include <QThread>
#include <QLabel>
#include <cstring>
#include <iostream>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include <QTimer>
using namespace std;
void set_color(QPushButton *but,QColor b);


class GetGrammar_main : public QMainWindow
{
    Q_OBJECT

public:
    GetGrammar_main(QWidget *parent = 0);
    ~GetGrammar_main();
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    void repeat_rec(int (&state)[10][2], string correct_rus[], string correct_eng[], string incorrect[]);
    void fill_labels(bool ans);
    void rem_rec(int n);
    int mode = 0;
    string correct_rus[10];
    string correct_eng[10];
    string incorrect[30];
    string rem_inc[3];
    int rem_mas_inc[3];
    int mas[10],mas_inc[30];
    int state[10][2];
    int answer = 0;
    int answer_correct = 0;
    int k = 0;
    int n_rem = 0;
    int cor_count,inc_count;
private slots:
    void choose_mode();
    void repeat_mode();
    void but1();
    void but2();
    void but3();
    void but4();
    bool check_state();
    void updateTime();
    void remember_mode();
    void check_ans();
    void mark_correct_answer();
private:
    QTimer *tmr = new QTimer(this);
    QTimer *rem_tmr = new QTimer(this);
    QTime time_;
    bool flag = false;
    QPushButton *start_button = new QPushButton("Старт",this);
    QRadioButton *repeat = new QRadioButton("Заучивание",this);
    QRadioButton *remember = new QRadioButton("Повторение",this);
    QPushButton *answerBut1 = new QPushButton("",this);
    QPushButton *answerBut2 = new QPushButton("",this);
    QPushButton *answerBut3 = new QPushButton("",this);
    QPushButton *answerBut4 = new QPushButton("",this);
    QLabel *label_ans = new QLabel("s",this);
    QLabel *label = new QLabel("Answer:",this);
    QLabel *label_rus = new QLabel("",this);
    QLabel *label_correct = new QLabel("",this);
    QLabel *label_incorrect = new QLabel("",this);

};

#endif // GETGRAMMAR_MAIN_H
