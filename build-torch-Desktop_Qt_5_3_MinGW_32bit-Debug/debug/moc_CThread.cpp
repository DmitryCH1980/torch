/****************************************************************************
** Meta object code from reading C++ file 'CThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../torch/CThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CThread_t {
    QByteArrayData data[15];
    char stringdata[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CThread_t qt_meta_stringdata_CThread = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 8),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 10),
QT_MOC_LITERAL(4, 29, 17),
QT_MOC_LITERAL(5, 47, 13),
QT_MOC_LITERAL(6, 61, 4),
QT_MOC_LITERAL(7, 66, 6),
QT_MOC_LITERAL(8, 73, 17),
QT_MOC_LITERAL(9, 91, 8),
QT_MOC_LITERAL(10, 100, 9),
QT_MOC_LITERAL(11, 110, 6),
QT_MOC_LITERAL(12, 117, 11),
QT_MOC_LITERAL(13, 129, 13),
QT_MOC_LITERAL(14, 143, 4)
    },
    "CThread\0SendStop\0\0SendResult\0"
    "SendServerCommand\0NewConnection\0sURL\0"
    "uiPort\0CommandConnection\0bCommand\0"
    "DelSocket\0OnRead\0OnConnected\0OnSocketError\0"
    "quit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,
       4,    2,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   83,    2, 0x0a /* Public */,
       8,    3,   88,    2, 0x0a /* Public */,
       8,    2,   95,    2, 0x2a /* Public | MethodCloned */,
       8,    1,  100,    2, 0x2a /* Public | MethodCloned */,
      10,    0,  103,    2, 0x0a /* Public */,
      11,    0,  104,    2, 0x0a /* Public */,
      12,    0,  105,    2, 0x0a /* Public */,
      13,    0,  106,    2, 0x0a /* Public */,
      14,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    6,    7,
    QMetaType::Void, QMetaType::UShort, QMetaType::QString, QMetaType::UShort,    9,    6,    7,
    QMetaType::Void, QMetaType::UShort, QMetaType::QString,    9,    6,
    QMetaType::Void, QMetaType::UShort,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CThread *_t = static_cast<CThread *>(_o);
        switch (_id) {
        case 0: _t->SendStop(); break;
        case 1: _t->SendResult((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 2: _t->SendServerCommand((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->NewConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 4: _t->CommandConnection((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 5: _t->CommandConnection((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->CommandConnection((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 7: _t->DelSocket(); break;
        case 8: _t->OnRead(); break;
        case 9: _t->OnConnected(); break;
        case 10: _t->OnSocketError(); break;
        case 11: _t->quit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CThread::SendStop)) {
                *result = 0;
            }
        }
        {
            typedef void (CThread::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CThread::SendResult)) {
                *result = 1;
            }
        }
        {
            typedef void (CThread::*_t)(quint16 , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CThread::SendServerCommand)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CThread.data,
      qt_meta_data_CThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *CThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CThread.stringdata))
        return static_cast<void*>(const_cast< CThread*>(this));
    return QThread::qt_metacast(_clname);
}

int CThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void CThread::SendStop()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CThread::SendResult(quint16 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CThread::SendServerCommand(quint16 _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
