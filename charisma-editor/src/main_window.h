#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class QTabWidget;
class ProjectManager;
class LoreEditorWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void createMenus();

    QTabWidget *tabWidget;
    ProjectManager *projectManager;
    LoreEditorWidget *loreEditor;
};

#endif // MAIN_WINDOW_H
