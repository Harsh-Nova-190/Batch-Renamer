/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : MainWindow.cpp
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#include "ui/MainWindow.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setupWindow();
    setupUI();
}

void MainWindow::setupWindow()
{
    setWindowTitle("NovaBytes Batch Renamer");

    resize(1200, 700);
    setMinimumSize(900, 600);
}

void MainWindow::setupUI()
{
    createMenuBar();

    createCentralWidget();

    createToolbar();

    createDropArea();

	createRenamePanel();

	createRenameButton();

    createWorkspace();

    createFileTable();

    createStatusBar();

    m_fileManager = new FileManager(this);

    connectSignals();
}

void MainWindow::createMenuBar()
{
	auto* fileMenu = menuBar()->addMenu("&File");

    m_addFilesAction = fileMenu->addAction(QIcon(":/icons/add_file.svg"), "Add Files...");
    m_addFilesAction->setShortcut(QKeySequence::Open);

    m_addFolderAction = fileMenu->addAction(QIcon(":/icons/folder.svg"), "Add Folder...");
	m_addFolderAction->setShortcut(QKeySequence("Ctrl+Shift+O"));

    fileMenu->addSeparator();

	m_renameAction = fileMenu->addAction(QIcon(":/icons/rename.svg"), "Rename Files");
	m_renameAction->setShortcut(QKeySequence("Ctrl+R"));

    fileMenu->addSeparator();

	m_clearAction = fileMenu->addAction(QIcon(":/icons/clear.svg"), "Clear");
	m_clearAction->setShortcut(QKeySequence("Ctrl+L"));

	fileMenu->addSeparator();

	m_exitAction = fileMenu->addAction("Exit");
	m_exitAction->setShortcut(QKeySequence::Quit);

    auto* editMenu = menuBar()->addMenu("&Edit");

    m_undoAction = editMenu->addAction(QIcon(":/icons/undo.svg"), "Undo");
    m_undoAction->setShortcut(QKeySequence::Undo);
    m_undoAction->setEnabled(false);

    m_redoAction = editMenu->addAction(QIcon(":/icons/redo.svg"), "Redo");
    m_redoAction->setShortcut(QKeySequence::Redo);
    m_redoAction->setEnabled(false);

    editMenu->addSeparator();

    m_selectAllAction = editMenu->addAction("Select All");
    m_selectAllAction->setShortcut(QKeySequence::SelectAll);

    editMenu->addSeparator();

    m_preferencesAction = editMenu->addAction("Preferences...");


    auto* helpMenu = menuBar()->addMenu("&Help");

    m_documentationAction =
        helpMenu->addAction("Documentation");

    m_githubAction =
        helpMenu->addAction("GitHub Repository");

    m_reportIssueAction =
        helpMenu->addAction("Report an Issue");

    helpMenu->addSeparator();

    m_checkUpdatesAction =
        helpMenu->addAction("Check for Updates");

    helpMenu->addSeparator();

    m_aboutAction =
        helpMenu->addAction("About NovaBytes Batch Renamer");
}

void MainWindow::createCentralWidget()
{
    m_centralWidget = new QWidget(this);

    setCentralWidget(m_centralWidget);

    m_mainLayout = new QVBoxLayout(m_centralWidget);

    m_mainLayout->setContentsMargins(20, 20, 20, 20);
    m_mainLayout->setSpacing(20);
}

void MainWindow::createToolbar()
{
    m_toolbarLayout = new QHBoxLayout();

    m_toolbarLayout->setSpacing(12);

    m_addFilesButton = new QPushButton(QIcon(":/icons/add_file.svg"), "Add Files");
    m_addFolderButton = new QPushButton(QIcon(":/icons/folder.svg"), "Add Folder");
    m_clearButton = new QPushButton(QIcon(":/icons/clear.svg"), "Clear");

    m_addFilesButton->setMinimumWidth(140);
    m_addFolderButton->setMinimumWidth(140);
    m_clearButton->setMinimumWidth(120);

    m_toolbarLayout->addWidget(m_addFilesButton);
    m_toolbarLayout->addWidget(m_addFolderButton);
    m_toolbarLayout->addWidget(m_clearButton);
    m_toolbarLayout->addStretch();

    m_mainLayout->addLayout(m_toolbarLayout);
}

void MainWindow::createWorkspace()
{
	m_topLayout = new QHBoxLayout();

	m_leftLayout = new QVBoxLayout();
	m_rightLayout = new QVBoxLayout();

	m_leftLayout->addWidget(m_dropArea);

	m_rightLayout->addWidget(m_renamePanel);
	m_rightLayout->addWidget(m_renameButton);
	m_rightLayout->addStretch();

	m_topLayout->addLayout(m_leftLayout, 2);
	m_topLayout->addLayout(m_rightLayout, 1);

	m_mainLayout->addLayout(m_topLayout);
}

void MainWindow::createDropArea()
{
    m_dropArea = new DropArea(m_centralWidget);
}

void MainWindow::createFileTable()
{
    m_fileTable = new FileTable(m_centralWidget);

    m_mainLayout->addWidget(m_fileTable);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage("Ready");

    auto* versionLabel = new QLabel("v0.1.0", this);

    statusBar()->addPermanentWidget(versionLabel);
}

void MainWindow::createRenamePanel()
{
    m_renamePanel = new RenamePanel(m_centralWidget);
}

void MainWindow::createRenameButton()
{
    m_renameButton = new QPushButton(QIcon(":/icons/rename.svg"),"Rename Files", this);

    m_renameButton->setMinimumHeight(45);
	m_renameButton->setEnabled(false);
}

void MainWindow::updatePreview()
{
    if(m_files.empty())
		return;

    m_renameEngine.generatePreview(
        m_files,
        m_renameOptions);

    m_fileTable->refresh(m_files);
}

void MainWindow::connectSignals()
{
    // =========================
    // Add Files
    // =========================
    connect(
        m_addFilesButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            m_files = m_fileManager->openFiles(this);

            if (m_files.empty())
                return;

            m_fileTable->loadFiles(m_files);

            m_renameButton->setEnabled(true);

            statusBar()->showMessage(
                QString("Loaded %1 file(s)")
                .arg(m_files.size()));
        });

    // =========================
    // Add Folder
    // =========================
    connect(
        m_addFolderButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            m_files = m_fileManager->openFolder(this);

            if (m_files.empty())
                return;

            m_fileTable->loadFiles(m_files);

            m_renameButton->setEnabled(true);

            statusBar()->showMessage(
                QString("Loaded %1 file(s)")
                .arg(m_files.size()));
        });

    // =========================
    // Drag & Drop
    // =========================
    connect(
        m_dropArea,
        &DropArea::filesDropped,
        this,
        [this](const QStringList& paths)
        {
            m_files = m_fileManager->loadFiles(paths);

            if (m_files.empty())
                return;

            m_fileTable->loadFiles(m_files);

            m_renameButton->setEnabled(true);

            statusBar()->showMessage(
                QString("Loaded %1 file(s)")
                .arg(m_files.size()));
        });

    // =========================
    // Rename Options
    // =========================
    connect(
        m_renamePanel,
        &RenamePanel::prefixChanged,
        this,
        [this](const QString& value)
        {
            m_renameOptions.prefix = value;
            updatePreview();
        });

    connect(
        m_renamePanel,
        &RenamePanel::suffixChanged,
        this,
        [this](const QString& value)
        {
            m_renameOptions.suffix = value;
            updatePreview();
        });

    connect(
        m_renamePanel,
        &RenamePanel::numberingChanged,
        this,
        [this](bool value)
        {
            m_renameOptions.useNumbering = value;
            updatePreview();
        });

    connect(
        m_renamePanel,
        &RenamePanel::startNumberChanged,
        this,
        [this](int value)
        {
            m_renameOptions.startNumber = value;
            updatePreview();
        });

    connect(
        m_renamePanel,
        &RenamePanel::incrementChanged,
        this,
        [this](int value)
        {
            m_renameOptions.increment = value;
            updatePreview();
        });

    connect(
        m_renamePanel,
        &RenamePanel::paddingChanged,
        this,
        [this](int value)
        {
            m_renameOptions.padding = value;
            updatePreview();
        });

    // =========================
    // Rename Button
    // =========================
    connect(
        m_renameButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            if (m_files.empty())
                return;

            bool success = m_renameExecutor.renameFiles(m_files);

            if (success)
            {
                m_fileTable->refresh(m_files);

                statusBar()->showMessage(
                    QString("%1 file(s) renamed.")
                    .arg(m_files.size()));

                QMessageBox::information(
                    this,
                    "Success",
                    "Files renamed successfully.");

				m_undoAction->setEnabled(true);
                m_redoAction->setEnabled(false);

				updatePreview();
            }
            else
            {
                QMessageBox::warning(
                    this,
                    "Error",
                    "Some files could not be renamed.");
            }
        });

    // =========================
    // Clear
    // =========================
    connect(
        m_clearButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            m_files.clear();

            m_fileTable->setRowCount(0);

            m_renameButton->setEnabled(false);

            statusBar()->showMessage("Ready");

            m_undoAction->setEnabled(false);
            m_redoAction->setEnabled(false);
            m_renameButton->setEnabled(false);
        });

    // =========================
    // Menu Actions
    // =========================

	// File Menu Actions
    connect(
        m_addFilesAction,
        &QAction::triggered,
        m_addFilesButton,
        &QPushButton::click);

    connect(
        m_addFolderAction,
        &QAction::triggered,
        m_addFolderButton,
        &QPushButton::click);

    connect(
        m_clearAction,
        &QAction::triggered,
        m_clearButton,
        &QPushButton::click);

    connect(
        m_renameAction,
        &QAction::triggered,
        m_renameButton,
        &QPushButton::click);

    connect(
        m_exitAction,
        &QAction::triggered,
        this,
        &QWidget::close);

	// Edit Menu Actions
    connect(
        m_selectAllAction,
        &QAction::triggered,
        m_fileTable,
        &FileTable::selectAllRows);

    connect(
        m_undoAction,
        &QAction::triggered,
        this,
        [this]()
        {
            if (m_renameExecutor.undoRename(m_files))
            {
                m_fileTable->refresh(m_files);

                m_undoAction->setEnabled(false);
                m_redoAction->setEnabled(true);

                statusBar()->showMessage("Undo completed");
            }
        });

    connect(
        m_redoAction,
        &QAction::triggered,
        this,
        [this]()
        {
            if (m_renameExecutor.redoRename(m_files))
            {
                m_fileTable->refresh(m_files);

                m_redoAction->setEnabled(false);
                m_undoAction->setEnabled(true);

                statusBar()->showMessage("Redo completed");
            }
        });

    connect(
        m_preferencesAction,
        &QAction::triggered,
        this,
        [this]()
        {
            QMessageBox::information(
                this,
                "Preferences",
                "Preferences will be available in a future update.");
        });


	// Help Menu Actions
    connect(
        m_documentationAction,
        &QAction::triggered,
        this,
        []()
        {
            QDesktopServices::openUrl(
                QUrl("https://github.com/YourGitHub/NovaBytes-Batch-Renamer/wiki"));
        });

    connect(
        m_githubAction,
        &QAction::triggered,
        this,
        []()
        {
            QDesktopServices::openUrl(
                QUrl("https://github.com/Harsh-Nova-190/Batch-Renamer"));
        });

    connect(
        m_reportIssueAction,
        &QAction::triggered,
        this,
        []()
        {
            QDesktopServices::openUrl(
                QUrl("https://github.com/YourGitHub/NovaBytes-Batch-Renamer/issues"));
        });

    connect(
        m_checkUpdatesAction,
        &QAction::triggered,
        this,
        [this]()
        {
            QMessageBox::information(
                this,
                "Check for Updates",
                "You're using the latest version (v0.1.0).");
        });

    connect(
        m_aboutAction,
        &QAction::triggered,
        this,
        [this]()
        {
            AboutDialog dialog(this);
            dialog.exec();
        });
}