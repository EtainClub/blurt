file(GLOB HEADERS "include/blurt/private_message/*.hpp")

add_library( blurt_private_message
             private_message_plugin.cpp
           )

target_link_libraries( blurt_private_message blurt_chain blurt_protocol blurt_app )
target_include_directories( blurt_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   blurt_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
