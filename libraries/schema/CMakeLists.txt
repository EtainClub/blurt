file(GLOB HEADERS "include/blurt/schema/*.hpp")
add_library( steem_schema schema.cpp ${HEADERS} )
target_link_libraries( steem_schema fc )
target_include_directories( steem_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   steem_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/blurt/schema" )
