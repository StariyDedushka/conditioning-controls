/**
 * @file mainwindow.h Файл с классом для взаимодействия с пользователем
 * */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QGraphicsScene>
#include <QDebug>
#include "structs.h"
#include <QtNumeric>
#include "colorrectitem.h"
#include "stylemanager.h"

 QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief MainWindow Класс со всей логикой GUI
 * @details В этом классе находятся все сигналы, слоты и переменные для работы GUI. Класс отвечает за работу всех элементов с которыми
 * может взаимодействовать пользователь
 * */

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    /**
     * @brief Сигнал об изменении значения QDial температуры
     * @param temperature Значение QDial, соответствующее текущей целевой темапературе
     */
    void signal_dial_temp_changed(qint32 temperature);
    /**
     * @brief Сигнал об изменении значения QDial направления
     * @param direction Значение QDial, соответствующее направлению воздуха в градусах
     */
    void signal_dial_direction_changed(quint32 direction);
    /**
     * @brief Сигнал включения системы кондиционирования
     * @param color Цвет, в который должны окраситься прямоугольники, обозначающие кондиционеры
     * @note В дальнейшем можно исключить хранение цвета состояния системы в этом методе
     */
    void signal_switch_pressed(QColor color);
    /**
     * @brief Сигнал открытия раздела настроек
     */
    void signal_openSettings();
    /**
     * @brief Сигнал открытия раздела симуляции
     */
    void signal_openSim();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    /**
     * @brief Слот изменения значения QDial температуры
     * @param Значение QDial
     */
    void on_dial_temperature_valueChanged(int value);
    /**
     * @brief Слот для кнопки вкл/выкл
     */
    void on_btn_switch_clicked();
    /**
     * @brief Слот нажатия на кнопку меню "Настройки"
     */
    void slot_openSettings();
    /**
     * @brief Слот нажатия на кнопку меню "Симулятор"
     */
    void slot_openSimulator();
    /**
     * @brief Слот изменения значения QDial угла подачи воздуха
     * @param Угол подачи воздуха в градусах
     */
    void on_dial_angle_valueChanged(int angle);
    /**
     * @brief Слот для изменения цвета условного обозначения кондиционеров
     * @param color QColor параметр для установки цвета прямоугольников в области графического отображения состояния кондиционеров
     */
    void slot_cond_setColor(const QColor &color);

public slots:
    /**
     * @brief Слот изменения системы счисления температуры
     * @details Нужен для изменения обозначения единицы измерения температуры. Обозначение находится справа от числового значения температуры
     * @param mode Система счисления
     */
    void slot_tempMode(qint32 mode);
    /**
     * @brief Слот изменения системы счисления давления
     * @details Нужен для изменения обозначения единицы измерения давления. Обозначение находится справа от числового значения давления
     * @param mode Система счисления
     */
    void slot_pressureMode(qint32 mode);
    /**
     * @brief Слот для получения результатов пересчёта температуры между системами счисления
     * @param temperature Пересчитанное значение температуры
     * @param dialMin Новое минимальное значение QDial температуры
     * @param dialMax Новое максимальное значение QDial температуры
     */
    void slot_tempRecalc(double temperature, qint32 dialMin, qint32 dialMax);
    /**
     * @brief Слот для получения результатов пересчёта давления между системами счисления
     * @param pressure Пересчитанное значение давления
     */
    void slot_pressureRecalc(double pressure);
    /**
     * @brief Слот для получения результата загрузки настроек из XML файла
     * @param currentTemperatureMode Загруженная система счисления температуры
     * @param currentPressureMode Загруженная система счисления давления
     * @param direction Загруженное последнее значение направления кондиционирования
     */
    void slot_loadSettings(tempMode currentTemperatureMode, pressureMode currentPressureMode, quint32 direction);
    /**
     * @brief Слот для изменения отображаемого значения влажности
     * @param humidity Влажность в процентах
     */
    void slot_humidityChanged(quint16 humidity);
    /**
     * @brief Слот для изменения темы интерфейса
     * @note На данный момент существуют только тёмная и светлая темы
     * @param newStyle Строка с полученным значением стиля
     */
    void slot_updateStyle(const QString &newStyle);


private:

    Ui::MainWindow *ui;
    bool darkMode;

    /**
     * @brief Метод для инициализации menubar действиями для открытия настроек, симулятора и выхода из программы
     */
    void initMenu();
    /**
     * @brief Метод для инициализации графического отображения состояния работы кондиционирования
     */
    void initGraphics();
    QMenu *menu;
    QAction *action_settings;
    QAction *action_simulator;
    QAction *action_quit;

    QGraphicsScene *scene;

    ColorRectItem *rect1, *rect2, *rect3;

};
#endif // MAINWINDOW_H
