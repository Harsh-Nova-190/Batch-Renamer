/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : RenameExecutor.h
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#pragma once

#include <vector>

#include "models/FileItem.h"
#include "models/RenameOptions.h"
#include "models/RenameOperation.h"

class RenameExecutor
{
public:
    bool renameFiles(std::vector<FileItem>& files);

	bool undoRename(std::vector<FileItem>& files);
	bool redoRename(std::vector<FileItem>& files);

private:
	std::vector<RenameOperation> m_lastOperations;
};