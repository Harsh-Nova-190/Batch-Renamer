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

    horizontalHeader()->setStretchLastSection(true);

    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    verticalHeader()->hide();

    setSelectionBehavior(QAbstractItemView::SelectRows);

    setEditTriggers(QAbstractItemView::NoEditTriggers);

    setAlternatingRowColors(true);

    setShowGrid(false);
}