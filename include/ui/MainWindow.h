/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : MainWindow.h
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QAction>
#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>
#include <vector>
#include "core/FileManager.h"
#include "widgets/DropArea.h"
#include "widgets/FileTable.h"
#include "models/FileItem.h"
#include "core/RenameEngine.h"
#include "widgets/RenamePanel.h"
#include "models/RenameOptions.h"
#include "core/RenameExecutor.h"
#include "ui/AboutDialog.h"

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
    QHBoxLayout* m_topLayout = nullptr;
    QVBoxLayout* m_leftLayout = nullptr;
    QVBoxLayout* m_rightLayout = nullptr;

    QPushButton* m_addFilesButton = nullptr;
    QPushButton* m_addFolderButton = nullptr;
    QPushButton* m_clearButton = nullptr;
	QPushButton* m_renameButton = nullptr;

	QAction* m_addFilesAction = nullptr;
	QAction* m_addFolderAction = nullptr;
	QAction* m_renameAction = nullptr;
	QAction* m_clearAction = nullptr;
	QAction* m_exitAction = nullptr;
    QAction* m_undoAction = nullptr;
    QAction* m_redoAction = nullptr;
    QAction* m_selectAllAction = nullptr;
    QAction* m_preferencesAction = nullptr;

    QAction* m_documentationAction = nullptr;
    QAction* m_githubAction = nullptr;
    QAction* m_reportIssueAction = nullptr;
    QAction* m_checkUpdatesAction = nullptr;
    QAction* m_aboutAction = nullptr;

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
	void createWorkspace();
	void updatePreview();

    void connectSignals();
	void createRenamePanel();
	void createRenameButton();
};