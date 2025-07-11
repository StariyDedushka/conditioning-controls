#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QObject>
#include <QWidget>
#include "structs.h"
#include "stylemanager.h"

namespace Ui
{
    class Simulator;
}
class Simulator : public QWidget
{
    Q_OBJECT

public slots:
    /**
     * @brief Слот для получения обновленной актуальной системы счисления температуры
     * @details Обновляет отображаемую единицу измерения температуры в окне симулятора
     * @param newMode Новая система измерения. Интерпретируется в enum tempMode
     */
    void slot_tempMode(qint32 newMode);
    /**
     * @brief Слот для получения обновлённой актуальной системы счисления давления
     * @details Обновляет отображаемую единицу измерения давления в окне симулятора
     * @param newMode Новая система измерения. Интерпретируется в enum pressureMode
     */
    void slot_pressureMode(qint32 newMode);
    /**
     * @brief Слот для получения загруженных из xml файла значений при запуске программы
     * @param _tempMode Загружаемая система счисления температуры
     * @param _pressMode Загружаемая система счисления давления
     * @param direction Загружаемое направление подачи воздуха
     * @note Направление подачи воздуха не используется в этом классе, оно загружается для сохранения универсальности сигнала loadSettings
     */
    void slot_loadSettings(qint32 _tempMode, qint32 _pressMode, quint32 direction);
    /**
     * @brief Слот для запуска виджета
     */
    void slot_start();
    /**
     * @brief Слот для закрытия виджета
     */
    void slot_exit();
    /**
     * @brief Слот для обновления стиля виджета
     * @param Полученное значение нового стиля
     */
    void slot_updateStyle(const QString &newStyle);

signals:
    /**
     * @brief Сигнал изменения температуры в виджете
     * @param temperature Температура в градусах/единицах
     */
    void signal_tempChanged(double temperature);
    /**
     * @brief Сигнал изменения давления в виджете
     * @param pressure Давление в единицах
     */
    void signal_pressChanged(double pressure);
    /**
     * @brief Сигнал изменения влажности в виджете
     * @param humidity Влажность в процентах
     */
    void signal_humidityChanged(quint32 humidity);
public:
    Simulator();

private slots:
    /**
     * @brief Внутренний слот для получения значения из спинбокса температуры
     * @param arg1 Температура в градусах/единицах
     */
    void on_spinBox_temperature_valueChanged(int arg1);
    /**
     * @brief Внутренний слот для получения значения из спинбокса давления
     * @param arg1 Давление в единицах
     */
    void on_spinBox_pressure_valueChanged(int arg1);
    /**
     * @brief Внутренний слот для получения значения из спинбокса влажности
     * @param arg1 Влажность в процентах
     */
    void on_spinBox_humidity_valueChanged(int arg1);

private:
    Ui::Simulator *ui;
    bool darkMode;
};

#endif // SIMULATOR_H
