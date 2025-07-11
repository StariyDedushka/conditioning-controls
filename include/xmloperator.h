#ifndef XMLOPERATOR_H
#define XMLOPERATOR_H

#include <QObject>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include "include/structs.h"
#include <QDebug>

class XmlOperator : public QObject
{
    Q_OBJECT

public:
    XmlOperator();
    ~XmlOperator();

private:
    QString savePath;
    tempMode temp;
    pressureMode press;
public:
    /**
     * @brief Запись файла XML с настройками программы
     * @param savePath Путь сохранения настроек
     * @param _tempMode Система счисления температуры, установленная в программе
     * @param _pressMode Система счисления давления, установленная в программе
     * @param direction Направление подачи воздуха, установленное в программе
     */
    void writeXml(QString savePath, tempMode _tempMode, pressureMode _pressMode, quint32 direction);

    /**
     * @brief Читает XML файл с настройками
     * @return Возвращает структуру info со всеми сохраненными в файле данными
     */
    info readXml();
};

#endif // XMLOPERATOR_H
