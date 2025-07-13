#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include <QObject>
#include <QString>

class ProjectManager {
public:
    ProjectManager();

    void createNewProject(const QString &projectPath);
    void loadProject(const QString &projectPath);
    void saveProject();

private:
    QString currentProjectPath;
};

#endif // PROJECT_MANAGER_H
