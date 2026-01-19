project('brightness-monitor', 'cpp',
  version : '0.1.0',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])

# メインの実行ファイル
executable('brightness-monitor',
           'src/main.cpp',
           install : true)

# CppUTestの依存関係を取得
cpputest_dep = dependency('cpputest', required : false)

# テストが有効な場合のみビルド
if cpputest_dep.found()
  # テスト実行ファイル
  test_exe = executable('test-runner',
                        'tests/test_main.cpp',
                        dependencies : cpputest_dep,
                        install : false)

  # VCNL4040テスト
  test_vcnl4040_exe = executable('test-vcnl4040',
                                  'tests/test_vcnl4040.cpp',
                                  include_directories : include_directories('src'),
                                  dependencies : cpputest_dep,
                                  install : false)

  # テストを登録
  test('unit tests', test_exe)
  test('vcnl4040 tests', test_vcnl4040_exe)
endif
