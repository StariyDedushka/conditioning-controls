#include "include/conditioner.h"

Conditioner::Conditioner() {
    xml = new XmlOperator();
}

void Conditioner::initialize()
{
    loadSettings();
}

Conditioner::~Conditioner()
{
    saveSettings();
    delete xml;
}

void Conditioner::slot_pressureMode(qint32 mode1)
{
    pressureMode mode = static_cast<pressureMode> (mode1);
    // qDebug() << "Current mode:";
    // if(currentPressureMode == pascals)
    //     qDebug() << "pascals";
    // else if(currentPressureMode == millimeters)
    //     qDebug() << "millimeters";

    switch(mode) {
    case pascals:
        recalcPress(currentPressureMode, pascals);
        // qDebug() << "Pressure mode changed! NewMode = pascals";
        // qDebug() << "Recalculated pressure:" << currentPressure;
        break;
    case millimeters:
        recalcPress(currentPressureMode, millimeters);
        // qDebug() << "Pressure mode changed! NewMode = millimeters";
        // qDebug() << "Recalculated pressure =" << currentPressure;
        break;
    }
        emit signal_pressureRecalc(currentPressure);
        currentPressureMode = mode;
}

void Conditioner::recalcTemp(tempMode mode, tempMode newMode)
{
    qDebug() << "Recalculating: old mode:" << mode << "New mode:" << newMode;
    qDebug() << "currentTemperature = " << currentTemperature;

    if(mode == celsius && newMode == fahrenheit)
        currentTemperature = 1.80 * currentTemperature + 32;
    else if (mode == fahrenheit && newMode == celsius)
        currentTemperature =  (currentTemperature - 32) / 1.80;
    else if(mode == celsius && newMode == kelvin)
        currentTemperature = (currentTemperature + 273);
    else if(mode == kelvin && newMode == celsius)
        currentTemperature = (currentTemperature - 273);
    else if(mode == fahrenheit && newMode == kelvin)
        currentTemperature =  5.0/9.0 * (currentTemperature - 32) + 273;
    else if(mode == kelvin && newMode == fahrenheit)
        currentTemperature = 1.80 * (currentTemperature - 273) + 32;
    else if(mode == newMode)
        currentTemperature = currentTemperature;
    qDebug() << "New current temp: " << currentTemperature;
}

void Conditioner::recalcPress(pressureMode mode, pressureMode newMode)
{
    if(mode == pascals && newMode == millimeters)
        currentPressure = (currentPressure * 0.0075 * 1000);
    else if(mode == millimeters && newMode == pascals)
        currentPressure = (currentPressure / (0.0075 * 1000));
    else if(mode == newMode)
        currentPressure = currentPressure;
}

void Conditioner::slot_tempMode(qint32 mode1)
{
    tempMode newMode = static_cast<tempMode> (mode1);
    switch(newMode)
    {
        case celsius:
            recalcTemp(currentTemperatureMode, celsius);
            dialMin = 0;
            dialMax = 40;
            emit signal_tempRecalc(currentTemperature, dialMin, dialMax);
            break;
        case fahrenheit:
            recalcTemp(currentTemperatureMode, fahrenheit);
            dialMin = 32;
            dialMax = 122;
            emit signal_tempRecalc(currentTemperature, dialMin, dialMax);
            break;
        case kelvin:
             recalcTemp(currentTemperatureMode, kelvin);
            dialMin = 273;
             dialMax = 323;
            emit signal_tempRecalc(currentTemperature, dialMin, dialMax);
            break;
    }
        currentTemperatureMode = newMode;
}


void Conditioner::slot_dial_direction_changed(quint32 direction)
{
    currentDirection = direction;

}

void Conditioner::slot_dial_temperature_changed(qint32 temperature)
{
    currentTemperature = temperature;
    emit signal_tempRecalc(temperature, dialMin, dialMax);
}


void Conditioner::saveSettings()
{
    xml->writeXml(QString("/"), currentTemperatureMode, currentPressureMode, currentDirection);
}

void Conditioner::loadSettings()
{
    info data = xml->readXml();
    currentTemperatureMode = static_cast<tempMode> (data._tempMode);
    currentPressureMode = static_cast<pressureMode>(data._pressMode);
    qDebug() << "Loaded temperature mode: " << currentTemperatureMode;
    qDebug() << "Loaded pressure mode: " << currentPressureMode;
    currentDirection = data.direction;
    // qDebug() << "current temp:" << currentTemperature;
    // qDebug() << "current pressure:" << currentPressure;
    // qDebug() << "current direction:" << currentDirection;
    qDebug() << "Emitting signal: load settings";
    emit signal_loadSettings(currentTemperatureMode, currentPressureMode, currentDirection);
}


void Conditioner::slot_pressureChanged(quint32 pressure)
{
    currentPressure = pressure;
    emit signal_pressureRecalc(currentPressure);
}


void Conditioner::slot_humidityChanged(quint16 humidity)
{
    emit signal_humidityChanged(humidity);
}
