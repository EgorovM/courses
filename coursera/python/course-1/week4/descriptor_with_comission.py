class Value:
	def __init__(self, amount=0):
		self.amount = amount
	
	def __get__(self, obj, obj_type):
		return self.amount

	def __set__(self, obj, amount):
		self.amount = int(amount * (1 - obj.commission))

class Account:
	amount = Value()
	
	def __init__(self, comission):
		self.commission = commission
