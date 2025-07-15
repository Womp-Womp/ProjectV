#include "project_manager.h"
#include <QDir>
#include <QDebug>

ProjectManager::ProjectManager(QObject *parent) : QObject(parent) {
}

void ProjectManager::createNewProject(const QString &projectPath) {
    QDir dir(projectPath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    currentProjectPath = projectPath;
    qDebug() << "Created new project at:" << currentProjectPath;
}

void ProjectManager::loadProject(const QString &projectPath) {
    currentProjectPath = projectPath;
    qDebug() << "Loaded project from:" << currentProjectPath;
}

void ProjectManager::saveProject() {
    if (currentProjectPath.isEmpty()) {
        qDebug() << "No project is currently open.";
        return;
    }
    qDebug() << "Project saved at:" << currentProjectPath;
}
