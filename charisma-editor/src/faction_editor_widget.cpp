#include "faction_editor_widget.h"
#include <QLabel>
#include <QVBoxLayout>

FactionEditorWidget::FactionEditorWidget(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Faction Editor", this);
    layout->addWidget(label);
    setLayout(layout);
}
