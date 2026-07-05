/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : MainWindow.cpp
 * ------------------------------------------------------------
 */

#include "ui/MainWindow.h"
#include "widgets/DropArea.h"
#include "widgets/FileTable.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QMenuBar>

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

    m_centralWidget = new QWidget(this);
    setCentralWidget(m_centralWidget);

    m_mainLayout = new QVBoxLayout(m_centralWidget);
    m_mainLayout->setContentsMargins(20, 20, 20, 20);
    m_mainLayout->setSpacing(20);

    m_toolbarLayout = new QHBoxLayout();
    m_toolbarLayout->setSpacing(12);

    m_addFilesButton = new QPushButton("Add Files");
    m_addFolderButton = new QPushButton("Add Folder");
    m_clearButton = new QPushButton("Clear");
    m_addFilesButton->setMinimumWidth(140);
    m_addFolderButton->setMinimumWidth(140);
    m_clearButton->setMinimumWidth(120);

    m_toolbarLayout->addWidget(m_addFilesButton);
    m_toolbarLayout->addWidget(m_addFolderButton);
    m_toolbarLayout->addWidget(m_clearButton);
    m_toolbarLayout->addStretch();

    m_dropArea = new DropArea(m_centralWidget);

    m_mainLayout->addLayout(m_toolbarLayout);
    m_mainLayout->addWidget(m_dropArea);

	m_fileTable = new FileTable(m_centralWidget);
	m_mainLayout->addWidget(m_fileTable);

    statusBar()->showMessage("Ready");

    statusBar()->addPermanentWidget(
        new QLabel("v0.1.0")
    );

    menuBar()->addMenu("File");
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Help");
}