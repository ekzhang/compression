import os
import sys
from threading import Thread

cow = sys.argv[1]

def run(filename):
	os.system('make run < {}'.format(filename))

Thread(target=os.system, args=('./imview < {}.200.in'.format(cow),)).start()
Thread(target=run, args=('{}.20000.in'.format(cow),)).start()
Thread(target=run, args=('{}.2000.in'.format(cow),)).start()
Thread(target=run, args=('{}.200.in'.format(cow),)).start()
