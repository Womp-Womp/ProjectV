#ifndef FACTION_EDITOR_WIDGET_H
#define FACTION_EDITOR_WIDGET_H

#include <QWidget>

class QListWidget;
class QPushButton;
class QLineEdit;
class QSpinBox;
class QGridLayout;
class QColorDialog;

class FactionEditorWidget : public QWidget {
    Q_OBJECT

public:
    explicit FactionEditorWidget(QWidget *parent = nullptr);

private:
    void createFactionList();
    void createFactionEditor();

    QGridLayout *mainLayout;
    QListWidget *factionList;
    QPushButton *newButton;
    QPushButton *deleteButton;
    QLineEdit *nameLineEdit;
    QPushButton *colorButton;
};

#endif // FACTION_EDITOR_WIDGET_H
