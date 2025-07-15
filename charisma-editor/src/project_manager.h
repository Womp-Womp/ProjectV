#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include <QObject>
#include <QString>

class ProjectManager : public QObject {
    Q_OBJECT
public:
    explicit ProjectManager(QObject *parent = nullptr);

    void createNewProject(const QString &projectPath);
    void loadProject(const QString &projectPath);
    void saveProject();

private:
    QString currentProjectPath;
};

#endif // PROJECT_MANAGER_H
