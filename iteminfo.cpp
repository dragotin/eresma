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

#include "iteminfo.h"
#include "region.h"


// Just a stub object to show information about the region/unit
ItemInfo::ItemInfo(QWidget *parent)
    : QTextBrowser(parent)
{
    setText(tr("<h1>Regions-Info</h1>Als html gerendert."));
}

void ItemInfo::slotCurrentRegion(Region *r)
{
    if( !r ) return;

    setText(tr("<h1>%1</h1>").arg(r->_name));
    // ...more html to be assembled here with details about the region
}
