#ifndef EVENT_EDITOR_WIDGET_H
#define EVENT_EDITOR_WIDGET_H

#include <QWidget>

class EventEditorWidget : public QWidget {
    Q_OBJECT

public:
    explicit EventEditorWidget(QWidget *parent = nullptr);

private:
    // Add event editor UI elements here
};

#endif // EVENT_EDITOR_WIDGET_H
