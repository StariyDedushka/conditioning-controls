/**
 * @file Файл с описанием структур, используемых в пределах приложения
 * */
#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QMetaType>

/**
     * @brief enum систем счисления температуры
     * @details Используется для упрощения обозначения используемых систем счисления температуры в пределах программы
     */
    enum tempMode {
        celsius,
        fahrenheit,
        kelvin
    };
/**
     * @brief enum систем счисления давления
     * @details Используется для упрощения обозначения используемых систем счисления давления в пределах программы
     */
    enum pressureMode {
        pascals,
        millimeters
    };
    /**
     * @brief Используется при загрузке данных из XML файла
     * @details Применяется в XmlOperator и Conditioner
     */

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
