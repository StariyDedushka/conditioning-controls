#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QMetaType>

    enum tempMode {
        celsius,
        fahrenheit,
        kelvin
    };
    enum pressureMode {
        pascals,
        millimeters
    };

    struct info{
        QString savePath;
        tempMode _tempMode;
        pressureMode _pressMode;
        quint32 direction;
    };

    Q_DECLARE_METATYPE(tempMode)
    Q_DECLARE_METATYPE(pressureMode)
    Q_DECLARE_METATYPE(info)

#endif // STRUCTS_H
