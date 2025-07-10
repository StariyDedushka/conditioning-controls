#include "include/settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
    setupGroupBoxes();
    this->setWindowTitle("Настройки");
}

Settings::~Settings()
{
    delete ui;
}

void Settings::initialize()
{
    emit signal_pressModeChanged(currentPressure);
}

void Settings::on_comboBox_temp_activated(int index)
{
    index = static_cast<tempMode>(index);
    switch(index)
    {
    case celsius:
        emit signal_tempModeChanged(celsius);
        break;
    case fahrenheit:
        emit signal_tempModeChanged(fahrenheit);
        break;
    case kelvin:
        emit signal_tempModeChanged(kelvin);
        break;
    }
}

void Settings::on_comboBox_pressure_activated(int index)
{
    index = static_cast<pressureMode>(index);
    switch(index)
    {
    case millimeters:
        emit signal_pressModeChanged(pressureMode::millimeters);
        break;
    case pascals:
        emit signal_pressModeChanged(pressureMode::pascals);
        break;
    }
}

void Settings::on_btn_reset_clicked()
{
    emit signal_default_pressed();
}

void Settings::setupGroupBoxes() {

    ui->comboBox_pressure->insertItem(0, "KПа");
    ui->comboBox_pressure->insertItem(1, "мм. рт. ст.");

    ui->comboBox_temp->insertItem(0, "°C");
    ui->comboBox_temp->insertItem(1, "°F");
    ui->comboBox_temp->insertItem(2, "K");
}

void Settings::slot_loadSettings(tempMode _tempMode, pressureMode _pressMode, quint32 direction)
{
    currentPressure = _pressMode;
    currentTempMode = _tempMode;
    ui->comboBox_pressure->setCurrentIndex(static_cast<int> (_pressMode));
    ui->comboBox_temp->setCurrentIndex(static_cast<int> (_tempMode));
    emit signal_tempModeChanged(currentTempMode);
    emit signal_pressModeChanged(currentPressure);

}

void Settings::slot_exit()
{
    this->close();
}

void Settings::slot_start()
{
    this->show();
}
