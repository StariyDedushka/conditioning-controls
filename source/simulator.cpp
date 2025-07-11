#include "include/simulator.h"
#include "ui_simulator.h"

Simulator::Simulator() :
    ui(new Ui::Simulator)
{
    ui->setupUi(this);
    this->setWindowTitle("Симулятор");
    connect(StyleManager::instance(), &StyleManager::signal_styleChanged, this, &Simulator::slot_updateStyle);
}

void Simulator::slot_updateStyle(const QString &newStyle)
{
    setStyleSheet(newStyle);
}

void Simulator::slot_tempMode(qint32 newMode)
{
    newMode = static_cast<tempMode>(newMode);
    QString modeName = "";
    switch(newMode) {
    case celsius:
        modeName = "°C";
        break;
    case fahrenheit:
        modeName = "°F";
        break;
    case kelvin:
        modeName = "K";
        break;
    }
    ui->label_temperature->setText(modeName);

}

void Simulator::slot_pressureMode(qint32 newMode)
{
    newMode = static_cast<pressureMode>(newMode);
    QString modeName = "";
    switch(newMode) {
    case millimeters:
        modeName = "мм. рт. столба";
        break;
    case pascals:
        modeName = "КПа";
        break;
    }
    ui->label_pressure->setText(modeName);
}

void Simulator::slot_loadSettings(qint32 _tempMode, qint32 _pressMode, quint32 direction)
{
    pressureMode pressMode = static_cast<pressureMode>(_pressMode);
    QString modeName = "";
    switch(pressMode) {
    case millimeters:
        modeName = "мм. рт. столба";
        break;
    case pascals:
        modeName = "КПа";
        break;
    }
    ui->label_pressure->setText(modeName);

    tempMode temperatureMode = static_cast<tempMode>(_tempMode);
    switch(temperatureMode) {
    case celsius:
        modeName = "°C";
        break;
    case fahrenheit:
        modeName = "°F";
        break;
    case kelvin:
        modeName = "K";
        break;
    }
    ui->label_temperature->setText(modeName);
}


void Simulator::on_spinBox_temperature_valueChanged(int arg1)
{
    emit signal_tempChanged(arg1);
}


void Simulator::on_spinBox_pressure_valueChanged(int arg1)
{
    emit signal_pressChanged(arg1);
}


void Simulator::on_spinBox_humidity_valueChanged(int arg1)
{
    emit signal_humidityChanged(arg1);
}

void Simulator::slot_start()
{
    this->show();
}

void Simulator::slot_exit()
{
    this->close();
}
