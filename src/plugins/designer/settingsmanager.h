/***************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact:  Qt Software Information (qt-info@nokia.com)
**
**
** Non-Open Source Usage
**
** Licensees may use this file in accordance with the Qt Beta Version
** License Agreement, Agreement version 2.2 provided with the Software or,
** alternatively, in accordance with the terms contained in a written
** agreement between you and Nokia.
**
** GNU General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU General
** Public License versions 2.0 or 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the packaging
** of this file.  Please review the following information to ensure GNU
** General Public Licensing requirements will be met:
**
** http://www.fsf.org/licensing/licenses/info/GPLv2.html and
** http://www.gnu.org/copyleft/gpl.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt GPL Exception
** version 1.3, included in the file GPL_EXCEPTION.txt in this package.
**
***************************************************************************/

#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QtDesigner/private/abstractsettings_p.h>
#include <QtCore/QSettings>

namespace Designer {
namespace Internal {

/* Prepends "Designer" to every value stored/retrieved by designer plugins,
   to avoid namespace polution. We cannot use a group because groups cannot be nested,
   and designer uses groups internally. */
class SettingsManager : public QDesignerSettingsInterface
{
public:
    virtual void beginGroup(const QString &prefix);
    virtual void endGroup();

    virtual bool contains(const QString &key) const;
    virtual void setValue(const QString &key, const QVariant &value);
    virtual QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const ;
    virtual void remove(const QString &key);

private:
    QString addPrefix(const QString &name) const;
    QSettings m_settings;
};

} // namespace Internal
} // namespace Designer

#endif // SETTINGSMANAGER_H
