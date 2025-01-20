add_custom_command(OUTPUT TbasicScintillatorPhysicsDict.cxx COMMAND ../../scripts/build_dict.sh TbasicScintillatorPhysics.h TbasicScintillatorPhysicsDict.cxx TbasicScintillatorPhysics.rootmap libNPbasicScintillator.dylib DEPENDS TbasicScintillatorPhysics.h)
add_custom_command(OUTPUT TbasicScintillatorDataDict.cxx COMMAND ../../scripts/build_dict.sh TbasicScintillatorData.h TbasicScintillatorDataDict.cxx TbasicScintillatorData.rootmap libNPbasicScintillator.dylib DEPENDS TbasicScintillatorData.h)
add_library(NPbasicScintillator SHARED TbasicScintillatorSpectra.cxx TbasicScintillatorData.cxx TbasicScintillatorPhysics.cxx TbasicScintillatorDataDict.cxx TbasicScintillatorPhysicsDict.cxx )
target_link_libraries(NPbasicScintillator ${ROOT_LIBRARIES} NPCore) 
install(FILES TbasicScintillatorData.h TbasicScintillatorPhysics.h TbasicScintillatorSpectra.h DESTINATION ${CMAKE_INCLUDE_OUTPUT_DIRECTORY})

