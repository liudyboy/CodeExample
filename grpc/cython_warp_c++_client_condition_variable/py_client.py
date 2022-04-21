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


    reply0 = work_process.GetReply()

    reply1 = work_process1.GetReply()

    time.sleep(5)
    print("Work0 get reply: ", reply0)
    print("Work1 get reply: ", reply1)

    end = time.time()
    print("Cost time: {}".format(end - start))
