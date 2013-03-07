/*=========================================================================

  Program:   Monteverdi2
  Language:  C++


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See Copyright.txt for details.

  Monteverdi2 is distributed under the CeCILL licence version 2. See
  Licence_CeCILL_V2-en.txt or
  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt for more details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __mvdColorBandDynamicsWidget_h
#define __mvdColorBandDynamicsWidget_h

//
// Configuration include.
//// Included at first position before any other ones.
#include "ConfigureMonteverdi2.h"


/*****************************************************************************/
/* INCLUDE SECTION                                                           */

//
// Qt includes (sorted by alphabetic order)
//// Must be included before system/custom includes.
#include <QtGui>

//
// System includes (sorted by alphabetic order)

//
// ITK includes (sorted by alphabetic order)

//
// OTB includes (sorted by alphabetic order)

//
// Monteverdi includes (sorted by alphabetic order)
#include "mvdGui.h"


/*****************************************************************************/
/* PRE-DECLARATION SECTION                                                   */

//
// External classes pre-declaration.
namespace
{
}

namespace mvd
{
//
// Internal classes pre-declaration.
namespace Ui
{
class ColorBandDynamicsWidget;
};


/*****************************************************************************/
/* CLASS DEFINITION SECTION                                                  */

/**
 * \class ColorBandDynamicsWidget
 */
class Monteverdi2_EXPORT ColorBandDynamicsWidget :
    public QWidget
{

  /*-[ QOBJECT SECTION ]-----------------------------------------------------*/

  Q_OBJECT;

  /** */
  Q_PROPERTY( RgbaChannel channelLabel
	      READ GetChannelLabel
	      WRITE SetChannelLabel );

  /** */
  Q_PROPERTY( double minIntensity
	      READ GetMinIntensity
	      WRITE SetMinIntensity );

  /** */
  Q_PROPERTY( double maxIntensity
	      READ GetMaxIntensity
	      WRITE SetMaxIntensity );

  /** */
  Q_PROPERTY( double lowIntensity
	      READ GetLowIntensity
	      WRITE SetLowIntensity );

  /** */
  Q_PROPERTY( double highIntensity
	      READ GetHighIntensity
	      WRITE SetHighIntensity );

  /** */
  Q_PROPERTY( double lowQuantile
	      READ GetLowQuantile
	      WRITE SetLowQuantile );

  /** */
  Q_PROPERTY( double highQuantile
	      READ GetHighQuantile
	      WRITE SetHighQuantile );

  /*-[ PUBLIC SECTION ]------------------------------------------------------*/

//
// Public methods.
public:

  /** Constructor */
  ColorBandDynamicsWidget( QWidget* parent =NULL, Qt::WindowFlags flags =0 );

  /** Destructor */
  virtual ~ColorBandDynamicsWidget();

  /** */
  RgbaChannel GetChannelLabel() const;
  /** */
  void SetChannelLabel( RgbaChannel );

  /** */
  double GetMinIntensity() const;
  /** */
  void SetMinIntensity( double );

  /** */
  double GetMaxIntensity() const;
  /** */
  void SetMaxIntensity( double );

  /** */
  double GetLowIntensity() const;
  /** */
  void SetLowIntensity( double );

  /** */
  double GetHighIntensity() const;
  /** */
  void SetHighIntensity( double );

  /** */
  double GetLowQuantile() const;
  /** */
  void SetLowQuantile( double );

  /** */
  double GetHighQuantile() const;
  /** */
  void SetHighQuantile( double );

  /*-[ SIGNALS SECTION ]-----------------------------------------------------*/

//
// Signals.
signals:
  /** */
  void LowQuantileChanged( RgbaChannel, double );
  /** */
  void HighQuantileChanged( RgbaChannel, double );
  /** */
  void LowIntensityChanged( RgbaChannel, double );
  /** */
  void HighIntensityChanged( RgbaChannel, double );

  /** */
  void ResetIntensityClicked( RgbaChannel );
  /** */
  void ResetQuantileClicked( RgbaChannel );
  /** */
  void ApplyAllClicked( RgbaChannel, double, double);


  /*-[ PROTECTED SECTION ]---------------------------------------------------*/

//
// Protected methods.
protected:

//
// Protected attributes.
protected:

  /*-[ PRIVATE SECTION ]-----------------------------------------------------*/

//
// Private methods.
private:

//
// Private attributes.
private:
  /**
   * uic generated.
   */
  Ui::ColorBandDynamicsWidget* m_UI;

  /** */
  RgbaChannel m_Channel;

  /*-[ PRIVATE SLOTS SECTION ]-----------------------------------------------*/

//
// Slots.
private slots:
  void on_lowIntensitySpinBox_valueChanged( double );
  void on_highIntensitySpinBox_valueChanged( double );

  void on_lowQuantileSpinBox_valueChanged( double );
  void on_highQuantileSpinBox_valueChanged( double );

  void on_minMaxButton_clicked();
  void on_defaultsButton_clicked();
  void on_applyAllButton_clicked();
};

} // end namespace 'mvd'.

#endif // __mvdColorBandDynamicsWidget_h
