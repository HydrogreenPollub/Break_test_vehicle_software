# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/lukasz/esp/esp-idf/components/bootloader/subproject"
  "/home/lukasz/projects_esp/telemetria/build/bootloader"
  "/home/lukasz/projects_esp/telemetria/build/bootloader-prefix"
  "/home/lukasz/projects_esp/telemetria/build/bootloader-prefix/tmp"
  "/home/lukasz/projects_esp/telemetria/build/bootloader-prefix/src/bootloader-stamp"
  "/home/lukasz/projects_esp/telemetria/build/bootloader-prefix/src"
  "/home/lukasz/projects_esp/telemetria/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/lukasz/projects_esp/telemetria/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/lukasz/projects_esp/telemetria/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
