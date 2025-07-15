#include "main_window.h"
#include "map_editor_widget.h"
#include "unit_editor_widget.h"
#include "faction_editor_widget.h"
#include "event_editor_widget.h"
#include "media_manager_widget.h"
#include "lore_editor_widget.h"
#include "project_manager.h"
#include <QTabWidget>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Charisma Editor");

    projectManager = new ProjectManager();

    tabWidget = new QTabWidget(this);
    MapEditorWidget *mapEditor = new MapEditorWidget(tabWidget);
    UnitEditorWidget *unitEditor = new UnitEditorWidget(tabWidget);
    FactionEditorWidget *factionEditor = new FactionEditorWidget(tabWidget);
    EventEditorWidget *eventEditor = new EventEditorWidget(tabWidget);
    MediaManagerWidget *mediaManager = new MediaManagerWidget(tabWidget);
    loreEditor = new LoreEditorWidget(tabWidget);
    tabWidget->addTab(mapEditor, "Map Editor");
    tabWidget->addTab(unitEditor, "Unit Editor");
    tabWidget->addTab(factionEditor, "Faction Editor");
    tabWidget->addTab(eventEditor, "Event Editor");
    tabWidget->addTab(mediaManager, "Media Manager");
    tabWidget->addTab(loreEditor, "Lore Editor");

    setCentralWidget(tabWidget);

    createMenus();
}

void MainWindow::createMenus() {
    QMenuBar *menuBar = this->menuBar();
    QMenu *fileMenu = menuBar->addMenu("File");

    QAction *newAction = fileMenu->addAction("New Project");
    connect(newAction, &QAction::triggered, this, [=]() {
        QString dir = QFileDialog::getExistingDirectory(this, "Create New Project", "", QFileDialog::ShowDirsOnly);
        if (!dir.isEmpty()) {
            projectManager->createNewProject(dir);
        }
    });

    QAction *openAction = fileMenu->addAction("Open Project");
    connect(openAction, &QAction::triggered, this, [=]() {
        QString dir = QFileDialog::getExistingDirectory(this, "Open Project", "", QFileDialog::ShowDirsOnly);
        if (!dir.isEmpty()) {
            projectManager->loadProject(dir);
        }
    });

    QAction *saveAction = fileMenu->addAction("Save Project");
    connect(saveAction, &QAction::triggered, projectManager, &ProjectManager::saveProject);

    fileMenu->addSeparator();
    QAction *exitAction = fileMenu->addAction("Exit");
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
}
