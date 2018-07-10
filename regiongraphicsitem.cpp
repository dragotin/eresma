/***************************************************************************
                     Eresma Qt based Eressea Viewer
                             -------------------
    begin                : July 2018
    copyright            : (C) 2018 Klaas Freitag
    email                : klaas@volle-kraft-voraus.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "regiongraphicsitem.h"

#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QColor>
#include <QPainter>

QPainterPath RegionGraphicsItem::_hexagonPath = QPainterPath();

RegionGraphicsItem::RegionGraphicsItem(Region *region)
    :QGraphicsItem(), _region(region)
{
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
}

int RegionGraphicsItem::baseSize()
{
    return 60;
}

QPainterPath RegionGraphicsItem::hexagonPath()
{
    if( _hexagonPath.isEmpty() ) {
        _hexagonPath.moveTo(baseSize()/2, 0);
        _hexagonPath.lineTo(baseSize(), baseSize() / 3);
        _hexagonPath.lineTo(baseSize(), baseSize() / 3 * 2 );
        _hexagonPath.lineTo(baseSize()/2, baseSize());
        _hexagonPath.lineTo(0, baseSize() / 3 * 2);
        _hexagonPath.lineTo(0,baseSize() / 3);
        _hexagonPath.lineTo(baseSize() /2, 0);
    }
    return _hexagonPath;
}

QRectF RegionGraphicsItem::boundingRect() const
{
    return QRectF(0, 0, baseSize(), baseSize());
}

Region *RegionGraphicsItem::region() const
{
    return _region;
}

QPainterPath RegionGraphicsItem::shape() const
{
    return hexagonPath();
}

void RegionGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    const QColor color("#80ffbf");
    QColor fillColor = (option->state & QStyle::State_Selected) ? color.dark(150) : color;
    if (option->state & QStyle::State_MouseOver)
        fillColor = fillColor.light(125);

    const qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());
    if (lod < 0.2) {
        // alternative draw if the scaling is very small.

    }

    QPen oldPen = painter->pen();
    QPen pen = oldPen;
    int width = 2;
    if (option->state & QStyle::State_Selected)
        width += 2;

    pen.setWidth(width);
    painter->setBrush(QBrush(fillColor.dark(option->state & QStyle::State_Sunken ? 120 : 100)));
    painter->setPen(pen);
    // Draw text <- FIXME, not yet working at all!!
    if (1 || lod >= 2) {
        QFont font("Times", 5);
        // font.setStyleStrategy(QFont::ForceOutline);
        painter->setFont(font);
        painter->save();
        // painter->scale(0.5, 0.5);
        painter->drawText(4, RegionGraphicsItem::baseSize()/2, _region->_name);
        painter->restore();
    }

    // Draw lines

    painter->drawPath(shape());
}


