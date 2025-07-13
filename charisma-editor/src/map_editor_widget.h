#ifndef MAP_EDITOR_WIDGET_H
#define MAP_EDITOR_WIDGET_H

#include <QWidget>

class MapEditorWidget : public QWidget {
    Q_OBJECT

public:
    explicit MapEditorWidget(QWidget *parent = nullptr);
    ~MapEditorWidget();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    // Add map data members here
};

#endif // MAP_EDITOR_WIDGET_H
