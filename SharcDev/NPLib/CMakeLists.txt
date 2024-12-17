add_custom_command(OUTPUT TSharcDevPhysicsDict.cxx COMMAND ../../scripts/build_dict.sh TSharcDevPhysics.h TSharcDevPhysicsDict.cxx TSharcDevPhysics.rootmap libNPSharcDev.dylib DEPENDS TSharcDevPhysics.h)
add_custom_command(OUTPUT TSharcDevDataDict.cxx COMMAND ../../scripts/build_dict.sh TSharcDevData.h TSharcDevDataDict.cxx TSharcDevData.rootmap libNPSharcDev.dylib DEPENDS TSharcDevData.h)
add_library(NPSharcDev SHARED TSharcDevSpectra.cxx TSharcDevData.cxx TSharcDevPhysics.cxx TSharcDevDataDict.cxx TSharcDevPhysicsDict.cxx )
target_link_libraries(NPSharcDev ${ROOT_LIBRARIES} NPCore) 
install(FILES TSharcDevData.h TSharcDevPhysics.h TSharcDevSpectra.h DESTINATION ${CMAKE_INCLUDE_OUTPUT_DIRECTORY})

