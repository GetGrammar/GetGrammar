/****************************************************************************
** Meta object code from reading C++ file 'getgrammar_main.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../get_grammar_graph/getgrammar_main.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getgrammar_main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GetGrammar_main_t {
    QByteArrayData data[13];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GetGrammar_main_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GetGrammar_main_t qt_meta_stringdata_GetGrammar_main = {
    {
QT_MOC_LITERAL(0, 0, 15), // "GetGrammar_main"
QT_MOC_LITERAL(1, 16, 11), // "choose_mode"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "repeat_mode"
QT_MOC_LITERAL(4, 41, 4), // "but1"
QT_MOC_LITERAL(5, 46, 4), // "but2"
QT_MOC_LITERAL(6, 51, 4), // "but3"
QT_MOC_LITERAL(7, 56, 4), // "but4"
QT_MOC_LITERAL(8, 61, 11), // "check_state"
QT_MOC_LITERAL(9, 73, 10), // "updateTime"
QT_MOC_LITERAL(10, 84, 13), // "remember_mode"
QT_MOC_LITERAL(11, 98, 9), // "check_ans"
QT_MOC_LITERAL(12, 108, 19) // "mark_correct_answer"

    },
    "GetGrammar_main\0choose_mode\0\0repeat_mode\0"
    "but1\0but2\0but3\0but4\0check_state\0"
    "updateTime\0remember_mode\0check_ans\0"
    "mark_correct_answer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GetGrammar_main[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GetGrammar_main::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GetGrammar_main *_t = static_cast<GetGrammar_main *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->choose_mode(); break;
        case 1: _t->repeat_mode(); break;
        case 2: _t->but1(); break;
        case 3: _t->but2(); break;
        case 4: _t->but3(); break;
        case 5: _t->but4(); break;
        case 6: { bool _r = _t->check_state();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->updateTime(); break;
        case 8: _t->remember_mode(); break;
        case 9: _t->check_ans(); break;
        case 10: _t->mark_correct_answer(); break;
        default: ;
        }
    }
}

const QMetaObject GetGrammar_main::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GetGrammar_main.data,
      qt_meta_data_GetGrammar_main,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GetGrammar_main::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GetGrammar_main::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GetGrammar_main.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GetGrammar_main::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
