#include "unit_editor_widget.h"
#include <QLabel>
#include <QVBoxLayout>

UnitEditorWidget::UnitEditorWidget(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Unit Editor", this);
    layout->addWidget(label);
    setLayout(layout);
}
