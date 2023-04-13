project('kMST_AIG', 'c',
        version : '0.1')

add_global_arguments('-lsqlite3',
                     '-O3',
                     language : 'c') #-g

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : true)
glib = dependency('glib-2.0')
thread_dep = dependency('threads')

src = [
  'src/main.c',
  'src/input_parser.c',
  'src/kmst.c',
  'src/point.c',
  'src/tree.c'
]

includes = include_directories('src/')

TSP_SA = static_library('kMST_AIG', src,
                        dependencies: [ glib, m_dep, thread_dep ],
                        include_directories: [ includes ],
                        install : true)

exe = executable('kMST_AIG', src,
                 dependencies: [ glib, m_dep, thread_dep ],
                 install : true)
