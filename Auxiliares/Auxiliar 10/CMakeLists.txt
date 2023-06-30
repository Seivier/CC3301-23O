add_executable(PT_buscar pauta/buscar.c)
add_executable(PT_cualquierusr pauta/cualquierusr.c)


add_executable(buscar aux/buscar.c)
add_executable(cualquierusr aux/cualquierusr.c)


file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/data)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


