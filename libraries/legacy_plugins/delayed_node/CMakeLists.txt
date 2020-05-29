file(GLOB HEADERS "include/blurt/delayed_node/*.hpp")

add_library( blurt_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( blurt_delayed_node blurt_chain blurt_protocol blurt_app )
target_include_directories( blurt_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   blurt_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
