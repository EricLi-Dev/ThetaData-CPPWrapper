#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "curlcpp::curlcpp" for configuration "Release"
set_property(TARGET curlcpp::curlcpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(curlcpp::curlcpp PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libcurlcpp.a"
  )

list(APPEND _cmake_import_check_targets curlcpp::curlcpp )
list(APPEND _cmake_import_check_files_for_curlcpp::curlcpp "${_IMPORT_PREFIX}/lib/libcurlcpp.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
