/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : RenameOptions.h
 * ------------------------------------------------------------
 */

#pragma once

#include <QString>

struct RenameOptions
{
    QString prefix;
    QString suffix;

    bool useNumbering = false;

    int startNumber = 1;
    int increment = 1;
    int padding = 3;

    bool keepExtension = true;
};