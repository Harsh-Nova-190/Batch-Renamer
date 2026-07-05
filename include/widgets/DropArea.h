/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : DropArea.h
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */

#pragma once
#include <QFrame>

class QLabel;

class DropArea : public QFrame
{
	Q_OBJECT

public:
	explicit DropArea(QWidget* parent = nullptr);

private:
	QLabel* m_titleLabel;
	QLabel* m_subTitleLabel;

	void setupUI();

};