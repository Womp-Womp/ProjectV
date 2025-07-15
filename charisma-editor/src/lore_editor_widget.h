#ifndef LORE_EDITOR_WIDGET_H
#define LORE_EDITOR_WIDGET_H

#include <QWidget>

class QListWidget;
class QPushButton;
class QTextEdit;
class QGridLayout;

class LoreEditorWidget : public QWidget {
    Q_OBJECT

public:
    explicit LoreEditorWidget(QWidget *parent = nullptr);

private:
    void createLoreList();
    void createLoreEditor();

    QGridLayout *mainLayout;
    QListWidget *loreList;
    QPushButton *newButton;
    QPushButton *deleteButton;
    QTextEdit *textEditor;
};

#endif // LORE_EDITOR_WIDGET_H
