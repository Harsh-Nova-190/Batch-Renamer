/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : FileManager.cpp
 * ------------------------------------------------------------
 */

#include "core/FileManager.h"

FileManager::FileManager(QObject* parent)
    : QObject(parent)
{
}

std::vector<FileItem> FileManager::openFiles(QWidget* parent)
{
    QStringList selectedFiles =
        QFileDialog::getOpenFileNames(
            parent,
            "Select Files");

    return loadFiles(selectedFiles);
}

std::vector<FileItem> FileManager::loadFiles(const QStringList& paths)
{
    std::vector<FileItem> files;

    files.reserve(paths.size());

    for (const QString& path : paths)
    {
        QFileInfo info(path);

        FileItem item;

        item.fileName = info.fileName();
        item.baseName = info.completeBaseName();
        item.newName = info.fileName();
        item.fullPath = info.absoluteFilePath();
        item.extension = info.suffix();
        item.fileSize = info.size();

        files.push_back(std::move(item));
    }

    return files;
}

std::vector<FileItem> FileManager::openFolder(QWidget* parent)
{
    QString folder =
        QFileDialog::getExistingDirectory(
            parent,
            "Select Folder");

    if (folder.isEmpty())
        return {};

    QStringList paths;

    QDirIterator it(
        folder,
        QDir::Files,
        QDirIterator::NoIteratorFlags);

    while (it.hasNext())
    {
        paths << it.next();
    }

    return loadFiles(paths);
}