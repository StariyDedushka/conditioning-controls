#include "include/xmloperator.h"

XmlOperator::XmlOperator()
{
}

XmlOperator::~XmlOperator()
{
}

struct info XmlOperator::readXml()
{
    QFile *openFile = new QFile("../../settings.xml");
    info data;

    if(openFile->open(QIODevice::ReadOnly))
    {
        QXmlStreamReader xmlReader(openFile);

        while(!xmlReader.atEnd())
        {
            QXmlStreamReader::TokenType token = xmlReader.readNext();

            if(token == QXmlStreamReader::StartDocument) continue;
            if(token == QXmlStreamReader::StartElement)
            {
                const QString elementName = xmlReader.name().toString();
                // qDebug() << "Element:" << elementName;

                if(elementName == "Data") continue;

                if(xmlReader.readNext() == QXmlStreamReader::Characters)
                {
                    const QString text = xmlReader.text().toString();
                    if(elementName == "temperatureMode")
                        data._tempMode = static_cast<tempMode>(text.toInt());
                    if(elementName == "pressureMode")
                        data._pressMode = static_cast<pressureMode>(text.toInt());
                    if(elementName == "direction")
                        data.direction = text.toInt();

                    // qDebug() << "TempMode: " << data._tempMode;
                    // qDebug() << "PressureMode:" << data._pressMode;
                    // qDebug() << "Temperature:" << data.temperature;

                }
                // for(const QXmlStreamAttribute &attr : xmlReader.attributes())
                // {
                //     const QString attrName = attr.name().toString();
                // }

            }
        }
    }
    openFile->close();
    return data;
}


void XmlOperator::writeXml(QString savePath, tempMode _tempMode, pressureMode _pressMode, quint32 direction)
{
    QString fullFileName = QString("../..%1%2").arg(savePath).arg("settings.xml");
    QFile *writeFile = new QFile(fullFileName);
    qDebug() << "File saved path:" << fullFileName;

    if(writeFile->open(QIODevice::WriteOnly))
        {
        QXmlStreamWriter xmlWriter(writeFile);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();

        xmlWriter.writeStartElement("Data");

        xmlWriter.writeStartElement("temperatureMode");
        xmlWriter.writeAttribute("type", "tempMode");
        xmlWriter.writeCharacters(QString::number(_tempMode));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("pressureMode");
        xmlWriter.writeAttribute("type", "pressureMode");
        xmlWriter.writeCharacters(QString::number(_pressMode));
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("direction");
        xmlWriter.writeAttribute("type", "quint32");
        xmlWriter.writeCharacters(QString::number(direction));
        xmlWriter.writeEndElement();

        writeFile->close();

        }
}
