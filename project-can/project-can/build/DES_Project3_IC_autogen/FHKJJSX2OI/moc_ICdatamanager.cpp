/****************************************************************************
** Meta object code from reading C++ file 'ICdatamanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/DES_Project3_IC/ICdatamanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ICdatamanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ICdatamanager_t {
    QByteArrayData data[18];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ICdatamanager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ICdatamanager_t qt_meta_stringdata_ICdatamanager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ICdatamanager"
QT_MOC_LITERAL(1, 14, 10), // "rpmChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "uint32_t"
QT_MOC_LITERAL(4, 35, 3), // "rpm"
QT_MOC_LITERAL(5, 39, 12), // "speedChanged"
QT_MOC_LITERAL(6, 52, 5), // "speed"
QT_MOC_LITERAL(7, 58, 11), // "gearChanged"
QT_MOC_LITERAL(8, 70, 4), // "gear"
QT_MOC_LITERAL(9, 75, 14), // "currentChanged"
QT_MOC_LITERAL(10, 90, 7), // "current"
QT_MOC_LITERAL(11, 98, 23), // "powerConsumptionChanged"
QT_MOC_LITERAL(12, 122, 16), // "powerConsumption"
QT_MOC_LITERAL(13, 139, 14), // "voltageChanged"
QT_MOC_LITERAL(14, 154, 7), // "voltage"
QT_MOC_LITERAL(15, 162, 14), // "batteryChanged"
QT_MOC_LITERAL(16, 177, 7), // "uint8_t"
QT_MOC_LITERAL(17, 185, 7) // "battery"

    },
    "ICdatamanager\0rpmChanged\0\0uint32_t\0"
    "rpm\0speedChanged\0speed\0gearChanged\0"
    "gear\0currentChanged\0current\0"
    "powerConsumptionChanged\0powerConsumption\0"
    "voltageChanged\0voltage\0batteryChanged\0"
    "uint8_t\0battery"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ICdatamanager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,
       7,    1,   55,    2, 0x06 /* Public */,
       9,    1,   58,    2, 0x06 /* Public */,
      11,    1,   61,    2, 0x06 /* Public */,
      13,    1,   64,    2, 0x06 /* Public */,
      15,    1,   67,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Float,   10,
    QMetaType::Void, QMetaType::Float,   12,
    QMetaType::Void, QMetaType::Float,   14,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void ICdatamanager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ICdatamanager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rpmChanged((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 1: _t->speedChanged((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 2: _t->gearChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->currentChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->powerConsumptionChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->voltageChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->batteryChanged((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ICdatamanager::*)(uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::rpmChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)(uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::speedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::gearChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::currentChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::powerConsumptionChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::voltageChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)(uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::batteryChanged)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ICdatamanager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ICdatamanager.data,
    qt_meta_data_ICdatamanager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ICdatamanager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ICdatamanager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ICdatamanager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ICdatamanager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ICdatamanager::rpmChanged(uint32_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ICdatamanager::speedChanged(uint32_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ICdatamanager::gearChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ICdatamanager::currentChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ICdatamanager::powerConsumptionChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ICdatamanager::voltageChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ICdatamanager::batteryChanged(uint8_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
