from PyGreeterClient import PyGreeterClient as greeter
g = greeter(b"localhost:50051")
print(g.SayHello(b"cython"))
