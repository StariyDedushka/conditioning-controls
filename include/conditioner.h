#ifndef CONDITIONER_H
#define CONDITIONER_H

#include <QObject>
#include <QDebug>
#include "xmloperator.h"
#include "include/structs.h"

/**
 * @brief Это класс для отслеживания системы кондиционирования
 * @details Класс содержит в себе всю логику отслеживания системы кондиционирования, в том числе значения всех параметров
 *  и методы для переведения этих параметров в разные системы счисления
 * @note Класс готов для интеграции в приложение с настоящими источниками данных благодаря системе слотов и сигналов
 * */
class Conditioner : public QObject
{
    Q_OBJECT
public:
    Conditioner();
    ~Conditioner();
    void initialize();


public slots:
    /**
     * @brief Слот для получения сигнала о смене системы счисления температуры
     * @param mode1 Параметр режима счисления температуры, который будет переведён в enum значение tempMode -- celsius, fahrenheit, kelvin
     * */
    void slot_tempMode(qint32 mode1);
    /**
     * @brief Слот для получения сигнала о смене системы счисления давления
     * @param mode1 Параметр режима счисления давления, который будет переведён в enum значениe pressureMode -- pascals, millimiters
     * */
    void slot_pressureMode(qint32 mode1);
    /**
     * @brief Слот для получения сигнала об изменении направления подачи воздуха
     * @param direction Параметр текущего направления кондиционирования
     * */
    void slot_dial_direction_changed(quint32 direction);
    /**
     * @brief Слот для получения сигнала об изменении значения целевой температуры
     * @param temperature Параметр получения данных о температуре из внешней системы. Подразумевается получение значения, установленного пользователем
     * */
    void slot_dial_temperature_changed(qint32 temperature);
    /**
     * @brief Слот для получения сигнала об изменении значения давления
     * @param pressure Параметр давления, принятые извне
     * */
    void slot_pressureChanged(quint32 pressure);
    /**
     *  @brief Слот для получения данных об изменении влажности
     *  @param humidity Параметр влажности, принятый извне
     * */
    void slot_humidityChanged(quint16 humidity);

private:
    /**
     * @brief Метод для пересчета значения температуры из одной системы счисления в другую
     * @param mode Параметр текущего температурного режима
     * @param newMode Параметр нового температурного режима
     * */
    void recalcTemp(tempMode mode, tempMode newMode);
    /**
     * @brief Метод для пересчета значения давления из одной системы счисления в другую
     * @param mode Параметр текущего режима давления
     * @param newMode Параметр нового режима давления
     * */
    void recalcPress(pressureMode mode, pressureMode newMode);
    /**
     * @brief Метод для сохранения установленных параметров в xml файл
     * @details В файле хранятся режим температуры, режим давления и направление воздуха
     * */
    void saveSettings();
    /**
     * @brief Метод для загрузки сохранённых в xml файл параметров
     */
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
    /**
     * @brief Сигнал с пересчитанным значением температуры
     * @param temperature Пересчитанная температура
     * @param dialMin Пересчитанное минимальное значение QDial, чтобы его положение не изменилось после пересчёта
     * @param dialMax Пересчитанное максимальное значение QDial, чтобы его максимальное значение не изменилось после пересчёта
     * */
    void signal_tempRecalc(double temperature, qint32 dialMin, qint32 dialMax);
    /**
     * @brief Сигнал с пересчитанным значением давления
     * @param pressure Пересчитанное давление
     * */
    void signal_pressureRecalc(double pressure);
    /**
     * @brief Сигнал с загруженными из файла параметрами системы
     * @details Сигнал отправляется в MainWindow для инициализации GUI нужными режимами и в Settings для установки значений в comboBox
     * @param currentTemperatureMode Загружаемая система счисления температуры
     * @param currentPressureMode Загружаемая система счисления давления
     * @param direction Загружаемое направление кондиционирования
     * */
    void signal_loadSettings(tempMode currentTemperatureMode, pressureMode currentPressureMode, quint32 direction);
    /**
     * @brief Сигнал с значением влажности
     * @param humidity Влажность в процентах
     * @note Нужен на случай расширения системы, чтобы влажность хранилась в текущем классе и передавалась дальше в интерфейс
     * */
    void signal_humidityChanged(quint16 humidity);
};

#endif // CONDITIONER_H
