set(AUX "auxiliar_7")
set(PAUTA "${CMAKE_CURRENT_SOURCE_DIR}/pauta")
set(MAIN modificar)

add_executable(PT_${MAIN} "${PAUTA}/${AUX}.c" "${PAUTA}/${MAIN}.c" "${PAUTA}/${MAIN}.h" )

add_executable(${MAIN} "auxiliar/${AUX}.c" "auxiliar/${MAIN}.c" "auxiliar/${MAIN}.h" )


file(COPY "${PAUTA}/dict.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")



