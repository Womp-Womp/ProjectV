#include "event_editor_widget.h"
#include <QListWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>

EventEditorWidget::EventEditorWidget(QWidget *parent) : QWidget(parent) {
    mainLayout = new QGridLayout(this);
    setLayout(mainLayout);

    createEventList();
    createEventEditor();
}

void EventEditorWidget::createEventList() {
    QVBoxLayout *listLayout = new QVBoxLayout();

    eventList = new QListWidget();
    listLayout->addWidget(eventList);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    newButton = new QPushButton("New");
    deleteButton = new QPushButton("Delete");
    buttonLayout->addWidget(newButton);
    buttonLayout->addWidget(deleteButton);
    listLayout->addLayout(buttonLayout);

    mainLayout->addLayout(listLayout, 0, 0);
}

void EventEditorWidget::createEventEditor() {
    QFormLayout *editorLayout = new QFormLayout();

    triggerComboBox = new QComboBox();
    triggerComboBox->addItem("Turn Number");
    triggerComboBox->addItem("Faction Captures Location");
    triggerComboBox->addItem("Unit is Destroyed");
    editorLayout->addRow("WHEN:", triggerComboBox);

    conditionTextEdit = new QTextEdit();
    editorLayout->addRow("IF:", conditionTextEdit);

    actionTextEdit = new QTextEdit();
    editorLayout->addRow("THEN DO:", actionTextEdit);

    luaTextEdit = new QTextEdit();
    editorLayout->addRow("Lua Script:", luaTextEdit);

    mainLayout->addLayout(editorLayout, 0, 1);
}
