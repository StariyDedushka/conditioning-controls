#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QGraphicsScene>
#include <QDebug>
#include "structs.h"
#include <QtNumeric>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void signal_dial_temp_changed(qint32 temperature);
    void signal_dial_direction_changed(quint32 direction);
    void signal_switch_pressed();
    void signal_openSettings();
    void signal_openSim();
    void signal_temperatureModeChanged(qint32 mode);
    void signal_pressureModeChanged(qint32 mode);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_dial_temperature_valueChanged(int value);
    void on_btn_switch_clicked();
    void slot_openSettings();
    void slot_openSimulator();
    void on_dial_angle_valueChanged(int angle);

public slots:
    void slot_tempMode(qint32 mode);
    void slot_pressureMode(qint32 mode);
    void slot_tempRecalc(double temperature, qint32 dialMin, qint32 dialMax);
    void slot_pressureRecalc(double pressure);
    void slot_loadSettings(tempMode currentTemperatureMode, pressureMode currentPressureMode, quint32 direction);
    void slot_humidityChanged(quint16 humidity);


private:

    Ui::MainWindow *ui;

    void initMenu();
    void initGraphics();
    QMenu *menu;
    QAction *action_settings;
    QAction *action_simulator;
    QAction *action_quit;

    QGraphicsScene *scene;
    QGraphicsItem *cond1;
    QGraphicsItem *cond2;
    QGraphicsItem *cond3;


};
#endif // MAINWINDOW_H
