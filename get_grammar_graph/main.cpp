#include "getgrammar_main.h"
#include "Grammar_logic_lib.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GetGrammar_main w;
    w.show();

    return a.exec();
}
