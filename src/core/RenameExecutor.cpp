/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : RenameExecutor.cpp
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#include "core/RenameExecutor.h"

#include <QFile>
#include <QFileInfo>

bool RenameExecutor::renameFiles(std::vector<FileItem>& files)
{
    bool success = true;

    m_lastOperations.clear();

    for (auto& file : files)
    {
        QFileInfo info(file.fullPath);

        QString newPath =
            info.absolutePath() + "/" + file.newName;

        if (QFile::rename(file.fullPath, newPath))
        {
            RenameOperation operation;

            operation.oldPath = file.fullPath;
            operation.newPath = newPath;

            m_lastOperations.push_back(operation);

            file.fullPath = newPath;
            file.fileName = file.newName;
            file.baseName = QFileInfo(newPath).completeBaseName();
            file.extension = QFileInfo(newPath).suffix();
            file.renamed = true;
        }
        else
        {
            success = false;
        }
    }

    return success;
}

bool RenameExecutor::undoRename(std::vector<FileItem>& files)
{
    bool success = true;

    for (auto it = m_lastOperations.rbegin();
        it != m_lastOperations.rend();
        ++it)
    {
        if (!QFile::rename(it->newPath, it->oldPath))
        {
            success = false;
            continue;
        }

        for (auto& file : files)
        {
            if (file.fullPath == it->newPath)
            {
                QFileInfo info(it->oldPath);

                file.fullPath = it->oldPath;
                file.fileName = info.fileName();
                file.baseName = info.completeBaseName();
                file.extension = info.suffix();
                file.newName = info.fileName();
                file.renamed = false;

                break;
            }
        }
    }

    return success;
}

bool RenameExecutor::redoRename(std::vector<FileItem>& files)
{
    bool success = true;

    for (const auto& operation : m_lastOperations)
    {
        if (!QFile::rename(operation.oldPath, operation.newPath))
        {
            success = false;
            continue;
        }

        for (auto& file : files)
        {
            if (file.fullPath == operation.oldPath)
            {
                QFileInfo info(operation.newPath);

                file.fullPath = operation.newPath;
                file.fileName = info.fileName();
                file.baseName = info.completeBaseName();
                file.extension = info.suffix();
                file.newName = info.fileName();
                file.renamed = true;

                break;
            }
        }
    }

    return success;
}