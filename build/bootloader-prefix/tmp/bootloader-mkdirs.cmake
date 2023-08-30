# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/lukasz/esp/esp-idf/components/bootloader/subproject"
  "/home/lukasz/hydros/Break_test_vehicle_software/build/bootloader"
  "/home/lukasz/hydros/Break_test_vehicle_software/build/bootloader-prefix"
  "/home/lukasz/hydros/Break_test_vehicle_software/build/bootloader-prefix/tmp"
  "/home/lukasz/hydros/Break_test_vehicle_software/build/bootloader-prefix/src/bootloader-stamp"
  "/home/lukasz/hydros/Break_test_vehicle_software/build/bootloader-prefix/src"
  "/home/lukasz/hydros/Break_test_vehicle_software/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/lukasz/hydros/Break_test_vehicle_software/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/lukasz/hydros/Break_test_vehicle_software/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
