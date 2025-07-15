#ifndef MAP_EDITOR_WIDGET_H
#define MAP_EDITOR_WIDGET_H

#include <QWidget>

class QGridLayout;
class QComboBox;
class QPushButton;
class QSpinBox;

class MapEditorWidget : public QWidget {
    Q_OBJECT

public:
    explicit MapEditorWidget(QWidget *parent = nullptr);
    ~MapEditorWidget();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void createTools();
    void createMap();

    QGridLayout *mainLayout;
    QComboBox *toolSelector;
    QPushButton *newMapButton;
    QSpinBox *widthSpinBox;
    QSpinBox *heightSpinBox;
};

#endif // MAP_EDITOR_WIDGET_H
