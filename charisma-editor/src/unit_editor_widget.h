#ifndef UNIT_EDITOR_WIDGET_H
#define UNIT_EDITOR_WIDGET_H

#include <QWidget>

class QListWidget;
class QPushButton;
class QLineEdit;
class QSpinBox;
class QGridLayout;

class UnitEditorWidget : public QWidget {
    Q_OBJECT

public:
    explicit UnitEditorWidget(QWidget *parent = nullptr);

private:
    void createUnitList();
    void createUnitEditor();

    QGridLayout *mainLayout;
    QListWidget *unitList;
    QPushButton *newButton;
    QPushButton *deleteButton;
    QPushButton *cloneButton;
    QLineEdit *nameLineEdit;
    QSpinBox *hpSpinBox;
    QSpinBox *enSpinBox;
    QSpinBox *attackSpinBox;
    QSpinBox *defenseSpinBox;
};

#endif // UNIT_EDITOR_WIDGET_H
