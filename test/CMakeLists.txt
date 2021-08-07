# Testing library
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
    )
FetchContent_MakeAvailable(googletest)

enable_testing()

# 渡されたテスト名を実行用ファイルとしてctestの対象に加えていく関数
function (add_gtest_target test_name)
    add_executable(${test_name} ${test_name}.cc)
    target_include_directories(
        ${test_name}
        PUBLIC ${CMAKE_SOURCE_DIR}/include
        )
    target_link_libraries(
        ${test_name}
        gpx-parser
        gtest
        gtest_main
        )
    add_test(
        NAME ${test_name}
        COMMAND ./${test_name}
        )
endfunction()

set(gtest_targets # テストファイルはこの配列に追加していく
    gpx_test
    )

# 上で定義されたテストファイル群をadd_gtest_target関数に渡すだけのループ
foreach(target ${gtest_targets})
    add_gtest_target(${target})
endforeach()
