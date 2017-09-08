/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[25];
    char stringdata[356];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Widget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 19),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 5),
QT_MOC_LITERAL(4, 34, 19),
QT_MOC_LITERAL(5, 54, 19),
QT_MOC_LITERAL(6, 74, 12),
QT_MOC_LITERAL(7, 87, 12),
QT_MOC_LITERAL(8, 100, 5),
QT_MOC_LITERAL(9, 106, 12),
QT_MOC_LITERAL(10, 119, 12),
QT_MOC_LITERAL(11, 132, 15),
QT_MOC_LITERAL(12, 148, 15),
QT_MOC_LITERAL(13, 164, 15),
QT_MOC_LITERAL(14, 180, 8),
QT_MOC_LITERAL(15, 189, 9),
QT_MOC_LITERAL(16, 199, 8),
QT_MOC_LITERAL(17, 208, 14),
QT_MOC_LITERAL(18, 223, 16),
QT_MOC_LITERAL(19, 240, 16),
QT_MOC_LITERAL(20, 257, 17),
QT_MOC_LITERAL(21, 275, 19),
QT_MOC_LITERAL(22, 295, 20),
QT_MOC_LITERAL(23, 316, 18),
QT_MOC_LITERAL(24, 335, 19)
    },
    "Widget\0xTranslationChanged\0\0value\0"
    "yTranslationChanged\0zTranslationChanged\0"
    "scaleChanged\0setXRotation\0angle\0"
    "setYRotation\0setZRotation\0setXTranslation\0"
    "setYTranslation\0setZTranslation\0"
    "setScale\0loadModel\0filename\0handleUpButton\0"
    "handleDownButton\0handleLeftButton\0"
    "handleRightButton\0handleForwardButton\0"
    "handleBackwardButton\0handleZoomInButton\0"
    "handleZoomOutButton\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06,
       4,    1,  117,    2, 0x06,
       5,    1,  120,    2, 0x06,
       6,    1,  123,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    1,  126,    2, 0x0a,
       9,    1,  129,    2, 0x0a,
      10,    1,  132,    2, 0x0a,
      11,    1,  135,    2, 0x0a,
      12,    1,  138,    2, 0x0a,
      13,    1,  141,    2, 0x0a,
      14,    1,  144,    2, 0x0a,
      15,    1,  147,    2, 0x0a,
      17,    0,  150,    2, 0x08,
      18,    0,  151,    2, 0x08,
      19,    0,  152,    2, 0x08,
      20,    0,  153,    2, 0x08,
      21,    0,  154,    2, 0x08,
      22,    0,  155,    2, 0x08,
      23,    0,  156,    2, 0x08,
      24,    0,  157,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,   16,
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

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        switch (_id) {
        case 0: _t->xTranslationChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->yTranslationChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->zTranslationChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->scaleChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->setXRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setYRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setZRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setXTranslation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setYTranslation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setZTranslation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->setScale((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->loadModel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->handleUpButton(); break;
        case 13: _t->handleDownButton(); break;
        case 14: _t->handleLeftButton(); break;
        case 15: _t->handleRightButton(); break;
        case 16: _t->handleForwardButton(); break;
        case 17: _t->handleBackwardButton(); break;
        case 18: _t->handleZoomInButton(); break;
        case 19: _t->handleZoomOutButton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Widget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget::xTranslationChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Widget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget::yTranslationChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Widget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget::zTranslationChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (Widget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget::scaleChanged)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, 0, 0}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void Widget::xTranslationChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::yTranslationChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Widget::zTranslationChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Widget::scaleChanged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
