#include "include/mainwindow.h"
#include "include/settings.h"
#include "include/conditioner.h"
#include "include/structs.h"
#include "include/simulator.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    qRegisterMetaType<tempMode>("tempMode");
    qRegisterMetaType<pressureMode>("pressureMode");
    qRegisterMetaType<info>("info");
    qRegisterMetaType<tempMode>("tempMode&");
    qRegisterMetaType<pressureMode>("pressureMode&");
    qRegisterMetaType<info>("info&");

    QApplication a(argc, argv);
    MainWindow w;
    Settings sett;
    Conditioner cond;
    Simulator sim;

    if(QMetaType::type("info") == QMetaType::UnknownType)
        qDebug() << "Type info is not registered!";
    if(QMetaType::type("tempMode") == QMetaType::UnknownType)
        qDebug() << "Type info is not registered!";
    if(QMetaType::type("pressureMode") == QMetaType::UnknownType)
        qDebug() << "Type info is not registered!";


    MainWindow::connect(&cond, &Conditioner::signal_pressureRecalc, &w, &MainWindow::slot_pressureRecalc);
    MainWindow::connect(&cond, &Conditioner::signal_tempRecalc, &w, &MainWindow::slot_tempRecalc);
    MainWindow::connect(&cond, &Conditioner::signal_loadSettings, &w, &MainWindow::slot_loadSettings);
    MainWindow::connect(&cond, &Conditioner::signal_humidityChanged, &w, &MainWindow::slot_humidityChanged);

    MainWindow::connect(&cond, &Conditioner::signal_loadSettings, &sett, &Settings::slot_loadSettings);


    MainWindow::connect(&w, &MainWindow::signal_openSettings, &sett, &Settings::slot_start);
    MainWindow::connect(&w, &MainWindow::signal_dial_direction_changed, &cond, &Conditioner::slot_dial_direction_changed);
    MainWindow::connect(&w, &MainWindow::signal_dial_temp_changed, &cond, &Conditioner::slot_dial_temperature_changed);
    MainWindow::connect(&w, &MainWindow::signal_openSim, &sim, &Simulator::slot_start);


    Conditioner::connect(&sett, &Settings::signal_pressModeChanged, &cond, &Conditioner::slot_pressureMode);
    Conditioner::connect(&sett, &Settings::signal_tempModeChanged, &cond, &Conditioner::slot_tempMode);

    MainWindow::connect(&sett, &Settings::signal_tempModeChanged, &w, &MainWindow::slot_tempMode);
    MainWindow::connect(&sett, &Settings::signal_pressModeChanged, &w, &MainWindow::slot_pressureMode);


    Simulator::connect(&sim, &Simulator::signal_tempChanged, &cond, &Conditioner::slot_dial_temperature_changed);
    Simulator::connect(&sim, &Simulator::signal_pressChanged, &cond, &Conditioner::slot_pressureChanged);
    Simulator::connect(&sim, &Simulator::signal_humidityChanged, &cond, &Conditioner::slot_humidityChanged);

    Settings::connect(&sett, &Settings::signal_pressModeChanged, &sim, &Simulator::slot_pressureMode);
    Settings::connect(&sett, &Settings::signal_tempModeChanged, &sim, &Simulator::slot_tempMode);
    Simulator::connect(&cond, &Conditioner::signal_loadSettings, &sim, &Simulator::slot_loadSettings);




    sett.initialize();
    cond.initialize();
    w.show();
    return a.exec();
}
