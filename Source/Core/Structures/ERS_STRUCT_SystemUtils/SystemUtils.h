//======================================================================//
// This file is part of the BrainGenix-ERS Environment Rendering System //
//======================================================================//

#pragma once

// Standard Libraries (BG convention: use <> instead of "")
#include <memory.h>

// Third-Party Libraries (BG convention: use <> instead of "")
#include <yaml-cpp/yaml.h>

// Internal Libraries (BG convention: use <> instead of "")

#include <BG/Common/Logger/Logger.h>
#include <HardwareInformation.h>
//#include <PythonInterpreterIntegration.h>
#include <ERS_CLASS_LuaJITInterpreterIntegration.h>


#include <RendererSettings.h>

#include <BG/ERS/IOSubsystem/IOSubsystem.h>
#include <FramerateManager.h>





/**
 * @brief The System utils struct contains most system utils prepopulated as shared pointers within.
 * 
 */
struct ERS_STRUCT_SystemUtils {


    std::vector<std::pair<std::string, std::string>> Arguments_; /**<Pair of key and value arguments used to launch the program*/
    std::string ArgumentString_; /**<String version of the argument pair*/

    std::unique_ptr<YAML::Node> LocalSystemConfiguration_; /**<Pointer To Config.yaml Data From Local Hard Drive*/
    std::unique_ptr<bool> SystemShouldRun_; /**<Pointer To Variable Setting If System Should Run Or Not*/

    std::unique_ptr<BG::Common::Logger::LoggingSystem> Logger_; /**<Pointer To BG-ERS Logging System*/
    std::unique_ptr<BG::ERS::IOSubsystem::IOSubsystem> ERS_IOSubsystem_; /**<Pointer To ERS Input Output Subsystem*/
    std::unique_ptr<ERS_CLASS_FramerateManager> FramerateManager_; /**<Pointer to framerate subsystem*/
    std::unique_ptr<ERS_HardwareInformation> ERS_HardwareInformation_; /**<Pointer to the hardware informaton class instance*/
   // std::unique_ptr<ERS_CLASS_PythonInterpreterIntegration> ERS_CLASS_PythonInterpreterIntegration_; /**<Pointer to the class integrating the python interpreter*/
    std::unique_ptr<ERS_CLASS_LuaJITInterpreterIntegration> ERS_CLASS_LuaJITInterpreterIntegration_; /**<Pointer to the class integrating the LuaJIT interpreter*/

    std::unique_ptr<ERS_STRUCT_RendererSettings> RendererSettings_; /**<Contains settings to be used by the renderer class, Automatically updates the renderer when this struct is updated.*/


    int RenderWidth_ = 0; /**<Width of the display being rendered to (if using a window, this is the size of the window)*/
    int RenderHeight_ = 0; /**<Height of the display being rendered to (if using a window, this is the size of the window)*/
    



};

