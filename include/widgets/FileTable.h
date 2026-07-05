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

class FileTable : public QTableWidget
{
	Q_OBJECT

public:
	explicit FileTable(QWidget* parent = nullptr);

private:
	void setupTable();
};