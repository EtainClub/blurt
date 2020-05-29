file(GLOB HEADERS "include/blurt/plugins/raw_block/*.hpp")

add_library( blurt_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( blurt_raw_block blurt_app blurt_chain blurt_protocol fc )
target_include_directories( blurt_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
