#pragma once

#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>

namespace qReal {
namespace gui {

class RenameDialog : public QDialog
{
public:
	static QString selectNewName(const QString &currentName, QWidget *parent = 0);

private slots:
	virtual void accept();
	virtual void reject();

private:
	explicit RenameDialog(const QString &initialText = "", QWidget *parent = 0);
	virtual ~RenameDialog();

	QString name() const;

	const QString mInitialName;
	QLineEdit *mTextBox;
};

}
}
