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

#include "eresmacanvas.h"
#include "regiontree.h"
#include "hexmap.h"
#include "iteminfo.h"
#include "ordereditor.h"
#include "region.h"
#include "regiontree.h"

#include <QVBoxLayout>

EresmaCanvas::EresmaCanvas(QWidget *parent) : QSplitter(parent)
{
    setOrientation(Qt::Horizontal);

    // Treeview with all Regions and Units in it
    _regionTree = new RegionTree;
    addWidget(_regionTree);

    // View widget for the map
    _hexMap = new HexMap;
    addWidget(_hexMap);

    // A container widget to host the vertical layout of item info
    // and the order editor
    QWidget *w = new QWidget;
    QVBoxLayout *vLay = new QVBoxLayout;
    _itemInfo = new ItemInfo;
    vLay->addWidget(_itemInfo);

    _orderEditor = new OrderEditor;
    vLay->addWidget(_orderEditor);

    w->setLayout(vLay);
    addWidget(w);

    // Connections
    connect( _hexMap, &HexMap::regionSelected, _itemInfo, &ItemInfo::slotCurrentRegion);

}
