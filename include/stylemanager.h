/**
 * @file Файл содержит класс StyleManager и его зависимости
 * */
#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H

#include <QObject>

/**
 * @brief Класс для работы со стилями программы
 * @details Класс применяется в паттерне singleton в программе для изменения стиля всех окон. На данный момент реализованы светлая и тёмная темы
 */

class StyleManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Единственный экземпляр класса
     * @details Реализация сохранения уникальности экземпляра этого класса в пределах программы
     * @return Экземпляр этого же класса
     */
    static StyleManager* instance();

    /**
     * @brief Возвращает текущий установленный стиль
     * @return Строка стиля
     */
    QString currentStyle() const;
    /**
     * @brief Устанавливает тёмную тему в приложении
     * @param darkMode Тёмная тема вкл/выкл
     */
    void setStyleDark(bool darkMode);

    QString m_styleDarkMode;
    QString m_styleLightMode;

signals:
    /**
     * @brief Сигнал об изменении стиля приложения
     * @param newStyle Установленный новый стиль
     */
    void signal_styleChanged(const QString &newStyle);

private:
    QString m_currentStyle;
    StyleManager(QObject *parent = nullptr);
};

#endif // STYLEMANAGER_H
