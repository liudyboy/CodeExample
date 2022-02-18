from distutils.core import setup, Extension
from Cython.Build import cythonize

grpc_path = '/home/reas/.local'

setup(name='PyGreeterClient',
      ext_modules=cythonize(Extension("PyGreeterClient", sources=["PyGreeterClient.pyx"], extra_link_args=["greeter_client.o"], libraries=['hw_grpc_proto', 'grpc++_reflection', 'grpc++', 'protobuf', 'grpc', 'z', 'cares', 'nsl', 'address_sorting', 're2', 'absl_raw_hash_set', 'absl_hashtablez_sampler', 'absl_exponential_biased', 'absl_hash', 'absl_city', 'absl_wyhash', 'absl_statusor', 'absl_bad_variant_access', 'gpr', 'upb', 'dl', 'rt', 'm', 'absl_status', 'absl_cord', 'absl_bad_optional_access',
                            'absl_str_format_internal', 'absl_synchronization', 'absl_stacktrace', 'absl_symbolize', 'absl_debugging_internal', 'absl_demangle_internal', 'absl_graphcycles_internal', 'absl_malloc_internal', 'absl_time', 'absl_strings', 'absl_throw_delegate', 'absl_int128', 'absl_strings_internal', 'absl_base', 'absl_raw_logging_internal', 'absl_log_severity', 'absl_spinlock_wait', 'rt', 'absl_civil_time', 'absl_time_zone', 'ssl', 'crypto', 'pthread', 'pthread'], library_dirs=[f'{grpc_path}/lib', '.'], include_dirs=[f'{grpc_path}/include'])))
