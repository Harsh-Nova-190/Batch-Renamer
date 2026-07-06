/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : RenamePanel.h
 * ------------------------------------------------------------
 */

#pragma once

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QSpinBox>

class QLineEdit;
class QCheckBox;
class QSpinBox;

class RenamePanel : public QWidget
{
    Q_OBJECT

public:
    explicit RenamePanel(QWidget* parent = nullptr);

signals:
    void optionsChanged();

    void prefixChanged(const QString&);
    void suffixChanged(const QString&);
    void numberingChanged(bool);
    void startNumberChanged(int);
    void incrementChanged(int);
    void paddingChanged(int);

private:
    QLineEdit* m_prefixEdit;
    QLineEdit* m_suffixEdit;

    QCheckBox* m_numberingCheck;

    QSpinBox* m_startSpin;
    QSpinBox* m_incrementSpin;
    QSpinBox* m_paddingSpin;

    void setupUI();
    void connectSignals();
};