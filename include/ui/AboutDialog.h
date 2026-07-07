/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : AboutDialog.h
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#pragma once

#include <QDialog>

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget* parent = nullptr);

private:
    void setupUI();
};