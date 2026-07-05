/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : main.cpp
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */


#include <QApplication>
#include "ui/MainWindow.h"
#include "core/ThemeManager.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

	ThemeManager::ApplyTheme(app);

    MainWindow window;
    window.show();

    return app.exec();
}