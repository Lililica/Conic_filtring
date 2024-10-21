# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/sil-src")
  file(MAKE_DIRECTORY "/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/sil-src")
endif()
file(MAKE_DIRECTORY
  "/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/sil-build"
  "/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/sil-subbuild/sil-populate-prefix"
  "/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/sil-subbuild/sil-populate-prefix/tmp"
  "/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/sil-subbuild/sil-populate-prefix/src/sil-populate-stamp"
  "/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/sil-subbuild/sil-populate-prefix/src"
  "/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/sil-subbuild/sil-populate-prefix/src/sil-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/sil-subbuild/sil-populate-prefix/src/sil-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/lililica/Documents/IMAC/Maths/Projets/Conic_filtring/build/_deps/sil-subbuild/sil-populate-prefix/src/sil-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
