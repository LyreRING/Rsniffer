/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[483];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 28), // "on_select_pushButton_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 26), // "on_load_pushButton_clicked"
QT_MOC_LITERAL(4, 68, 26), // "on_save_pushButton_clicked"
QT_MOC_LITERAL(5, 95, 25), // "on_add_pushButton_clicked"
QT_MOC_LITERAL(6, 121, 28), // "on_delete_pushButton_clicked"
QT_MOC_LITERAL(7, 150, 27), // "on_clear_pushButton_clicked"
QT_MOC_LITERAL(8, 178, 27), // "on_apply_pushButton_clicked"
QT_MOC_LITERAL(9, 206, 29), // "on_accept_radioButton_clicked"
QT_MOC_LITERAL(10, 236, 29), // "on_reject_radioButton_clicked"
QT_MOC_LITERAL(11, 266, 30), // "on_flashlog_pushButton_clicked"
QT_MOC_LITERAL(12, 297, 30), // "on_clearlog_pushButton_clicked"
QT_MOC_LITERAL(13, 328, 31), // "on_selectlog_pushButton_clicked"
QT_MOC_LITERAL(14, 360, 29), // "on_loadlog_pushButton_clicked"
QT_MOC_LITERAL(15, 390, 29), // "on_savelog_pushButton_clicked"
QT_MOC_LITERAL(16, 420, 29), // "on_datalog_pushButton_clicked"
QT_MOC_LITERAL(17, 450, 32) // "on_detailslog_pushButton_clicked"

    },
    "MainWindow\0on_select_pushButton_clicked\0"
    "\0on_load_pushButton_clicked\0"
    "on_save_pushButton_clicked\0"
    "on_add_pushButton_clicked\0"
    "on_delete_pushButton_clicked\0"
    "on_clear_pushButton_clicked\0"
    "on_apply_pushButton_clicked\0"
    "on_accept_radioButton_clicked\0"
    "on_reject_radioButton_clicked\0"
    "on_flashlog_pushButton_clicked\0"
    "on_clearlog_pushButton_clicked\0"
    "on_selectlog_pushButton_clicked\0"
    "on_loadlog_pushButton_clicked\0"
    "on_savelog_pushButton_clicked\0"
    "on_datalog_pushButton_clicked\0"
    "on_detailslog_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_select_pushButton_clicked(); break;
        case 1: _t->on_load_pushButton_clicked(); break;
        case 2: _t->on_save_pushButton_clicked(); break;
        case 3: _t->on_add_pushButton_clicked(); break;
        case 4: _t->on_delete_pushButton_clicked(); break;
        case 5: _t->on_clear_pushButton_clicked(); break;
        case 6: _t->on_apply_pushButton_clicked(); break;
        case 7: _t->on_accept_radioButton_clicked(); break;
        case 8: _t->on_reject_radioButton_clicked(); break;
        case 9: _t->on_flashlog_pushButton_clicked(); break;
        case 10: _t->on_clearlog_pushButton_clicked(); break;
        case 11: _t->on_selectlog_pushButton_clicked(); break;
        case 12: _t->on_loadlog_pushButton_clicked(); break;
        case 13: _t->on_savelog_pushButton_clicked(); break;
        case 14: _t->on_datalog_pushButton_clicked(); break;
        case 15: _t->on_detailslog_pushButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
