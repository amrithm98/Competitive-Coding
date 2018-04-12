import threading
import time

exitFlag = 0

class myThread(threading.Thread):
    def __init__(self,threadID,name,counter):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter

    # def run(self):
    #     for x in range(0,10):
    #         print("Child Thread : ",x)
    #         time.sleep(1)

    def SUM(self,a,b):
        print("SUM " + str(a+b))

    def run(self):
        #If lock isn't used. Threads work concurrently
        print("Starting : " + self.name)
        threadLock.acquire()
        print("Task STarted : "+ self.name)
        time.sleep(6)
        print("Task Ends: " + self.name)
        threadLock.release()

threadLock = threading.Lock()
threads = []

thread1 = myThread(1,"Thread-1",1)
thread2 = myThread(2,"Thread-2",2)

thread1.start()
thread2.start()

#print("Alive : ",thread1.isAlive())