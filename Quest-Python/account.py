import threading
import time

exitFlag = 0

class Account(object):
    def __init__(self,initVal):
        self.money = initVal

    def withDraw(self,cash):
        self.money -= cash

    def balance(self):
        print("\nCurrent Balance is : ",self.money)

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
        threadLock.acquire()
        print("\nWithdrawing STarted : "+ self.name)
        account.withDraw(100)
        time.sleep(4)
        account.balance()
        print("\nWithdrawing Done: " + self.name)
        threadLock.release()

threadLock = threading.Lock()
threads = []

account = Account(1000)

thread1 = myThread(1,"Thread-1",1)
thread2 = myThread(2,"Thread-2",2)

thread1.start()
thread2.start()
thread1.join()
thread2.join()

#print("Alive : ",thread1.isAlive())