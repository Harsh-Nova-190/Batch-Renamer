/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : RenamePanel.cpp
 * ------------------------------------------------------------
 */

#include "widgets/RenamePanel.h"

#include <QFormLayout>
#include <QLineEdit>

RenamePanel::RenamePanel(QWidget* parent)
    : QWidget(parent)
{
    setupUI();
    connectSignals();
}

void RenamePanel::setupUI()
{
    auto* layout = new QFormLayout(this);

    m_prefixEdit = new QLineEdit(this);
    m_suffixEdit = new QLineEdit(this);

    m_numberingCheck = new QCheckBox("Enable Numbering", this);

    m_startSpin = new QSpinBox(this);
    m_incrementSpin = new QSpinBox(this);
    m_paddingSpin = new QSpinBox(this);

    m_startSpin->setMinimum(1);

    m_incrementSpin->setMinimum(1);

    m_paddingSpin->setRange(1, 10);
    m_paddingSpin->setValue(3);

    layout->addRow("Prefix", m_prefixEdit);
    layout->addRow("Suffix", m_suffixEdit);
    layout->addRow("", m_numberingCheck);
    layout->addRow("Start", m_startSpin);
    layout->addRow("Increment", m_incrementSpin);
    layout->addRow("Padding", m_paddingSpin);
}

void RenamePanel::connectSignals()
{
    connect(m_prefixEdit,
        &QLineEdit::textChanged,
        this,
        &RenamePanel::prefixChanged);

    connect(m_suffixEdit,
        &QLineEdit::textChanged,
        this,
        &RenamePanel::suffixChanged);

    connect(m_numberingCheck,
        &QCheckBox::toggled,
        this,
        &RenamePanel::numberingChanged);

    connect(m_startSpin,
        qOverload<int>(&QSpinBox::valueChanged),
        this,
        &RenamePanel::startNumberChanged);

    connect(m_incrementSpin,
        qOverload<int>(&QSpinBox::valueChanged),
        this,
        &RenamePanel::incrementChanged);

    connect(m_paddingSpin,
        qOverload<int>(&QSpinBox::valueChanged),
        this,
        &RenamePanel::paddingChanged);
}