/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : FileTable.h
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#pragma once

#include <QTableWidget>
#include <vector>

#include "models/FileItem.h"

class FileTable : public QTableWidget
{
    Q_OBJECT

public:
    explicit FileTable(QWidget* parent = nullptr);

	void refresh(const std::vector<FileItem>& files);

    void loadFiles(const std::vector<FileItem>& files);

    void selectAllRows();

private:
    void setupTable();
};