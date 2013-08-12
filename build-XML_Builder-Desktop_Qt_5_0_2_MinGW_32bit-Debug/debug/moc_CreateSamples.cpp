/****************************************************************************
** Meta object code from reading C++ file 'CreateSamples.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XML_Builder/CreateSamples.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateSamples.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateSamples_t {
    QByteArrayData data[7];
    char stringdata[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CreateSamples_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CreateSamples_t qt_meta_stringdata_CreateSamples = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 15),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 16),
QT_MOC_LITERAL(4, 48, 7),
QT_MOC_LITERAL(5, 56, 7),
QT_MOC_LITERAL(6, 64, 18)
    },
    "CreateSamples\0changeInputFile\0\0"
    "changeOutputFile\0changeW\0changeH\0"
    "startCreateSamples\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateSamples[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08,
       3,    0,   40,    2, 0x08,
       4,    0,   41,    2, 0x08,
       5,    0,   42,    2, 0x08,
       6,    0,   43,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateSamples::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateSamples *_t = static_cast<CreateSamples *>(_o);
        switch (_id) {
        case 0: _t->changeInputFile(); break;
        case 1: _t->changeOutputFile(); break;
        case 2: _t->changeW(); break;
        case 3: _t->changeH(); break;
        case 4: _t->startCreateSamples(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CreateSamples::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CreateSamples.data,
      qt_meta_data_CreateSamples,  qt_static_metacall, 0, 0}
};


const QMetaObject *CreateSamples::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateSamples::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreateSamples.stringdata))
        return static_cast<void*>(const_cast< CreateSamples*>(this));
    return QWidget::qt_metacast(_clname);
}

int CreateSamples::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
