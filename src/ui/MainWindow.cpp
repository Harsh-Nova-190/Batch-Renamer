/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : MainWindow.cpp
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

    createFileTable();

	createRenamePanel();

	createRenameButton();

    createStatusBar();

    m_fileManager = new FileManager(this);

    connectSignals();
}

void MainWindow::createMenuBar()
{
    menuBar()->addMenu("File");
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Help");
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

    m_addFilesButton = new QPushButton("📂 Add Files");
    m_addFolderButton = new QPushButton("📁 Add Folder");
    m_clearButton = new QPushButton("🗑 Clear");

    m_addFilesButton->setMinimumWidth(140);
    m_addFolderButton->setMinimumWidth(140);
    m_clearButton->setMinimumWidth(120);

    m_toolbarLayout->addWidget(m_addFilesButton);
    m_toolbarLayout->addWidget(m_addFolderButton);
    m_toolbarLayout->addWidget(m_clearButton);
    m_toolbarLayout->addStretch();

    m_mainLayout->addLayout(m_toolbarLayout);
}

void MainWindow::createDropArea()
{
    m_dropArea = new DropArea(m_centralWidget);

    m_mainLayout->addWidget(m_dropArea);
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
    m_mainLayout->addWidget(m_renamePanel);
}

void MainWindow::createRenameButton()
{
    m_renameButton = new QPushButton("Rename Files", this);

    m_renameButton->setMinimumHeight(45);

    m_mainLayout->addWidget(m_renameButton);
}

void MainWindow::connectSignals()
{
    // Add Files button
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

            statusBar()->showMessage(
                QString("Loaded %1 file(s)").arg(m_files.size()));
        });

	// Add Folder button
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

            statusBar()->showMessage(
                QString("Loaded %1 file(s)")
                .arg(m_files.size()));
        });

    // Drag & Drop
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

            statusBar()->showMessage(
                QString("Loaded %1 file(s)").arg(m_files.size()));
        });

	// Rename Panel
    connect(
        m_renamePanel,
        &RenamePanel::prefixChanged,
        this,
        [this](const QString& prefix)
        {
            m_renameOptions.prefix = prefix;

            m_renameEngine.generatePreview(
                m_files,
                m_renameOptions);

            m_fileTable->refresh(m_files);
        });

	// Rename Button
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

                QMessageBox::information(
                    this,
                    "Success",
                    "Files renamed successfully.");
            }
            else
            {
                QMessageBox::warning(
                    this,
                    "Error",
                    "Some files could not be renamed.");
            }
        });

    connect(m_renamePanel, &RenamePanel::prefixChanged,
        this, [this](const QString& value)
        {
            m_renameOptions.prefix = value;
            m_renameEngine.generatePreview(m_files, m_renameOptions);
            m_fileTable->refresh(m_files);
        });

    connect(m_renamePanel, &RenamePanel::suffixChanged,
        this, [this](const QString& value)
        {
            m_renameOptions.suffix = value;
            m_renameEngine.generatePreview(m_files, m_renameOptions);
            m_fileTable->refresh(m_files);
        });

    connect(m_renamePanel, &RenamePanel::numberingChanged,
        this, [this](bool value)
        {
            m_renameOptions.useNumbering = value;
            m_renameEngine.generatePreview(m_files, m_renameOptions);
            m_fileTable->refresh(m_files);
        });

    connect(m_renamePanel, &RenamePanel::startNumberChanged,
        this, [this](int value)
        {
            m_renameOptions.startNumber = value;
            m_renameEngine.generatePreview(m_files, m_renameOptions);
            m_fileTable->refresh(m_files);
        });

    connect(m_renamePanel, &RenamePanel::incrementChanged,
        this, [this](int value)
        {
            m_renameOptions.increment = value;
            m_renameEngine.generatePreview(m_files, m_renameOptions);
            m_fileTable->refresh(m_files);
        });

    connect(m_renamePanel, &RenamePanel::paddingChanged,
        this, [this](int value)
        {
            m_renameOptions.padding = value;
            m_renameEngine.generatePreview(m_files, m_renameOptions);
            m_fileTable->refresh(m_files);
        });
}