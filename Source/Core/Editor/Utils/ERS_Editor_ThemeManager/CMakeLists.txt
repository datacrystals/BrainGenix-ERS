########################################################################
# This file is part of the BrainGenix-ERS Environment Rendering System #
########################################################################


# Create Library (Name Should Be Parent Dir Name)
add_library(ERS_Editor_ThemeManager

            # Add Source Files (.cpp)
            "ThemeManager.cpp"

            # Add Header Files (.h)
            "ThemeManager.h"
            
            ${BACKWARD_ENABLE}
            )
set_property(TARGET ERS_Editor_ThemeManager PROPERTY CXX_STANDARD 17)
            
# Link 3rd Party Libs
target_link_libraries(ERS_Editor_ThemeManager
    yaml-cpp
    IMGUI
    ghcFilesystem::ghc_filesystem
    )

# Link Internal Libs
target_link_libraries(ERS_Editor_ThemeManager
    bg-common-logger
    )

target_include_directories(ERS_Editor_ThemeManager PUBLIC ./)
