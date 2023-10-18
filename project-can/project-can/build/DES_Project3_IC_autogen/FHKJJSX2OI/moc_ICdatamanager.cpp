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
    char stringdata0[203];
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
QT_MOC_LITERAL(3, 26, 12), // "speedChanged"
QT_MOC_LITERAL(4, 39, 11), // "gearChanged"
QT_MOC_LITERAL(5, 51, 14), // "currentChanged"
QT_MOC_LITERAL(6, 66, 23), // "powerConsumptionChanged"
QT_MOC_LITERAL(7, 90, 14), // "voltageChanged"
QT_MOC_LITERAL(8, 105, 19), // "batteryLevelChanged"
QT_MOC_LITERAL(9, 125, 3), // "rpm"
QT_MOC_LITERAL(10, 129, 8), // "uint32_t"
QT_MOC_LITERAL(11, 138, 5), // "speed"
QT_MOC_LITERAL(12, 144, 4), // "gear"
QT_MOC_LITERAL(13, 149, 7), // "current"
QT_MOC_LITERAL(14, 157, 16), // "powerConsumption"
QT_MOC_LITERAL(15, 174, 7), // "uint8_t"
QT_MOC_LITERAL(16, 182, 7), // "voltage"
QT_MOC_LITERAL(17, 190, 12) // "batteryLevel"

    },
    "ICdatamanager\0rpmChanged\0\0speedChanged\0"
    "gearChanged\0currentChanged\0"
    "powerConsumptionChanged\0voltageChanged\0"
    "batteryLevelChanged\0rpm\0uint32_t\0speed\0"
    "gear\0current\0powerConsumption\0uint8_t\0"
    "voltage\0batteryLevel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ICdatamanager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       7,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,
       8,    0,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       9, 0x80000000 | 10, 0x0049510b,
      11, 0x80000000 | 10, 0x0049510b,
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::Float, 0x00495103,
      14, 0x80000000 | 15, 0x0049510b,
      16, QMetaType::Float, 0x00495103,
      17, 0x80000000 | 15, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,

       0        // eod
};

void ICdatamanager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ICdatamanager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rpmChanged(); break;
        case 1: _t->speedChanged(); break;
        case 2: _t->gearChanged(); break;
        case 3: _t->currentChanged(); break;
        case 4: _t->powerConsumptionChanged(); break;
        case 5: _t->voltageChanged(); break;
        case 6: _t->batteryLevelChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ICdatamanager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::rpmChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::speedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::gearChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::currentChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::powerConsumptionChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::voltageChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ICdatamanager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ICdatamanager::batteryLevelChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ICdatamanager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint32_t*>(_v) = _t->getRpm(); break;
        case 1: *reinterpret_cast< uint32_t*>(_v) = _t->getSpeed(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getGear(); break;
        case 3: *reinterpret_cast< float*>(_v) = _t->getCurrent(); break;
        case 4: *reinterpret_cast< uint8_t*>(_v) = _t->getPowerConsumption(); break;
        case 5: *reinterpret_cast< float*>(_v) = _t->getVoltage(); break;
        case 6: *reinterpret_cast< uint8_t*>(_v) = _t->getBatteryLevel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ICdatamanager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRpm(*reinterpret_cast< uint32_t*>(_v)); break;
        case 1: _t->setSpeed(*reinterpret_cast< uint32_t*>(_v)); break;
        case 2: _t->setGear(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setCurrent(*reinterpret_cast< float*>(_v)); break;
        case 4: _t->setPowerConsumption(*reinterpret_cast< uint8_t*>(_v)); break;
        case 5: _t->setVoltage(*reinterpret_cast< float*>(_v)); break;
        case 6: _t->setBatteryLevel(*reinterpret_cast< uint8_t*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_a;
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ICdatamanager::rpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ICdatamanager::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ICdatamanager::gearChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ICdatamanager::currentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ICdatamanager::powerConsumptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ICdatamanager::voltageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ICdatamanager::batteryLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
