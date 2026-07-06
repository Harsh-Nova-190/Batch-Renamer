#pragma once

#include <vector>

#include "models/FileItem.h"

class RenameExecutor
{
public:
    bool renameFiles(std::vector<FileItem>& files);
};