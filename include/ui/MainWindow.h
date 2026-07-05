/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : MainWindow.h
 * ------------------------------------------------------------
 */

#pragma once

#include <QMainWindow>
#include <QDebug>

class DropArea;

class QPushButton;
class QWidget;
class QVBoxLayout;
class QHBoxLayout;
class FileTable;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    QWidget* m_centralWidget;

    QVBoxLayout* m_mainLayout;
    QHBoxLayout* m_toolbarLayout;

    QPushButton* m_addFilesButton;
    QPushButton* m_addFolderButton;
    QPushButton* m_clearButton;

    DropArea* m_dropArea;

	FileTable* m_fileTable;

    void setupWindow();
    void setupUI();
};