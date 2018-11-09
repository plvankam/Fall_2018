import threading
import time
import logging

logging.basicConfig(level=logging.DEBUG,
                    format='[%(levelname)s](%(threadName)-10s) %(message)s',)

def worker():
    logging.debug('Starting')
    time.sleep(2)
    logging.debug('Exiting')

def my_service():
    logging.debug('Starting')
    time.sleep(3)
    logging.debug('Exiting')


if __name__ == "__main__":
    t  = threading.Thread(name='my_service', target=my_service)
    t2 = threading.Thread(name='worker', target=worker)
    w  = threading.Thread(target=my_service)
    w.start()
    t2.start()
    t.start()
