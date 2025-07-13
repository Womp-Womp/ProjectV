#include "media_manager_widget.h"
#include <QLabel>
#include <QVBoxLayout>

MediaManagerWidget::MediaManagerWidget(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Media Manager", this);
    layout->addWidget(label);
    setLayout(layout);
}
