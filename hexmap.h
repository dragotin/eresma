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

#ifndef HEXMAP_H
#define HEXMAP_H

#include "region.h"

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QGraphicsView>
#include <QGraphicsScene>

class QGraphicsScene;

class HexMap : public QFrame
{
    Q_OBJECT
public:
    HexMap( QWidget *parent=0);

    QGraphicsView *graphicsView() const;

signals:
    void regionSelected(Region*);

protected slots:
    void slotSelectionChanged();

private:
    void populateScene();

    QScopedPointer<QGraphicsView>  _view;
    QScopedPointer<QGraphicsScene> _scene;
};

#endif // HEXMAP_H
