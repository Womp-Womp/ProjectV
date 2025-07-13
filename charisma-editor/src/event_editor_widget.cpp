#include "event_editor_widget.h"
#include <QLabel>
#include <QVBoxLayout>

EventEditorWidget::EventEditorWidget(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Event Editor", this);
    layout->addWidget(label);
    setLayout(layout);
}
