from distutils.core import setup, Extension
from Cython.Build import cythonize

setup(ext_modules=cythonize(Extension(
    'PyAsy',                          # 生成的模块名称
    sources=['pyasy.pyx'],            # 要编译的文件
    language='g++',                         # 使用的语言
    include_dirs=[],                        # gcc的-I参数
    library_dirs=[],                        # gcc的-L参数
    libraries=['boost_system', 'boost_thread', 'pthread'],                           # gcc的-l参数
    extra_compile_args=[],                  # 附加编译参数
    extra_link_args=[],                     # 附加链接参数
)))
