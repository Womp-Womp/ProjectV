#ifndef MEDIA_MANAGER_WIDGET_H
#define MEDIA_MANAGER_WIDGET_H

#include <QWidget>

class QListWidget;
class QPushButton;
class QLabel;
class QGridLayout;

class MediaManagerWidget : public QWidget {
    Q_OBJECT

public:
    explicit MediaManagerWidget(QWidget *parent = nullptr);

private:
    void createAssetList();
    void createPreview();

    QGridLayout *mainLayout;
    QListWidget *assetList;
    QPushButton *importButton;
    QLabel *previewLabel;
};

#endif // MEDIA_MANAGER_WIDGET_H
