########################################################################
# This file is part of the BrainGenix-ERS Environment Rendering System #
########################################################################


# Create Library (Name Should Be Parent Dir Name)
add_library(ERS_STRUCT_Shader

            # Add Source Files (.cpp)
            "Shader.cpp"

            # Add Header Files (.h)
            "Shader.h"

            ${BACKWARD_ENABLE}
            )

# Link 3rd Party Libs
target_link_libraries(ERS_STRUCT_Shader
    glm
    glad
    glfw
    )

# Link Internal Libs
target_link_libraries(ERS_STRUCT_Shader
    bg-common-logger
    )

target_include_directories(ERS_STRUCT_Shader PUBLIC ./)