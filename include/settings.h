#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QAction>
#include "structs.h"

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

private:
    Ui::Settings *ui;
signals:
    void signal_default_pressed();
    void signal_tempModeChanged(int mode);
    void signal_pressModeChanged(int mode);


public slots:
    void slot_start();
    void slot_exit();
    void slot_loadSettings(tempMode _tempMode, pressureMode _pressMode, quint32 direction);

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
    void initialize();


private slots:
    void on_comboBox_temp_activated(int index);
    void on_comboBox_pressure_activated(int index);
    void on_btn_reset_clicked();

private:

    tempMode currentTempMode;
    pressureMode currentPressure;
    void setupGroupBoxes();

    // QAction *actionCelsius;
    // QAction *actionKelvin;
    // QAction *actionFahrenheit;

    // QAction *actionPascals;
    // QAction *actionMillimeters;


};

#endif // SETTINGS_H
