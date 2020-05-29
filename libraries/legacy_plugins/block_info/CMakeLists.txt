file(GLOB HEADERS "include/blurt/plugins/block_info/*.hpp")

add_library( blurt_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( blurt_block_info blurt_app blurt_chain blurt_protocol fc )
target_include_directories( blurt_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
