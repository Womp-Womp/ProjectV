#include "gtest/gtest.h"
#include "project_manager.h"

TEST(ProjectManagerTest, CreateNewProject) {
    ProjectManager pm;
    pm.createNewProject("test_project");
    // Add assertions here
}
