##########################
# Builds Library For ERS #
##########################

ERSBuildLogger(${Green} "Configuring ImGuiFileDialog Library")
add_subdirectory(${LIB_DIR}/NonSuperBuild/ImGuiFileDialog)
disable_target_warnings(ImGuiFileDialog)
ERSBuildLogger(${BoldGreen} "Finished Configuring ImGuiFileDialog Library")