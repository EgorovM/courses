import time


class count_time:
	def __init__(self):
		self.start_time = time.time()

	def __enter__(self):
		pass

	def __exit__(self, *args):
		print(time.time() - self.start_time)
		

with count_time():
	time.sleep(1)

