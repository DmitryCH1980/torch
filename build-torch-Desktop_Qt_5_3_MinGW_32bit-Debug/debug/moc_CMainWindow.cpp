/****************************************************************************
** Meta object code from reading C++ file 'CMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../torch/CMainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CMainWindow_t {
    QByteArrayData data[15];
    char stringdata[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMainWindow_t qt_meta_stringdata_CMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 10),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 17),
QT_MOC_LITERAL(4, 42, 15),
QT_MOC_LITERAL(5, 58, 9),
QT_MOC_LITERAL(6, 68, 6),
QT_MOC_LITERAL(7, 75, 10),
QT_MOC_LITERAL(8, 86, 7),
QT_MOC_LITERAL(9, 94, 7),
QT_MOC_LITERAL(10, 102, 11),
QT_MOC_LITERAL(11, 114, 5),
QT_MOC_LITERAL(12, 120, 6),
QT_MOC_LITERAL(13, 127, 8),
QT_MOC_LITERAL(14, 136, 6)
    },
    "CMainWindow\0SendRedraw\0\0SendThreadCommand\0"
    "OnCommandServer\0uiCommand\0sColor\0"
    "OnRunTorch\0OnClose\0OnSetup\0OnTakeSetup\0"
    "sHost\0uiPort\0OnResult\0result"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    3,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   69,    2, 0x0a /* Public */,
       4,    1,   74,    2, 0x2a /* Public | MethodCloned */,
       7,    0,   77,    2, 0x0a /* Public */,
       8,    0,   78,    2, 0x0a /* Public */,
       9,    0,   79,    2, 0x0a /* Public */,
      10,    2,   80,    2, 0x0a /* Public */,
      13,    1,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::UShort, QMetaType::QString, QMetaType::UShort,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::UShort,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   11,   12,
    QMetaType::Void, QMetaType::UShort,   14,

       0        // eod
};

void CMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMainWindow *_t = static_cast<CMainWindow *>(_o);
        switch (_id) {
        case 0: _t->SendRedraw((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SendThreadCommand((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 2: _t->OnCommandServer((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->OnCommandServer((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 4: _t->OnRunTorch(); break;
        case 5: _t->OnClose(); break;
        case 6: _t->OnSetup(); break;
        case 7: _t->OnTakeSetup((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 8: _t->OnResult((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CMainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMainWindow::SendRedraw)) {
                *result = 0;
            }
        }
        {
            typedef void (CMainWindow::*_t)(quint16 , QString , quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CMainWindow::SendThreadCommand)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CMainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CMainWindow.data,
      qt_meta_data_CMainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *CMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CMainWindow.stringdata))
        return static_cast<void*>(const_cast< CMainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int CMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CMainWindow::SendRedraw(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CMainWindow::SendThreadCommand(quint16 _t1, QString _t2, quint16 _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
