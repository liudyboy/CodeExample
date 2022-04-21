import asyncio
import random
import threading
import time

def producer(cv):
    cv.acquire()
    time.sleep(10)
    cv.notify()
    cv.release()
    print("producer notify done.")

def consumer(cv):
    cv.acquire()
    cv.wait()
    cv.release()
    print("consumer completed.")

if __name__ == "__main__":
    cv = threading.Condition()
    pro = threading.Thread(target=producer, args=(cv,))
    con = threading.Thread(target=consumer, args=(cv,))
    con.start()
    time.sleep(1)
    pro.start()
    pro.join()
    con.join()
