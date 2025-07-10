#include "include/colorrectitem.h"

ColorRectItem::ColorRectItem(const QRectF &rect, QGraphicsItem *parent) :
    QObject()
    , QGraphicsRectItem(rect, parent)
{
    setFlag(QGraphicsObject::ItemIsSelectable);
    setBrush(Qt::gray);
}

void ColorRectItem::setColor(const QColor &color)
{
    setBrush(QBrush(color));
}
