########################################################################
# This file is part of the BrainGenix-ERS Environment Rendering System #
########################################################################


# Create Library (Name Should Be Parent Dir Name)
add_library(ERS_Editor_LayoutManager

            # Add Source Files (.cpp)
            "LayoutManager.cpp"

            # Add Header Files (.h)
            "LayoutManager.h"
            
            ${BACKWARD_ENABLE}
            )
set_property(TARGET ERS_Editor_LayoutManager PROPERTY CXX_STANDARD 17)
            
# Link 3rd Party Libs
target_link_libraries(ERS_Editor_LayoutManager
    yaml-cpp
    IMGUI
    ghcFilesystem::ghc_filesystem
    )

# Link Internal Libs
target_link_libraries(ERS_Editor_LayoutManager
    bg-common-logger
    ERS_STRUCT_SystemUtils
    ERS_Editor_WindowManager
    )

target_include_directories(ERS_Editor_LayoutManager PUBLIC ./)
