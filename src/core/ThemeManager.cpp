/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : ThemeManager.cpp
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */


#include "core/ThemeManager.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>

void ThemeManager::ApplyTheme(QApplication& app)
{
    QFile file(":/qss/NovaBytesDark.qss");

    if (file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);

        app.setStyleSheet(stream.readAll());

        file.close();
    }
}