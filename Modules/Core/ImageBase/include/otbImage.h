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
#ifndef otbImage_h
#define otbImage_h

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "itkImage.h"
#pragma GCC diagnostic pop
#else
#include "itkImage.h"
#endif

#include "otbImageMetadataInterfaceBase.h"

namespace otb
{
/** \class Image
 * \brief Creation of an "otb" image which contains metadata.
 *
 *
 * \ingroup OTBImageBase
 */

template <class TPixel, unsigned int VImageDimension = 2>
class ITK_EXPORT Image : public itk::Image<TPixel, VImageDimension>
{
public:
  /** Standard class typedefs. */
  typedef Image                               Self;
  typedef itk::Image<TPixel, VImageDimension> Superclass;
  typedef itk::SmartPointer<Self>             Pointer;
  typedef itk::SmartPointer<const Self>       ConstPointer;
  typedef itk::WeakPointer<const Self>        ConstWeakPointer;

  typedef ImageMetadataInterfaceBase::VectorType           VectorType;
  typedef ImageMetadataInterfaceBase::ImageKeywordlistType ImageKeywordlistType;
  typedef ImageMetadataInterfaceBase::Pointer              ImageMetadataInterfacePointerType;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(Image, itk::Image);

  /** Pixel typedef support. Used to declare pixel type in filters
   * or other operations. */
  typedef typename Superclass::PixelType PixelType;

  /** Typedef alias for PixelType */
  typedef typename Superclass::ValueType ValueType;

  /** Internal Pixel representation. Used to maintain a uniform API
   * with Image Adaptors and allow keeping a particular internal
   * representation of data while showing a different external
   * representation. */
  typedef typename Superclass::InternalPixelType InternalPixelType;

  typedef typename Superclass::IOPixelType IOPixelType;

  /** Accessor type that convert data between internal and external
   *  representations.  */
  //typedef itk::DefaultPixelAccessor< PixelType > AccessorType;
  //typedef itk::DefaultPixelAccessorFunctor< Self > AccessorFunctorType;

  /** Tyepdef for the functor used to access a neighborhood of pixel pointers.*/
  typedef itk::NeighborhoodAccessorFunctor<Self>
  NeighborhoodAccessorFunctorType;

  /** Dimension of the image.  This constant is used by functions that are
   * templated over image type (as opposed to being templated over pixel type
   * and dimension) when they need compile time access to the dimension of
   * the image. */
  itkStaticConstMacro(ImageDimension, unsigned int, VImageDimension);

  /** Container used to store pixels in the image. */
  typedef typename Superclass::PixelContainer PixelContainer;

  /** Index typedef support. An index is used to access pixel values. */
  typedef typename Superclass::IndexType IndexType;

  /** Offset typedef support. An offset is used to access pixel values. */
  typedef typename Superclass::OffsetType OffsetType;

  /** Size typedef support. A size is used to define region bounds. */
  typedef typename Superclass::SizeType SizeType;

  /** Direction typedef support. A matrix of direction cosines. */
  typedef typename Superclass::DirectionType DirectionType;

  /** Region typedef support. A region is used to specify a subset of an image. */
  typedef typename Superclass::RegionType RegionType;

  /** Spacing typedef support.  Spacing holds the size of a pixel.  The
   * spacing is the geometric distance between image samples. */
  typedef typename Superclass::SpacingType SpacingType;

  /** Origin typedef support.  The origin is the geometric coordinates
   * of the index (0, 0). */
  typedef typename Superclass::PointType PointType;

  /** A pointer to the pixel container. */
  typedef typename PixelContainer::Pointer      PixelContainerPointer;
  typedef typename PixelContainer::ConstPointer PixelContainerConstPointer;

  /** Offset typedef (relative position between indices) */
  typedef typename Superclass::OffsetValueType OffsetValueType;

  /** Return the Pixel Accessor object */
//   AccessorType GetPixelAccessor( void )
//   {
//     return AccessorType();
//   }

//   /** Return the Pixel Accesor object */
//   const AccessorType GetPixelAccessor( void ) const
//   {
//     return AccessorType();
//   }

  /** Return the NeighborhoodAccessor functor */
  NeighborhoodAccessorFunctorType GetNeighborhoodAccessor()
  {
    return NeighborhoodAccessorFunctorType();
  }

  /** Return the NeighborhoodAccessor functor */
  const NeighborhoodAccessorFunctorType GetNeighborhoodAccessor() const
  {
    return NeighborhoodAccessorFunctorType();
  }

  /** Get the projection coordinate system of the image. */
  virtual std::string GetProjectionRef(void) const;

  virtual void SetProjectionRef(const std::string& wkt);


  /** Get the GCP projection coordinates of the image. */
  virtual std::string GetGCPProjection(void) const;

  virtual unsigned int GetGCPCount(void) const;

  virtual OTB_GCP& GetGCPs(unsigned int GCPnum);
  virtual const OTB_GCP& GetGCPs(unsigned int GCPnum) const;

  virtual std::string GetGCPId(unsigned int GCPnum) const;
  virtual std::string GetGCPInfo(unsigned int GCPnum) const;
  virtual double GetGCPRow(unsigned int GCPnum) const;
  virtual double GetGCPCol(unsigned int GCPnum) const;
  virtual double GetGCPX(unsigned int GCPnum) const;
  virtual double GetGCPY(unsigned int GCPnum) const;
  virtual double GetGCPZ(unsigned int GCPnum) const;

  /** Get the six coefficients of affine geoTtransform. */
  virtual VectorType GetGeoTransform(void) const;

  /** Get image corners. */
  virtual VectorType GetUpperLeftCorner(void) const;
  virtual VectorType GetUpperRightCorner(void) const;
  virtual VectorType GetLowerLeftCorner(void) const;
  virtual VectorType GetLowerRightCorner(void) const;

  /** Get image keyword list */
  virtual ImageKeywordlistType GetImageKeywordlist(void);

  virtual const ImageKeywordlistType GetImageKeywordlist(void) const;

  virtual void SetImageKeywordList(const ImageKeywordlistType& kwl);

  void PrintSelf(std::ostream& os, itk::Indent indent) const ITK_OVERRIDE;

/// Copy metadata from a DataObject
  void CopyInformation(const itk::DataObject *) ITK_OVERRIDE;

protected:
  Image();
  ~Image() ITK_OVERRIDE {}

private:
  Image(const Self &); //purposely not implemented
  void operator =(const Self&); //purposely not implemented

  /** Return the ImageMetadataInterfacePointer associated to the data
   *  and creates it on first call
   */
  ImageMetadataInterfacePointerType GetMetaDataInterface() const;

  // The image metadata accessor object. Don't use it directly. Instead use GetMetaDataInterface()
  mutable ImageMetadataInterfacePointerType m_ImageMetadataInterface;

};

} // end namespace otb

#ifndef OTB_MANUAL_INSTANTIATION
#include "otbImage.txx"
#endif

#endif
