#ifndef EVENT_EDITOR_WIDGET_H
#define EVENT_EDITOR_WIDGET_H

#include <QWidget>

class QListWidget;
class QPushButton;
class QTextEdit;
class QGridLayout;
class QComboBox;

class EventEditorWidget : public QWidget {
    Q_OBJECT

public:
    explicit EventEditorWidget(QWidget *parent = nullptr);

private:
    void createEventList();
    void createEventEditor();

    QGridLayout *mainLayout;
    QListWidget *eventList;
    QPushButton *newButton;
    QPushButton *deleteButton;
    QComboBox *triggerComboBox;
    QTextEdit *conditionTextEdit;
    QTextEdit *actionTextEdit;
    QTextEdit *luaTextEdit;
};

#endif // EVENT_EDITOR_WIDGET_H
