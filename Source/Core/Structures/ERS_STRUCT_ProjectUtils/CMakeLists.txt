########################################################################
# This file is part of the BrainGenix-ERS Environment Rendering System #
########################################################################


# Create Library (Name Should Be Parent Dir Name)
add_library(ERS_STRUCT_ProjectUtils

            # Add Source Files (.cpp)
            "ProjectUtils.cpp"

            # Add Header Files (.h)
            "ProjectUtils.h"
            
            ${BACKWARD_ENABLE}
            )

# Link 3rd Party Libs
target_link_libraries(ERS_STRUCT_ProjectUtils
    )

# Link Internal Libs
target_link_libraries(ERS_STRUCT_ProjectUtils
    bg-common-logger
    ERS_SceneManager

    bg-ers-iosubsystem
    ERS_FramerateManager
    ERS_ModelWriter
    ERS_ModelLoader
    ERS_SceneLoader
    ERS_ProjectLoader
    ERS_ProjectManager
    ERS_ProjectWriter
    ERS_ModelImporter

    )


target_include_directories(ERS_STRUCT_ProjectUtils PUBLIC ./)
