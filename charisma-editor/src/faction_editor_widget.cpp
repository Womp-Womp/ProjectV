#include "faction_editor_widget.h"
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QColorDialog>

FactionEditorWidget::FactionEditorWidget(QWidget *parent) : QWidget(parent) {
    mainLayout = new QGridLayout(this);
    setLayout(mainLayout);

    createFactionList();
    createFactionEditor();
}

void FactionEditorWidget::createFactionList() {
    QVBoxLayout *listLayout = new QVBoxLayout();

    factionList = new QListWidget();
    listLayout->addWidget(factionList);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    newButton = new QPushButton("New");
    deleteButton = new QPushButton("Delete");
    buttonLayout->addWidget(newButton);
    buttonLayout->addWidget(deleteButton);
    listLayout->addLayout(buttonLayout);

    mainLayout->addLayout(listLayout, 0, 0);
}

void FactionEditorWidget::createFactionEditor() {
    QFormLayout *editorLayout = new QFormLayout();

    nameLineEdit = new QLineEdit();
    editorLayout->addRow("Name:", nameLineEdit);

    colorButton = new QPushButton("Choose Color");
    connect(colorButton, &QPushButton::clicked, this, [=]() {
        QColor color = QColorDialog::getColor();
        if (color.isValid()) {
            QString styleSheet = QString("background-color: %1").arg(color.name());
            colorButton->setStyleSheet(styleSheet);
        }
    });
    editorLayout->addRow("Color:", colorButton);

    mainLayout->addLayout(editorLayout, 0, 1);
}
