/****************************************************************************
** Meta object code from reading C++ file 'serverworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../ChatServer/serverworker.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSServerWorkerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSServerWorkerENDCLASS = QtMocHelpers::stringData(
    "ServerWorker",
    "logMessage",
    "",
    "msg",
    "jsonReceived",
    "ServerWorker*",
    "sender",
    "docObj",
    "onReadyRead",
    "sendMessage",
    "text",
    "type",
    "sendJson",
    "json"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSServerWorkerENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[13];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[13];
    char stringdata5[14];
    char stringdata6[7];
    char stringdata7[7];
    char stringdata8[12];
    char stringdata9[12];
    char stringdata10[5];
    char stringdata11[5];
    char stringdata12[9];
    char stringdata13[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSServerWorkerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSServerWorkerENDCLASS_t qt_meta_stringdata_CLASSServerWorkerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "ServerWorker"
        QT_MOC_LITERAL(13, 10),  // "logMessage"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 3),  // "msg"
        QT_MOC_LITERAL(29, 12),  // "jsonReceived"
        QT_MOC_LITERAL(42, 13),  // "ServerWorker*"
        QT_MOC_LITERAL(56, 6),  // "sender"
        QT_MOC_LITERAL(63, 6),  // "docObj"
        QT_MOC_LITERAL(70, 11),  // "onReadyRead"
        QT_MOC_LITERAL(82, 11),  // "sendMessage"
        QT_MOC_LITERAL(94, 4),  // "text"
        QT_MOC_LITERAL(99, 4),  // "type"
        QT_MOC_LITERAL(104, 8),  // "sendJson"
        QT_MOC_LITERAL(113, 4)   // "json"
    },
    "ServerWorker",
    "logMessage",
    "",
    "msg",
    "jsonReceived",
    "ServerWorker*",
    "sender",
    "docObj",
    "onReadyRead",
    "sendMessage",
    "text",
    "type",
    "sendJson",
    "json"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSServerWorkerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       4,    2,   53,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   58,    2, 0x0a,    6 /* Public */,
       9,    2,   59,    2, 0x0a,    7 /* Public */,
       9,    1,   64,    2, 0x2a,   10 /* Public | MethodCloned */,
      12,    1,   67,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QJsonObject,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QJsonObject,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject ServerWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSServerWorkerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSServerWorkerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSServerWorkerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ServerWorker, std::true_type>,
        // method 'logMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'jsonReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ServerWorker *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'onReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sendMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sendJson'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>
    >,
    nullptr
} };

void ServerWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->jsonReceived((*reinterpret_cast< std::add_pointer_t<ServerWorker*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 2: _t->onReadyRead(); break;
        case 3: _t->sendMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->sendMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->sendJson((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ServerWorker* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ServerWorker::*)(const QString & );
            if (_t _q_method = &ServerWorker::logMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ServerWorker::*)(ServerWorker * , const QJsonObject & );
            if (_t _q_method = &ServerWorker::jsonReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *ServerWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSServerWorkerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ServerWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ServerWorker::logMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServerWorker::jsonReceived(ServerWorker * _t1, const QJsonObject & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
