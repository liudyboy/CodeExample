all: greeter_server greeter_client_main greeter_client_cython helloworld_pb2_grpc.py
default_target: all
.PHONY: default_target

GPRC_PATH = /home/reas/.local

CXX_FLAGS =   -std=gnu++11 -fPIC

CXX_DEFINES = -DCARES_STATICLIB

#-L/usr/local/lib `pkg-config --libs protobuf grpc++`
CXX_LIBS = -L$(GPRC_PATH)/lib
#  -lprotobuf -lgrpc -lgrpc++\
#            -pthread\
#            -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
#            -ldl
CXX_LIBS +=  libhw_grpc_proto.a -L/home/reas/.local/lib -lgrpc++_reflection -lgrpc++ -lprotobuf -lgrpc -lz -lcares -lnsl -laddress_sorting -lre2 -labsl_raw_hash_set -labsl_hashtablez_sampler -labsl_exponential_biased -labsl_hash -labsl_city -labsl_wyhash -labsl_statusor -labsl_bad_variant_access -lgpr -lupb -ldl -lrt -lm -labsl_status -labsl_cord -labsl_bad_optional_access -labsl_str_format_internal -labsl_synchronization -labsl_stacktrace -labsl_symbolize -labsl_debugging_internal -labsl_demangle_internal -labsl_graphcycles_internal -labsl_malloc_internal -labsl_time -labsl_strings -labsl_throw_delegate -labsl_int128 -labsl_strings_internal -labsl_base -labsl_raw_logging_internal -labsl_log_severity -labsl_spinlock_wait -lrt -labsl_civil_time -labsl_time_zone -lssl -lcrypto -lpthread -lpthread

CXX_INCLUDES = -I. -isystem $(GPRC_PATH)/include

CXX = /usr/bin/c++
# `pkg-config --cflags --libs protobuf`

PROTOS_PATH = .

PROTOC = $(GPRC_PATH)/bin/protoc

greeter_client_cython: libhw_grpc_proto.a
	python3 build.py build_ext --inplace

greeter_client_main:  greeter_client.o greeter_client_main.o libhw_grpc_proto.a
	$(CXX) $^ $(LDFLAGS) $(CXX_LIBS) -o $@

greeter_server:  greeter_server.o libhw_grpc_proto.a
	$(CXX) $^ $(LDFLAGS) $(CXX_LIBS) -o $@


libhw_grpc_proto.a: helloworld.grpc.pb.o helloworld.pb.o
	/usr/bin/ar qc $@ $^
	/usr/bin/ranlib $@

greeter_server.o: greeter_server.cc helloworld.grpc.pb.cc helloworld.pb.cc
	$(CXX) $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c greeter_server.cc

greeter_client.o: greeter_client.cc helloworld.grpc.pb.cc helloworld.pb.cc
	$(CXX) $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c greeter_client.cc


%.o: %.cc
	$(CXX) $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o $@ -c $^

.PRECIOUS: %.grpc.pb.cc
%.grpc.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` $<

.PRECIOUS: %.pb.cc
%.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=. $<

helloworld_pb2_grpc.py: helloworld.proto
	python3 -m grpc_tools.protoc -I. --python_out=. --grpc_python_out=. ./helloworld.proto

clean:
	rm *.o greeter_client_main greeter_server *.a *.pb.cc *.pb.h *.so Py*.cpp *pb2.py *pb2_grpc.py
	rm -rf ./build
.PHONY: clean
