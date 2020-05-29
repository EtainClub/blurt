file(GLOB HEADERS "include/blurt/schema/*.hpp")
add_library( blurt_schema schema.cpp ${HEADERS} )
target_link_libraries( blurt_schema fc )
target_include_directories( blurt_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   blurt_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/blurt/schema" )
