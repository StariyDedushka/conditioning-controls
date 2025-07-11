/**
 * @file Описание графического элемента -- прямоугольника
 * */

#ifndef COLORRECTITEM_H
#define COLORRECTITEM_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBrush>

/**
 * @brief Класс прямоугольника для графического представления системы кондиционирования
 * @see mainwindow.cpp
 * */
class ColorRectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    /**
     * @param &rect это встроенный примитив-прямоугольник
     * @param parent это графический объект-родитель на случай, если он нужен
     * @note Всё, что нам нужно для определения прямоугольника это примитив и родитель
     * */
    ColorRectItem(const QRectF &rect, QGraphicsItem* parent = nullptr);

public slots:
    /**
     * @brief setColor Цвет прямоугольника нужно задавать извне для индикации работы системы
     * @param color   Цвет
     * */
    void setColor(const QColor &color);
};

#endif // COLORRECTITEM_H
