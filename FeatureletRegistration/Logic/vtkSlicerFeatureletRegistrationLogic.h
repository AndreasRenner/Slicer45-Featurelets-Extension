/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// .NAME vtkSlicerFeatureletRegistrationLogic - slicer logic class for volumes manipulation
// .SECTION Description
// This class manages the logic associated with reading, saving,
// and changing propertied of the volumes


#ifndef __vtkSlicerFeatureletRegistrationLogic_h
#define __vtkSlicerFeatureletRegistrationLogic_h

// Slicer includes
#include "vtkSlicerModuleLogic.h"
#include "vtkSlicerFeatureletRegistrationModuleLogicExport.h"
#include "FeatureletRegistrationResult.h"
class vtkSlicerMarkupsLogic;
class vtkSlicerVolumesLogic;
class vtkMRMLMarkupsFiducialNode;
class vtkMRMLMarkupsNode;
class vtkMRMLVolumeNode;
class vtkMRMLFeatureletRegistrationNode;

// STD includes
#include <cstdlib>
#include "stdio.h"
#include "string"
#include "math.h"
#include "map"
#include "fstream"
#include "gdcmGlobal.h"

// VTK includes
#include <vtkMatrix4x4.h>

// ITK includes
#include "itkBSplineInterpolateImageFunction.h"
#include "itkCastImageFilter.h"
#include "itkCenteredTransformInitializer.h"
#include "itkCheckerBoardImageFilter.h"
#include "itkCommand.h"
#include "itkConstantPadImageFilter.h"
#include "itkDiscreteGaussianImageFilter.h"
#include "itkExtractImageFilter.h"
#include "itkGradientDescentOptimizer.h"
#include "itkGradientDifferenceImageToImageMetric.h"
#include "itkIdentityTransform.h"
#include <itkImage.h>
#include "itkImageRegistrationMethod.h"
#include "itkIntensityWindowingImageFilter.h"
#include "itkKappaStatisticImageToImageMetric.h"
#include "itkKullbackLeiblerCompareHistogramImageToImageMetric.h"
#include "itkLinearInterpolateImageFunction.h"
#include "itkMatchCardinalityImageToImageMetric.h"
#include "itkMattesMutualInformationImageToImageMetric.h"
#include "itkMeanReciprocalSquareDifferenceImageToImageMetric.h"
#include "itkMeanSquaresHistogramImageToImageMetric.h"
#include "itkMeanSquaresImageToImageMetric.h"
#include "itkMetaDataDictionary.h"
#include "itkMetaDataObject.h"
#include "itkMinimumMaximumImageCalculator.h"
#include "itkMutualInformationImageToImageMetric.h"
#include "itkNearestNeighborInterpolateImageFunction.h"
#include "itkNormalizeImageFilter.h"
#include "itkNormalizedCorrelationImageToImageMetric.h"
#include "itkNormalVariateGenerator.h"
#include "itkOnePlusOneEvolutionaryOptimizer.h"
#include "itkPowellOptimizer.h"
#include "itkQuaternionRigidTransform.h"
#include "itkQuaternionRigidTransformGradientDescentOptimizer.h"
#include "itkRegionOfInterestImageFilter.h"
#include "itkRegularStepGradientDescentOptimizer.h"
#include "itkResampleImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkRecursiveGaussianImageFilter.h"
#include "itkSobelEdgeDetectionImageFilter.h"
#include "itkSubtractImageFilter.h"
#include "itkThresholdImageFilter.h"
#include "itkTranslationTransform.h"
#include "itkVector.h"
#include "itkVectorResampleImageFilter.h"
#include "itkVersorRigid3DTransform.h"
#include "itkVersorRigid3DTransformOptimizer.h"
#include "itkWarpImageFilter.h"
#include "itkWindowedSincInterpolateImageFunction.h"


typedef short PixelType;
//typedef int PixelType;
const unsigned int Dimension = 3;
typedef itk::Image<PixelType, Dimension> ImageType;

// For Featurelet Registration Result
typedef FeatureletRegistrationResult FeatureletRegistrationResultType;
typedef FeatureletRegistrationResultType::Pointer FeatureletRegistrationResultPointer;


/// \ingroup Slicer_QtModules_ExtensionTemplate
class VTK_SLICER_FEATURELETREGISTRATION_MODULE_LOGIC_EXPORT vtkSlicerFeatureletRegistrationLogic :
  public vtkSlicerModuleLogic
{
public:
  static vtkSlicerFeatureletRegistrationLogic *New();
  vtkTypeMacro(vtkSlicerFeatureletRegistrationLogic, vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);
  void SetAndObserveFeatureletRegistrationNode(vtkMRMLFeatureletRegistrationNode* node);

  void SetVolumesLogic(vtkSlicerVolumesLogic* logic);
  vtkSlicerVolumesLogic* GetVolumesLogic();

  int RunClicked(vtkMRMLFeatureletRegistrationNode*);
  int ShowVolume(vtkMRMLFeatureletRegistrationNode*, bool);

  vtkGetObjectMacro(FeatureletRegistrationNode, vtkMRMLFeatureletRegistrationNode);

  bool ConvertVolumeNodeToItkImage(vtkMRMLVolumeNode*, itk::Image<PixelType, Dimension>::Pointer);
  int SubsampleVolume( const ImageType::Pointer Image,
                       ImageType::SizeType FeatureletSize,
                       ImageType::SizeType SearchRegionSize,
                       ImageType::IndexType ImageIndex,
                       bool fixed);
  Featurelet::Status CheckFeaturelet(bool fixed, bool FiducialPoints, vtkMRMLMarkupsFiducialNode *Fiducials);
  FeatureletRegistrationResult::Pointer RegisterVolumes1(ImageType* FixedImage, ImageType* MovingImage, bool debugMode, bool rigid);
  FeatureletRegistrationResult::Pointer RegisterVolumes2(ImageType* FixedImage, ImageType* MovingImage, bool debugMode, bool rigid);
  FeatureletRegistrationResult::Pointer RegisterVolumesI(bool debugMode, bool rigid);
  FeatureletRegistrationResult::Pointer RegisterVolumesII(bool debugMode, bool rigid);
  int ResampleVolumesToBeIsotropic(ImageType* Image);


protected:
  vtkSlicerFeatureletRegistrationLogic();
  virtual ~vtkSlicerFeatureletRegistrationLogic();

  virtual void SetMRMLSceneInternal(vtkMRMLScene* newScene);
  //Register MRML Node classes to Scene. Gets called automatically when MRMLScene is attached to this logic class.
  virtual void RegisterNodes();
  virtual void UpdateFromMRMLScene();
  virtual void OnMRMLSceneNodeAdded(vtkMRMLNode* node);
  virtual void OnMRMLSceneNodeRemoved(vtkMRMLNode* node);
  virtual void OnMRMLSceneEndImport();
  virtual void OnMRMLSceneEndClose();

  vtkMRMLFeatureletRegistrationNode* FeatureletRegistrationNode;

private:
  vtkSlicerFeatureletRegistrationLogic(const vtkSlicerFeatureletRegistrationLogic&); // Not implemented
  void operator=(const vtkSlicerFeatureletRegistrationLogic&); // Not implemented

  class vtkInternal;
  vtkInternal* Internal;

  ImageType::Pointer FeatureletPointerFixed;
  ImageType::Pointer FeatureletPointerMoving;
  ImageType::Pointer SearchRegionPointerFixed;
  ImageType::Pointer SearchRegionPointerMoving;
  double MaxStepLength;
  double MinStepLength;
  int NumberIterations;
};

#endif
