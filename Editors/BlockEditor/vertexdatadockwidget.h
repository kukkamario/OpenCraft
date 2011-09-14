#ifndef VERTEXDATADOCKWIDGET_H
#define VERTEXDATADOCKWIDGET_H

#include <QDockWidget>

namespace Ui {
    class VertexDataDockWidget;
}

class VertexDataDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit VertexDataDockWidget(QWidget *parent = 0);
    ~VertexDataDockWidget();

private:
    Ui::VertexDataDockWidget *ui;
};

#endif // VERTEXDATADOCKWIDGET_H
