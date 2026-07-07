/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : main.cpp
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */


#include <QApplication>
#include <QIcon>
#include <QDebug>
#include <QFile>
#include "ui/MainWindow.h"
#include "core/ThemeManager.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("NovaBytes Batch Renamer");
    app.setOrganizationName("NovaBytes");
    app.setApplicationVersion("1.0.0");

    app.setWindowIcon(QIcon(":/branding/NovaBytes.ico"));

	ThemeManager::ApplyTheme(app);

    MainWindow window;
    window.show();

    return app.exec();
}