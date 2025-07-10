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
signals:
    // void signal_tempMode(tempMode mode);
    // void signal_pressureMode(pressureMode mode);
    void signal_xml_elementName(const QString &elementName);
    void signal_xml_attribute(const QString &attributeName);
    void signal_xml_text(const QString &xmlText);

public:
    XmlOperator();
    ~XmlOperator();

private:
    QString savePath;
    tempMode temp;
    pressureMode press;
public:
    void writeXml(QString savePath, tempMode _tempMode, pressureMode _pressMode, quint32 direction);
    info readXml();
};

#endif // XMLOPERATOR_H
