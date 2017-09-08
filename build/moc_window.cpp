/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyWindow_t {
    QByteArrayData data[17];
    char stringdata[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MyWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MyWindow_t qt_meta_stringdata_MyWindow = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 12),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 8),
QT_MOC_LITERAL(4, 32, 15),
QT_MOC_LITERAL(5, 48, 5),
QT_MOC_LITERAL(6, 54, 15),
QT_MOC_LITERAL(7, 70, 15),
QT_MOC_LITERAL(8, 86, 8),
QT_MOC_LITERAL(9, 95, 16),
QT_MOC_LITERAL(10, 112, 16),
QT_MOC_LITERAL(11, 129, 16),
QT_MOC_LITERAL(12, 146, 12),
QT_MOC_LITERAL(13, 159, 5),
QT_MOC_LITERAL(14, 165, 12),
QT_MOC_LITERAL(15, 178, 12),
QT_MOC_LITERAL(16, 191, 18)
    },
    "MyWindow\0openOBJFiles\0\0filename\0"
    "setXTranslation\0value\0setYTranslation\0"
    "setZTranslation\0setScale\0xRotationChanged\0"
    "yRotationChanged\0zRotationChanged\0"
    "setXRotation\0angle\0setYRotation\0"
    "setZRotation\0openOBJFilesDialog\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,   77,    2, 0x0a,
       6,    1,   80,    2, 0x0a,
       7,    1,   83,    2, 0x0a,
       8,    1,   86,    2, 0x0a,
       9,    1,   89,    2, 0x08,
      10,    1,   92,    2, 0x08,
      11,    1,   95,    2, 0x08,
      12,    1,   98,    2, 0x08,
      14,    1,  101,    2, 0x08,
      15,    1,  104,    2, 0x08,
      16,    0,  107,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void MyWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyWindow *_t = static_cast<MyWindow *>(_o);
        switch (_id) {
        case 0: _t->openOBJFiles((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setXTranslation((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->setYTranslation((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->setZTranslation((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->setScale((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->xRotationChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->yRotationChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->zRotationChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setXRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setYRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setZRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->openOBJFilesDialog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyWindow::openOBJFiles)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MyWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyWindow.data,
      qt_meta_data_MyWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWindow.stringdata))
        return static_cast<void*>(const_cast< MyWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MyWindow::openOBJFiles(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
