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

#ifndef REGIONGRAPHICSITEM_H
#define REGIONGRAPHICSITEM_H

#include "region.h"

#include <QObject>
#include <QGraphicsItem>

class RegionGraphicsItem : public QGraphicsItem
{
public:
    RegionGraphicsItem(Region *region);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

    static int baseSize();
    Region* region() const;

private:
    static QPainterPath hexagonPath();

    Region *_region;
    QVector<QPointF> _coords;
    static QPainterPath _hexagonPath;
};

#endif // REGIONGRAPHICSITEM_H
