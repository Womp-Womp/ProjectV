#ifndef UNIT_EDITOR_WIDGET_H
#define UNIT_EDITOR_WIDGET_H

#include <QWidget>

class UnitEditorWidget : public QWidget {
    Q_OBJECT

public:
    explicit UnitEditorWidget(QWidget *parent = nullptr);

private:
    // Add unit editor UI elements here
};

#endif // UNIT_EDITOR_WIDGET_H
