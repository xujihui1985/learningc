file(REMOVE_RECURSE
  "libutils.pdb"
  "libutils.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/utils.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
