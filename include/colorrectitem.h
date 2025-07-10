#ifndef COLORRECTITEM_H
#define COLORRECTITEM_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBrush>

class ColorRectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ColorRectItem(const QRectF &rect, QGraphicsItem* parent = nullptr);

public slots:
    void setColor(const QColor &color);
};

#endif // COLORRECTITEM_H
