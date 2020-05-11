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
    label_rus->setGeometry(QRect(QPoint(150, 30), QSize(100,50)));
    tmr->setInterval(1000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    label_ans->setVisible(false);
    label->setVisible(false);
}


void GetGrammar_main::updateTime(){
    QString s = label_ans->text();

    if(s!="s")
    {
         label_ans->setText("s");

         if(answer == answer_correct) state[k%10][0] += 1;
         else state[k%10][1]+= 1;

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
}
GetGrammar_main::~GetGrammar_main()
{

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
    }
    label_ans->setText("1");
}
void GetGrammar_main::but2(){
    answer = 2;
    if(answer_correct == 2){
        set_color(answerBut2,QColor(0,255,0));
    }else{
        set_color(answerBut2,QColor(255,0,0));
    }
    label_ans->setText("2");
    flag = true;
}
void GetGrammar_main::but3(){
    answer = 3;
    if(answer_correct == 3){
        set_color(answerBut3,QColor(0,255,0));
    }else{
        set_color(answerBut3,QColor(255,0,0));
    }
    label_ans->setText("3");
    flag = true;
}
void GetGrammar_main::but4(){
    answer = 4;
    if(answer_correct == 4){
        set_color(answerBut4,QColor(0,255,0));
    }else{
        set_color(answerBut4,QColor(255,0,0));
    }
    label_ans->setText("4");
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
        if(state[k%10][0] == 2)k++;
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



void GetGrammar_main::repeat_mode(){
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
