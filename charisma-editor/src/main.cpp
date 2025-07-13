#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QFileDialog>
#include "project_manager.h"
#include "map_editor_widget.h"
#include "unit_editor_widget.h"
#include "faction_editor_widget.h"
#include "event_editor_widget.h"
#include "media_manager_widget.h"
#include <QTabWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ProjectManager projectManager;

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Charisma Editor");

    QTabWidget *tabWidget = new QTabWidget(&mainWindow);
    MapEditorWidget *mapEditor = new MapEditorWidget(tabWidget);
    UnitEditorWidget *unitEditor = new UnitEditorWidget(tabWidget);
    FactionEditorWidget *factionEditor = new FactionEditorWidget(tabWidget);
    EventEditorWidget *eventEditor = new EventEditorWidget(tabWidget);
    MediaManagerWidget *mediaManager = new MediaManagerWidget(tabWidget);
    tabWidget->addTab(mapEditor, "Map Editor");
    tabWidget->addTab(unitEditor, "Unit Editor");
    tabWidget->addTab(factionEditor, "Faction Editor");
    tabWidget->addTab(eventEditor, "Event Editor");
    tabWidget->addTab(mediaManager, "Media Manager");

    mainWindow.setCentralWidget(tabWidget);

    QMenuBar *menuBar = mainWindow.menuBar();
    QMenu *fileMenu = menuBar->addMenu("File");

    QAction *newAction = fileMenu->addAction("New Project");
    QObject::connect(newAction, &QAction::triggered, [&]() {
        QString dir = QFileDialog::getExistingDirectory(&mainWindow, "Create New Project", "", QFileDialog::ShowDirsOnly);
        if (!dir.isEmpty()) {
            projectManager.createNewProject(dir);
        }
    });

    QAction *openAction = fileMenu->addAction("Open Project");
    QObject::connect(openAction, &QAction::triggered, [&]() {
        QString dir = QFileDialog::getExistingDirectory(&mainWindow, "Open Project", "", QFileDialog::ShowDirsOnly);
        if (!dir.isEmpty()) {
            projectManager.loadProject(dir);
        }
    });

    QAction *saveAction = fileMenu->addAction("Save Project");
    QObject::connect(saveAction, &QAction::triggered, [&]() { projectManager.saveProject(); });

    fileMenu->addSeparator();
    QAction *exitAction = fileMenu->addAction("Exit");

    QObject::connect(exitAction, &QAction::triggered, &app, &QApplication::quit);

    mainWindow.show();

    return app.exec();
}
