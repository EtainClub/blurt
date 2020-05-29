file(GLOB HEADERS "include/blurt/chain/*.hpp" "include/blurt/chain/util/*.hpp" "include/blurt/chain/smt_objects/*.hpp" "include/blurt/chain/sps_objects/*.hpp")

## SORT .cpp by most likely to change / break compile
add_library( blurt_chain

             # As database takes the longest to compile, start it first
             database.cpp
             index.cpp

             sps_evaluator.cpp

             steem_evaluator.cpp
             blurt_objects.cpp

             witness_schedule.cpp
             fork_database.cpp

             shared_authority.cpp
             block_log.cpp

             generic_custom_operation_interpreter.cpp

             util/rd.cpp
             util/reward.cpp
             util/impacted.cpp
             util/advanced_benchmark_dumper.cpp
             util/sps_processor.cpp
             util/sps_helper.cpp

             ${HEADERS}
           )

target_link_libraries( blurt_chain steem_jsonball blurt_protocol fc chainbase blurt_schema appbase mira
                       ${PATCH_MERGE_LIB} )
target_include_directories( blurt_chain
                            PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_BINARY_DIR}/include" )

if( CLANG_TIDY_EXE )
   set_target_properties(
      blurt_chain PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

if(MSVC)
  set_source_files_properties( database.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   blurt_chain

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/blurt/chain" )
