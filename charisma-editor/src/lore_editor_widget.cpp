#include "lore_editor_widget.h"
#include <QListWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QGridLayout>
#include <QVBoxLayout>

LoreEditorWidget::LoreEditorWidget(QWidget *parent) : QWidget(parent) {
    mainLayout = new QGridLayout(this);
    setLayout(mainLayout);

    createLoreList();
    createLoreEditor();
}

void LoreEditorWidget::createLoreList() {
    QVBoxLayout *listLayout = new QVBoxLayout();

    loreList = new QListWidget();
    listLayout->addWidget(loreList);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    newButton = new QPushButton("New");
    deleteButton = new QPushButton("Delete");
    buttonLayout->addWidget(newButton);
    buttonLayout->addWidget(deleteButton);
    listLayout->addLayout(buttonLayout);

    mainLayout->addLayout(listLayout, 0, 0);
}

void LoreEditorWidget::createLoreEditor() {
    textEditor = new QTextEdit();
    mainLayout->addWidget(textEditor, 0, 1);
}
