#include "vertexdatadockwidget.h"
#include "ui_vertexdatadockwidget.h"

VertexDataDockWidget::VertexDataDockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::VertexDataDockWidget)
{
    ui->setupUi(this);
}

VertexDataDockWidget::~VertexDataDockWidget()
{
    delete ui;
}
