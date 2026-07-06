/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : FileTable.cpp
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#include "widgets/FileTable.h"

#include <QHeaderView>
#include <QTableWidgetItem>

FileTable::FileTable(QWidget* parent)
    : QTableWidget(parent)
{
    setupTable();
}

void FileTable::setupTable()
{
    setColumnCount(4);

    setHorizontalHeaderLabels({
        "File Name",
        "New Name",
        "Size",
        "Status"
        });

    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    verticalHeader()->hide();

    setSelectionBehavior(QAbstractItemView::SelectRows);

    setEditTriggers(QAbstractItemView::NoEditTriggers);

    setAlternatingRowColors(true);

    setShowGrid(false);
}

void FileTable::loadFiles(const std::vector<FileItem>& files)
{
    setRowCount(0);

    for (const auto& file : files)
    {
        const int row = rowCount();

        insertRow(row);

        setItem(row, 0, new QTableWidgetItem(file.fileName));
        setItem(row, 1, new QTableWidgetItem(file.newName));

        QString sizeText;

        if (file.fileSize >= 1024 * 1024)
        {
            sizeText = QString::number(file.fileSize / (1024.0 * 1024.0), 'f', 2) + " MB";
        }
        else
        {
            sizeText = QString::number(file.fileSize / 1024.0, 'f', 1) + " KB";
        }

        setItem(row, 2, new QTableWidgetItem(sizeText));

        setItem(row, 3, new QTableWidgetItem("Ready"));
    }
}

void FileTable::refresh(const std::vector<FileItem>& files)
{
	loadFiles(files);
}