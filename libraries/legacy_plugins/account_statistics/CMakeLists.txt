file(GLOB HEADERS "include/blurt/account_statistics/*.hpp")

add_library( blurt_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( blurt_account_statistics blurt_chain blurt_protocol blurt_app )
target_include_directories( blurt_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   blurt_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)