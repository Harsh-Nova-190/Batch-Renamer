/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : FileItem.h
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#pragma once

#include <QString>

struct FileItem
{
    QString fileName;
    QString newName;
    QString baseName;
    QString fullPath;
    QString extension;

    qint64 fileSize = 0;

    bool renamed = false;
};