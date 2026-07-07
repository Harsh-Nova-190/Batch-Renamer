#include "ui/AboutDialog.h"

#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

AboutDialog::AboutDialog(QWidget* parent)
    : QDialog(parent)
{
    setupUI();
}

void AboutDialog::setupUI()
{
    setWindowTitle("About NovaBytes Batch Renamer");
    setFixedSize(500, 300);

    auto* mainLayout = new QVBoxLayout(this);

    auto* topLayout = new QHBoxLayout();

    auto* logo = new QLabel(this);
    logo->setPixmap(
        QPixmap(":/branding/novabytes_nb_logo_512x512.png")
        .scaled(
            96,
            96,
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));

    auto* infoLayout = new QVBoxLayout();

    auto* title =
        new QLabel("<h2>NovaBytes Batch Renamer</h2>");

    auto* version =
        new QLabel("Version 1.0.0");

    auto* company =
        new QLabel("<b>Developed by Harsh Laskar</b>");

    auto* qt =
        new QLabel("Built with C++20 & Qt 6");

    infoLayout->addWidget(title);
    infoLayout->addWidget(version);
    infoLayout->addWidget(company);
    infoLayout->addWidget(qt);
    infoLayout->addStretch();

    topLayout->addWidget(logo);
    topLayout->addSpacing(20);
    topLayout->addLayout(infoLayout);

    auto* copyright =
        new QLabel(
            "© 2026 NovaBytes\n"
            "All Rights Reserved.");

    copyright->setAlignment(Qt::AlignCenter);

    auto* buttons =
        new QDialogButtonBox(QDialogButtonBox::Ok);

    connect(
        buttons,
        &QDialogButtonBox::accepted,
        this,
        &QDialog::accept);

    mainLayout->addLayout(topLayout);
    mainLayout->addStretch();
    mainLayout->addWidget(copyright);
    mainLayout->addWidget(buttons);
}