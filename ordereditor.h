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

#ifndef ORDEREDITOR_H
#define ORDEREDITOR_H

#include <QObject>
#include <QWidget>

class QTextEdit;
class QCheckBox;

class OrderEditor : public QWidget
{
    Q_OBJECT
public:
    explicit OrderEditor(QWidget *parent = nullptr);

signals:

public slots:

private:
    QTextEdit *_orderText;
    QCheckBox *_cbAck;
};

#endif // ORDEREDITOR_H
