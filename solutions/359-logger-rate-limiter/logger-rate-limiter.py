class Logger:

    def __init__(self):
        self.log={}
        

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message not in self.log:
            self.log[message]=timestamp+10
            return True
        else:
            if timestamp>=self.log[message]:
                self.log[message]=timestamp+10
                return True

            else:
                return False
