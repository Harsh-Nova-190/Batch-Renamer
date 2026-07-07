/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : RenameEngine.h
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#pragma once

#include <QString>
#include <vector>

#include "models/FileItem.h"
#include "models/RenameOptions.h"

class RenameEngine
{
public:
    RenameEngine() = default;

    void generatePreview(std::vector<FileItem>& files, const RenameOptions& options);
};