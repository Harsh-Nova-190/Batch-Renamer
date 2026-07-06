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
#include <QStringList>

class QLabel;
class QDragEnterEvent;
class QDropEvent;

class DropArea : public QFrame
{
	Q_OBJECT

public:
	explicit DropArea(QWidget* parent = nullptr);

private:
	QLabel* m_titleLabel;
	QLabel* m_subTitleLabel;

	void setupUI();

signals:
	void filesDropped(const QStringList& filePaths);

protected:
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dropEvent(QDropEvent* event) override;

};