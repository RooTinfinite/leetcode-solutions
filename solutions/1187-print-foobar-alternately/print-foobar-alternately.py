"""
Condition
"""


class FooBar:
    def __init__(self, n):
        self.n = n
        self.lock = threading.Lock()
        self.foo_turn = True
        self.cond = threading.Condition(self.lock)

    def foo(self, printFoo: "Callable[[], None]") -> None:

        for i in range(self.n):

            # printFoo() outputs "foo". Do not change or remove this line.
            with self.cond:
                while not self.foo_turn:
                    self.cond.wait()
                printFoo()
                self.foo_turn = False
                self.cond.notify_all()

    def bar(self, printBar: "Callable[[], None]") -> None:

        for i in range(self.n):

            # printBar() outputs "bar". Do not change or remove this line.
            with self.cond:
                while self.foo_turn:
                    self.cond.wait()
                printBar()
                self.foo_turn = True
                self.cond.notify_all()


# """
# Semaphore
# """

# import threading


# class FooBar:
#     def __init__(self, n):
#         self.n = n
#         self.foo_sem = threading.Semaphore(1)  # 初始允许foo执行
#         self.bar_sem = threading.Semaphore(0)  # 初始阻塞bar

#     def foo(self, printFoo: "Callable[[], None]") -> None:

#         for i in range(self.n):

#             # printFoo() outputs "foo". Do not change or remove this line.
#             self.foo_sem.acquire()
#             printFoo()
#             self.bar_sem.release()

#     def bar(self, printBar: "Callable[[], None]") -> None:

#         for i in range(self.n):

#             # printBar() outputs "bar". Do not change or remove this line.
#             self.bar_sem.acquire()
#             printBar()
#             self.foo_sem.release()