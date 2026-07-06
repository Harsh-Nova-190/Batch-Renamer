#include "core/RenameExecutor.h"

#include <QFile>
#include <QFileInfo>

bool RenameExecutor::renameFiles(std::vector<FileItem>& files)
{
    bool success = true;

    for (auto& file : files)
    {
        QFileInfo info(file.fullPath);

        QString newPath =
            info.absolutePath() + "/" + file.newName;

        if (QFile::rename(file.fullPath, newPath))
        {
            file.fullPath = newPath;
            file.fileName = file.newName;
            file.baseName = QFileInfo(newPath).completeBaseName();
            file.renamed = true;
        }
        else
        {
            success = false;
        }
    }

    return success;
}