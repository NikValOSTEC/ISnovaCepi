#pragma once

#include <QLineEdit>

class QLineEditFocusOutSignal  : public QLineEdit
{
	Q_OBJECT

public:
	QLineEditFocusOutSignal(QWidget *parent);
	~QLineEditFocusOutSignal();
	virtual void focusInEvent(QFocusEvent* e);
	virtual void focusOutEvent(QFocusEvent* e);
signals:
	void focussed(bool hasFocus);
};
