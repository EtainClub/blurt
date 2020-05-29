file(GLOB HEADERS "include/blurt/blockchain_statistics/*.hpp")

add_library( steem_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( steem_blockchain_statistics blurt_chain blurt_protocol blurt_app )
target_include_directories( steem_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   steem_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)