/****************************************************************************
** Meta object code from reading C++ file 'TrainCascade.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XML_Builder/TrainCascade.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TrainCascade.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TrainCascade_t {
    QByteArrayData data[12];
    char stringdata[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TrainCascade_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TrainCascade_t qt_meta_stringdata_TrainCascade = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 15),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 16),
QT_MOC_LITERAL(4, 47, 8),
QT_MOC_LITERAL(5, 56, 12),
QT_MOC_LITERAL(6, 69, 12),
QT_MOC_LITERAL(7, 82, 15),
QT_MOC_LITERAL(8, 98, 17),
QT_MOC_LITERAL(9, 116, 16),
QT_MOC_LITERAL(10, 133, 23),
QT_MOC_LITERAL(11, 157, 13)
    },
    "TrainCascade\0changeInputFile\0\0"
    "changeOutputFile\0changeBG\0changeNumPos\0"
    "changeNumNeg\0changeNumStages\0"
    "changeFeatureType\0changeMinHitRate\0"
    "changeMaxFalseAlarmRate\0startTraining\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrainCascade[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08,
       3,    0,   65,    2, 0x08,
       4,    0,   66,    2, 0x08,
       5,    0,   67,    2, 0x08,
       6,    0,   68,    2, 0x08,
       7,    0,   69,    2, 0x08,
       8,    0,   70,    2, 0x08,
       9,    0,   71,    2, 0x08,
      10,    0,   72,    2, 0x08,
      11,    0,   73,    2, 0x08,

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

       0        // eod
};

void TrainCascade::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrainCascade *_t = static_cast<TrainCascade *>(_o);
        switch (_id) {
        case 0: _t->changeInputFile(); break;
        case 1: _t->changeOutputFile(); break;
        case 2: _t->changeBG(); break;
        case 3: _t->changeNumPos(); break;
        case 4: _t->changeNumNeg(); break;
        case 5: _t->changeNumStages(); break;
        case 6: _t->changeFeatureType(); break;
        case 7: _t->changeMinHitRate(); break;
        case 8: _t->changeMaxFalseAlarmRate(); break;
        case 9: _t->startTraining(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TrainCascade::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TrainCascade.data,
      qt_meta_data_TrainCascade,  qt_static_metacall, 0, 0}
};


const QMetaObject *TrainCascade::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrainCascade::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TrainCascade.stringdata))
        return static_cast<void*>(const_cast< TrainCascade*>(this));
    return QWidget::qt_metacast(_clname);
}

int TrainCascade::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
