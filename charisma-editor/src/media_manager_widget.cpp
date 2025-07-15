#include "media_manager_widget.h"
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPixmap>

MediaManagerWidget::MediaManagerWidget(QWidget *parent) : QWidget(parent) {
    mainLayout = new QGridLayout(this);
    setLayout(mainLayout);

    createAssetList();
    createPreview();
}

void MediaManagerWidget::createAssetList() {
    QVBoxLayout *listLayout = new QVBoxLayout();

    assetList = new QListWidget();
    connect(assetList, &QListWidget::currentItemChanged, this, [=](QListWidgetItem *current) {
        if (current) {
            previewLabel->setPixmap(QPixmap(current->text()).scaled(200, 200, Qt::KeepAspectRatio));
        }
    });
    listLayout->addWidget(assetList);

    importButton = new QPushButton("Import");
    connect(importButton, &QPushButton::clicked, this, [=]() {
        QStringList files = QFileDialog::getOpenFileNames(this, "Import Assets", "", "Images (*.png *.jpg);;Audio (*.ogg *.mp3)");
        assetList->addItems(files);
    });
    listLayout->addWidget(importButton);

    mainLayout->addLayout(listLayout, 0, 0);
}

void MediaManagerWidget::createPreview() {
    previewLabel = new QLabel();
    previewLabel->setFixedSize(200, 200);
    previewLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(previewLabel, 0, 1);
}
