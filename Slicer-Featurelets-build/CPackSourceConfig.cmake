# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


SET(CPACK_BINARY_7Z "")
SET(CPACK_BINARY_BUNDLE "")
SET(CPACK_BINARY_CYGWIN "")
SET(CPACK_BINARY_DEB "")
SET(CPACK_BINARY_DRAGNDROP "")
SET(CPACK_BINARY_IFW "")
SET(CPACK_BINARY_NSIS "")
SET(CPACK_BINARY_OSXX11 "")
SET(CPACK_BINARY_PACKAGEMAKER "")
SET(CPACK_BINARY_RPM "")
SET(CPACK_BINARY_STGZ "")
SET(CPACK_BINARY_TBZ2 "")
SET(CPACK_BINARY_TGZ "")
SET(CPACK_BINARY_TXZ "")
SET(CPACK_BINARY_TZ "")
SET(CPACK_BINARY_WIX "")
SET(CPACK_BINARY_ZIP "")
SET(CPACK_CMAKE_GENERATOR "Unix Makefiles")
SET(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
SET(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
SET(CPACK_GENERATOR "TGZ;TXZ")
SET(CPACK_IGNORE_FILES "/CVS/;/\\.svn/;/\\.bzr/;/\\.hg/;/\\.git/;\\.swp\$;\\.#;/#")
SET(CPACK_INSTALLED_DIRECTORIES "/home/andreas/code/Slicer-Featurelets;/")
SET(CPACK_INSTALL_CMAKE_PROJECTS "")
SET(CPACK_INSTALL_PREFIX "/usr/local")
SET(CPACK_MODULE_PATH "/home/andreas/Slicer-SuperBuild-Release_4.5/SlicerExecutionModel-build/CMake;/home/andreas/Slicer-SuperBuild-Release_4.5/SlicerExecutionModel-build/CMake;/home/andreas/Slicer-SuperBuild-Release_4.5/SlicerExecutionModel-build/CMake;/home/andreas/Slicer-SuperBuild-Release_4.5/VTKv6/CMake;/home/andreas/Slicer-SuperBuild-Release_4.5/ITKv4/CMake;/home/andreas/Slicer-SuperBuild-Release_4.5/CTK/Utilities/CMake;/home/andreas/Slicer-SuperBuild-Release_4.5/CTK/CMake;/home/andreas/Slicer-SuperBuild-Release_4.5/ITKv4/Modules/ThirdParty/DCMTK/CMake;/home/andreas/Slicer-SuperBuild-Release_4.5/CTK/Utilities/CMake;/home/andreas/MyProjects/Slicer-r24735/CMake;/home/andreas/MyProjects/Slicer-r24735/Extensions/CMake;/home/andreas/Slicer-SuperBuild-Release_4.5/VTKv6/CMake")
SET(CPACK_MONOLITHIC_INSTALL "ON")
SET(CPACK_NSIS_DISPLAY_NAME "Slicer-Featurelets 0.1.1")
SET(CPACK_NSIS_INSTALLER_ICON_CODE "")
SET(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
SET(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
SET(CPACK_NSIS_MODIFY_PATH "OFF")
SET(CPACK_NSIS_PACKAGE_NAME "Slicer-Featurelets 0.1.1")
SET(CPACK_OUTPUT_CONFIG_FILE "/home/andreas/code/Slicer-Featurelets_4.5/Slicer-Featurelets-build/CPackConfig.cmake")
SET(CPACK_PACKAGE_DEFAULT_LOCATION "/")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "/home/andreas/MyProjects/Slicer-r24735/README.txt")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "This Extension uses regularly distributed image subvolumes to achiev multimodal deformable registration.")
SET(CPACK_PACKAGE_FILE_NAME "Slicer-Featurelets-0.1.1-Source")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "Slicer-Featurelets 0.1.1")
SET(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "Slicer-Featurelets 0.1.1")
SET(CPACK_PACKAGE_NAME "Slicer-Featurelets")
SET(CPACK_PACKAGE_RELOCATABLE "true")
SET(CPACK_PACKAGE_VENDOR "NA-MIC")
SET(CPACK_PACKAGE_VERSION "0.1.1")
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "1")
SET(CPACK_PACKAGE_VERSION_PATCH "1")
SET(CPACK_RESOURCE_FILE_LICENSE "/home/andreas/MyProjects/Slicer-r24735/License.txt")
SET(CPACK_RESOURCE_FILE_README "/usr/local/share/cmake-3.4/Templates/CPack.GenericDescription.txt")
SET(CPACK_RESOURCE_FILE_WELCOME "/usr/local/share/cmake-3.4/Templates/CPack.GenericWelcome.txt")
SET(CPACK_SET_DESTDIR "OFF")
SET(CPACK_SOURCE_7Z "")
SET(CPACK_SOURCE_CYGWIN "")
SET(CPACK_SOURCE_GENERATOR "TGZ;TXZ")
SET(CPACK_SOURCE_IGNORE_FILES "/CVS/;/\\.svn/;/\\.bzr/;/\\.hg/;/\\.git/;\\.swp\$;\\.#;/#")
SET(CPACK_SOURCE_INSTALLED_DIRECTORIES "/home/andreas/code/Slicer-Featurelets;/")
SET(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/andreas/code/Slicer-Featurelets_4.5/Slicer-Featurelets-build/CPackSourceConfig.cmake")
SET(CPACK_SOURCE_PACKAGE_FILE_NAME "Slicer-Featurelets-0.1.1-Source")
SET(CPACK_SOURCE_TBZ2 "OFF")
SET(CPACK_SOURCE_TGZ "ON")
SET(CPACK_SOURCE_TOPLEVEL_TAG "Linux-Source")
SET(CPACK_SOURCE_TXZ "ON")
SET(CPACK_SOURCE_TZ "OFF")
SET(CPACK_SOURCE_ZIP "OFF")
SET(CPACK_STRIP_FILES "")
SET(CPACK_SYSTEM_NAME "Linux")
SET(CPACK_TOPLEVEL_TAG "Linux-Source")
SET(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/andreas/code/Slicer-Featurelets_4.5/Slicer-Featurelets-build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()