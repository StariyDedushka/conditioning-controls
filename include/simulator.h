#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QObject>
#include <QWidget>
#include "structs.h"

namespace Ui
{
    class Simulator;
}
class Simulator : public QWidget
{
    Q_OBJECT

public slots:
    void slot_tempMode(qint32 newMode);
    void slot_pressureMode(qint32 newMode);
    void slot_loadSettings(qint32 _tempMode, qint32 _pressMode, quint32 direction);
    void slot_start();
    void slot_exit();

signals:
    void signal_tempChanged(double temperature);
    void signal_pressChanged(double pressure);
    void signal_humidityChanged(quint32 humidity);
public:
    Simulator();

private slots:
    void on_spinBox_temperature_valueChanged(int arg1);
    void on_spinBox_pressure_valueChanged(int arg1);
    void on_spinBox_humidity_valueChanged(int arg1);

private:
    Ui::Simulator *ui;
};

#endif // SIMULATOR_H
