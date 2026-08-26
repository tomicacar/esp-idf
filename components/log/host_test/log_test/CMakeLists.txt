cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
set(COMPONENTS main)
list(APPEND EXTRA_COMPONENT_DIRS "$ENV{IDF_PATH}/tools/mocks/freertos/")
project(test_log_host)

# Lower the cache generation limit, the real one is not reachable in a test
set(TEST_LOG_CACHE_MAX_GENERATION 255)
idf_component_get_property(log_lib log COMPONENT_LIB)
target_compile_definitions(${log_lib} PRIVATE LOG_CACHE_MAX_GENERATION=${TEST_LOG_CACHE_MAX_GENERATION})
idf_component_get_property(main_lib main COMPONENT_LIB)
target_compile_definitions(${main_lib} PRIVATE LOG_CACHE_MAX_GENERATION=${TEST_LOG_CACHE_MAX_GENERATION})
