########################################################################
# This file is part of the BrainGenix-ERS Environment Rendering System #
########################################################################


# Create Library (Name Should Be Parent Dir Name)
add_library(GUI_Window_ImportModelDirectory

            # Add Source Files (.cpp)
            "GUI_Window_ImportModelDirectory.cpp"


            # Add Header Files (.h)
            "GUI_Window_ImportModelDirectory.h"
            
            ${BACKWARD_ENABLE}
            )
set_property(TARGET GUI_Window_ImportModelDirectory PROPERTY CXX_STANDARD 17)
            
# Link 3rd Party Libs
target_link_libraries(GUI_Window_ImportModelDirectory
    IMGUI
    ImGuiFileDialog
    ghcFilesystem::ghc_filesystem
    )

# Link Internal Libs
target_link_libraries(GUI_Window_ImportModelDirectory
    bg-common-logger

    ERS_STRUCT_SystemUtils
    ERS_STRUCT_ProjectUtils
    ERS_STRUCT_ModelImportOptions

    GUI_Window_ImportProgressBar
    )

target_include_directories(GUI_Window_ImportModelDirectory PUBLIC ./)