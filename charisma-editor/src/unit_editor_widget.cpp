#include "unit_editor_widget.h"
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>

UnitEditorWidget::UnitEditorWidget(QWidget *parent) : QWidget(parent) {
    mainLayout = new QGridLayout(this);
    setLayout(mainLayout);

    createUnitList();
    createUnitEditor();
}

void UnitEditorWidget::createUnitList() {
    QVBoxLayout *listLayout = new QVBoxLayout();

    unitList = new QListWidget();
    listLayout->addWidget(unitList);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    newButton = new QPushButton("New");
    deleteButton = new QPushButton("Delete");
    cloneButton = new QPushButton("Clone");
    buttonLayout->addWidget(newButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(cloneButton);
    listLayout->addLayout(buttonLayout);

    mainLayout->addLayout(listLayout, 0, 0);
}

void UnitEditorWidget::createUnitEditor() {
    QFormLayout *editorLayout = new QFormLayout();

    nameLineEdit = new QLineEdit();
    editorLayout->addRow("Name:", nameLineEdit);

    hpSpinBox = new QSpinBox();
    editorLayout->addRow("HP:", hpSpinBox);

    enSpinBox = new QSpinBox();
    editorLayout->addRow("EN:", enSpinBox);

    attackSpinBox = new QSpinBox();
    editorLayout->addRow("Attack:", attackSpinBox);

    defenseSpinBox = new QSpinBox();
    editorLayout->addRow("Defense:", defenseSpinBox);

    mainLayout->addLayout(editorLayout, 0, 1);
}
