#ifndef MEDIA_MANAGER_WIDGET_H
#define MEDIA_MANAGER_WIDGET_H

#include <QWidget>

class MediaManagerWidget : public QWidget {
    Q_OBJECT

public:
    explicit MediaManagerWidget(QWidget *parent = nullptr);

private:
    // Add media manager UI elements here
};

#endif // MEDIA_MANAGER_WIDGET_H
