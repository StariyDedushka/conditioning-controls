#ifndef CONDITIONER_H
#define CONDITIONER_H

#include <QObject>
#include <QDebug>
#include "xmloperator.h"
#include "include/structs.h"

class Conditioner : public QObject
{
    Q_OBJECT
public:
    Conditioner();
    ~Conditioner();
    void initialize();


public slots:
    void slot_tempMode(qint32 mode1);
    void slot_pressureMode(qint32 mode1);
    void slot_dial_direction_changed(quint32 direction);
    void slot_dial_temperature_changed(qint32 temperature);
    void slot_pressureChanged(quint32 pressure);
    void slot_humidityChanged(quint16 humidity);

private:
    void recalcTemp(tempMode mode, tempMode newMode);
    void recalcPress(pressureMode mode, pressureMode newMode);
    void saveSettings();
    void loadSettings();

    double currentTemperature;
    double currentPressure;
    quint32 currentDirection;
    qint16 dialMin;
    qint16 dialMax;
    tempMode currentTemperatureMode;
    pressureMode currentPressureMode;
    XmlOperator *xml;



signals:
    void signal_tempRecalc(double temperature, qint32 dialMin, qint32 dialMax);
    void signal_pressureRecalc(double pressure);
    void signal_loadSettings(tempMode currentTemperatureMode, pressureMode currentPressureMode, quint32 direction);
    void signal_humidityChanged(quint16 humidity);
};

#endif // CONDITIONER_H
