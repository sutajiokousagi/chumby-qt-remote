/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include <qkbddriverplugin_qws.h>
#include <qchumbyirkb_qws.h>
#include <stdio.h>
QT_BEGIN_NAMESPACE

class QChumbyIrKbDriver : public QKbdDriverPlugin
{
public:
    QChumbyIrKbDriver();

    QStringList keys() const;
    QWSKeyboardHandler* create(const QString &driver, const QString &device);
};

QChumbyIrKbDriver::QChumbyIrKbDriver()
    : QKbdDriverPlugin()
{
	fprintf(stderr, "Initialized chumby IR keyboard driver\n");
}

QStringList QChumbyIrKbDriver::keys() const
{
    return (QStringList() << QLatin1String("chumbyirkb"));
}

QWSKeyboardHandler* QChumbyIrKbDriver::create(const QString &driver,
                                                 const QString &device)
{
    Q_UNUSED(device);
    if (driver.compare(QLatin1String("chumbyirkb"), Qt::CaseInsensitive))
        return 0;
    return new QWSChumbyIrKbHandler(device);
}

Q_EXPORT_PLUGIN2(qwslinuxinputkbddriver, QChumbyIrKbDriver)

QT_END_NAMESPACE
