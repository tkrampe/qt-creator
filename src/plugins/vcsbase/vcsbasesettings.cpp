/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact:  Qt Software Information (qt-info@nokia.com)
**
** Commercial Usage
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
**
**************************************************************************/

#include "vcsbasesettings.h"

#include <QtCore/QSettings>
#include <QtCore/QDebug>

static const char *settingsGroupC = "VCS";
static const char *nickNameMailMapKeyC = "NickNameMailMap";
static const char *nickNameFieldListFileKeyC = "NickNameFieldListFile";
static const char *promptForSubmitKeyC = "PromptForSubmit";
static const char *submitMessageCheckScriptKeyC = "SubmitMessageCheckScript";

namespace VCSBase {
namespace Internal {

VCSBaseSettings::VCSBaseSettings() :
    promptForSubmit(true)
{
}

void VCSBaseSettings::toSettings(QSettings *s) const
{
    s->beginGroup(QLatin1String(settingsGroupC));
    s->setValue(QLatin1String(nickNameMailMapKeyC), nickNameMailMap);
    s->setValue(QLatin1String(nickNameFieldListFileKeyC), nickNameFieldListFile);
    s->setValue(QLatin1String(submitMessageCheckScriptKeyC), submitMessageCheckScript);
    s->setValue(QLatin1String(promptForSubmitKeyC), promptForSubmit);
    s->endGroup();
}

void VCSBaseSettings::fromSettings(QSettings *s)
{
    s->beginGroup(QLatin1String(settingsGroupC));
    nickNameMailMap = s->value(QLatin1String(nickNameMailMapKeyC), QString()).toString();
    nickNameFieldListFile = s->value(QLatin1String(nickNameFieldListFileKeyC), QString()).toString();
    submitMessageCheckScript = s->value(QLatin1String(submitMessageCheckScriptKeyC), QString()).toString();
    promptForSubmit = s->value(QLatin1String(promptForSubmitKeyC), QVariant(true)).toBool();
    s->endGroup();
}

bool VCSBaseSettings::equals(const VCSBaseSettings &rhs) const
{
    return promptForSubmit == rhs.promptForSubmit
           && nickNameMailMap == rhs.nickNameMailMap
           && nickNameFieldListFile == rhs.nickNameFieldListFile
           && submitMessageCheckScript == rhs.submitMessageCheckScript;
}

}
}
