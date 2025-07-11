/**
 * @file settings.h Содержит в себе класс и зависимости для реализации раздела настроек программы
 * */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QAction>
#include "structs.h"
#include "stylemanager.h"

namespace Ui {
class Settings;
}

/**
 * @brief Класс описывает окно настроек программы
 * @details Определены все слоты и сигналы для реализации интерфейса с возможностью общения между окном настроек и главными модулями программы
 */
class Settings : public QWidget
{
    Q_OBJECT

private:
    Ui::Settings *ui;
signals:
    /**
     * @brief Сигнал изменения системы счисления температуры
     * @param mode Система счисления, которая интерпретируется в enum tempMode
     */
    void signal_tempModeChanged(int mode);
    /**
     * @brief Сигнал изменения системы счисления давления
     * @param mode Система счисления, которая интерпретируется в enum pressureMode
     */
    void signal_pressModeChanged(int mode);
    /**
     * @brief Сигнал об отметке чекбокса "Тёмная тема"
     */
    void signal_theme_changed();


public slots:
    /**
     * @brief Слот для запуска виджета
     */
    void slot_start();
    /**
     * @brief Слот для закрытия виджета
     */
    void slot_exit();
    /**
     * @brief Слот для получения информации из xml файла при загрузке программы
     * @param _tempMode Загружаемая система счисления температуры
     * @param _pressMode Загружаемая система счисления давления
     * @param direction Загружаемое направление подачи воздуха
     * @note Направление подачи воздуха загружается не из необходимости, а в целях сохранения универсальности сигнала loadSettings
     */
    void slot_loadSettings(tempMode _tempMode, pressureMode _pressMode, quint32 direction);
    /**
     * @brief Слот получает информацию для установки стиля виджета
     * @param newStyle Значение нового стиля виджета
     */
    void slot_updateStyle(const QString &newStyle);

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
    void initialize();


private slots:
    /**
     * @brief Слот нажатия на пункт в выпадающем меню выбора системы счисления температуры
     * @param index Выбранный пункт меню
     */
    void on_comboBox_temp_activated(int index);
    /**
     * @brief Слот нажатия на пункт в выпадающем меню выбора системы счисления давления
     * @param index Выбранный пункт меню
     */
    void on_comboBox_pressure_activated(int index);
    /**
     * @brief Слот изменения состояния чекбокса с выбором темной темы
     * @param arg1 Состояние чекбокса: вкл/выкл
     */
    void on_checkBox_darkMode_stateChanged(int arg1);

private:

    tempMode currentTempMode;
    pressureMode currentPressure;
    /**
     * @brief Метод для инициализации выпадающих меню значениями
     */
    void setupGroupBoxes();
    bool darkMode;

};

#endif // SETTINGS_H
