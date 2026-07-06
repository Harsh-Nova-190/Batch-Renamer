/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : DropArea.cpp
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#include "widgets/DropArea.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QFont>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QUrl>

DropArea::DropArea(QWidget* parent)
    : QFrame(parent)
{
    setupUI();
	setAcceptDrops(true);
}

void DropArea::setupUI()
{
    setObjectName("dropArea");

    auto* layout = new QVBoxLayout(this);

    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(10);

    m_titleLabel = new QLabel("📥 Drop Files Here", this);
    m_titleLabel->setAlignment(Qt::AlignCenter);

    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);

    m_titleLabel->setFont(titleFont);

    m_subTitleLabel = new QLabel("or click 'Add Files' above", this);
    m_subTitleLabel->setAlignment(Qt::AlignCenter);

    layout->addStretch();
    layout->addWidget(m_titleLabel);
    layout->addWidget(m_subTitleLabel);
    layout->addStretch();
}

void DropArea::dragEnterEvent(QDragEnterEvent* event)
{
    if (event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
    }
}

void DropArea::dropEvent(QDropEvent* event)
{
    QStringList paths;

    for (const QUrl& url : event->mimeData()->urls())
    {
        if (url.isLocalFile())
        {
            paths << url.toLocalFile();
        }
    }

    if (!paths.isEmpty())
    {
        emit filesDropped(paths);
    }

    event->acceptProposedAction();
}