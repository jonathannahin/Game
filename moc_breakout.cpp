/****************************************************************************
** Meta object code from reading C++ file 'breakout.h'
**
** Created: Fri Apr 20 02:21:46 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "breakout.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'breakout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Breakout[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x05,
      40,   34,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,    9,    9,    9, 0x0a,
      70,    9,    9,    9, 0x0a,
      82,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Breakout[] = {
    "Breakout\0\0score\0scoreChanged(int)\0"
    "level\0levelChanged(int)\0startGame()\0"
    "pauseGame()\0stopGame()\0"
};

const QMetaObject Breakout::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Breakout,
      qt_meta_data_Breakout, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Breakout::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Breakout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Breakout::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Breakout))
        return static_cast<void*>(const_cast< Breakout*>(this));
    return QWidget::qt_metacast(_clname);
}

int Breakout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: scoreChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: levelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: startGame(); break;
        case 3: pauseGame(); break;
        case 4: stopGame(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Breakout::scoreChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Breakout::levelChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
