########################################################################
# This file is part of the BrainGenix-ERS Environment Rendering System #
########################################################################


# Create Library (Name Should Be Parent Dir Name)
add_library(ERS_STRUCT_TextureLevel

            # Add Source Files (.cpp)
            "TextureLevel.cpp"

            # Add Header Files (.h)
            "TextureLevel.h"
            
            ${BACKWARD_ENABLE}
            )

# Link 3rd Party Libs
target_link_libraries(ERS_STRUCT_TextureLevel
    yaml-cpp
    glm
    glad
    glfw
    assimp::assimp
    freeimage::FreeImage
    )

# Link Internal Libs
target_link_libraries(ERS_STRUCT_TextureLevel
    )

target_include_directories(ERS_STRUCT_TextureLevel PUBLIC ./)