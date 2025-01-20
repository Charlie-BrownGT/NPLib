add_library(NPSbasicScintillator SHARED  basicScintillator.cc)
target_link_libraries(NPSbasicScintillator NPSCore ${ROOT_LIBRARIES} ${Geant4_LIBRARIES} ${NPLib_LIBRARIES} -lNPbasicScintillator)
