from py_greeter_client import PyClient

client = PyClient()
client.Connect(b"localhost:50051")
reply = client.SayHello(b"python")
print("server reply: {}".format(reply))
