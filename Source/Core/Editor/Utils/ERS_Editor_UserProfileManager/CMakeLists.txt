########################################################################
# This file is part of the BrainGenix-ERS Environment Rendering System #
########################################################################


# Create Library (Name Should Be Parent Dir Name)
add_library(ERS_Editor_UserProfileManager

            # Add Source Files (.cpp)
            "UserProfileManager.cpp"

            # Add Header Files (.h)
            "UserProfileManager.h"
            
            ${BACKWARD_ENABLE}
            )
set_property(TARGET ERS_Editor_UserProfileManager PROPERTY CXX_STANDARD 17)
            
# Link 3rd Party Libs
target_link_libraries(ERS_Editor_UserProfileManager
    yaml-cpp
    )

# Link Internal Libs
target_link_libraries(ERS_Editor_UserProfileManager
    bg-common-logger
    )

target_include_directories(ERS_Editor_UserProfileManager PUBLIC ./)
