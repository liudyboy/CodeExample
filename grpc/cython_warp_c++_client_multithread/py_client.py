from py_greeter_client import PyWorkProcess
import time

if __name__ == "__main__":
    start = time.time()
    target = b"localhost:50051"
    user = b"work0"
    work_process = PyWorkProcess()
    work_process.Start(target, user)

    user = b"work1"
    work_process1 = PyWorkProcess()
    work_process1.Start(target, user)


    reply = work_process.GetReply()
    print("Work0 get reply: ", reply)

    reply = work_process1.GetReply()
    print("Work1 get reply: ", reply)

    end = time.time()
    print("Cost time: {}".format(end - start))
