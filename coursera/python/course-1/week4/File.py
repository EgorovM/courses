import os
import tempfile


class File:
	def __init__(self, path):
		self.path = path
		self._check_file()
	
	def __getitem__(self, index):
		with open(self.path, 'r') as f:
			return f.readlines()[index]
	
	def __str__(self):
		return self.path
	
	def __add__(self, obj):
		curr_directory = tempfile.gettempdir()
		content1 = self.read()
		content2 = obj.read()
		new_name = self.path + obj.path
		new_path = os.path.join(curr_directory, new_name)
		new_path = os.path.join(curr_directory, str(hash(new_path)))

		new_file = File(new_path)
		new_file.write(content1 + content2)

		return new_file

	def _check_file(self):
		if not os.path.exists(self.path):
			with open(self.path, 'a') as f:
				pass
	
	def _read(self):
		with open(self.path, 'r') as f:
			return f.read()
	
	def _write(self, line):
		with open(self.path, 'w') as f:
			return f.write(line)

	def read(self):
		return self._read()	

	def write(self, line):
		return self._write(line)
