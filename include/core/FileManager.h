/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : FileManager.h
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#pragma once

#include <QObject>
#include <QStringList>
#include <vector>
#include <utility>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>

#include "models/FileItem.h"

class QWidget;

class FileManager : public QObject
{
    Q_OBJECT

public:
    explicit FileManager(QObject* parent = nullptr);

    std::vector<FileItem> openFiles(QWidget* parent = nullptr);
    std::vector<FileItem> loadFiles(const QStringList& paths);

    std::vector<FileItem> openFolder(QWidget* parent = nullptr);

    void clearFiles();
};