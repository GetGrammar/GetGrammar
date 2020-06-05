#include "getgrammar_main.h"
#include "Grammar_logic_lib.h"


GetGrammar_main::GetGrammar_main(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("GetGrammar");
    resize(400, 400);
    start_button->setGeometry(QRect(QPoint(100, 300), QSize(200, 50)));
    answerBut1->setGeometry(QRect(QPoint(60, 130), QSize(110, 50)));
    answerBut2->setGeometry(QRect(QPoint(230, 130), QSize(110,50)));
    answerBut3->setGeometry(QRect(QPoint(60, 200), QSize(110,50)));
    answerBut4->setGeometry(QRect(QPoint(230, 200), QSize(110,50)));
    set_color(answerBut1,QColor(0,0,255));
    set_color(answerBut2,QColor(0,0,255));
    set_color(answerBut3,QColor(0,0,255));
    set_color(answerBut4,QColor(0,0,255));
    connect( start_button, SIGNAL(clicked()), this, SLOT(choose_mode()) );
    repeat->setGeometry(QRect(QPoint(60, 70), QSize(110,50)));
    repeat->setChecked(true);
    remember->setGeometry(QRect(QPoint(230, 70), QSize(110,50)));
    label->setGeometry(QRect(QPoint(10, 40), QSize(200,50)));
    label_rus->setGeometry(QRect(QPoint(150, 30), QSize(200,50)));
    tmr->setInterval(1000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    label_ans->setVisible(false);
    label->setVisible(false);
    label_correct->setGeometry(QRect(QPoint(60, 0), QSize(150, 50)));
    label_incorrect->setGeometry(QRect(QPoint(230, 0), QSize(150, 50)));
}

void GetGrammar_main::check_ans(){
    fill_labels(answer == answer_correct);

    if(mode == 1){
        if(answer == answer_correct)
         state[k%10][0] += 1;
         else state[k%10][1]+= 1;
    }
    //answer = 0;

}


void GetGrammar_main::updateTime(){
    if(answer!=0)
    {
        check_ans();
        answer = 0;
        if(mode == 1){
        if(check_state())repeat_rec(state,correct_rus,correct_eng,incorrect);
        else{
            tmr->stop();
            label_rus->setText("Успешно");
            mode = 0;
            start_button->setText("Старт");
            set_color(answerBut1,QColor(0,0,255));
            set_color(answerBut2,QColor(0,0,255));
            set_color(answerBut3,QColor(0,0,255));
            set_color(answerBut4,QColor(0,0,255));
            answerBut1->setText("");
            answerBut2->setText("");
            answerBut3->setText("");
            answerBut4->setText("");
            }
        }
        else rem_rec(n_rem);
    }

}


GetGrammar_main::~GetGrammar_main()
{

}

void GetGrammar_main::fill_labels(bool ans){
    string s;
    if(ans){
        s = "Верно : ";
        cor_count++;
        s = s + to_string(cor_count);
        label_correct->setText(str_to_char(s));
    }
    else{
        s = "Неверно : ";
        inc_count++;
        s = s + to_string(inc_count);
        label_incorrect->setText(str_to_char(s));
    }

}

void GetGrammar_main::mark_correct_answer(){
    if(answer_correct == 1)set_color(answerBut1,QColor(0,255,0));
    if(answer_correct == 2)set_color(answerBut2,QColor(0,255,0));
    if(answer_correct == 3)set_color(answerBut3,QColor(0,255,0));
    if(answer_correct == 4)set_color(answerBut4,QColor(0,255,0));
}

bool GetGrammar_main::check_state(){
    int g = 1;
    for(int i = 0; i < 10; ++i){
        if(state[i][0] == 2) g*=1;
        else g*=0;
    }
    if(g == 0) return true;
    else return false;
}

void GetGrammar_main::but1(){
    answer = 1;
    if(answer_correct == 1){
        set_color(answerBut1,QColor(0,255,0));
    }else{
        set_color(answerBut1,QColor(255,0,0));
        mark_correct_answer();
    }


}
void GetGrammar_main::but2(){
    answer = 2;
    if(answer_correct == 2){
        set_color(answerBut2,QColor(0,255,0));
    }else{
        set_color(answerBut2,QColor(255,0,0));
        mark_correct_answer();
    }

}
void GetGrammar_main::but3(){
    answer = 3;
    if(answer_correct == 3){
        set_color(answerBut3,QColor(0,255,0));
    }else{
        set_color(answerBut3,QColor(255,0,0));
        mark_correct_answer();
    }

}
void GetGrammar_main::but4(){
    answer = 4;
    if(answer_correct == 4){
        set_color(answerBut4,QColor(0,255,0));
    }else{
        set_color(answerBut4,QColor(255,0,0));
        mark_correct_answer();
    }

}







void GetGrammar_main::repeat_rec(int (&state)[10][2], string correct_rus[], string correct_eng[], string incorrect[]){
    srand(time(0));

    set_color(answerBut1,QColor(0,0,255));
    set_color(answerBut2,QColor(0,0,255));
    set_color(answerBut3,QColor(0,0,255));
    set_color(answerBut4,QColor(0,0,255));

    answer_correct = rand()%4 + 1;
    int incorrect_pos = rand()%28 + 2;
    k++;
    while(true){
        if(state[k%10][0] == 2){
            k++;
            rem(correct_rus[k%10],correct_eng[k%10]);
        }
        else break;
    }
    label_rus->setText(str_to_char(correct_rus[k%10]));
    switch (answer_correct){
        case 1:
            answerBut1->setText(str_to_char(correct_eng[k%10]));
            answerBut2->setText(str_to_char(incorrect[incorrect_pos]));
            answerBut3->setText(str_to_char(incorrect[incorrect_pos - 1]));
            answerBut4->setText(str_to_char(incorrect[incorrect_pos - 2]));
            break;
        case 2:
            answerBut2->setText(str_to_char(correct_eng[k%10]));
            answerBut1->setText(str_to_char(incorrect[incorrect_pos]));
            answerBut3->setText(str_to_char(incorrect[incorrect_pos - 1]));
            answerBut4->setText(str_to_char(incorrect[incorrect_pos - 2]));
            break;
        case 3:
            answerBut3->setText(str_to_char(correct_eng[k%10]));
            answerBut2->setText(str_to_char(incorrect[incorrect_pos]));
            answerBut1->setText(str_to_char(incorrect[incorrect_pos - 1]));
            answerBut4->setText(str_to_char(incorrect[incorrect_pos - 2]));
            break;
        case 4:
            answerBut4->setText(str_to_char(correct_eng[k%10]));
            answerBut2->setText(str_to_char(incorrect[incorrect_pos]));
            answerBut3->setText(str_to_char(incorrect[incorrect_pos - 1]));
            answerBut1->setText(str_to_char(incorrect[incorrect_pos - 2]));
            break;
    }

    connect( answerBut1, SIGNAL(clicked()), this, SLOT(but1()));
    connect( answerBut2, SIGNAL(clicked()), this, SLOT(but2()));
    connect( answerBut3, SIGNAL(clicked()), this, SLOT(but3()));
    connect( answerBut4, SIGNAL(clicked()), this, SLOT(but4()));

}

void GetGrammar_main::rem_rec(int n){

    srand(time(0));
    string correct_rus,correct_eng;
    int rnd_correct = rand()%n;
    answer_correct = rand()%4 + 1;
    correct_rus = find_word(rnd_correct,0);
    correct_eng = find_word(rnd_correct,1);
    get_rem_mass(rem_mas_inc,n,3,rnd_correct);
    //cout << rnd_correct << " " <<  rem_mas_inc[0]<< " " << rem_mas_inc[1]  <<  " "<< rem_mas_inc[2];
    rem_inc[0] = find_word(rem_mas_inc[0],1);
    rem_inc[1] = find_word(rem_mas_inc[1],1);
    rem_inc[2] = find_word(rem_mas_inc[2],1);
    set_color(answerBut1,QColor(0,0,255));
    set_color(answerBut2,QColor(0,0,255));
    set_color(answerBut3,QColor(0,0,255));
    set_color(answerBut4,QColor(0,0,255));
    label_rus->setText(str_to_char(correct_rus));
    switch (answer_correct){
        case 1:
            answerBut1->setText(str_to_char(correct_eng));
            answerBut2->setText(str_to_char(rem_inc[2]));
            answerBut3->setText(str_to_char(rem_inc[1]));
            answerBut4->setText(str_to_char(rem_inc[0]));
            break;
        case 2:
            answerBut2->setText(str_to_char(correct_eng));
            answerBut1->setText(str_to_char(rem_inc[2]));
            answerBut3->setText(str_to_char(rem_inc[1]));
            answerBut4->setText(str_to_char(rem_inc[0]));
            break;
        case 3:
            answerBut3->setText(str_to_char(correct_eng));
            answerBut2->setText(str_to_char(rem_inc[2]));
            answerBut1->setText(str_to_char(rem_inc[1]));
            answerBut4->setText(str_to_char(rem_inc[0]));
            break;
        case 4:
            answerBut4->setText(str_to_char(correct_eng));
            answerBut2->setText(str_to_char(rem_inc[2]));
            answerBut3->setText(str_to_char(rem_inc[1]));
            answerBut1->setText(str_to_char(rem_inc[0]));
            break;
    }

    connect( answerBut1, SIGNAL(clicked()), this, SLOT(but1()));
    connect( answerBut2, SIGNAL(clicked()), this, SLOT(but2()));
    connect( answerBut3, SIGNAL(clicked()), this, SLOT(but3()));
    connect( answerBut4, SIGNAL(clicked()), this, SLOT(but4()));

}

void GetGrammar_main::remember_mode(){
    tmr->start();
    label_incorrect->setText("Неверно : ");
    label_correct->setText("Верно : ");
    cor_count = 0;
    inc_count = 0;
    rem_tmr->start();
    srand(time(0));
    n_rem = 0;
    string a;
    ifstream check;
    check.open("dictionaries/rem_rus.txt",ios_base::in);
    while(getline(check,a))
        n_rem++;
    check.close();
    rem_rec(n_rem);
}

void GetGrammar_main::repeat_mode(){
    label_incorrect->setText("Неверно : ");
    label_correct->setText("Верно : ");
    cor_count = 0;
    inc_count = 0;
    tmr->start();
    srand(time(0));
    k = -1;
    answer_correct = rand()%4 + 1;
    ifstream in;
    in.open("dictionaries/rus.txt");
    string a;
    int n = 0;
    while (getline(in, a)) {
        n++;
    }
    in.close();
    for(int i = 0; i < 10; ++i){
            state[i][0] = 0;
                state[i][1] = 0;
            }
    get_correct_words_for_first_mode(mas,correct_rus,correct_eng,10,n);
    get_incorrect_words_for_first_mode(mas,mas_inc,incorrect,10,30,n);

    repeat_rec(state,correct_rus,correct_eng,incorrect);


}

void GetGrammar_main::choose_mode(){
    start_button->setText("Стоп");
    if(mode == 0){
    if(repeat->isChecked() == true){
        mode = 1;
        repeat_mode();
    }
    else{
        mode = 2;
        remember_mode();
    }
    }
    else{
        mode = 0;
        tmr->stop();
        start_button->setText("Старт");
        set_color(answerBut1,QColor(0,0,255));
        set_color(answerBut2,QColor(0,0,255));
        set_color(answerBut3,QColor(0,0,255));
        set_color(answerBut4,QColor(0,0,255));
        answerBut1->setText("");
        answerBut2->setText("");
        answerBut3->setText("");
        answerBut4->setText("");
        label_rus->setText("");
    }
}

void set_color(QPushButton *but, QColor b){
    QPalette myPalette = but->palette();
    myPalette.setColor( but->backgroundRole(), b );
    but->setPalette( myPalette );
}
