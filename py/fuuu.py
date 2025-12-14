import threading
import time
from queue import Queue
order = Queue()
finished_count = 0
count_lock = threading.Lock()
NUM_WORKERS = 2
def customer():
    drink = ["美式咖啡", "拿铁", "柠檬水", "奶茶", "None", "None"]
    print("--- 顾客开始下单 ---")
    for d in drink:
        if d == "None":
            order.put(None)
            print(f"顾客：放入结束标记 (None) 到队列。")
        else:
            print(f"顾客点了【{d}】，请尽快制作！")
            order.put(d)
        time.sleep(0.5)
    print("--- 顾客下单完毕 ---")
def barista(name):
    global finished_count
    while True:
        od = order.get()
        if od is None:
            print(f"【{name}】接到了结束标记 (None)，收工！！！")
            order.put(None)
            break
        print(f"【{name}】开始工作，制作 {od}")
        time.sleep(1)
        print(f"【{name}】制作完成：{od}")
        count_lock.acquire()
        try:
            finished_count += 1
            print(f"【{name}】已完成订单数：{finished_count}")
        finally:
            count_lock.release()
        order.task_done()
def main():
    global NUM_WORKERS
    worker_names = [f"T{i+1}" for i in range(NUM_WORKERS)]
    ts = []
    customer_thread = threading.Thread(target=customer)
    customer_thread.start()
    for name in worker_names:
        t = threading.Thread(target=barista, args=(name,))
        ts.append(t)
        t.start()
    customer_thread.join()
    for t in ts:
        t.join()
    print("\n======== 实验结果 ========")
    print(f"总订单数：{len([d for d in customer.__code__.co_consts[1] if d != 'None'])}")
    print(f"实际完成的订单数 (共享计数器)：{finished_count}")
    print("所有线程已结束，程序退出。")
if __name__ == "__main__":
    main()
