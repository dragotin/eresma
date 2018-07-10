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

#include "hexmap.h"
#include "region.h"
#include "regiongraphicsitem.h"

#include <QDebug>
#include <QGraphicsView>
#include <QVBoxLayout>



HexMap::HexMap(QWidget *parent)
    :QFrame(parent)
{
    QVBoxLayout *lay = new QVBoxLayout;
    setLayout(lay);
    setFrameStyle(Sunken | StyledPanel);

    // Use a VBoxLayout here, just in case. Currently there is only one widget,
    // but maybe there should be a zoom slider or anything above the map.
    _view.reset(new QGraphicsView);
    lay->addWidget(_view.data());
    _view->setRenderHint(QPainter::Antialiasing, false);
    _view->setDragMode(QGraphicsView::RubberBandDrag);
    _view->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    _view->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    _view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    _scene.reset(new QGraphicsScene);

    connect( _scene.data(), &QGraphicsScene::selectionChanged, this, &HexMap::slotSelectionChanged);

    _view->setScene(_scene.data());
    populateScene();
}


// Test routine to fill up the map with a huge number of regions.
// Later this or a similar routine needs to go somewhere else. Probably where the parsing of the
// reports is done.
void HexMap::populateScene()
{
    const int rx = RegionGraphicsItem::baseSize();
    const int rx23 = rx / 3 * 2;
    const int rx2  = rx / 2;

    for( int x = 0; x < 400; x++) {
        for( int y = 0; y < 300; y++) {
            const QString name = QString("Region%1_%2").arg(x).arg(y);
            int cx = x*rx;
            int cy = y*rx23;
            if( y % 2 ) {
                cx += rx2;
            }
            Region *r = new Region(name, Region::Wood, cx, cy);
            RegionGraphicsItem *item = new RegionGraphicsItem(r);
            item->setPos(QPointF(cx, cy));

            _scene->addItem( item );
        }
    }
}


// Slot to handle the selection of regions within the map
void HexMap::slotSelectionChanged()
{
     QList<QGraphicsItem*> selected = _scene->selectedItems();
     if( selected.count() > 0 ) {
         Region *r = static_cast<RegionGraphicsItem*>(selected.at(0))->region();
         emit regionSelected(r); // tell others about the selection.
     }
}

QGraphicsView *HexMap::graphicsView() const
{
    return _view.data();
}
