/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : MainWindow.h
 * ------------------------------------------------------------
 */

#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <vector>
#include "core/FileManager.h"
#include "widgets/DropArea.h"
#include "widgets/FileTable.h"
#include "models/FileItem.h"
#include "core/RenameEngine.h"
#include "widgets/RenamePanel.h"
#include "models/RenameOptions.h"
#include "core/RenameExecutor.h"

class QWidget;
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;

class DropArea;
class FileTable;
class FileManager;
class RenamePanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);


private:

    QWidget* m_centralWidget = nullptr;

    QVBoxLayout* m_mainLayout = nullptr;
    QHBoxLayout* m_toolbarLayout = nullptr;

    QPushButton* m_addFilesButton = nullptr;
    QPushButton* m_addFolderButton = nullptr;
    QPushButton* m_clearButton = nullptr;
	QPushButton* m_renameButton = nullptr;

    DropArea* m_dropArea = nullptr;
    FileTable* m_fileTable = nullptr;

    FileManager* m_fileManager = nullptr;

    std::vector<FileItem> m_files;

    RenameEngine m_renameEngine;
	RenamePanel* m_renamePanel = nullptr;
	RenameOptions m_renameOptions;
	RenameExecutor m_renameExecutor;

    void setupWindow();
    void setupUI();

    void createCentralWidget();
    void createMenuBar();
    void createToolbar();
    void createDropArea();
    void createFileTable();
    void createStatusBar();

    void connectSignals();
	void createRenamePanel();
	void createRenameButton();
};