add_library(NPSSharcDev SHARED  SharcDev.cc)
target_link_libraries(NPSSharcDev NPSCore ${ROOT_LIBRARIES} ${Geant4_LIBRARIES} ${NPLib_LIBRARIES} -lNPSharcDev)
