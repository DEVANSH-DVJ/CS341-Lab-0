import gdb


class HeapPrinter:
    def __init__(self, val):
        self.val = val

    def to_string(self):
        string = 'VertexHeap object\n'
        string += 'Capacity: {}\n'.format(self.val['capacity'])
        string += 'Size: {}\n'.format(self.val['size'])
        string += 'index2HeapIdx: {}\n'.format(self.val['index2HeapIdx'])
        string += 'heapIdx2index: {}\n'.format(self.val['heapIdx2index'])
        heap = self.val['heap']
        string += 'Heap Address: {}\n'.format(heap)
        string += 'Heap: {'
        for i in range(self.val['size']):
            string += '[{}]: {}, '.format(i, heap.dereference())
            heap += 1
        return string[:-2] + '}\n'


def custom_printer(val):
    if str(val.type) == 'VertexHeap':
        return HeapPrinter(val)


gdb.pretty_printers.append(custom_printer)
