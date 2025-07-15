#include "map_editor_widget.h"
#include <QPainter>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>

MapEditorWidget::MapEditorWidget(QWidget *parent) : QWidget(parent) {
    mainLayout = new QGridLayout(this);
    setLayout(mainLayout);

    createTools();
}

MapEditorWidget::~MapEditorWidget() {
}

void MapEditorWidget::createTools() {
    QVBoxLayout *toolsLayout = new QVBoxLayout();

    toolSelector = new QComboBox();
    toolSelector->addItem("Brush");
    toolSelector->addItem("Fill");
    toolSelector->addItem("Eraser");
    toolsLayout->addWidget(toolSelector);

    widthSpinBox = new QSpinBox();
    widthSpinBox->setRange(10, 500);
    widthSpinBox->setValue(50);
    toolsLayout->addWidget(new QLabel("Width:"));
    toolsLayout->addWidget(widthSpinBox);

    heightSpinBox = new QSpinBox();
    heightSpinBox->setRange(10, 500);
    heightSpinBox->setValue(50);
    toolsLayout->addWidget(new QLabel("Height:"));
    toolsLayout->addWidget(heightSpinBox);

    newMapButton = new QPushButton("New Map");
    connect(newMapButton, &QPushButton::clicked, this, &MapEditorWidget::createMap);
    toolsLayout->addWidget(newMapButton);

    mainLayout->addLayout(toolsLayout, 0, 0);
}

void MapEditorWidget::createMap() {
    // TODO: Implement map creation logic
    update();
}

void MapEditorWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBrush(Qt::lightGray);
    painter.drawRect(rect());

    // Add grid drawing logic here
}
