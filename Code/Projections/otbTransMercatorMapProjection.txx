/*=========================================================================

  Program:   ORFEO Toolbox
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See OTBCopyright.txt for details.


     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __otbTransMercatorMapProjection_txx
#define __otbTransMercatorMapProjection_txx

#include "otbTransMercatorMapProjection.h"

namespace otb
{

template <Transform::TransformationDirection transform>
TransMercatorMapProjection<transform>
::TransMercatorMapProjection()
{
  ossimEllipsoid ellipsoid = *(ossimEllipsoidFactory::instance()->create("WE"));
  ossimGpt origin(49.83, 6.16); //TODO check where this is coming from
  this->m_MapProjection->setEllipsoid(ellipsoid);
  this->m_MapProjection->setOrigin(origin);
}

/// Desctructor
template <Transform::TransformationDirection transform>
TransMercatorMapProjection<transform>
::~TransMercatorMapProjection()
{
}

///Set the false Easting
template <Transform::TransformationDirection transform>
void TransMercatorMapProjection<transform>
::SetFalseEasting(double falseEasting)
{
  this->m_MapProjection->setFalseEasting(falseEasting);
}

///Set the False Northing
template <Transform::TransformationDirection transform>
void TransMercatorMapProjection<transform>
::SetFalseNorthing(double falseNorthing)
{
  this->m_MapProjection->setFalseNorthing(falseNorthing);
}

///Set the scale factor
template <Transform::TransformationDirection transform>
void TransMercatorMapProjection<transform>
::SetScaleFactor(double scaleFactor)
{
  this->m_MapProjection->setScaleFactor(scaleFactor);
}

///Set the parameters
template <Transform::TransformationDirection transform>
void TransMercatorMapProjection<transform>
::SetParameters(double falseEasting, double falseNorthing, double scaleFactor)
{
  this->m_MapProjection->setParameters(falseEasting, falseNorthing, scaleFactor);
}

///Set the default parameters
template <Transform::TransformationDirection transform>
void TransMercatorMapProjection<transform>
::SetDefaults()
{
  this->m_MapProjection->setDefaults();
}

///\return the scale factor
template <Transform::TransformationDirection transform>
double TransMercatorMapProjection<transform>
::GetScaleFactor() const
{
  double scaleFactor;
  scaleFactor = this->m_MapProjection->getScaleFactor();

  return scaleFactor;
}

///\return the false northing (avoid negative coordinates)
template <Transform::TransformationDirection transform>
double TransMercatorMapProjection<transform>
::GetFalseNorthing() const
{
  double falseNorthing = this->m_MapProjection->getFalseNorthing();

  return falseNorthing;
}

///\return the false easting (avoid negative coordinates)
template <Transform::TransformationDirection transform>
double TransMercatorMapProjection<transform>
::GetFalseEasting() const
{
  double falseEasting = this->m_MapProjection->getFalseEasting();

  return falseEasting;
}

}
#endif
