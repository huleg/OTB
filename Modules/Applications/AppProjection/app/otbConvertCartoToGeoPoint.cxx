/*=========================================================================

  Program:   ORFEO Toolbox
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See OTBCopyright.txt for details.


     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE,  See the above copyright notices for more information.

=========================================================================*/
#include "otbWrapperApplicationFactory.h"

#include <iostream>
#include <iomanip>

#include "otbWrapperNumericalParameter.h"
#include "otbWrapperMapProjectionParametersHandler.h"

#include "otbImageToGenericRSOutputParameters.h"

namespace otb
{
namespace Wrapper
{

class ConvertCartoToGeoPoint : public Application
{
public:
  /** Standard class typedefs. */
  typedef ConvertCartoToGeoPoint                    Self;
  typedef Application                   Superclass;
  typedef itk::SmartPointer<Self>       Pointer;
  typedef itk::SmartPointer<const Self> ConstPointer;

  /** Standard macro */
  itkNewMacro(Self);

  itkTypeMacro(ConvertCartoToGeoPoint, otb::Application);

  typedef otb::GenericRSTransform<>        TransformType;

private:
  void DoInit() ITK_OVERRIDE
  {
    SetName("ConvertCartoToGeoPoint");
    SetDescription("Convert cartographic coordinates to geographic one.");

    // Documentation
    SetDocName("Cartographic to geographic coordinates conversion");
    SetDocLongDescription("This application computes the geographic coordinates from a cartographic one. User has to give the X and Y coordinate and the cartographic projection (UTM/LAMBERT/LAMBERT2/LAMBERT93/SINUS/ECKERT4/TRANSMERCATOR/MOLLWEID/SVY21).");
    SetDocLimitations("None");
    SetDocAuthors("OTB-Team");
    SetDocSeeAlso(" ");

    AddDocTag(Tags::Geometry);
	AddDocTag(Tags::Coordinates);

    AddParameter(ParameterType_Group, "carto", "Input cartographic coordinates");
    AddParameter(ParameterType_Float, "carto.x", "X cartographic coordinates");
    SetParameterDescription("carto.x", "X cartographic coordinates in the specified projection.");

    AddParameter(ParameterType_Float, "carto.y", "Y cartographic coordinates");
    SetParameterDescription("carto.y", "Y cartographic coordinates in the specified projection.");

    // Add the MapProjectionParameters
    MapProjectionParametersHandler::AddMapProjectionParameters(this, "mapproj");

    AddParameter(ParameterType_Float, "long", "Output long");
    SetParameterDescription("long", "Point longitude coordinates.");
    SetParameterRole("long", Role_Output);

    AddParameter(ParameterType_Float, "lat", "Output lat");
    SetParameterDescription("lat", "Point latitude coordinates.");
    SetParameterRole("lat", Role_Output);

    // Doc example parameter settings
    SetDocExampleParameterValue("carto.x", "367074.625");
    SetDocExampleParameterValue("carto.y", "4835740");
    SetDocExampleParameterValue("mapproj", "utm");
    SetDocExampleParameterValue("mapproj.utm.northhem", "true");
    SetDocExampleParameterValue("mapproj.utm.zone", "31");
  }

  void DoUpdateParameters() ITK_OVERRIDE
  {
  }

  void DoExecute() ITK_OVERRIDE
  {
    // Get the projectionRef
    std::string inputProjRef = MapProjectionParametersHandler::GetProjectionRefFromChoice(this, "mapproj");

    // Instantiate a GenericRSTransform
    // Input : coordiante system picked up by the user
    // Output : WGS84 corresponding to epsg code 4326
    TransformType::Pointer  transform = TransformType::New();
    transform->SetInputProjectionRef(inputProjRef);
    transform->SetOutputProjectionRef(otb::GeoInformationConversion::ToWKT(4326));
    transform->InstantiateTransform();

    TransformType::InputPointType   cartoPoint;
    TransformType::OutputPointType  geoPoint;

    cartoPoint[0] = GetParameterFloat("carto.x");
    cartoPoint[1] = GetParameterFloat("carto.y");

    geoPoint = transform->TransformPoint(cartoPoint);

    otbAppLogINFO( << std::setprecision(10) << "Cartographic Point  (x , y)  : (" << cartoPoint[0] << ", " << cartoPoint[1] << ")" );
    otbAppLogINFO( << std::setprecision(10) << "Geographic   Point (Long, Lat) : (" << geoPoint[0] << ", " <<  geoPoint[1] << ")" );


    SetParameterFloat( "long", geoPoint[0] );
    SetParameterFloat( "lat", geoPoint[1] );
  }
};

}
}

OTB_APPLICATION_EXPORT(otb::Wrapper::ConvertCartoToGeoPoint)
