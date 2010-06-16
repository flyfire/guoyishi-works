/////////////////////////////
// Date: 2010-06-15
// Copier: Yishi Guo
/////////////////////////////
#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QSpinBox>
#include <QtGui/QSlider>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>

int main( int argc, char** argv ) {
  QApplication app( argc, argv );
  QWidget *window = new QWidget;
  window->setWindowTitle( "Enter your age" );

  QSpinBox *spinBox = new QSpinBox;
  QSlider *slider = new QSlider( Qt::Horizontal );
  spinBox->setRange( 0, 130 );
  slider->setRange( 0, 130 );

  QObject::connect( slider,
                    SIGNAL( valueChanged(int) ),
                    spinBox,
                    SLOT( setValue(int) )
                  );
  QObject::connect( spinBox,
                    SIGNAL( valueChanged(int) ),
                    slider,
                    SLOT( setValue(int) )
                  );
  spinBox->setValue( 35 );

  QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget( spinBox );
  layout->addWidget( slider );
  window->setLayout( layout );

  window->show();

  return app.exec();
}
