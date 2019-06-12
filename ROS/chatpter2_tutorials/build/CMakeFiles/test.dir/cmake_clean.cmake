file(REMOVE_RECURSE
  "../msg_gen"
  "../srv_gen"
  "../msg_gen"
  "../srv_gen"
  "../src/chatpter2_tutorials/msg"
  "../src/chatpter2_tutorials/srv"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/test.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
