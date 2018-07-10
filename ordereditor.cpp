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

#include "ordereditor.h"

#include <QTextEdit>
#include <QLayout>
#include <QLabel>
#include <QCheckBox>


OrderEditor::OrderEditor(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vbLay = new QVBoxLayout;
    setLayout(vbLay);

    vbLay->addWidget(new QLabel(tr("Order:")));
    _orderText = new QTextEdit;
    vbLay->addWidget(_orderText);

    _cbAck = new QCheckBox(tr("&Acknowledge"));
    vbLay->addWidget(_cbAck);
}
