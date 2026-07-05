#include "ui/MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setupWindow();
}

void MainWindow::setupWindow()
{
    setWindowTitle("NovaBytes Batch Renamer");

    resize(1200, 700);

    setMinimumSize(900, 600);
}