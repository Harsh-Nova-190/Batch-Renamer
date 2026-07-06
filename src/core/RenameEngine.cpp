/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : RenameEngine.cpp
 * ------------------------------------------------------------
 */

#include "core/RenameEngine.h"

void RenameEngine::generatePreview(
    std::vector<FileItem>& files,
    const RenameOptions& options)
{
    int number = options.startNumber;

    for (auto& file : files)
    {
        QString newName;

        newName += options.prefix;

        if (options.useNumbering)
        {
            newName += QString("%1")
                .arg(number,
                    options.padding,
                    10,
                    QChar('0'));

            number += options.increment;
        }
        else
        {
            newName += file.baseName;
        }

        newName += options.suffix;

        if (options.keepExtension && !file.extension.isEmpty())
        {
            newName += "." + file.extension;
        }

        file.newName = newName;
    }
}