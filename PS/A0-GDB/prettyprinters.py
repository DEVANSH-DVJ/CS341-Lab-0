class HeapPrinter:
	def __init__(self, val):
		self.val = val

	def to_string(self):
		return 'I am a VertexHeap'

def custom_printer(val):
	if str(val.type) == 'VertexHeap' : return HeapPrinter(val)

gdb.pretty_printers.append(custom_printer)