#include "QLineEditFocusOutSignal.h"

QLineEditFocusOutSignal::QLineEditFocusOutSignal(QWidget *parent)
	: QLineEdit(parent)
{}



QLineEditFocusOutSignal::~QLineEditFocusOutSignal()
{}

void QLineEditFocusOutSignal::focusInEvent(QFocusEvent * e)
{
	emit focussed(true);
	QLineEdit::focusInEvent(e);
}

void QLineEditFocusOutSignal::focusOutEvent(QFocusEvent* e)
{
	emit focussed(false);
	QLineEdit::focusOutEvent(e);
}
